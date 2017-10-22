/** Write command line arguments to clipboard **/
#include "windows.h"
#include "string.h"

int wmain( int argc, wchar_t *argv[], wchar_t *envp[] )  
{
    LPWSTR cmdLine = GetCommandLineW();
    const DWORD argv0Len = wcslen(argv[0]),
        cmdLineLen = wcslen(cmdLine);
    if (argv0Len + 2 >= cmdLineLen) {
        return 1;
    }
    LPWSTR strBuffer = cmdLine + argv0Len + 2;

    DWORD len = wcslen(strBuffer);
    HGLOBAL hdst;
    LPWSTR dst;

    // Allocate string for cwd
    hdst = GlobalAlloc(GMEM_MOVEABLE | GMEM_DDESHARE, (len + 1) * sizeof(WCHAR));
    dst = (LPWSTR)GlobalLock(hdst);
    memcpy(dst, strBuffer, len * sizeof(WCHAR));
    dst[len] = 0;
    GlobalUnlock(hdst);

    // Set clipboard data
    if (!OpenClipboard(NULL)) return GetLastError();
    EmptyClipboard();
    if (!SetClipboardData(CF_UNICODETEXT, hdst)) return GetLastError();
    CloseClipboard();

    return 0;
}