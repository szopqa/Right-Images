#pragma once
#include <iostream>
#include "../representations/Image.h"

class ImageReader
{
private:
    std::string imagesDir;
public:
    ImageReader();
    ImageReader(std::string);
    ~ImageReader();

    Image *readImage(std::string);
};