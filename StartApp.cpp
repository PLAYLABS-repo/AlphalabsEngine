
#include <cstdio>
#include <windows.h>
#include <chrono>
#include <mmsystem.h>
#include <cmath>

#include <FreeImage.h>

#include "Clients/Shells/Win32/GameShell.h"
#include "Engine/Src/D2D1Render/D2D1RenderAll.h"

using namespace Alphalabs;

int main()
{
    printf("Program started.\n");

    /*
        --------------------------------------------------
        COM
        --------------------------------------------------
    */

    HRESULT ComResult =
        CoInitializeEx(
            nullptr,
            COINIT_APARTMENTTHREADED
        );

    if (FAILED(ComResult))
    {
        printf(
            "ERROR: CoInitializeEx failed: 0x%08lX\n",
            static_cast<unsigned long>(ComResult)
        );

        return 1;
    }

    printf("COM initialized.\n");

    /*
        --------------------------------------------------
        FreeImage
        --------------------------------------------------
    */

    FreeImage_Initialise();

    printf("FreeImage initialized.\n");

    /*
        --------------------------------------------------
        Window
        --------------------------------------------------
    */

    Window GameWindow;

    GameWindow.Init();

    printf("Window initialized.\n");

    /*
        --------------------------------------------------
        Direct2D
        --------------------------------------------------
    */

    D2D1HardwareSettings(
        D2D1_RENDER_TARGET_TYPE_HARDWARE,
        D2D1_RENDER_TARGET_USAGE_NONE
    );

    if (!D2D1Initialise(
            GameWindow.hWnd,
            GameWindow.Width,
            GameWindow.Height))
    {
        printf("ERROR: D2D1Initialise failed.\n");

        FreeImage_DeInitialise();
        CoUninitialize();

        return 1;
    }

    printf("Direct2D initialized.\n");

    /*
        --------------------------------------------------
        Texture
        --------------------------------------------------
    */

    const char* ImagePath =
        "UnitTest/Image/RGB1.png";

    printf(
        "Loading texture: %s\n",
        ImagePath
    );

    D2D1Texture Texture;

    if (!D2D1CreateTexture(
            ImagePath,
            Texture))
    {
        printf(
            "ERROR: D2D1CreateTexture failed.\n"
        );

        D2D1Shutdown();
        FreeImage_DeInitialise();
        CoUninitialize();

        return 1;
    }

    printf(
        "Texture loaded successfully: %ux%u\n",
        Texture.Width,
        Texture.Height
    );

    /*
        --------------------------------------------------
        Music
        --------------------------------------------------
    */

    MCIERROR MusicResult =
        mciSendStringA(
            "open UnitTest/Sound/LoadingBG2.mp3 "
            "type MPEGVideo alias myAudio",
            nullptr,
            0,
            nullptr
        );

    if (MusicResult != 0)
    {
        printf(
            "WARNING: Music failed to open: %u\n",
            MusicResult
        );
    }
    else
    {
        MCIERROR PlayResult =
            mciSendStringA(
                "play myAudio repeat",
                nullptr,
                0,
                nullptr
            );

        if (PlayResult != 0)
        {
            printf(
                "WARNING: Music failed to play: %u\n",
                PlayResult
            );
        }
    }

    /*
        --------------------------------------------------
        Animation
        --------------------------------------------------
    */

    auto PreviousTime =
        std::chrono::steady_clock::now();

    float SquareX = 100.0f;
    float SquareY = 100.0f;
    float Time = 0.0f;

    /*
        --------------------------------------------------
        Main loop
        --------------------------------------------------
    */

    while (GameWindow.running)
    {
        GameWindow.PollEvents();

        auto CurrentTime =
            std::chrono::steady_clock::now();

        std::chrono::duration<float> Delta =
            CurrentTime - PreviousTime;

        PreviousTime = CurrentTime;

        float DeltaTime =
            Delta.count();

        if (DeltaTime > 0.1f)
        {
            DeltaTime = 0.1f;
        }

        Time += DeltaTime;

        SquareX +=
            std::sin(
                4.0f * Time + 100.0f
            ) *
            DeltaTime *
            100.0f;

        SquareY +=
            std::cos(
                4.0f * Time + 100.0f
            ) *
            DeltaTime *
            100.0f;

        /*
            --------------------------------------------------
            Begin frame
            --------------------------------------------------
        */

        D2D1Begin(
            D2D1::ColorF(
                D2D1::ColorF::Black
            )
        );

        /*
            Reset transform so the texture is drawn
            directly in window coordinates.
        */



        /*
            --------------------------------------------------
            Render texture
            --------------------------------------------------
        */

        D2D1Render(
            Texture,
            SquareX,
            SquareY,
            200.0f,
            200.0f
        );

        /*
            --------------------------------------------------
            End frame
            --------------------------------------------------
        */

        D2D1End();
    }

    /*
        --------------------------------------------------
        Music cleanup
        --------------------------------------------------
    */

    mciSendStringA(
        "stop myAudio",
        nullptr,
        0,
        nullptr
    );

    mciSendStringA(
        "close myAudio",
        nullptr,
        0,
        nullptr
    );

    /*
        --------------------------------------------------
        Texture cleanup
        --------------------------------------------------
    */

    D2D1ReleaseTexture(Texture);

    /*
        --------------------------------------------------
        Direct2D cleanup
        --------------------------------------------------
    */

    D2D1Shutdown();

    /*
        --------------------------------------------------
        FreeImage cleanup
        --------------------------------------------------
    */

    FreeImage_DeInitialise();

    /*
        --------------------------------------------------
        COM cleanup
        --------------------------------------------------
    */

    CoUninitialize();

    printf("Program exited normally.\n");

    return 0;
}

