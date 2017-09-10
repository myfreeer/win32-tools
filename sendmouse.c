#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

UINT MouseClick(unsigned int x, unsigned int y) {
  SetCursorPos(x, y);
  INPUT input[2];
  input[0].type = input[1].type = INPUT_MOUSE;
  input[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
  input[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
  return SendInput(2, input, sizeof(INPUT));
}

//main entry
int main(int argc, char ** argv) {
  POINT point;
  LONG x, y;

  //get self path
  char selfName[MAX_PATH];
  GetModuleFileName(NULL, selfName, MAX_PATH);

  //get file name from path
  const char * ptr = strrchr(selfName, '\\');

  if (ptr != NULL)
    strcpy(selfName, ptr + 1);
  if (argc > 2) {
    x = atoi(argv[1]);
    y = atoi(argv[2]);
    if (x && y)
      MouseClick(x, y);
  }
  if (GetCursorPos( & point)) {
    x = point.x;
    y = point.y;
  }
  if (x && y) {
    printf("Usage: %s x y\r\n  x = %ld\r\n  y = %ld\r\n", selfName, x, y);
  }
  return 0;
}