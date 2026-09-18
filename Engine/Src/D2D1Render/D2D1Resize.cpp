#include "D2D1Resize.h"
#include "D2D1State.h"

#ifdef _WIN32

namespace Alphalabs
{
    bool D2D1Resize(UINT Width, UINT Height)
    {
        if (!D2DRenderTarget)
        {
            return false;
        }

        HRESULT Result = D2DRenderTarget->Resize(
            D2D1::SizeU(Width, Height)
        );

        return SUCCEEDED(Result);
    }
}

#endif
