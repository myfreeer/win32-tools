#define UNICODE
#define _UNICODE
#include <windows.h>
//main entry
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd) {
  const int cmdLineLength = lstrlenW(lpCmdLine);
  if (cmdLineLength == 0) {
    return 1;
  }
  for (int i = 0; i < cmdLineLength; i++) {
    SendMessageW(GetForegroundWindow(), WM_CHAR, lpCmdLine[i], 0);
  }
  return 0;
}