/*********************

Format.cpp
Created by Josh Billena

*********************/

#include "Format.h"

namespace Alphalabs{

    FIBITMAP* Format::Decode(std::string Path){
        FREE_IMAGE_FORMAT FormatType;


        FormatType = FreeImage_GetFileType(Path.c_str(), 0);


        if (FormatType == FIF_UNKNOWN)
        {
            FormatType = FreeImage_GetFIFFromFilename(Path.c_str());
        }


        if (FormatType == FIF_UNKNOWN)
        {
            return nullptr;
        }


        return FreeImage_Load(FormatType, Path.c_str());
    }
}
