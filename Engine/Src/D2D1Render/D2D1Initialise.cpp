#include "D2D1Initialise.h"
#include "D2D1State.h"
#include "D2D1RenderProperties.h"

#include <cstdio>

#ifdef _WIN32

namespace Alphalabs
{
    bool D2D1Initialise(HWND hWnd, UINT Width, UINT Height)
    {
        if (D2D1IsInitialised)
        {
            return true;
        }

        if (!hWnd)
        {
            std::printf("D2D1Initialise: HWND is null\n");
            return false;
        }

        HRESULT Result = D2D1CreateFactory(
            D2D1_FACTORY_TYPE_SINGLE_THREADED,
            __uuidof(ID2D1Factory),
            nullptr,
            reinterpret_cast<void**>(&D2DFactory)
        );

        if (FAILED(Result))
        {
            std::printf(
                "D2D1CreateFactory failed: 0x%08lX\n",
                static_cast<unsigned long>(Result)
            );

            D2DFactory = nullptr;
            return false;
        }

        std::printf("D2D1CreateFactory success\n");

        if (!D2D1RenderProperties(
            hWnd,
            Width,
            Height
        ))
        {
            std::printf("D2D1RenderProperties failed\n");

            if (D2DFactory)
            {
                D2DFactory->Release();
                D2DFactory = nullptr;
            }

            return false;
        }

        D2D1IsInitialised = true;

        std::printf("D2D1 initialization succeess\n");

        return true;
    }
}

#endif
