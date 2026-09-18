#include "D2D1Render.h"

#ifdef _WIN32

namespace Alphalabs
{
    bool D2D1Render(
        const D2D1Texture& Texture,
        float X,
        float Y,
        float Width,
        float Height,
        float Opacity
    )
    {
        if (!D2DRenderTarget || !Texture.Bitmap)
        {
            return false;
        }

        if (Opacity < 0.0f)
        {
            Opacity = 0.0f;
        }

        if (Opacity > 1.0f)
        {
            Opacity = 1.0f;
        }

        D2DRenderTarget->DrawBitmap(
            Texture.Bitmap,
            D2D1::RectF(
                X,
                Y,
                X + Width,
                Y + Height
            ),
            Opacity,
            D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
            D2D1::RectF(
                0.0f,
                0.0f,
                static_cast<float>(Texture.Width),
                static_cast<float>(Texture.Height)
            )
        );

        return true;
    }
}

#endif
