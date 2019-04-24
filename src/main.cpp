#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <ctime>

#include "./images_reader/ImageReader.h"
#include "./representations/Pixel.h"
#include "./file_system/FsReader.h"
#include "./images_reader/ImagesReader.h"

#include "./portable_anymap/PortableAnymapImagesFactory.h"

const std::string imagesDir = "/home/mszopa/Desktop/right_images/input_img/";

int main()
{
    srand(time(NULL));
    PortableAnymapImagesFactory pixMapImage;   

    ImagesReader imagesReader(imagesDir);
    Iterator<Image*>* imagesIterator = imagesReader.getIterator();
    while(imagesIterator->hasNext())
    {
        Image *image = imagesIterator->getNext();
        if(image)
        {
            image->getSpecificPixel(2,2)->getInfo();
            std::string imageName = "img_" + std::to_string(std::rand());
            pixMapImage.saveImage(image, imageName);
            delete image;
        }
    }
    delete imagesIterator;
    
    return 0;
}