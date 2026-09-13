/*********************

Codec.h
Created by Josh Billena

*********************/

#ifndef CODEC_H
#define CODEC_H
#include "../../Necessity.h"

namespace Alphalabs{

    class ImageCodec{

    public:

        std::string GetFormat(std::string Path);


        bool Supported(std::string Path);

    };

}
#endif // CODEC_H
