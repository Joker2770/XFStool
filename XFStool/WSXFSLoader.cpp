
#include <QtWidgets/QMessageBox>
#include "WSXFSLoader.h"

WSXFSLoader::WSXFSLoader()
{
	hDllLib = LoadLibraryA("./msxfs.dll");
	if (hDllLib == nullptr)
	{
		QMessageBox::information(NULL, "NO", "DLL is not loaded!");
		return;
	}

// 	WCHAR lpDllPath[MAX_PATH];
// 	GetModuleFileName(hDllLib, lpDllPath, sizeof(lpDllPath));

	//WFM
	m_fpWFMAllocateBuffer = (WFMAllocateBufferProc)GetProcAddress(hDllLib, "WFMAllocateBuffer");
	m_fpWFMAllocateMore = (WFMAllocateMoreProc)GetProcAddress(hDllLib, "WFMAllocateMore");
	m_fpWFMFreeBuffer = (WFMFreeBufferProc)GetProcAddress(hDllLib, "WFMFreeBuffer");
	m_fpWFMGetTraceLevel = (WFMGetTraceLevelProc)GetProcAddress(hDllLib, "WFMGetTraceLevel");
	m_fpWFMKillTimer = (WFMKillTimerProc)GetProcAddress(hDllLib, "WFMKillTimer");
	m_fpWFMOutputTraceData = (WFMOutputTraceDataProc)GetProcAddress(hDllLib, "WFMOutputTraceData");
	m_fpWFMReleaseDLL = (WFMReleaseDLLProc)GetProcAddress(hDllLib, "WFMReleaseDLL");
	m_fpWFMSetTimer = (WFMSetTimerProc)GetProcAddress(hDllLib, "WFMSetTimer");
	m_fpWFMSetTraceLevel = (WFMSetTraceLevelProc)GetProcAddress(hDllLib, "WFMSetTraceLevel");
	//WFS
	m_fpWFSAsyncClose = (WFSAsyncCloseProc)GetProcAddress(hDllLib, "WFSAsyncClose");
	m_fpWFSAsyncDeregister = (WFSAsyncDeregisterProc)GetProcAddress(hDllLib, "WFSAsyncDeregister");
	m_fpWFSAsyncExecute = (WFSAsyncExecuteProc)GetProcAddress(hDllLib, "WFSAsyncExecute");
	m_fpWFSAsyncGetInfo = (WFSAsyncGetInfoProc)GetProcAddress(hDllLib, "WFSAsyncGetInfo");
	m_fpWFSAsyncLock = (WFSAsyncLockProc)GetProcAddress(hDllLib, "WFSAsyncLock");
	m_fpWFSAsyncOpen = (WFSAsyncOpenProc)GetProcAddress(hDllLib, "WFSAsyncOpen");
	m_fpWFSAsyncRegister = (WFSAsyncRegisterProc)GetProcAddress(hDllLib, "WFSAsyncRegister");
	m_fpWFSAsyncUnlock = (WFSAsyncUnlockProc)GetProcAddress(hDllLib, "WFSAsyncUnlock");
	m_fpWFSCancelAsyncRequest = (WFSCancelAsyncRequestProc)GetProcAddress(hDllLib, "WFSCancelAsyncRequest");
	m_fpWFSCancelBlockingCall = (WFSCancelBlockingCallProc)GetProcAddress(hDllLib, "WFSCancelBlockingCall");
	m_fpWFSCleanUp = (WFSCleanUpProc)GetProcAddress(hDllLib, "WFSCleanUp");
	m_fpWFSClose = (WFSCloseProc)GetProcAddress(hDllLib, "WFSClose");
	m_fpWFSDeregister = (WFSDeregisterProc)GetProcAddress(hDllLib, "WFSDeregister");
	m_fpWFSDestroyAppHandle = (WFSDestroyAppHandleProc)GetProcAddress(hDllLib, "WFSDestroyAppHandle");
	m_fpWFSFreeResult = (WFSFreeResultProc)GetProcAddress(hDllLib, "WFSFreeResult");
	m_fpWFSGetInfo = (WFSGetInfoProc)GetProcAddress(hDllLib, "WFSGetInfo");
	m_fpWFSIsBlocking = (WFSIsBlockingProc)GetProcAddress(hDllLib, "WFSIsBlocking");
	m_fpWFSLock = (WFSLockProc)GetProcAddress(hDllLib, "WFSLock");
	m_fpWFSOpen = (WFSOpenProc)GetProcAddress(hDllLib, "WFSOpen");
	m_fpWFSRegister = (WFSRegisterProc)GetProcAddress(hDllLib, "WFSRegister");
	m_fpWFSSetBlockingHook = (WFSSetBlockingHookProc)GetProcAddress(hDllLib, "WFSSetBlockingHook");
	m_fpWFSStartUp = (WFSStartUpProc)GetProcAddress(hDllLib, "WFSStartUp");
	m_fpWFSUnhookBlockingHook = (WFSUnhookBlockingHookProc)GetProcAddress(hDllLib, "WFSUnhookBlockingHook");
	m_fpWFSUnlock = (WFSUnlockProc)GetProcAddress(hDllLib, "WFSUnlock");

	//DWORD dwVersion = (*fpWFSStartUp)();
	//DWORD dwWindowsMajorVersion = (DWORD)(LOBYTE(LOWORD(dwVersion)));
	//DWORD dwWindowsMinorVersion = (DWORD)(HIBYTE(LOWORD(dwVersion)));
	//const int nBufSize = 512;
	//TCHAR chBuf[nBufSize];
	//ZeroMemory(chBuf, nBufSize);
	//OutputDebugString(chBuf);
	//FreeLibrary(hDllLib);
}

