#ifndef STORM_INCLUDED
#define STORM_INCLUDED

#if defined(_MSC_VER) && _MSC_VER > 1000
#pragma once
#endif

#include <stddef.h>

#ifdef _WIN32
#include <windows.h>
#else
typedef int BOOL;
typedef unsigned long DWORD;
typedef void* HANDLE;
typedef unsigned long LCID;
typedef long LONG;
#endif

#ifdef __cplusplus
extern "C"
{
#endif

	BOOL   __stdcall NetInit();
	BOOL   __stdcall SNetCreateGame(char* Source, char* a2, char* a3, int a4, int a5, int a6, char* a7, char* a8, int* playerid);
	BOOL   __cdecl   SNetDestroy();
	BOOL   __stdcall SNetEnumProviders(int mincaps, int(__stdcall* callback)(DWORD*, DWORD*, DWORD*, DWORD*));
	BOOL   __stdcall SNetEnumDevices(int(__stdcall* callback)(DWORD*, DWORD*, DWORD*));
	BOOL   __stdcall SNetEnumGames(int(__stdcall* callback)(DWORD*, DWORD*, DWORD*), int* hintnextcall);
	BOOL   __stdcall SNetDropPlayer(int playerid, int flags);
	BOOL   __stdcall SNetGetGameInfo(int type, void* src, unsigned int length, int* byteswritten);
	BOOL   __stdcall SNetGetNetworkLatency(int measurementtype, int* result);
	BOOL   __stdcall SNetGetNumPlayers(int* firstplayerid, int* lastplayerid, int* activeplayers);
	BOOL   __stdcall SNetGetOwnerTurnsWaiting(int* turns);
	BOOL   __stdcall SNetGetPerformanceData(int counterid, int* countervalue, int* countertype, int* counterscale, LPFILETIME* measurementtime, int* measurementfreq);
	BOOL   __stdcall SNetGetPlayerCaps(char a1, int* caps);
	BOOL   __stdcall SNetGetPlayerName(int playerid, char* buffer, size_t buffersize);
	BOOL   __stdcall SNetGetProviderCaps(void* caps);
	BOOL   __stdcall SNetGetTurnsInTransit(int* turns);
	BOOL   __stdcall SNetInitializeDevice(int a1, int a2, int a3, int a4, int a5);
	BOOL   __stdcall SNetInitializeProvider(DWORD providerName, int a2, int a3, int a4, DWORD ThreadID);
	BOOL   __stdcall SNetJoinGame(int a1, char* a2, char* a3, char* playerName, char* a5, int* playerid);
	BOOL   __stdcall SNetLeaveGame(int type);
	BOOL   __stdcall SNetPerformUpgrade(DWORD* upgradestatus);
	BOOL   __stdcall SNetReceiveMessage(int* senderplayerid, int* data, int* databytes);
	BOOL   __stdcall SNetReceiveTurns(unsigned int a1, int arraysize, void* arraydata, void* arraydatabytes, void* arrayplayerstatus);
	HANDLE __stdcall SNetRegisterEventHandler(int event, int size);
	BOOL   __cdecl   SNetResetLatencyMeasurements();
	int    __stdcall SNetSelectGame(int a1, int a2, int a3, int a4, int a5, int* playerid);
	BOOL   __stdcall SNetSelectProvider(LPARAM lparam, int a2, int a3, int a4, int a5, int* providerid);
	BOOL   __stdcall SNetSendMessage(signed int playerID, void* data, int databytes);
	BOOL   __stdcall SNetSendTurn(void* data, int databytes);
	BOOL   __stdcall SNetSetBasePlayer(int a1);
	BOOL   __stdcall SNetSetGameMode(int a1);
	int    __stdcall SNetUnregisterEventHandler(int a1, int callback);
	
	BOOL __stdcall SNetEnumGamesEx(int a1, int a2, int(__fastcall* callback)(DWORD*, DWORD*, DWORD*), int* hintnextcall);
	int	 __stdcall SNetSendServerChatCommand(char* command);
	BOOL __stdcall SNet135(signed int a1, int a2, int a3);
	BOOL __stdcall SNet136(int a1, int a2, int a3);
	BOOL __stdcall SNet137(int a1);
	BOOL __stdcall SNetCreateLadderGame(int a1, int a2, int a3, int a4, int a5, int a6, const void* MemSrc, int MemSize, int a9, char* playerName, int a11, int a12);
	BOOL __stdcall SNetReportGameResult(unsigned int a1, int size, int a3, int a4, int a5);
	BOOL __stdcall SNetCheckDataFile(int a1, int a2, int a3, int a4);
	int	 __stdcall SNetSendLeagueCommand(char* cmd, int a2);
	int	 __stdcall SNetSendReplayPath(int a1, int a2, char* replayPath);
	int	 __stdcall SNet143(int a1);
	BOOL __stdcall SNet144(int a1);
	int	 __stdcall SNetLeagueLogout(char* bnetName);
	int	 __stdcall SNet146(int* curPlayerID, size_t nameSize);
	
	BOOL	__stdcall SDlgInit();
	HDC     __stdcall SDlgBeginPaint(HWND window, LPPAINTSTRUCT ps);
	int     __stdcall SDlgBltToWindowI(HWND window, HRGN hrgnSrc2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10);
	BOOL    __cdecl   SDlgCheckTimers();
	int     __stdcall SDlgCreateDialogIndirectParam(HMODULE hModule, LPCSTR lpName, HWND hWndParent, LPVOID lpParam);
	int     __stdcall SDlgCreateDialogParam(int a1, int a2, HWND hWndParent, LPVOID lpParam);
	HGDIOBJ __stdcall SDlgDefDialogProc(HWND hDlg, signed int DlgType, HDC textLabel, HWND hWnd);
	void	__stdcall SDlgDestroy();
	int     __stdcall SDlgDialogBoxIndirectParam(int a1, int a2, HWND hWndParent, LPVOID lpParam, LPARAM lParam);
	int     __stdcall SDlgDialogBoxParam(HMODULE hModule, LPCSTR lpName, HWND hWndParent, LPVOID lpParam, LPARAM lParam);
	int     __stdcall SDlgDrawBitmap(HWND window, HGDIOBJ a2, HRGN hrgnSrc2, int a4, int a5, int a6, int a7);
	BOOL    __stdcall SDlgEndDialog(HWND hDlg, HANDLE nResult);
	BOOL    __stdcall SDlgEndPaint(HWND hWnd, PAINTSTRUCT* lpPaint);
	int     __stdcall SDlgKillTimer(int a1, int a2);
	int     __stdcall SDlgSetBaseFont(int a1, int a2, int a3, int a4, char* Source);
	int     __stdcall SDlgSetBitmapI(int a1, int a2, char* Str2, int a4, int a5, int a6, int a7, int a8, int a9, int a10);
	int     __stdcall SDlgSetControlBitmaps(HWND parentwindow, int a2, int a3, int a4, int a5, int arg14, int a7);
	int     __stdcall SDlgSetCursor(HWND hWnd, LONG dwNewLong, int a3, int a4);
	int     __stdcall SDlgSetSystemCursor(int a1, int a2, int a3, signed int a4);
	int     __stdcall SDlgSetTimer(int a1, int a2, int a3, int a4);
	int     __cdecl   SDlgUpdateCursor();
	int     __stdcall SDlgBltToWindowE(HWND hWnd, HRGN a2, char* a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10);
	int     __stdcall SDlgSetBitmapE(int a1, int a2, char* src, int a4, int a5, int a6, int a7, signed int a8, int a9, signed int a10);
	char* __stdcall SDlgSetLocale(int a1, const char* a2);
	int     __stdcall Ordinal224(int a1);
	
	BOOL	__stdcall SFileInit();
	int     __stdcall SFileAuthenticateArchive(HANDLE hArchive, int a2);
	BOOL    __stdcall SFileCloseArchive(HANDLE hArchive);
	BOOL    __stdcall SFileCloseFile(HANDLE hFile);
	int     __stdcall SFileDdaBegin(HANDLE hFile, int a2, int a3);
	int     __stdcall SFileDdaBeginEx(HANDLE hFile, signed int a2, unsigned int a3, unsigned __int32 lDistanceToMove, signed int a5, signed int a6, int a7);
	BOOL    __cdecl   SFileDdaDestroy();
	BOOL    __stdcall SFileDdaEnd(HANDLE directsound);
	BOOL    __stdcall SFileDdaGetPos(int a1, int a2, int a3);
	BOOL    __stdcall SFileDdaGetVolume(int a1, int a2, int a3);
	BOOL    __stdcall SFileDdaInitialize(HANDLE directsound);
	BOOL    __stdcall SFileDdaSetVolume(HANDLE directsound, signed int bigvolume, signed int volume);
	BOOL    __cdecl   SFileDestroy();
	BOOL    __stdcall SFileEnableDirectAccess(HANDLE hFile);
	BOOL    __stdcall SFileGetFileArchive(HANDLE hFile, HANDLE archive);
	LONG    __stdcall SFileGetFileSize(HANDLE hFile, DWORD* lpFileSizeHigh);
	BOOL    __stdcall SFileOpenArchive(const char* archivename, DWORD dwPriority, DWORD dwFlags, HANDLE* handle);
	BOOL    __stdcall SFileOpenFile(const char* filename, HANDLE* handle);
	BOOL    __stdcall SFileOpenFileEx(HANDLE handle, const char* filename, char mode, HANDLE* result);
	BOOL    __stdcall SFileReadFile(HANDLE hFile, const char* buffer, DWORD nNumberOfBytesToRead, int* read, LONG lpDistanceToMoveHigh);
	BOOL    __stdcall SFileSetBasePath(const char* path);
	LONG    __stdcall SFileSetFilePointer(HANDLE hFile, LONG filePos, LONG* filePosHigh, DWORD dwMethod);
	LCID    __stdcall SFileSetLocale(LCID lcLocale);
	BOOL    __stdcall SFileGetBasePath(const char* result, int maxSize);
	BOOL    __stdcall SFileSetIoErrorMode(int a1, int a2);
	BOOL    __stdcall SFileGetArchiveName(HANDLE hArchive, const char* name, int length);
	BOOL    __stdcall SFileGetFileName(HANDLE hFile, const char* buffer, int length);
	int     __stdcall SFileGetArchiveInfo(int a1, int a2, int a3);
	char    __stdcall SFileSetPlatform(char a1);
	int     __stdcall SFileLoadFile(const char* filename, int a2, int a3, int a4, int a5);
	BOOL    __stdcall SFileUnloadFile(void* buffer);
	BOOL    __stdcall SFileLoadFileEx(void* hArchive, const char* filename, int a3, int a4, int a5, DWORD searchScope, struct _OVERLAPPED* lpOverlapped);
	void    __stdcall SFilePrioritizeRequest(int a1, int a2);
	void    __stdcall SFileCancelRequest(int a1);
	int     __stdcall SFileSetAsyncBudget(int a1);
	void    __stdcall SFileSetDataChunkSize(int a1);
	BOOL	__stdcall SFileOpenFileAsArchive(int a1, const char* archivename, DWORD dwPriority, DWORD dwFlags, HANDLE* handle);
	LCID    __cdecl   SFileGetLocale();
	BOOL    __cdecl   StormDestroy();
	HMODULE __cdecl   StormGetInstance();
	BOOL    __stdcall StormGetOption(int type, int optval, size_t optlen);
	BOOL    __stdcall StormSetOption(int type, int optval, size_t optlen);
	
	BOOL __stdcall SBltDestroy();
	BOOL __stdcall SBltGetSCode(unsigned int a1, char* buffer, size_t buffersize, int a4);
	BOOL __stdcall SBltROP3(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
	BOOL __stdcall SBltROP3Clipped(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10);
	BOOL __stdcall SBltROP3Tiled(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10);
	
	BOOL   __stdcall SBmpInit();
	BOOL   __stdcall SBmpDecodeImage(int a1, signed int* a2, unsigned int a3, int a4, int a5, int a6, int a7, int a8, int a9);
	BOOL   __stdcall SBmpDestroy();
	BOOL   __stdcall SBmpLoadImage(const char* fileName, int a2, int a3, int a4, int a5, int a6, int a7);
	BOOL   __stdcall SBmpSaveImage(const char* fileName, unsigned __int16 width, unsigned __int16 height, int paletteentries, int bitdepth, int bitmapbits);
	HANDLE __stdcall SBmpAllocLoadImage(const char* fileName, int a2, int a3, int a4, int a5, int a6, int a7, int(__stdcall* a8)(DWORD*));
	BOOL   __stdcall SBmpSaveImageEx(const char* filename, unsigned __int16 width, unsigned __int16 height, int paletteentries, int bitdepth, int bitmapbits, int reserved);
	
	BOOL __stdcall SCodeInit();
	BOOL __stdcall SCodeCompile(char* directives1, char* directives2, int a3, unsigned int a4, unsigned int flags, char* src);
	BOOL __stdcall SCodeDelete(int handle);
	BOOL __stdcall SCodeDestroy();
	int  __cdecl   SCodeExecute(int a1, int a2);
	BOOL __stdcall SCodeGetPseudocode(int scodestring, int buffer, size_t buffersize);
	
	BOOL __stdcall SDrawInit();
	BOOL __stdcall SDrawAutoInitialize(HINSTANCE hWnd, LPCSTR lpClassName, LPCSTR lpWindowName, int(__stdcall* a4)(HWND, UINT, WPARAM, LPARAM), signed int a5, int nWidth, int nHeight, int a8);
	BOOL __stdcall SDrawCaptureScreen(char* source);
	BOOL __stdcall SDrawClearSurface(int surfacenumber);
	BOOL __cdecl   SDrawDestroy();
	BOOL __cdecl   SDrawFlipPage();
	HWND __stdcall SDrawGetFrameWindow(int sdraw_framewindow);
	BOOL __stdcall SDrawGetObjects(int obj1, int obj2, int obj3, int obj4, int obj5, int obj6, int obj7);
	BOOL __stdcall SDrawGetScreenSize(int width, int height, int depth);
	BOOL __stdcall SDrawGetServiceLevel(int a1);
	BOOL __stdcall SDrawLockSurface(int surfacenumber, RECT* lpDestRect, void** lplpSurface, int* lpPitch, int arg_unused);
	BOOL __stdcall SDrawManualInitialize(HWND a1, int obj1, int obj2, int obj3, int obj4, int obj5, int obj6, void* obj7);
	int  __stdcall SDrawMessageBox(LPCSTR lpText, LPCSTR lpCaption, UINT uType);
	BOOL __cdecl   SDrawPostClose();
	BOOL __cdecl   SDrawRealizePalette();
	int  __stdcall SDrawSelectGdiSurface(unsigned int a1, int a2);
	BOOL __stdcall SDrawUnlockSurface(int surfacenumber, void* lpSurface, int zero1, int zero2);
	BOOL __stdcall SDrawUpdatePalette(unsigned int firstentry, unsigned int numentries, PALETTEENTRY* pPalEntries, int a4);
	BOOL __stdcall SDrawUpdateScreen(int a1);
	int  __cdecl   SDrawWaitForVerticalBlank();
	
	BOOL __stdcall SEvtDispatch(DWORD messageID, int a2, int a3, int a4);
	BOOL __stdcall SEvtRegisterHandler(DWORD messageID, unsigned int a2, int event, int a4, int a5);
	BOOL __stdcall SEvtUnregisterHandler(DWORD messageID, int a2, int a3, int a4);
	BOOL __stdcall SEvtUnregisterType(DWORD messageID, int a2);
	BOOL __stdcall SEvtPopState(DWORD messageID, int type);
	BOOL __stdcall SEvtPushState(DWORD messageID, int type);
	BOOL __stdcall SEvtBreakHandlerChain(int a1);
	
	BOOL __stdcall SGdiInit();
	BOOL __stdcall SGdiBitBlt(int a1, int a2, int a3, int a4, unsigned int a5, int a6, int a7, unsigned int a8, signed int a9);
	BOOL __stdcall SGdiCreateFont(const void* handle, int bits, int width, int height, int filecharwidth, int filecharheight, const void* charsizetable, int a8);
	BOOL __stdcall SGdiDeleteObject(int a1);
	BOOL __cdecl  SGdiDestroy();
	BOOL __stdcall SGdiExtTextOut(int a1, int a2, int a3, int a4, unsigned int a8, signed int a6, signed int a7, const char* arg1C, unsigned int arg20);
	BOOL __stdcall SGdiImportFont(HGDIOBJ handle, int windowsfont);
	BOOL __stdcall SGdiLoadFont(char* Str, int a5, int a6, int argC, int a7, int a8);
	BOOL __stdcall SGdiRectangle(int a1, int a2, int a3, int a4, int a5, int a6);
	BOOL __stdcall SGdiSelectObject(int a1);
	BOOL __stdcall SGdiSetPitch(int pitch);
	BOOL __stdcall SGdiTextOut(int a1, int a2, int a3, unsigned int a8, const char* arg1C, unsigned int arg20);
	BOOL __stdcall SGdi392(int, int, int, int);
	BOOL __stdcall Ordinal393(int, int, int);
	
	BOOL  __stdcall SMemInit();
	void* __stdcall SMemAlloc(int amount, char* logfilename, int logline, int defaultValue);
	BOOL  __cdecl   SMemDestroy();
	BOOL  __stdcall SMemFree(void* location, char* logfilename, int logline, int defaultValue);
	int   __stdcall SMemGetSize(void* location, char* logfilename, int logline);
	void* __stdcall SMemReAlloc(void* location, int amount, char* logfilename, int logline, int defaultValue);
	
	BOOL   __stdcall SMsgDispatchMessage(HWND hWnd, DWORD messageID, WPARAM wParam, LPARAM lParam, int a5, int a6);
	WPARAM __stdcall SMsgDoMessageLoop(void* callback, int followWithStormDestroy);
	BOOL   __stdcall SMsgRegisterCommand(int a1, int a2, int a3);
	BOOL   __stdcall SMsgRegisterKeyDown(int a1, int a2, int a3);
	BOOL   __stdcall SMsgRegisterKeyUp(int a1, int a2, int a3);
	BOOL   __stdcall SMsgRegisterMessage(int a1, int a2, int a3);
	BOOL   __stdcall SMsgPopRegisterState(int type);
	BOOL   __stdcall SMsgPushRegisterState(int type);
	BOOL   __stdcall SMsg420(int a1, int a2, int a3);
	BOOL   __stdcall SRegLoadData(char* keyname, char* valuename, HKEY phkResult, LPBYTE lpData, int a5, DWORD* lpcbData);
	BOOL   __stdcall SRegLoadString(char* keyname, char* valuename, int a3, char* buffer, size_t buffersize);
	BOOL   __stdcall SRegLoadValue(char* keyname, char* valuename, int a3, int value);
	BOOL   __stdcall SRegSaveData(char* keyname, char* valuename, BYTE flags, BYTE* lpData, DWORD cbData);
	BOOL   __stdcall SRegSaveString(char* keyname, char* valuename, BYTE flags, char* string);
	BOOL   __stdcall SRegSaveValue(char* keyname, char* valuename, BYTE flags, DWORD result);
	BOOL   __stdcall SRegGetBaseKey(char flags, char* buffer, size_t bufferchars);
	BOOL   __stdcall SReg428(char* keyname, char* valuename, HKEY phkResult);
	BOOL   __stdcall SReg429(char* keyname, DWORD dwflags, DWORD dwIndex, char*, size_t);
	BOOL   __stdcall SReg430(char* keyname, int, DWORD cSubKeys);
	BOOL   __stdcall STransBlt(int a1, int a2, int a3, int a4, int a5);
	BOOL   __stdcall STransBltUsingMask(int a1, int a2, int a3, int a4, int a5);
	BOOL   __stdcall STransCreateI(int a1, int a2, int a3, signed int a4, int a5, int a6, int a7);
	BOOL   __stdcall STransDelete(int a1);
	BOOL   __stdcall STransDestroy();
	BOOL   __stdcall STransDuplicate(int handle, int source);
	BOOL   __stdcall STransIntersectDirtyArray(int handle, int dirtyarraymask, unsigned __int8 dirtyarray, int sourcemask);
	BOOL   __stdcall STransInvertMask(int handle, int sourcemask);
	BOOL   __stdcall STransLoadI(char* filename, int a5, int a6, int handle);
	BOOL   __stdcall STransSetDirtyArrayInfo(signed int depth, int depth2, int height, int width);
	BOOL   __stdcall STransUpdateDirtyArray(int a1, char a2, int a3, int a4, int a5, int a6);
	BOOL   __stdcall STrans442(int, int, int, char*, size_t);
	BOOL   __stdcall STransCombineMasks(int, int, int, int, int, int);
	BOOL   __stdcall STransCreateE(int, int, int, int, int, int, int);
	BOOL   __stdcall STrans446(int, int, int, int, int, int, int);
	BOOL   __stdcall STransLoadE(char* filename, int, int, int handle);
	
	BOOL  __stdcall SVidInit();
	BOOL  __cdecl   SVidDestroy();
	BOOL  __stdcall SVidGetSize(int video, int a2, int a3, int a4);
	BOOL  __stdcall SVidInitialize(int arg0);
	BOOL  __stdcall SVidPlayBegin(char* filename, int arg4, int a3, int a4, int a5, int a6, int a7);
	BOOL  __stdcall SVidPlayBeginFromMemory(void* destbuffer, int destsize, int arg4, int a3, int a4, int a6, int sourcebytes, int sourceptr);
	BOOL  __cdecl   SVidPlayContinue();
	BOOL  __stdcall SVidPlayContinueSingle(int video, int a2, int a3);
	BOOL  __stdcall SVidPlayEnd(int video);
	BOOL  __stdcall SVidSetVolume(int video, int a2, int a3, int type);
	BOOL  __stdcall SErrInit();
	int   __stdcall SErrDisplayError(DWORD dwMessageId, char* logfile, int logline, char a3, int a4, UINT uExitCode);
	int   __stdcall SErrGetErrorStr(DWORD dwMessageId, char* buffer, size_t bufferchars);
	DWORD __cdecl   SErrGetLastError();
	BOOL  __stdcall SErrRegisterMessageSource(__int16 a1, int a2, int a3);
	void  __stdcall SErrSetLastError(DWORD dwErrCode);
	int   __stdcall SErrReportNamedResourceLeak(char* resourceName, int);
	int   __stdcall SErrReportResourceLeak(char* resourceName);
	BOOL  __stdcall SErrSuppressErrors(BOOL suppressErrors);
	int   __stdcall SErrRegisterHandler(int);
	void  __stdcall SErr470(int);
	
	BOOL __stdcall SCmdGetBool(int a1);
	int  __stdcall SCmdGetNum(int a1);
	BOOL __stdcall SCmdGetString(int a1, char* dest, size_t size);
	BOOL __stdcall SCmdProcess(const char** string, int a2, int a3, int a4);
	BOOL __stdcall SCmdRegisterArgList(int, int);
	BOOL __stdcall SCmdRegisterArgument(int a1, int a2, char* str, int a4, int a5, int a6, int a7, int a8);
	int  __stdcall SCmd478(int);
	BOOL __stdcall SCmdProcessCommandLine(int, int);
	BOOL __stdcall SMemInit2();
	BOOL __stdcall SMemFindNextBlock(int, int, int, int);
	BOOL __stdcall SMemFindNextHeap(int prevheap, int details, int nextheap);
	int  __stdcall SMemGetHeapByCaller(int, int);
	int  __stdcall SMemGetHeapByPtr(int);
	int  __stdcall SMemHeapAlloc(int, int, int);
	int  __stdcall SMemHeapCreate(int, int, int, char, DWORD ExitCode);
	BOOL __stdcall SMemHeapDestroy(int);
	BOOL __stdcall SMemHeapFree(int a1, int a2, void* a3);
	int  __stdcall SMemHeapRealloc(int a1, int a2, void* a3, int a4);
	int  __stdcall SMemHeapSize(int a1, int a2, void* a3);
	int  __stdcall SMemCopy(void* dest, const void* source, size_t size);
	int  __stdcall SMemFill(void* location, size_t length, char fillWith);
	int  __stdcall SMemMove(void* dest, void* source, size_t size);
	int  __stdcall SMemZero(void* location, size_t length);
	int  __stdcall SMemCmp(void* location1, void* location2, size_t size);
	int  __stdcall SMem496(int, char);
	BOOL __stdcall SMemDumpState(int, int);
	
	BOOL  __stdcall SStrInit();
	int   __stdcall SStrCopy(char* dest, const char* source, size_t size);
	DWORD __stdcall SStrHash(const char* string, unsigned long flags, unsigned long Seed);
	int   __stdcall SStrNCat(char* base, char* _new, int max_length);
	void  __stdcall SStrTokenize(const char** string, char* (*string2), char* buffer, const char* whitespace, size_t size);
	char* __stdcall SStr505(const char* string, char c, int type);
	int   __stdcall SStrLen(const char* string);
	void* __stdcall SStrDup(int a1);
	int   __stdcall SStrCmp(const char* string1, const char* string2, size_t size);
	int   __stdcall SStrCmpI(const char* string1, const char* string2, size_t size);
	int   __stdcall SStrUpper(char* string);
	BOOL  __stdcall SMsgBreakHandlerChain(int a1);
	BOOL  __stdcall SMsgUnregisterCommand(int a1, int a2, int a3);
	BOOL  __stdcall SMsgUnregisterKeyDown(int a1, int a2, int a3);
	BOOL  __stdcall SMsgUnregisterKeyUp(int a1, int a2, int a3);
	BOOL  __stdcall SMsgUnregisterMessage(int a1, int a2, int a3);
	int   __stdcall SMsg516(int a1);
	BOOL  __stdcall SMsgSetDefaultWindow(int a1);
	HWND  __cdecl   SMsgGetDefaultWindow();
	BOOL  __stdcall SMsg519(int a1, int a2, int a3);
	
	int __stdcall Ordinal521(int a1);
	
	void __stdcall SRgn523(int handle, int a2, int a3, int a4);
	void __stdcall SRgn524(int handle, int a2);
	void __stdcall SRgn525(int handle);
	
	void   __stdcall SRgn527(int handle, int a2, int a3);
	void   __stdcall SRgn528i(int handle, int a2, int a3, int a4);
	void   __stdcall SRgn529i(int handle, int a2, int a3);
	void   __stdcall SRgn530i(int handle, int a2);
	BOOL   __stdcall SRgn531i(int handle, int a2, int a3);
	BOOL   __stdcall SRgn532i(int handle, int a2);
	void   __stdcall SRgn533i(int handle, int a2, int a3);
	void   __stdcall SRgn534(int handle, int a2, int a3, int a4);
	void   __stdcall SRgn535f(int handle, float a2, float a3, float a4);
	void   __stdcall SRgn536f(int handle, float a2, float a3);
	void   __stdcall SRgn537f(int handle, float a2);
	BOOL   __stdcall SRgn538f(int handle, float a2, float a3);
	BOOL   __stdcall SRgn539f(int handle, float a2);
	void   __stdcall SRgn540f(int handle, float a2, float a3);
	void   __stdcall SLogClose(DWORD NumberOfBytesWritten);
	HANDLE __stdcall SLogCreate(char* filename, int a2, int a3);
	void   __stdcall SLog543(int a1, int a2);
	void   __stdcall SLogDump(int a1, int a2, DWORD NumberOfBytesWritten);
	void   __stdcall SLogFlush(DWORD NumberOfBytesWritten);
	void   __cdecl   SLogFlushAll();
	void   __cdecl   SLogPend(int a1, char* a2, char a3);
	void   __cdecl   SLogWrite(HANDLE handle, char* format, ...);
	void   __stdcall SLog549(int a1, int a2);
	void   __stdcall SLog550(HANDLE handle, int a2);
	BOOL   __stdcall SCompCompress(void* a1, int a2, unsigned int a3, signed int amount, int a5, char a6, int a7);
	BOOL   __stdcall SCompDecompress(void* a1, int* a2, const void* a3, unsigned int a4);
	void   __cdecl   SLogVWrite(HANDLE handle, char* format, ...);
	
	void                         __cdecl   SErr561(char*, char);
	int                          __cdecl   SErrDisplayErrorFmt(DWORD dwMessageId, char* logfile, int logline, int unk, UINT uExitCode, char* format, ...);
	int                          __cdecl   SErrIsDisplayingError();
	int                          __stdcall SErrPrepareAppFatal(int a1, int a2);
	int                          __stdcall SErrSetLogTitleString(int a1);
	int                          __stdcall SErrDisplayAppFatal(int a1);
	LPTOP_LEVEL_EXCEPTION_FILTER __cdecl   SErrCatchUnhandledExceptions();
	
	char* __stdcall SStrChr(const char* string, char c);
	char* __stdcall SStrChrR(const char* string, char c);
	double       __stdcall SStrToDouble(const char* string);
	float        __stdcall SStrToFloat(const char* string);
	signed int   __stdcall SStrToInt(const char* string);
	unsigned int __stdcall SStrToUnsigned(const char* string);
	__int64      __stdcall SStrToInt64(const char* string);
	int          __cdecl   SStrVPrintf(char* dest, size_t size, const char* format, ...);
	int          __stdcall SStrLower(char* string);
	int          __stdcall Ordinal580(int a1, int a2, int a3, int a4);
	int          __cdecl   SStrPrintf(char* dest, size_t size, const char* format, ...);
	void         __stdcall Ordinal582(LPRECT lpRect);
	int          __stdcall Ordinal583(LPRECT lpRect);
	int          __stdcall SStrStrI(const char* string, const char* search);
	int          __stdcall SStrStr(const char* string, const char* search);
	int          __stdcall SNet588(char* a1, char* a2);
	
	BOOL __stdcall SBigInit();
	int  __stdcall SBigAdd(void* buffer, const void* buffer2, const void* buffer3);
	int  __stdcall SBigAnd(void* buffer, const void* buffer2, const void* buffer3);
	int  __stdcall SBigCompare(void* buffer, void* buffer2);
	int  __stdcall SBigCopy(void* buffer, void* buffer2);
	int  __stdcall SBigDec(void* buffer, const void* buffer2);
	int  __stdcall SBigDel(void* buffer);
	int  __stdcall SBigDiv(int a1, const void* buffer1, const void* buffer2);
	int  __stdcall SBigFindPrime(int a1, void* a2, unsigned int a3, const void* a4);
	int  __stdcall SBigFromBinary(void* buffer, const void* str, size_t size);
	int  __stdcall SBigFromStr(void* buffer, int a2);
	int  __stdcall SBigFromStream(void* buffer, int a2, int a3, int a4);
	int  __stdcall SBigFromUnsigned(void* buffer, unsigned int value);
	int  __stdcall SBigGcd(void* buffer, int a2, int a3);
	int  __stdcall SBigInc(void* buffer, int a2);
	int  __stdcall SBigInvMod(void* buffer, int a2, int a3);
	int  __stdcall SBigIsEven(void* buffer);
	int  __stdcall SBigIsOdd(void* buffer);
	int  __stdcall SBigIsOne(void* buffer);
	int  __stdcall SBigIsPrime(void* buffer);
	int  __stdcall SBigIsZero(void* buffer);
	int  __stdcall SBigMod(void* buffer, int a2, int a3);
	int  __stdcall SBigMul(void* buffer, int a2, int a3);
	int  __stdcall SBigMulMod(void* buffer, int a2, int a3, int a4);
	int  __stdcall SBigNew(void** buffer);
	int  __stdcall SBigNot(void* buffer, int a2);
	int  __stdcall SBigOr(void* buffer, int a2, int a3);
	int  __stdcall SBigPow(void* buffer, int a2, int a3);
	int  __stdcall SBigPowMod(void* buffer, int a2, int a3, int a4);
	int  __stdcall SBigRand(void* buffer, int a2, int a3);
	int  __stdcall SBigSet2Exp(void* buffer, int a2);
	int  __stdcall SBigSetOne(void* buffer);
	int  __stdcall SBigSetZero(void* buffer);
	int  __stdcall SBigShl(void* buffer, int a2, int a3);
	int  __stdcall SBigShr(void* buffer, int a2, int a3);
	int  __stdcall SBigSquare(void* buffer, int a2);
	int  __stdcall SBigSub(void* buffer, int a2, int a3);
	int  __stdcall SBigToBinaryArray(void* buffer, int a2, int a3);
	int  __stdcall SBigToBinaryBuffer(void* buffer, int a2, int a3, int a4);
	int  __stdcall SBigToBinaryPtr(void* buffer, int a2, int a3);
	int  __stdcall SBigToStrArray(void* buffer, int a2, int a3);
	int  __stdcall SBigToStrBuffer(void* buffer, char* dst, int count);
	int  __stdcall SBigToStrPtr(void* buffer, int a2);
	int  __stdcall SBigToStreamArray(void* buffer, int a2, int a3);
	int  __stdcall SBigToStreamBuffer(void* buffer, int a2, int a3, int a4);
	int  __stdcall SBigToStreamPtr(void* buffer, int a2, int a3);
	int  __stdcall SBigToUnsigned(void* buffer, int a2);
	int  __stdcall SBigXor(void* buffer, int a2, int a3);
	BOOL __stdcall SSignatureVerify(int, int, int, int);
	BOOL __stdcall SSignatureVerifyStream_Begin(int);
	BOOL __stdcall SSignatureVerifyStream_ProvideData(int);
	BOOL __stdcall SSignatureVerifyStream_Finish(int);
	BOOL __stdcall SSignatureGenerate(int, int, int, int, int, int);
	BOOL __stdcall SSignatureVerifyStream_GetSignatureLength();
	
	BOOL __stdcall SUniInit();
	int  __stdcall SUniConvertUTF16to8Len(int a1, int a2, int a3);
	int  __stdcall SUniConvertUTF16to8(int a1, int a2, int a3, int a4, int a5, int a6);
	int  __stdcall SUniConvertUTF8to16Len(int a1, int a2, int a3);
	int  __stdcall SUniConvertUTF8to16(int a1, int a2, int a3, int a4, int a5, int a6);
	int  __stdcall SUniS905(int a1, int a2);
	int  __stdcall SUniS906(int a1, int a2);
	int  __stdcall SUniFindAfterUTF8Chr(int a1, int a2);
	int  __stdcall SUniFindUTF8ChrStart(int a1, int a2);
	int  __stdcall SUniConvertUTF16To909(unsigned __int32 a1, char* a2, unsigned __int16* a3);
	int  __stdcall SUniConvertUTF16To910(unsigned __int32 a1, char* a2, unsigned __int16* a3);
	int  __stdcall SUniConvertUTF16To911(unsigned __int32 a1, char* a2, unsigned __int16* a3);
	int  __stdcall SUniConvert912(int a1, int a2, int a3);
	int  __stdcall SUniConvert913(int a1, int a2, int a3);
	int  __stdcall SUniConvert914(int a1, int a2, int a3);
	int  __stdcall SUniConvertUTF8ToWin(unsigned __int32 a1, char* a2, unsigned __int16* a3);

#ifdef __cplusplus
}
#endif

#endif