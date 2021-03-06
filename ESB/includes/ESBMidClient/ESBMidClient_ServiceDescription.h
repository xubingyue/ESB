#ifndef _INCLUDE_ESBMIDCLIENT_CONNECTION_H_
#define _INCLUDE_ESBMIDCLIENT_CONNECTION_H_

#include <string>

#ifndef ESBMIDCONN_API
#define ESBMIDCONN_API
#endif

namespace ESBMidService
{
	class IESBConnection : Utils::SafeCoding::IDisposable
	{
	public:
		virtual int Initialize(const std::wstring& wsURL, const GUID& guidService) = 0;
		virtual int Uninitialzie(void) = 0;
		virtual int IsInitialized(void) const = 0;
		virtual int Send(const std::wstring& wsContent, std::wstring& wsResult) = 0;
		virtual std::wstring&& GetInitialURL() = 0;
		virtual std::wstring&& GetActualURL() = 0;
		virtual GUID&& GetServiceGUID() = 0;
	};

	ESBMIDCONN_API IESBConnection* CreateESBConnection();
};

#endif //_INCLUDE_ESBMIDCLIENT_CONNECTION_H_