#include "./ImagesProcessorFactory.h"

ImagesProcessor* ImagesProcessorFactory::createProcessor(ImageProcessorsEnum chosenProcessor, ImagesReader imagesReader)
{
  switch (chosenProcessor)
  {
  case ImageProcessorsEnum::NEIGHBORING_IMAGES_COMPARATOR:
    return new ImagesComparator(imagesReader);
  
  default:
    throw std::invalid_argument("Unhandled image processor.");
    break;
  }
}