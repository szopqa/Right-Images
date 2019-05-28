#include "ImagesComparator.h"

ImagesComparator::ImagesComparator(ImagesReader imagesReader)
{
    this->imagesReader = imagesReader;
}

void ImagesComparator::processImages() 
{
    Iterator<Image*>* imagesIterator = imagesReader.getIterator();

    Image* imageA = nullptr;
    Image* imageB = nullptr;

    while(imagesIterator->hasNext())
    {
        imageA = imageB ? imageB : imagesIterator->getNext();
        if(imageA)
        {
            if(imagesIterator->hasNext())
            {
                imageB = imagesIterator->getNext();
            }

            // Images comparison logic should be implemented here
            if (imageA && imageB)
            {
                std::cout << "Comparing images: \n" << "\t" << imageA->getInfo() << "\n" << "with:\n" << "\t" << imageB->getInfo() << std::endl;
            }
        }
    }

    delete imageA;
    delete imageB;

    delete imagesIterator;
}