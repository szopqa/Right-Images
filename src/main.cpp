#include <iostream>
#include <typeinfo>
#include "ImageReader.h"
#include "./representations/Pixel.h"
#include "./file_system/FsReader.h"

#include "./portable_anymap/PortableAnymapImagesFactory.h"

const std::string imagesDir = "/home/mszopa/Desktop/right_images/input_img/";

int main()
{
    /* WITH FS_ITERATOR USAGE
    
    ImageReader reader;
    FsReader fsReader(imagesDir);
    Iterator<fs::path>* fsIterator = fsReader.getIterator();
    while(fsIterator->hasNext())
    {
        fs::path image_path = fsIterator->getNext();
        Image *img = reader.readImage(image_path.string());
        img->getSpecificPixel(2,2)->getInfo();
    
        PortablePixMap pixMapImage;
        pixMapImage.fromImage(img);

        delete img;
    }
    delete fsIterator;
    
    */

    ImageReader reader(imagesDir);
    Image *img = reader.readImage("img.jpg");

    PortableAnymapImagesFactory pixMapImage;
    pixMapImage.saveImage(img, "img");
}