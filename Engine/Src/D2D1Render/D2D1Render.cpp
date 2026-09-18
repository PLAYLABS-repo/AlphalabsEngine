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

        if (Width <= 0.0f || Height <= 0.0f)
        {
            return false;
        }

        if (Opacity < 0.0f)
        {
            Opacity = 0.0f;
        }
        else if (Opacity > 1.0f)
        {
            Opacity = 1.0f;
        }

        // Prefer the real bitmap pixel size. This also makes rendering work
        // if a caller created Texture.Bitmap manually and forgot to populate
        // Texture.Width / Texture.Height.
        const D2D1_SIZE_U PixelSize = Texture.Bitmap->GetPixelSize();

        if (PixelSize.width == 0 || PixelSize.height == 0)
        {
            return false;
        }

        const D2D1_RECT_F Destination = D2D1::RectF(
            X,
            Y,
            X + Width,
            Y + Height
        );

        const D2D1_RECT_F Source = D2D1::RectF(
            0.0f,
            0.0f,
            static_cast<float>(PixelSize.width),
            static_cast<float>(PixelSize.height)
        );

        D2DRenderTarget->DrawBitmap(
            Texture.Bitmap,
            Destination,
            Opacity,
            D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
            Source
        );

        return true;
    }
}

#endif
