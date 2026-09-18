#include "D2D1Initialise.h"
#include "D2D1State.h"
#include "D2D1RenderProperties.h"

#ifdef _WIN32

namespace Alphalabs
{
    bool D2D1Initialise(HWND hWnd, UINT Width, UINT Height)
    {
        if (D2D1IsInitialised)
        {
            return true;
        }

        HRESULT Result = D2D1CreateFactory(
            D2D1_FACTORY_TYPE_SINGLE_THREADED,
            &D2DFactory
        );

        if (FAILED(Result))
        {
            D2DFactory = nullptr;
            return false;
        }

        if (!D2D1RenderProperties(hWnd, Width, Height))
        {
            D2DFactory->Release();
            D2DFactory = nullptr;
            return false;
        }

        D2D1IsInitialised = true;
        return true;
    }
}

#endif
