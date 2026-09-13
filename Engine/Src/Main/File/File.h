/*********************

File.h
Created by Josh Billena

*********************/
#ifndef FILE_H
#define FILE_H


#include <fstream>
#include <vector>
#include <string>
namespace Alphalabs{

    struct File{

        static std::string Read(const std::string& path);

        static bool Save(const std::string contents, const std::string& path, const std::string& name);

    };

}
#endif // FILE_H
