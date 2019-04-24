#include "./ImageReader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../external/stb_image.h"

#define RGB 3

ImageReader::ImageReader() {}

ImageReader::ImageReader(std::string imagesDir)
    :imagesDir(imagesDir) {}

ImageReader::~ImageReader()
{
}

Image *ImageReader::readImage(std::string imagePath)
{
    std::cout<< "Reading image at path: " << imagePath << std::endl;

    std::string imageLocation = this->imagesDir.empty() ? imagePath : this->imagesDir + imagePath;

    int width, height, nrChannels;
    unsigned char *imageData = stbi_load(imageLocation.c_str(), &width, &height, &nrChannels, RGB);
    return new Image(imageData, width, height, nrChannels, RGB);
}
