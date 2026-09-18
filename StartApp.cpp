
#include <cstdio>
#include <windows.h>

#include "Clients/Shells/Win32/GameShell.h"
#include "Engine/Src/D2D1Render/D2D1RenderAll.h"

using namespace Alphalabs;

int main()
{
    HRESULT ComResult = CoInitializeEx(
        nullptr,
        COINIT_APARTMENTTHREADED
    );


    Window GameWindow;

    GameWindow.Init();

    D2D1HardwareSettings(
        D2D1_RENDER_TARGET_TYPE_HARDWARE,
        D2D1_RENDER_TARGET_USAGE_NONE
    );

    D2D1Initialise(
        GameWindow.hWnd,
        GameWindow.Width,
        GameWindow.Height
    );


    ID2D1SolidColorBrush* SquareBrush = nullptr;

    D2D1_COLOR_F Red =
    {
        1.0f,
        0.0f,
        0.0f,
        1.0f
    };

    HRESULT BrushResult =
        D2DRenderTarget->CreateSolidColorBrush(
            &Red,
            nullptr,
            &SquareBrush
        );



    while (GameWindow.running)
    {
        GameWindow.PollEvents();

        D2D1Begin(
            D2D1::ColorF(
                D2D1::ColorF::Black
            )
        );

        D2DRenderTarget->FillRectangle(
            D2D1::RectF(
                100.0f,
                100.0f,
                300.0f,
                300.0f
            ),
            SquareBrush
        );

        D2D1End();
    }

    if (SquareBrush)
    {
        SquareBrush->Release();
        SquareBrush = nullptr;
    }

    D2D1Shutdown();

    CoUninitialize();

    return 0;
}

