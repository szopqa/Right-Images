#include "./ImagesProcessorFactory.h"

ImagesProcessorFactory::ImagesProcessorFactory() 
{ 
  
}

ImagesProcessor* ImagesProcessorFactory::createProcessor(ImageProcessors chosenProcessor)
{
  switch (chosenProcessor)
  {
  case NEIGHBORING_IMAGES_COMPARATOR:
    return new ImagesComparator();
  
  default:
    throw std::invalid_argument("Unhandled image processor.");
    break;
  }
}