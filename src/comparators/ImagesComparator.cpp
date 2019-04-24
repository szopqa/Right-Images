#include "ImagesComparator.h"

ImageComparator::ImageComparator(FsReader* fsReader)
    : fsReader(fsReader) {}

ImageComparator::~ImageComparator()
{
}

void ImageComparator::compareImagesInDirectory(ImageAnalyzer imageAnalyzer)
{
    // Iterator<fs::path>* imageFilesIterator = this->fsReader->getIterator();
    // while(imageFilesIterator->hasNext())
    // {
    //     fs::path image_path = imageFilesIterator->getNext();
    //     Image *img = imageReader.readImage(image_path.string());
    //     img->getSpecificPixel(2,2)->getInfo();
    //     imageAnalyzer.analyze(img);
    //     delete img;
    // }
}