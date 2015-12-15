// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the ESBHUBSERVICELIB_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// ESBHUBSERVICELIB_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef ESBHUBSERVICELIB_EXPORTS
#define ESBHUBSERVICELIB_API __declspec(dllexport)
#else
#define ESBHUBSERVICELIB_API __declspec(dllimport)
#endif

// This class is exported from the ESBHubServiceLib.dll
class ESBHUBSERVICELIB_API CESBHubServiceLib {
public:
	CESBHubServiceLib(void);
	// TODO: add your methods here.
};

extern ESBHUBSERVICELIB_API int nESBHubServiceLib;

ESBHUBSERVICELIB_API int fnESBHubServiceLib(void);