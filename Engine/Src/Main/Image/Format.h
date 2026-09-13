/*********************

Format.h
Created by Josh Billena

*********************/

#ifndef FORMAT_H
#define FORMAT_H

#include "../../Necessity.h"
#include <FreeImage.h>

namespace Alphalabs{

    class Format{
    public:

        virtual FIBITMAP* Decode(std::string Path) = 0;

        virtual ~Format() {}
    };
}

#endif // FORMAT_H
