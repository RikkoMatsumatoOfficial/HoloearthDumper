// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <filesystem>
namespace f = std::filesystem;

DWORD WINAPI ThreadMain() {
    HWND hwnd_main;
    hwnd_main = FindWindowA(0, "Holoearth");
    if (!hwnd_main) {
        MessageBoxA(0, "Not Founded Holoearth.exe Window", "HoloearthDumper", MB_OK | MB_ICONERROR);
        exit(3365);
    }
    else {
        UnityResolve::Init(GetModuleHandleA("GameAssembly.dll"), UnityResolve::Mode::Il2Cpp);
        UnityResolve::DumpToFile("DumpedHoloearthFunctionsAndOffsets");
        f::path pm("DumpedHoloearthFunctionsAndOffsets.h");
        if (pm.empty()) {
            MessageBoxA(0, "Not Founded Dumped Functions And Offsets...", "HoloearthDumper", MB_OK | MB_ICONERROR);
            exit(3321);
        }
        else {
            MessageBoxA(0, "Dumped!!!", "HoloearthDumper", MB_OK | MB_ICONWARNING);
            exit(1223);
        }

    }
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ThreadMain, 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

