/*********************

Codec.h
Created by Josh Billena

*********************/
#include "Codec.h"

namespace Alphalabs{

    std::string ImageCodec::GetFormat(std::string Path){

        std::size_t DotPosition = Path.find_last_of('.');

        if (DotPosition == std::string::npos){
            return "";
        }

        return Path.substr(DotPosition + 1);
    }

    bool ImageCodec::Supported(std::string Path){
        std::string Format = GetFormat(Path);

        if (Format == "png" ||
            Format == "PNG" ||
            Format == "jpg" ||
            Format == "JPG" ||
            Format == "jpeg" ||
            Format == "JPEG" ||
            Format == "bmp" ||
            Format == "BMP")
        {
            return true;
        }

        return false;
    }

}
