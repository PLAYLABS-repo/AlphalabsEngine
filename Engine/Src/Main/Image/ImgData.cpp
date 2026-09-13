/*********************

ImgData.cpp
Created by Josh Billena

*********************/
#include "ImgData.h"
#include <FreeImage.h>

namespace Alphalabs{


        GLuint ImgData::GetImageData(std::string Path){

        File::Read(Path);

        return TargetImageData;

    }


}



