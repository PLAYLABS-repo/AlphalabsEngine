#include "D2D1State.h"

#ifdef _WIN32

namespace Alphalabs
{
    ID2D1Factory* D2DFactory = nullptr;
    ID2D1HwndRenderTarget* D2DRenderTarget = nullptr;
    D2D1_RENDER_TARGET_PROPERTIES D2DRenderTargetProperties = D2D1::RenderTargetProperties();
    bool D2D1IsInitialised = false;

    D2D1Texture::D2D1Texture()
        : Bitmap(nullptr), Image(nullptr), Width(0), Height(0)
    {
    }
}

#endif
