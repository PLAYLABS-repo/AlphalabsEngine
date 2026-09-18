#include <windows.h>

int main()
{
    HRESULT ComResult = CoInitializeEx(
        nullptr,
        COINIT_APARTMENTTHREADED
    );

    if (FAILED(ComResult))
    {
        printf(
            "COM initialization failed: 0x%08lX\n",
            static_cast<unsigned long>(ComResult)
        );

        return 1;
    }

    Window GameWindow;

    if (!GameWindow.Init())
    {
        CoUninitialize();
        return 1;
    }

    if (!D2D1Initialise(
        GameWindow.hWnd,
        GameWindow.Width,
        GameWindow.Height
    ))
    {
        printf("D2D1 initialization failed\n");

        CoUninitialize();
        return 1;
    }

    // Render loop...

    D2D1Shutdown();

    CoUninitialize();

    return 0;
}
