#ifndef _INCLUDE_ESBMIDSERVICE_HUBCONNECTION_H_
#define _INCLUDE_ESBMIDSERVICE_HUBCONNECTION_H_

#include "../Utils/SafeCoding/IDisposable.h"

namespace ESBMidService
{
	class IESBServiceHubConnection
	{
	public:
		virtual BOOL IsValid() const = 0;
		virtual int ModifySessionLimitation(int nLimitation) = 0;
		virtual int IncreaseSessionLoad() = 0;
		virtual int DecreaseSessionLoad() = 0;
		virtual int Unregister() = 0;
	};

};

#endif //_INCLUDE_ESBMIDSERVICE_HUBCONNECTION_H_