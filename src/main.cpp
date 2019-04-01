#include <iostream>
#include <typeinfo>
#include "ImageReader.cpp"
#include "./representations/Pixel.cpp"
#include "./file_system/FsReader.cpp"

const std::string imagesDir = "/home/mszopa/Desktop/right_images/input_img/";

int main()
{
    ImageReader reader;
    FsReader fsReader(imagesDir);

    Iterator<fs::path>* fsIterator = fsReader.getIterator();

    while(fsIterator->hasNext())
    {
        fs::path image_path = fsIterator->getNext();
        Image *img = reader.readImage(image_path.string());
        img->getSpecificPixel(2,2)->getInfo();
        delete img;
    }
    delete fsIterator;
}

