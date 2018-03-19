#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    HMODULE PowrProf = LoadLibrary("PowrProf.dll");
    if (!HMODULE) {
        return 1;
    }
    typedef BOOL (CALLBACK *LPSetSuspendState)(BOOL,BOOL,BOOL);
    LPSetSuspendState SetSuspendState = (LPSetSuspendState)GetProcAddress(PowrProf, "SetSuspendState");
    if (!SetSuspendState) {
        return 1;
    }
    (*SetSuspendState)(FALSE, FALSE, FALSE);
    FreeLibrary(PowrProf);
    return 0;
}
