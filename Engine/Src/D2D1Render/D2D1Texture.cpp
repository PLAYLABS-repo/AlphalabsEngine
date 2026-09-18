#include "D2D1Texture.h"

#ifdef _WIN32

namespace Alphalabs
{
    bool D2D1CreateTexture(const char* Path, D2D1Texture& Texture)
    {
        if (!D2DRenderTarget || !Path)
        {
            return false;
        }

        D2D1ReleaseTexture(Texture);

        FREE_IMAGE_FORMAT Format = FreeImage_GetFileType(Path, 0);

        if (Format == FIF_UNKNOWN)
        {
            Format = FreeImage_GetFIFFromFilename(Path);
        }

        if (Format == FIF_UNKNOWN)
        {
            return false;
        }

        FIBITMAP* LoadedImage = FreeImage_Load(Format, Path);

        if (!LoadedImage)
        {
            return false;
        }

        FIBITMAP* Image32 = FreeImage_ConvertTo32Bits(LoadedImage);
        FreeImage_Unload(LoadedImage);

        if (!Image32)
        {
            return false;
        }

        UINT Width = FreeImage_GetWidth(Image32);
        UINT Height = FreeImage_GetHeight(Image32);
        BYTE* Bits = FreeImage_GetBits(Image32);

        if (!Bits || Width == 0 || Height == 0)
        {
            FreeImage_Unload(Image32);
            return false;
        }

        D2D1_BITMAP_PROPERTIES BitmapProperties =
            D2D1::BitmapProperties(
                D2D1::PixelFormat(
                    DXGI_FORMAT_B8G8R8A8_UNORM,
                    D2D1_ALPHA_MODE_STRAIGHT
                )
            );

        ID2D1Bitmap* Bitmap = nullptr;

        HRESULT Result = D2DRenderTarget->CreateBitmap(
            D2D1::SizeU(Width, Height),
            Bits,
            Width * 4,
            BitmapProperties,
            &Bitmap
        );

        if (FAILED(Result))
        {
            FreeImage_Unload(Image32);
            return false;
        }

        Texture.Bitmap = Bitmap;
        Texture.Image = Image32;
        Texture.Width = Width;
        Texture.Height = Height;

        return true;
    }

    void D2D1ReleaseTexture(D2D1Texture& Texture)
    {
        if (Texture.Bitmap)
        {
            Texture.Bitmap->Release();
            Texture.Bitmap = nullptr;
        }

        if (Texture.Image)
        {
            FreeImage_Unload(Texture.Image);
            Texture.Image = nullptr;
        }

        Texture.Width = 0;
        Texture.Height = 0;
    }
}

#endif
