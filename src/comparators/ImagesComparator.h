#pragma once
#include "../file_system/FsReader.h"
#include "../iterators/Iterator.h"
#include "../representations/Image.h"
#include "../images_reader/ImageReader.h"
#include "./image_analyzers/ImageAnalyzer.h"

class ImageComparator
{
private:
    FsReader* fsReader;
    ImageReader imageReader;
public:
    ImageComparator(FsReader*);
    ~ImageComparator();    

    void compareImagesInDirectory(ImageAnalyzer);
};