#include "D2D1End.h"
#include "D2D1State.h"

#ifdef _WIN32

namespace Alphalabs
{
    bool D2D1End()
    {
        if (!D2DRenderTarget)
        {
            return false;
        }

        HRESULT Result = D2DRenderTarget->EndDraw();

        if (Result == D2DERR_RECREATE_TARGET)
        {
            D2DRenderTarget->Release();
            D2DRenderTarget = nullptr;
            return false;
        }

        return SUCCEEDED(Result);
    }
}

#endif
