#pragma once
#include <stdexcept>
#include "ImagesProcessor.h"
#include "ImageProcessorsEnum.h"

#include "./images_comparators/ImagesComparator.h"

class ImagesProcessorFactory
{
public:
  static ImagesProcessor* createProcessor(ImageProcessorsEnum, ImagesReader);
};
