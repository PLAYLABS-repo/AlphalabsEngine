#ifndef D2D1STATE_H
#define D2D1STATE_H

#ifdef _WIN32

#include <windows.h>
#include <d2d1.h>
#include <FreeImage.h>

namespace Alphalabs
{
    extern ID2D1Factory* D2DFactory;
    extern ID2D1HwndRenderTarget* D2DRenderTarget;
    extern D2D1_RENDER_TARGET_PROPERTIES D2DRenderTargetProperties;
    extern bool D2D1IsInitialised;

    struct D2D1Texture
    {
        ID2D1Bitmap* Bitmap;
        FIBITMAP* Image;
        UINT Width;
        UINT Height;

        D2D1Texture();
    };
}

#endif

#endif
