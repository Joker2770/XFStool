#ifndef __WSXFSLOADER_H__
#define __WSXFSLOADER_H__

#include "xfsapi.h"
#include "xfsadmin.h"
#include "xfsspi.h"

//WFM
typedef HRESULT(WINAPI * WFMAllocateBufferProc)(ULONG, ULONG, LPVOID);
typedef HRESULT(WINAPI * WFMAllocateMoreProc)(ULONG ulSize, LPVOID lpvOriginal, LPVOID * lppvData);
typedef HRESULT(WINAPI * WFMFreeBufferProc)(LPVOID lpvData);
typedef HRESULT(WINAPI * WFMGetTraceLevelProc)(HSERVICE hService, LPDWORD lpdwTraceLevel);
typedef HRESULT(WINAPI * WFMKillTimerProc)(WORD wTimerID);
typedef HRESULT(WINAPI * WFMOutputTraceDataProc)(LPSTR lpszData);
typedef HRESULT(WINAPI * WFMReleaseDLLProc)(HPROVIDER hProvider);
typedef HRESULT(WINAPI * WFMSetTimerProc)(HWND hWnd, LPVOID lpContext, DWORD dwTimeVal, LPWORD lpwTimerID);
typedef HRESULT(WINAPI * WFMSetTraceLevelProc)(HSERVICE hService, DWORD dwTraceLevel);
//WFS
typedef HRESULT(WINAPI * WFSAsyncCloseProc)(HSERVICE hService, HWND hWnd, LPREQUESTID lpRequestID);
typedef HRESULT(WINAPI * WFSAsyncDeregisterProc)(HSERVICE hService, DWORD dwEventClass, HWND hWndReg, HWND hWnd, LPREQUESTID lpRequestID);
typedef HRESULT(WINAPI * WFSAsyncExecuteProc)(HSERVICE hService, DWORD dwCommand, LPVOID lpCmdData, DWORD dwTimeOut, HWND hWnd, LPREQUESTID lpRequestID);
typedef HRESULT(WINAPI * WFSAsyncGetInfoProc)(HSERVICE hService, DWORD dwCategory, LPVOID lpQueryDetails, DWORD dwTimeOut, HWND hWnd, LPREQUESTID lpRequestID);
typedef HRESULT(WINAPI * WFSAsyncLockProc)(HSERVICE hService, DWORD dwTimeOut, HWND hWnd, LPREQUESTID lpRequestID);
typedef HRESULT(WINAPI * WFSAsyncOpenProc)(LPSTR lpszLogicalName, HAPP hApp, LPSTR lpszAppID, DWORD dwTraceLevel, DWORD dwTimeOut, LPHSERVICE lphService, HWND hWnd, DWORD dwSrvcVersionsRequired, LPWFSVERSION lpSrvcVersion, LPWFSVERSION lpSPIVersion, LPREQUESTID lpRequestID);
typedef HRESULT(WINAPI * WFSAsyncRegisterProc)(HSERVICE hService, DWORD dwEventClass, HWND hWndReg, HWND hWnd, LPREQUESTID lpRequestID);
typedef HRESULT(WINAPI * WFSAsyncUnlockProc)(HSERVICE hService, HWND hWnd, LPREQUESTID lpRequestID);
typedef HRESULT(WINAPI * WFSCancelAsyncRequestProc)(HSERVICE hService, REQUESTID RequestID);
typedef HRESULT(WINAPI * WFSCancelBlockingCallProc)(DWORD dwThreadID);
typedef HRESULT(WINAPI * WFSCleanUpProc)();
typedef HRESULT(WINAPI * WFSCloseProc)(HSERVICE hService);
typedef HRESULT(WINAPI * WFSDeregisterProc)(HSERVICE hService, DWORD dwEventClass, HWND hWndReg);
typedef HRESULT(WINAPI * WFSDestroyAppHandleProc)(HAPP hApp);
typedef HRESULT(WINAPI * WFSExecuteProc)(HSERVICE hService, DWORD dwCommand, LPVOID lpCmdData, DWORD dwTimeOut, LPWFSRESULT * lppResult);
typedef HRESULT(WINAPI * WFSFreeResultProc)(LPWFSRESULT lpResult);
typedef HRESULT(WINAPI * WFSGetInfoProc)(HSERVICE hService, DWORD dwCategory, LPVOID lpQueryDetails, DWORD dwTimeOut, LPWFSRESULT * lppResult);
typedef BOOL(WINAPI * WFSIsBlockingProc)();
typedef HRESULT(WINAPI * WFSLockProc)(HSERVICE hService, DWORD dwTimeOut, LPWFSRESULT * lppResult);
typedef HRESULT(WINAPI * WFSOpenProc)(LPSTR lpszLogicalName, HAPP hApp, LPSTR lpszAppID, DWORD dwTraceLevel, DWORD dwTimeOut, DWORD dwSrvcVersionsRequired, LPWFSVERSION lpSrvcVersion, LPWFSVERSION lpSPIVersion, LPHSERVICE lphService);
typedef HRESULT(WINAPI * WFSRegisterProc)(HSERVICE hService, DWORD dwEventClass, HWND hWndReg);
typedef HRESULT(WINAPI * WFSSetBlockingHookProc)(XFSBLOCKINGHOOK lpBlockFunc, LPXFSBLOCKINGHOOK lppPrevFunc);
typedef HRESULT(WINAPI * WFSStartUpProc)(DWORD dwVersionsRequired, LPWFSVERSION lpWFSVersion);
typedef HRESULT(WINAPI * WFSUnhookBlockingHookProc)();
typedef HRESULT(WINAPI * WFSUnlockProc)(HSERVICE hService);

