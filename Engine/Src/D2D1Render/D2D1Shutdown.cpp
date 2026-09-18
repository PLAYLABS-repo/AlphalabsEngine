#include "D2D1Shutdown.h"
#include "D2D1State.h"

#ifdef _WIN32

namespace Alphalabs
{
    void D2D1Shutdown()
    {
        if (D2DRenderTarget)
        {
            D2DRenderTarget->Release();
            D2DRenderTarget = nullptr;
        }

        if (D2DFactory)
        {
            D2DFactory->Release();
            D2DFactory = nullptr;
        }

        D2D1IsInitialised = false;
    }
}

#endif
