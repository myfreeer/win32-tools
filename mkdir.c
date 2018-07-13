#include <windows.h>
#include <tchar.h>

// https://stackoverflow.com/a/16719260/6848772
DWORD mkdir(TCHAR *path) {
    TCHAR path2[MAX_PATH + 1] = {0};
    _tcscpy(path2, path);
    _tcscat(path2, _T("\\"));
    TCHAR folder[MAX_PATH + 1] = {0};
    TCHAR *end = _tcschr(path, _T('\\'));
    while (end != NULL) {
        _tcsncpy(folder, path, end - path + 1);
        if (!CreateDirectory(folder, NULL)) {
            DWORD err = GetLastError();
            if (err != ERROR_ALREADY_EXISTS) {
                return err;
            }
        }
        end = _tcschr(++end, L'\\');
    }
    return 0;
}

int _tmain(int argc, TCHAR **argv) {
    if (argc > 1)
        mkdir(argv[1]);
    return 0;
}
