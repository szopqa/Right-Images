#pragma once
#include <iostream>
#include <sstream>
#include "string"
#include "Pixel.h"

class Image
{
private:
    unsigned char *data;
    int width;
    int height;
    int nrChannels;
    // number of interleaved 8-bit components per pixel
    int componentsPerPixel;
    std::string imagePath;
    Pixel** imageMatrix;
public:
    Image(unsigned char *, int, int, int, int, std::string);
    ~Image();
    
    std::string getInfo();
    int getWidth();
    int getHeight();
    int getComponentsPerPixel();
    unsigned char* getData();
    Pixel* getSpecificPixel(unsigned int x, unsigned int y);
    unsigned char* getSpecificRawPixel(unsigned int x, unsigned int y);
    Pixel** getImageInMatrixRepresentation();
};