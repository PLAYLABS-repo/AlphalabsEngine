/*********************

ImgData.h
Created by Josh Billena

*********************/
#ifndef IMGDATA_H
#define IMGDATA_H
#include "../../GLES2Includes.h"
#include "../File/File.h"
#include "../../Necessity.h"
#include <FreeImage.h>

namespace Alphalabs{

    class ImgData{

    public:

     float RedChannel;
     float GreenChannel;
     float BlueChannel;
     float AlphaChannel;
     GLuint TargetImageData;
     int TargetImageWidth;
     int TargetImageHeight;

    GLuint GetImageData(std::string Path);


    };

}


#endif // IMGDATA_H


