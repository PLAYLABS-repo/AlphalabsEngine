/*********************

File.cpp
Created by Josh Billena

*********************/
#include "File.h"

namespace Alphalabs{
    std::string File::Read(const std::string& path){
        std::ifstream Stream(path);
        //If file could not load then don't do anything
        if (!Stream){
            return "";
        }

        std::string Contents(
            (std::istreambuf_iterator<char>(Stream)),
            std::istreambuf_iterator<char>()
        );

        return Contents;
    }

    bool File::Save(const std::string contents,const std::string& path,const std::string& name){
        std::ofstream Stream(path + "/" + name);

        if (!Stream){
            return false;
        }

        Stream << contents;

        return true;
    }
}