WSXFSLoader::~WSXFSLoader()
{
	if (hDllLib != nullptr)
	{
		FreeLibrary(hDllLib);
	}
}

HRESULT WSXFSLoader::WFMAllocateBuffer(ULONG ulSize, ULONG ulFlags, LPVOID * lppvData)
{
	return (*m_fpWFMAllocateBuffer)(ulSize, ulFlags, lppvData);
}

HRESULT WSXFSLoader::WFMAllocateMore(ULONG ulSize, LPVOID lpvOriginal, LPVOID * lppvData)
{
	return (*m_fpWFMAllocateMore)(ulSize, lpvOriginal, lppvData);
}

HRESULT WSXFSLoader::WFMFreeBuffer(LPVOID lpvData)
{
	return (*m_fpWFMFreeBuffer)(lpvData);
}

HRESULT WSXFSLoader::WFMGetTraceLevel(HSERVICE hService, LPDWORD lpdwTraceLevel)
{
	return (*m_fpWFMGetTraceLevel)(hService, lpdwTraceLevel);
}

HRESULT WSXFSLoader::WFMKillTimer(WORD wTimerID)
{
	return (*m_fpWFMKillTimer)(wTimerID);
}

HRESULT WSXFSLoader::WFMOutputTraceData(LPSTR lpszData)
{
	return (*m_fpWFMOutputTraceData)(lpszData);
}

HRESULT WSXFSLoader::WFMReleaseDLL(HPROVIDER hProvider)
{
	return (*m_fpWFMReleaseDLL)(hProvider);
}

HRESULT WSXFSLoader::WFMSetTimer(HWND hWnd, LPVOID lpContext, DWORD dwTimeVal, LPWORD lpwTimerID)
{
	return (*m_fpWFMSetTimer)(hWnd, lpContext, dwTimeVal, lpwTimerID);
}

HRESULT WSXFSLoader::WFMSetTraceLevel(HSERVICE hService, DWORD dwTraceLevel)
{
	return (*m_fpWFMSetTraceLevel)(hService, dwTraceLevel);
}

HRESULT WSXFSLoader::WFSAsyncClose(HSERVICE hService, HWND hWnd, LPREQUESTID lpRequestID)
{
	return (*m_fpWFSAsyncClose)(hService, hWnd, lpRequestID);
}

HRESULT WSXFSLoader::WFSAsyncDeregister(HSERVICE hService, DWORD dwEventClass, HWND hWndReg, HWND hWnd, LPREQUESTID lpRequestID)
{
	return (*m_fpWFSAsyncDeregister)(hService, dwEventClass, hWndReg, hWnd, lpRequestID);
}

HRESULT WSXFSLoader::WFSAsyncExecute(HSERVICE hService, DWORD dwCommand, LPVOID lpCmdData, DWORD dwTimeOut, HWND hWnd, LPREQUESTID lpRequestID)
{
	return (*m_fpWFSAsyncExecute)(hService, dwCommand, lpCmdData, dwTimeOut, hWnd, lpRequestID);
}

HRESULT WSXFSLoader::WFSAsyncGetInfo(HSERVICE hService, DWORD dwCategory, LPVOID lpQueryDetails, DWORD dwTimeOut, HWND hWnd, LPREQUESTID lpRequestID)
{
	return (*m_fpWFSAsyncGetInfo)(hService, dwCategory, lpQueryDetails, dwTimeOut, hWnd, lpRequestID);
}

HRESULT WSXFSLoader::WFSAsyncLock(HSERVICE hService, DWORD dwTimeOut, HWND hWnd, LPREQUESTID lpRequestID)
{
	return (*m_fpWFSAsyncLock)(hService, dwTimeOut, hWnd, lpRequestID);
}

