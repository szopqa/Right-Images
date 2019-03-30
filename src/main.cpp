#include <iostream>
#include <typeinfo>
#include "ImageReader.cpp"
#include "./representations/Pixel.cpp"
#include "./file_system/FsReader.cpp"

const std::string imagesDir = "/home/mszopa/Desktop/right_images/input_img/";

int main()
{
    ImageReader reader("../input_img");
    Image *img = reader.readImage("../input_img/img.jpg");
   
    // getting image example data
    img->getSpecificPixel(2,2)->getInfo();

    FsReader fsReader(imagesDir);

    Iterator<fs::path>* fsIterator = fsReader.getIterator();

    while(fsIterator->hasNext())
    {
        fsIterator->getNext();
    }
}

