/*********************

ImgDecode.h
Created by Josh Billena

*********************/
#ifndef IMGDECODE_H
#define IMGDECODE_H

#include "ImgData.h"
#include <FreeImage.h>
#include <vector>

namespace Alphalabs{

    class ImgDecode{

    public:

        bool Decode(std::string Path, ImgData& Data);

        void Unload();

        unsigned char* GetPixels();
        unsigned char* GetRGBAPixels();
        int GetPitch();
        int GetBitsPerPixel();

    private:

        FIBITMAP* Bitmap = nullptr;
        std::vector<unsigned char> RGBABuffer;

    };

}

#endif // IMGDECODE_H
