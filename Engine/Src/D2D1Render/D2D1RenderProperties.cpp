#include "D2D1RenderProperties.h"
#include "D2D1State.h"

#ifdef _WIN32

namespace Alphalabs
{
    bool D2D1RenderProperties(HWND hWnd, UINT Width, UINT Height)
    {
        if (!D2DFactory || !hWnd)
        {
            return false;
        }

        if (D2DRenderTarget)
        {
            D2DRenderTarget->Release();
            D2DRenderTarget = nullptr;
        }

        D2D1_HWND_RENDER_TARGET_PROPERTIES HwndProperties =
            D2D1::HwndRenderTargetProperties(
                hWnd,
                D2D1::SizeU(Width, Height)
            );

        HRESULT Result = D2DFactory->CreateHwndRenderTarget(
            D2DRenderTargetProperties,
            HwndProperties,
            &D2DRenderTarget
        );

        return SUCCEEDED(Result);
    }
}

#endif
