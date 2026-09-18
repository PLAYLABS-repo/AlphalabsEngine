#include "D2D1ColorEffect.h"
#include "D2D1Texture.h"

#ifdef _WIN32

namespace Alphalabs
{
    bool D2D1ColorEffect(
        D2D1Texture& Texture,
        float Red,
        float Green,
        float Blue,
        float Alpha
    )
    {
        if (!D2DRenderTarget || !Texture.Image || Texture.Width == 0 || Texture.Height == 0)
        {
            return false;
        }

        if (Red < 0.0f) Red = 0.0f;
        if (Red > 1.0f) Red = 1.0f;
        if (Green < 0.0f) Green = 0.0f;
        if (Green > 1.0f) Green = 1.0f;
        if (Blue < 0.0f) Blue = 0.0f;
        if (Blue > 1.0f) Blue = 1.0f;
        if (Alpha < 0.0f) Alpha = 0.0f;
        if (Alpha > 1.0f) Alpha = 1.0f;

        BYTE* Bits = FreeImage_GetBits(Texture.Image);

        if (!Bits)
        {
            return false;
        }

        const size_t PixelCount =
            static_cast<size_t>(Texture.Width) *
            static_cast<size_t>(Texture.Height);

        for (size_t Index = 0; Index < PixelCount; ++Index)
        {
            BYTE* Pixel = Bits + (Index * 4);

            Pixel[0] = static_cast<BYTE>(Pixel[0] * Blue);
            Pixel[1] = static_cast<BYTE>(Pixel[1] * Green);
            Pixel[2] = static_cast<BYTE>(Pixel[2] * Red);
            Pixel[3] = static_cast<BYTE>(Pixel[3] * Alpha);
        }

        if (Texture.Bitmap)
        {
            Texture.Bitmap->Release();
            Texture.Bitmap = nullptr;
        }

        D2D1_BITMAP_PROPERTIES BitmapProperties =
            D2D1::BitmapProperties(
                D2D1::PixelFormat(
                    DXGI_FORMAT_B8G8R8A8_UNORM,
                    D2D1_ALPHA_MODE_STRAIGHT
                )
            );

        HRESULT Result = D2DRenderTarget->CreateBitmap(
            D2D1::SizeU(Texture.Width, Texture.Height),
            Bits,
            Texture.Width * 4,
            BitmapProperties,
            &Texture.Bitmap
        );

        return SUCCEEDED(Result);
    }
}

#endif
