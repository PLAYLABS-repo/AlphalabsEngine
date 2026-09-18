#include "D2D1Texture.h"

#ifdef _WIN32

namespace Alphalabs
{
    bool D2D1CreateTexture(const char* Path, D2D1Texture& Texture)
    {
        if (!D2DRenderTarget || !Path || !*Path)
        {
            return false;
        }

        D2D1ReleaseTexture(Texture);

        FREE_IMAGE_FORMAT Format = FreeImage_GetFileType(Path, 0);

        if (Format == FIF_UNKNOWN)
        {
            Format = FreeImage_GetFIFFromFilename(Path);
        }

        if (Format == FIF_UNKNOWN || !FreeImage_FIFSupportsReading(Format))
        {
            return false;
        }

        FIBITMAP* LoadedImage = FreeImage_Load(Format, Path, 0);

        if (!LoadedImage)
        {
            return false;
        }

        FIBITMAP* Image32 = FreeImage_ConvertTo32Bits(LoadedImage);
        FreeImage_Unload(LoadedImage);
        LoadedImage = nullptr;

        if (!Image32)
        {
            return false;
        }

        const UINT Width = FreeImage_GetWidth(Image32);
        const UINT Height = FreeImage_GetHeight(Image32);

        if (Width == 0 || Height == 0)
        {
            FreeImage_Unload(Image32);
            return false;
        }

        // FreeImage stores normal bitmaps bottom-up. Direct2D expects the
        // first source row to be the top row of the image.
        FreeImage_FlipVertical(Image32);

        // Direct2D's BGRA bitmap format is normally used with premultiplied
        // alpha. Convert FreeImage's straight-alpha pixels before upload.
        FreeImage_PreMultiplyWithAlpha(Image32);

        BYTE* Bits = FreeImage_GetBits(Image32);
        const UINT Pitch = FreeImage_GetPitch(Image32);

        if (!Bits || Pitch == 0)
        {
            FreeImage_Unload(Image32);
            return false;
        }

        const D2D1_BITMAP_PROPERTIES BitmapProperties =
            D2D1::BitmapProperties(
                D2D1::PixelFormat(
                    DXGI_FORMAT_B8G8R8A8_UNORM,
                    D2D1_ALPHA_MODE_PREMULTIPLIED
                ),
                96.0f,
                96.0f
            );

        ID2D1Bitmap* Bitmap = nullptr;

        const HRESULT Result = D2DRenderTarget->CreateBitmap(
            D2D1::SizeU(Width, Height),
            Bits,
            Pitch,
            BitmapProperties,
            &Bitmap
        );

        // CreateBitmap copies the pixel data, so FreeImage no longer needs
        // to remain alive after this point.
        FreeImage_Unload(Image32);
        Image32 = nullptr;

        if (FAILED(Result) || !Bitmap)
        {
            return false;
        }

        Texture.Bitmap = Bitmap;
        Texture.Image = nullptr;
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
