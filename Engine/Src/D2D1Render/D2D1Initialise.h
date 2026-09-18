#ifndef D2D1INITIALISE_H
#define D2D1INITIALISE_H

#ifdef _WIN32

#include <windows.h>

namespace Alphalabs
{
    bool D2D1Initialise(HWND hWnd, UINT Width, UINT Height);
}

#endif

#endif
