#include<Windows.h>
#include "Window.h"
#include <iostream>

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevinstance, LPSTR lpszCmdline, int nCmdShow)
{
    HANDLE hMutex = OpenMutex(MUTEX_ALL_ACCESS, 0, "GnfGameEngineDX11");
    if (!hMutex)
        hMutex = CreateMutex(0, 0, "GnfGameEngineDX11");
    else {
        MessageBox(0, ("Program is already running"), ("Title"), 0);
        return 0;
    }

    UNREFERENCED_PARAMETER(hPrevinstance);
    UNREFERENCED_PARAMETER(lpszCmdline);

    Window wnd(800, 170, "Selam");
    MSG msg;
    BOOL gResult;
    while ((gResult = GetMessage(&msg, nullptr, 0, 0) > 0)) 
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    if (gResult == -1)
        return -1;
    return msg.wParam;
}