HRESULT WSXFSLoader::WFSAsyncOpen(LPSTR lpszLogicalName, HAPP hApp, LPSTR lpszAppID, DWORD dwTraceLevel, DWORD dwTimeOut, LPHSERVICE lphService, HWND hWnd, DWORD dwSrvcVersionsRequired, LPWFSVERSION lpSrvcVersion, LPWFSVERSION lpSPIVersion, LPREQUESTID lpRequestID)
{
	return (*m_fpWFSAsyncOpen)(lpszLogicalName, hApp, lpszAppID, dwTraceLevel, dwTimeOut, lphService, hWnd, dwSrvcVersionsRequired, lpSrvcVersion, lpSPIVersion, lpRequestID);
}

HRESULT WSXFSLoader::WFSAsyncRegister(HSERVICE hService, DWORD dwEventClass, HWND hWndReg, HWND hWnd, LPREQUESTID lpRequestID)
{
	return (*m_fpWFSAsyncRegister)(hService, dwEventClass, hWndReg, hWnd, lpRequestID);
}

HRESULT WSXFSLoader::WFSAsyncUnlock(HSERVICE hService, HWND hWnd, LPREQUESTID lpRequestID)
{
	return (*m_fpWFSAsyncUnlock)(hService, hWnd, lpRequestID);
}

HRESULT WSXFSLoader::WFSCancelAsyncRequest(HSERVICE hService, REQUESTID lpRequestID)
{
	return (*m_fpWFSCancelAsyncRequest)(hService, lpRequestID);
}

HRESULT WSXFSLoader::WFSCancelBlockingCall(DWORD dwThreadID)
{
	return (*m_fpWFSCancelBlockingCall)(dwThreadID);
}

HRESULT WSXFSLoader::WFSCleanUp()
{
	return (*m_fpWFSCleanUp)();
}

HRESULT WSXFSLoader::WFSClose(HSERVICE hService)
{
	return (*m_fpWFSClose)(hService);
}

HRESULT WSXFSLoader::WFSDeregister(HSERVICE hService, DWORD dwEventClass, HWND hWndReg)
{
	return (*m_fpWFSDeregister)(hService, dwEventClass, hWndReg);
}

HRESULT WSXFSLoader::WFSDestroyAppHandle(HAPP hApp)
{
	return (*m_fpWFSDestroyAppHandle)(hApp);
}

HRESULT WSXFSLoader::WFSExecute(HSERVICE hService, DWORD dwCommand, LPVOID lpCmdData, DWORD dwTimeOut, LPWFSRESULT * lppResult)
{
	return (*m_fpWFSExecute)(hService, dwCommand, lpCmdData, dwTimeOut, lppResult);
}

HRESULT WSXFSLoader::WFSFreeResult(LPWFSRESULT lpResult)
{
	return (*m_fpWFSFreeResult)(lpResult);
}

HRESULT WSXFSLoader::WFSGetInfo(HSERVICE hService, DWORD dwCategory, LPVOID lpQueryDetails, DWORD dwTimeOut, LPWFSRESULT * lppResult)
{
	return (*m_fpWFSGetInfo)(hService, dwCategory, lpQueryDetails, dwTimeOut, lppResult);
}

HRESULT WSXFSLoader::WFSIsBlocking()
{
	return (*m_fpWFSIsBlocking)();
}

HRESULT WSXFSLoader::WFSLock(HSERVICE hService, DWORD dwTimeOut, LPWFSRESULT * lppResult)
{
	return (*m_fpWFSLock)(hService, dwTimeOut, lppResult);
}

HRESULT WSXFSLoader::WFSOpen(LPSTR lpszLogicalName, HAPP hApp, LPSTR lpszAppID, DWORD dwTraceLevel, DWORD dwTimeOut, DWORD dwSrvcVersionsRequired, LPWFSVERSION lpSrvcVersion, LPWFSVERSION lpSPIVersion, LPHSERVICE lphService)
{
	return (*m_fpWFSOpen)(lpszLogicalName, hApp, lpszAppID, dwTraceLevel, dwTimeOut, dwSrvcVersionsRequired, lpSrvcVersion, lpSPIVersion, lphService);
}

HRESULT WSXFSLoader::WFSRegister(HSERVICE hService, DWORD dwEventClass, HWND hWndReg)
{
	return (*m_fpWFSRegister)(hService, dwEventClass, hWndReg);
}

HRESULT WSXFSLoader::WFSSetBlockingHook(XFSBLOCKINGHOOK lpBlockFunc, LPXFSBLOCKINGHOOK lppPrevFunc)
{
	return (*m_fpWFSSetBlockingHook)(lpBlockFunc, lppPrevFunc);
}

HRESULT WSXFSLoader::WFSStartUp(DWORD dwVersionsRequired, LPWFSVERSION lpWFSVersion)
{
	return (*m_fpWFSStartUp)(dwVersionsRequired, lpWFSVersion);
}

HRESULT WSXFSLoader::WFSUnhookBlockingHook()
{
	return (*m_fpWFSUnhookBlockingHook)();
}

HRESULT WSXFSLoader::WFSUnlock(HSERVICE hService)
{
	return (*m_fpWFSUnlock)(hService);
}