class WSXFSLoader
{
private:
	//ULONG ulMemFlags = WFS_MEM_ZEROINIT | WFS_MEM_SHARE;
	HMODULE hDllLib;

	//WFM
	WFMAllocateBufferProc m_fpWFMAllocateBuffer;
	WFMAllocateMoreProc m_fpWFMAllocateMore;
	WFMFreeBufferProc m_fpWFMFreeBuffer;
	WFMGetTraceLevelProc m_fpWFMGetTraceLevel;
	WFMKillTimerProc m_fpWFMKillTimer;
	WFMOutputTraceDataProc m_fpWFMOutputTraceData;
	WFMReleaseDLLProc m_fpWFMReleaseDLL;
	WFMSetTimerProc m_fpWFMSetTimer;
	WFMSetTraceLevelProc m_fpWFMSetTraceLevel;
	//WFS
	WFSAsyncCloseProc m_fpWFSAsyncClose;
	WFSAsyncDeregisterProc m_fpWFSAsyncDeregister;
	WFSAsyncExecuteProc m_fpWFSAsyncExecute;
	WFSAsyncGetInfoProc m_fpWFSAsyncGetInfo;
	WFSAsyncLockProc m_fpWFSAsyncLock;
	WFSAsyncOpenProc m_fpWFSAsyncOpen;
	WFSAsyncRegisterProc m_fpWFSAsyncRegister;
	WFSAsyncUnlockProc m_fpWFSAsyncUnlock;
	WFSCancelAsyncRequestProc m_fpWFSCancelAsyncRequest;
	WFSCancelBlockingCallProc m_fpWFSCancelBlockingCall;
	WFSCleanUpProc m_fpWFSCleanUp;
	WFSCloseProc m_fpWFSClose;
	WFSDeregisterProc m_fpWFSDeregister;
	WFSDestroyAppHandleProc m_fpWFSDestroyAppHandle;
	WFSExecuteProc m_fpWFSExecute;
	WFSFreeResultProc m_fpWFSFreeResult;
	WFSGetInfoProc m_fpWFSGetInfo;
	WFSIsBlockingProc m_fpWFSIsBlocking;
	WFSLockProc m_fpWFSLock;
	WFSOpenProc m_fpWFSOpen;
	WFSRegisterProc m_fpWFSRegister;
	WFSSetBlockingHookProc m_fpWFSSetBlockingHook;
	WFSStartUpProc m_fpWFSStartUp;
	WFSUnhookBlockingHookProc  m_fpWFSUnhookBlockingHook;
	WFSUnlockProc m_fpWFSUnlock;

public:
	WSXFSLoader();
	~WSXFSLoader();
	HRESULT WFMAllocateBuffer(ULONG ulSize, ULONG ulFlags, LPVOID * lppvData);
	HRESULT WFMAllocateMore(ULONG ulSize, LPVOID lpvOriginal, LPVOID * lppvData);
	HRESULT WFMFreeBuffer(LPVOID lpvData);
	HRESULT WFMGetTraceLevel(HSERVICE hService, LPDWORD lpdwTraceLevel);
	HRESULT WFMKillTimer(WORD wTimerID);
	HRESULT WFMOutputTraceData(LPSTR lpszData);
	HRESULT WFMReleaseDLL(HPROVIDER hProvider);
	HRESULT WFMSetTimer(HWND hWnd, LPVOID lpContext, DWORD dwTimeVal, LPWORD lpwTimerID);
	HRESULT WFMSetTraceLevel(HSERVICE hService, DWORD dwTraceLevel);
	HRESULT WFSAsyncClose(HSERVICE hService, HWND hWnd, LPREQUESTID lpRequestID);
	HRESULT WFSAsyncDeregister(HSERVICE hService, DWORD dwEventClass, HWND hWndReg, HWND hWnd, LPREQUESTID lpRequestID);
	HRESULT WFSAsyncExecute(HSERVICE hService, DWORD dwCommand, LPVOID lpCmdData, DWORD dwTimeOut, HWND hWnd, LPREQUESTID lpRequestID);
	HRESULT WFSAsyncGetInfo(HSERVICE hService, DWORD dwCategory, LPVOID lpQueryDetails, DWORD dwTimeOut, HWND hWnd, LPREQUESTID lpRequestID);
	HRESULT WFSAsyncLock(HSERVICE hService, DWORD dwTimeOut, HWND hWnd, LPREQUESTID lpRequestID);
	HRESULT WFSAsyncOpen(LPSTR lpszLogicalName, HAPP hApp, LPSTR lpszAppID, DWORD dwTraceLevel, DWORD dwTimeOut, LPHSERVICE lphService, HWND hWnd, DWORD dwSrvcVersionsRequired, LPWFSVERSION lpSrvcVersion, LPWFSVERSION lpSPIVersion, LPREQUESTID lpRequestID);
	HRESULT WFSAsyncRegister(HSERVICE hService, DWORD dwEventClass, HWND hWndReg, HWND hWnd, LPREQUESTID lpRequestID);
	HRESULT WFSAsyncUnlock(HSERVICE hService, HWND hWnd, LPREQUESTID lpRequestID);
	HRESULT WFSCancelAsyncRequest(HSERVICE hService, REQUESTID RequestID);
	HRESULT WFSCancelBlockingCall(DWORD dwThreadID);
	HRESULT WFSCleanUp();
	HRESULT WFSClose(HSERVICE hService);
	HRESULT WFSDeregister(HSERVICE hService, DWORD dwEventClass, HWND hWndReg);
	HRESULT WFSDestroyAppHandle(HAPP hApp);
	HRESULT WFSExecute(HSERVICE hService, DWORD dwCommand, LPVOID lpCmdData, DWORD dwTimeOut, LPWFSRESULT * lppResult);
	HRESULT WFSFreeResult(LPWFSRESULT lpResult);
	HRESULT WFSGetInfo(HSERVICE hService, DWORD dwCategory, LPVOID lpQueryDetails, DWORD dwTimeOut, LPWFSRESULT * lppResult);
	HRESULT WFSIsBlocking();
	HRESULT WFSLock(HSERVICE hService, DWORD dwTimeOut, LPWFSRESULT * lppResult);
	HRESULT WFSOpen(LPSTR lpszLogicalName, HAPP hApp, LPSTR lpszAppID, DWORD dwTraceLevel, DWORD dwTimeOut, DWORD dwSrvcVersionsRequired, LPWFSVERSION lpSrvcVersion, LPWFSVERSION lpSPIVersion, LPHSERVICE lphService);
	HRESULT WFSRegister(HSERVICE hService, DWORD dwEventClass, HWND hWndReg);
	HRESULT WFSSetBlockingHook(XFSBLOCKINGHOOK lpBlockFunc, LPXFSBLOCKINGHOOK lppPrevFunc);
	HRESULT WFSStartUp(DWORD dwVersionsRequired, LPWFSVERSION lpWFSVersion);
	HRESULT WFSUnhookBlockingHook();
	HRESULT WFSUnlock(HSERVICE hService);
};

#endif
