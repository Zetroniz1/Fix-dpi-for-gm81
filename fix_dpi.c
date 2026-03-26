#include <windows.h>

__attribute__((dllexport)) double fix_dpi_scaling() {
    HMODULE hUser32 = GetModuleHandle("user32.dll");
    if (hUser32) {
        typedef BOOL (WINAPI *PSET_DPI)(void);
        PSET_DPI pSetProcessDPIAware = (PSET_DPI)GetProcAddress(hUser32, "SetProcessDPIAware");
        if (pSetProcessDPIAware) return pSetProcessDPIAware() ? 1.0 : 0.0;
    }
    return -1.0;
}

__attribute__((dllexport)) double get_screen_size(double mode) {
    if (mode == 0) return (double)GetSystemMetrics(SM_CXSCREEN);
    if (mode == 1) return (double)GetSystemMetrics(SM_CYSCREEN);
    return 0;
}