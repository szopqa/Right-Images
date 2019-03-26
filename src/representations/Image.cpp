#pragma once
#include <iostream>
#include <sstream>
#include "../Pixel.cpp"

class Image
{
private:
    unsigned char *data;
    int width;
    int height;
    int nrChannels;
    // number of interleaved 8-bit components per pixel
    int componentsPerPixel;
public:
    Image(unsigned char *, int, int, int, int);
    ~Image(/* args */);
    
    std::string getInfo();
    int getWidth();
    int getHeight();
    int getComponentsPerPixel();
    unsigned char* getData();
    Pixel* getSpecificPixel(unsigned int x, unsigned int y);
};

Image::Image(unsigned char *imageData, int imageWidth, int imageHeight, int nrChannels, int c_p_p)
    : data(imageData), width(imageWidth), height(imageHeight), nrChannels(nrChannels), componentsPerPixel(c_p_p) {}

//The return value from an image loader is an 'unsigned char *' which points
// to the pixel data, or NULL on an allocation failure or if the image is
// corrupt or invalid. The pixel data consists of *y scanlines of *x pixels,
// with each pixel consisting of N interleaved 8-bit components; the first
// pixel pointed to is top-left-most in the image.
Image::~Image()
{
    stbi_image_free(data);
}

std::string Image::getInfo()
{
    std::stringstream ss;
    ss << "Data addr: " << &data << " width: " << width << " height: " << height << " nrChan: " << nrChannels << " c_p_p: " << componentsPerPixel << std::endl;
    return ss.str();
}

int Image::getWidth() { return this->width; }
int Image::getHeight() { return this->height; }
int Image::getComponentsPerPixel() { return this->componentsPerPixel; }
unsigned char* Image::getData() { return this->data; }

Pixel* Image::getSpecificPixel(unsigned int x, unsigned int y)
{
    if(x < 0 || y < 0 || x > this->getWidth() || y > this->getHeight())
    {
        throw std::invalid_argument( "Invalid input value error" );
    };
    unsigned short int valuesPerRow = this->width * this->componentsPerPixel;
    unsigned char* selectedRow = this->data + (y - 1) * valuesPerRow;
    unsigned char* selectedPixData = selectedRow + this->componentsPerPixel * (x - 1);

    int r = (int)selectedPixData[0];
    int g = (int)selectedPixData[1];
    int b = (int)selectedPixData[2];
    int a = this->getComponentsPerPixel() > 3 ? (int)selectedPixData[3] : 0;

    return new Pixel(x, y, r, g, b, a);
}