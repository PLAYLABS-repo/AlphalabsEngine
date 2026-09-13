/*********************

GameShell.h
Created by Josh Billena

*********************/
#ifndef GAMESHELL_H
#define GAMESHELL_H

#include <windows.h>
#include <EGL/egl.h>
#include <GLES2/gl2.h>
namespace Alphalabs{

class Window{

public:
    Window();
    const wchar_t* WindowName = L"Window Name";
    int Width = 1280;
    int Height = 720;
    bool Init();
    HWND hWnd = NULL;
    HDC hDc = NULL;
    HINSTANCE hInstance = GetModuleHandleW(NULL);
    EGLDisplay display = EGL_NO_DISPLAY;
    EGLSurface surface = EGL_NO_SURFACE;
    EGLContext context = EGL_NO_CONTEXT;
    EGLConfig config = NULL;
    //static bool keys[256];
    bool running = false;
    void PollEvents();



private:
    static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
};
}
#endif // GAMESHELL_H
