
#include <cstdio>
#include <windows.h>
#include <chrono>
#include <mmsystem.h>
#include <cmath>

#include "Clients/Shells/Win32/GameShell.h"
#include "Engine/Src/D2D1Render/D2D1RenderAll.h"

using namespace Alphalabs;

int main()
{



    auto PreviousTime =
        std::chrono::steady_clock::now();
    float SquareX = 100.0f;
    float SquareY = 100.0f;
    float Time = 0.0f;

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
    mciSendStringA("open UnitTest/Sound/LoadingBG2.mp3 type MPEGVideo alias myAudio", NULL, NULL, NULL);
    mciSendStringA("play myAudio repeat",NULL, NULL, NULL );



    while (GameWindow.running)
    {
        GameWindow.PollEvents();
        GameWindow.WindowName = L"testwindow";

        auto CurrentTime =
        std::chrono::steady_clock::now();

        std::chrono::duration<float> Delta =
        CurrentTime - PreviousTime;
        PreviousTime = CurrentTime;
        float DeltaTime = Delta.count();
        Time += DeltaTime;
        SquareX += std::sin(4.0f * Time + 100.0f);
        SquareY += std::cos(4.0f * Time + 100.0f);


        D2D1Begin(
            D2D1::ColorF(
                D2D1::ColorF::Black
            )
        );
        D2D1Transform(
            SquareX,
            SquareY,
            0.0f,
            1.0f,
            1.0f,
            0.0f,
            0.0f
        );

        D2DRenderTarget->FillRectangle(
            D2D1::RectF(
                120.0f,
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

