#pragma once
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "./external/stb_image.h"
#include "./representations/Image.cpp"

#define RGB 3

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

ImageReader::ImageReader(std::string imagesDir)
    :imagesDir(imagesDir) {}

ImageReader::~ImageReader()
{
}

Image *ImageReader::readImage(std::string imagePath)
{
    int width, height, nrChannels;
    unsigned char *imageData = stbi_load(imagePath.c_str(), &width, &height, &nrChannels, RGB);
    return new Image(imageData, width, height, nrChannels, RGB);
}
