// Thread.cpp 
//

#include "stdafx.h"
#include "UtilsRuntime.h"
#include "ThreadImp.h"

using namespace std;

// For thread information looking up
struct THREAD_CONTEXT
{
	Utils::Thread::IThread* pthread;
};

static map<int, THREAD_CONTEXT>	s_mapThreads;
CCriticalSectionImp				s_csmapThreads;


const UINT CThreadImp::MSG_INVOKE(::RegisterWindowMessageW(L"CThreadImp::MSG_INVOKE"));

CThreadImp::CThreadImp()
	: m_hThread(NULL),
	m_nThreadID(-1)
{
	// Use m_hThreadParamSig to ensure the thread would be running
	// before this object deleted.
	m_hThreadParamSig = ::CreateEvent(NULL, FALSE, FALSE, NULL);
	m_hhThread = ::CreateEvent(NULL, FALSE, FALSE, NULL);
	if (m_hThreadParamSig == NULL || m_hhThread == NULL)
	{
		// TODO: throw exception.
	}

	// Create a new thread.
	m_hThread = reinterpret_cast<HANDLE>( _beginthreadex (NULL,
		0, reinterpret_cast<_beginthreadex_proc_type>(&_Run),
		this, NULL, &m_nThreadID) );
	if (m_hThread == NULL)
	{
		// TODO: throw exception.
	}
	// Notify the thread that m_hThread and m_nThreadID have already created.
	SetEvent(m_hhThread);

	// Wait for the thread running.
	::WaitForSingleObject(m_hThreadParamSig, INFINITE);
	// Thread running well. Therefore we release m_hThreadParamSig.
	::CloseHandle(m_hThreadParamSig);
	m_hThreadParamSig = NULL;

	// Add thread information for looking up.
	{
		THREAD_CONTEXT tx;
		tx.pthread = this;
		SLOCK(&s_csmapThreads);
		s_mapThreads[m_nThreadID] = tx;
	}
}

CThreadImp::~CThreadImp()
{

}

bool CThreadImp::CancleAWaitingTask(const CAsynTaskImp* task)
{
	SLOCK(&m_csdqTasks);
	CAsynTaskImp *pTask = NULL;
	for (auto cur = m_dqTasks.begin(); cur != m_dqTasks.end(); ++cur)
	{
		pTask = static_cast<CAsynTaskImp*>((::Utils::Thread::IAsynTask*)(*cur));
		if (pTask == task)
		{
			pTask->SetThread(NULL);
			m_dqTasks.erase(cur);
			return true;
		}
	}
	return false;
}

unsigned int CThreadImp::Run()
{
	// Wait for the creation of m_hThread and m_nThreadID.
	::WaitForSingleObject(m_hhThread, INFINITE);
	// m_hhThread is no long needed.
	::CloseHandle(m_hhThread);
	m_hhThread = NULL;
	MSG msg;
	// Tell the system this thread has a message pump before it start GetMessage.
	// Or the message would post to this thread failedly after SetEvent(m_hThreadParamSig).
	::PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE);
	SetEvent(m_hThreadParamSig);
	while (::GetMessage(&msg, NULL, 0, 0))
	{
		if (msg.message == MSG_INVOKE)
			DispatchInvoke(msg.wParam, msg.lParam);
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
	}

	CleanUpTasks();
	//::CloseHandle(m_hThread);

	// Clear up thread information.
	{
		SLOCK(&s_csmapThreads);
		s_mapThreads.erase(m_nThreadID);
		::InterlockedExchange(reinterpret_cast<volatile long*>(&m_nThreadID), -1);
	}

	delete this;

	return 0;
}

void CThreadImp::DispatchInvoke(WPARAM wparam, LPARAM lparam)
{
	for (;;)
	{
		CAsynTaskImp *pTask = NULL;
		{
			SLOCK(&m_csdqTasks);
			if (m_dqTasks.empty())
				break;
			pTask = static_cast<CAsynTaskImp*>((::Utils::Thread::IAsynTask*)(*m_dqTasks.begin()));
			m_dqTasks.pop_front();
		}
		if (pTask != NULL)
			pTask->Execute();
	}
}

unsigned int _stdcall CThreadImp::_Run(CThreadImp* This)
{
	return This->Run();
}

void CThreadImp::CleanUpTasks()
{
	SLOCK(&m_csdqTasks);
	CAsynTaskImp *pTask = NULL;
	while (!m_dqTasks.empty())
	{
		pTask = static_cast<CAsynTaskImp*>((::Utils::Thread::IAsynTask*)(m_dqTasks.back()));
		pTask->SetThread(NULL);
		pTask->Cancle();
		m_dqTasks.pop_back();
	}
}


void CThreadImp::Invoke(const std::function<void()> &func)
{
	if (::GetCurrentThreadId() == m_nThreadID)
		func();
	else
	{
		//auto task = AsynInvoke(func, true);
		auto task = AsynInvoke(func);
		task->Join();
	}
}


SREF(Utils::Thread::IAsynTask) CThreadImp::AsynInvoke(const std::function<void()> &func)
{
	SREF(Utils::Thread::IAsynTask) spTask = new CAsynTaskImp(func, this, false);
	if (spTask == NULL)
	{
		// TODO: throw;
	}
	{
		SLOCK(&m_csdqTasks);
		m_dqTasks.push_back(spTask);
	}
	::PostThreadMessage(m_nThreadID, MSG_INVOKE, 0, 0);
	return spTask;
}

//bool CThreadImp::CancleTask(Utils::Thread::IAsynTask* task)
//{
//	CAsynTaskImp* _task = static_cast<CAsynTaskImp*>(task);
//	if (CancleAWaitingTask(_task))
//	{
//		task->Cancle();
//		return true;
//	}
//	else
//		return false;
//}

void CThreadImp::Dispose()
{
	if (GetCurrentThread() != this)
	{
		CleanUpTasks();
		HANDLE hThread = m_hThread;
		int nThreadID = m_nThreadID;
		::PostThreadMessage(nThreadID, WM_QUIT, 0, 0);
		::WaitForSingleObject(hThread, INFINITE);
	}
	else
		::PostThreadMessage(m_nThreadID, WM_QUIT, 0, 0);
}

namespace Utils
{
	namespace Thread
	{
		UTILSRUNTIME_API IThread* CreateThread()
		{
			return new CThreadImp;
		}

		UTILSRUNTIME_API IThread* GetCurrentThread()
		{
			int nThreadID = ::GetCurrentThreadId();
			SLOCK(&s_csmapThreads);
			auto lookup = s_mapThreads.find(nThreadID);
			if (lookup != s_mapThreads.end())
				return lookup->second.pthread;
			else
				return NULL;
		}
	};
};