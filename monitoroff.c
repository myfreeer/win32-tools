#include <windows.h>
#define MONITOR_OFF 2
#define MONITOR_ON -1
#define MONITOR_STANBY 1

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
  SendMessage(HWND_TOPMOST, WM_SYSCOMMAND, SC_MONITORPOWER, MONITOR_OFF);
  return 0;
}
