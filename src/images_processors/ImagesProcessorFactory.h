#pragma once
#include <stdexcept>
#include "ImagesProcessor.h"

#include "./images_comparators/ImagesComparator.h"

enum ImageProcessors 
{
  NEIGHBORING_IMAGES_COMPARATOR
};

class ImagesProcessorFactory
{
public:
  ImagesProcessorFactory(/* args */);
  ~ImagesProcessorFactory();

  ImagesProcessor* createProcessor(ImageProcessors);
};
