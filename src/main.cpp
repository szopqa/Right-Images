#include <iostream>
#include <typeinfo>
#include "ImageReader.cpp"
#include "./representations/Pixel.cpp"
#include "./file_system/FsReader.cpp"

#include "./portable_anymap/PortableAnymapImagesFactory.cpp"

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
    Image *img = reader.readImage("img_3x3.jpg");

    PortableAnymapImagesFactory pixMapImage;
    pixMapImage.saveImage(img, "test_image");
}