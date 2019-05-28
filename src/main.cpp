#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <ctime>

#include "./images_reader/ImageReader.h"
#include "./representations/Pixel.h"
#include "./file_system/FsReader.h"
#include "./images_reader/ImagesReader.h"

#include "./portable_anymap/PortableAnymapImagesFactory.h"

#include "./images_processors/ImagesProcessorFactory.h"
#include "./images_processors/ImageProcessorsEnum.h"

const std::string imagesDir = "/home/mszopa/Desktop/right_images/input_img/";

int main()
{
    ImagesReader imagesReader(imagesDir);
    ImageProcessorsEnum comparator = ImageProcessorsEnum::NEIGHBORING_IMAGES_COMPARATOR;
    ImagesProcessor* imagesComparator = ImagesProcessorFactory().createProcessor(comparator, imagesReader);
 
    imagesComparator->processImages(imagesDir);
    
    return 0;
}