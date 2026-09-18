/*********************

GameShell.cpp
Created by Josh Billena

*********************/
#include "GameShell.h"
#include <string>
namespace Alphalabs{

Window::Window(){
}
// GameShell.cpp
//bool Window::keys[256] = {};
LRESULT CALLBACK Window::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam){
   switch(msg){
    case WM_DESTROY:
       PostQuitMessage(0);
   /*    case WM_KEYDOWN:
    if (wParam < 256)
        Window::keys[wParam] = true;
    return 0;

case WM_KEYUP:
    if (wParam < 256)
        Window::keys[wParam] = false;
   */
       case WM_SIZE:
    {
    int width = LOWORD(lParam);
    int height = HIWORD(lParam);

    if (height == 0)
        height = 1;



    return 0;
}
       return 0;
   }

   return DefWindowProcW(hWnd, msg, wParam, lParam);

}
bool Window::Init(){

   WNDCLASSW wc = { };
   const wchar_t WndClassName[] = L"WndCLass";

   wc.lpfnWndProc = WndProc;
   wc.hInstance = hInstance;
   wc.lpszClassName = WndClassName;
   RegisterClassW(&wc);
    AllocConsole();

    // Get the console window.
    HWND ConsoleWindow = GetConsoleWindow();

    // Show the console.
    if (ConsoleWindow != NULL)
    {
        ShowWindow(ConsoleWindow, SW_SHOW);
    }

   HWND hWnd = CreateWindowExW(0,
                               WndClassName,
                               WindowName,
                               WS_OVERLAPPEDWINDOW,
                               CW_USEDEFAULT,
                               CW_USEDEFAULT,
                               Width,
                               Height,
                               NULL,
                               NULL,
                               hInstance,
                               this );
   //Why did windows.h use ANSI as normal functions and Unicode as W???? Fuck window32

   ShowWindow(hWnd, SW_SHOW);
   UpdateWindow(hWnd);
   hDc = GetDC(hWnd);
   display = eglGetDisplay((EGLNativeDisplayType)hDc);
   eglInitialize(display, NULL, NULL);
   //Now i have to do a plethera of functions just for a context?
   //Really?
   eglBindAPI(EGL_OPENGL_ES_API);
   EGLint configAttribs[]{
       EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
       EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,

       EGL_RED_SIZE, 8,
       EGL_GREEN_SIZE, 8,
       EGL_BLUE_SIZE,  8,
       EGL_ALPHA_SIZE, 8,

       EGL_DEPTH_SIZE, 24,

       EGL_NONE
   };
   EGLint numConfigs = 0;

   eglChooseConfig(
        display,
        configAttribs,
        &config,
        1,
        &numConfigs);
    surface = eglCreateWindowSurface(
        display,
        config,
        (EGLNativeWindowType)hWnd,
        NULL
    );
      EGLint contextAttribs[] =
    {
        EGL_CONTEXT_CLIENT_VERSION, 2,
        EGL_NONE
    };

    context = eglCreateContext(
        display,
        config,
        EGL_NO_CONTEXT,
        contextAttribs
    );
    eglMakeCurrent(
        display,
        surface,
        surface,
        context);
    glViewport(0, 0, Width, Height);
   running = true;
   return true;
}
void Window::PollEvents(){
   MSG msg = {};
   while (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                running = false;
                break;
            }

            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }

}



}
