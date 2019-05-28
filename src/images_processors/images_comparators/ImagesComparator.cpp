#include "ImagesComparator.h"

ImagesComparator::ImagesComparator(ImagesReader imagesReader)
{
    this->imagesReader = imagesReader;
}

void ImagesComparator::processImages(std::string imagesDirectory)
{    
    Iterator<Image*>* imagesIterator = imagesReader.getIterator();
    while(imagesIterator->hasNext())
    {
        Image *image = imagesIterator->getNext();
        if(image)
        {
            image->getSpecificPixel(2,2)->getInfo();
            delete image;
        }
    }
    delete imagesIterator;
}