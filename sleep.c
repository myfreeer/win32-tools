#include <windows.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 2) return 1;
  char *ptr;
  unsigned long time = strtoul(argv[1], &ptr, 10);
  if (ptr[0] != argv[1][0]) {
  	  Sleep(time);
  	  return 0;
  }
  return -1;
}