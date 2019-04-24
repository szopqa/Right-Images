#include "ImagesComparator.h"

ImageComparator::ImageComparator(FsReader* fsReader)
    : fsReader(fsReader) {}

ImageComparator::~ImageComparator()
{
}

void ImageComparator::compareImagesInDirectory(ImageAnalyzer imageAnalyzer)
{
}