#include "D2D1Begin.h"
#include "D2D1State.h"

#ifdef _WIN32

namespace Alphalabs
{
    void D2D1Begin(const D2D1_COLOR_F& Color)
    {
        if (!D2DRenderTarget)
        {
            return;
        }

        D2DRenderTarget->BeginDraw();
        D2DRenderTarget->Clear(Color);
    }
}

#endif
