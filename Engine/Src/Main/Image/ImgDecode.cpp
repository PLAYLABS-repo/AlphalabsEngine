/*********************

ImgDecode.cpp
Created by Josh Billena

*********************/

#ifndef GL_BGRA_EXT
#define GL_BGRA_EXT 0x80E1
#endif
#include "ImgDecode.h"

namespace Alphalabs{

    bool ImgDecode::Decode(std::string Path, ImgData& Data){
        FREE_IMAGE_FORMAT Format =
            FreeImage_GetFileType(Path.c_str(), 0);

        if (Format == FIF_UNKNOWN){
            Format =
                FreeImage_GetFIFFromFilename(Path.c_str());
        }

        if (Format == FIF_UNKNOWN){
            return false;
        }

        Bitmap = FreeImage_Load(
            Format,
            Path.c_str()
        );

        if (Bitmap == nullptr){
            return false;
        }

        Data.TargetImageWidth =
            FreeImage_GetWidth(Bitmap);

        Data.TargetImageHeight =
            FreeImage_GetHeight(Bitmap);

        return true;
    }

    void ImgDecode::Unload()
    {
        if (Bitmap != nullptr)
        {
            FreeImage_Unload(Bitmap);

            Bitmap = nullptr;
        }
    }

    unsigned char* ImgDecode::GetPixels() {
        if (Bitmap == nullptr) return nullptr;
        return FreeImage_GetBits(Bitmap);
    }

    int ImgDecode::GetPitch() {
        if (Bitmap == nullptr) return 0;
        return FreeImage_GetPitch(Bitmap);
    }

    int ImgDecode::GetBitsPerPixel() {
        if (Bitmap == nullptr) return 0;
        return FreeImage_GetBPP(Bitmap);
    }

    unsigned char* ImgDecode::GetRGBAPixels() {
        if (Bitmap == nullptr) return nullptr;

        int width  = FreeImage_GetWidth(Bitmap);
        int height = FreeImage_GetHeight(Bitmap);
        int pitch  = FreeImage_GetPitch(Bitmap);
        int bpp    = FreeImage_GetBPP(Bitmap);

        if (bpp != 32) {
            // Not already 4 bytes/pixel — convert to 32bpp first so the swap below is safe.
            FIBITMAP* converted = FreeImage_ConvertTo32Bits(Bitmap);
            if (converted == nullptr) return nullptr;

            FreeImage_Unload(Bitmap);
            Bitmap = converted;

            pitch = FreeImage_GetPitch(Bitmap);
            bpp   = 32;
        }

        unsigned char* src = FreeImage_GetBits(Bitmap);
        RGBABuffer.resize(static_cast<size_t>(height) * width * 4);

        // FreeImage stores rows bottom-up; flip to top-down while swapping B/R.
        for (int y = 0; y < height; y++) {
            unsigned char* srcRow = src + y * pitch;
            unsigned char* dstRow = RGBABuffer.data() + (height - 1 - y) * width * 4;

            for (int x = 0; x < width; x++) {
                unsigned char* s = srcRow + x * 4;
                unsigned char* d = dstRow + x * 4;

                d[0] = s[2]; // R = B
                d[1] = s[1]; // G = G
                d[2] = s[0]; // B = R
                d[3] = s[3]; // A = A
            }
        }

        return RGBABuffer.data();
    }

}
