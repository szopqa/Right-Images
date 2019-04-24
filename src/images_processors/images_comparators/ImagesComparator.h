#pragma once
#include "../ImagesProcessor.h"

class ImagesComparator : public ImagesProcessor
{
public:
  ImagesComparator();

  void processImages(std::string imagesDirectory) override;
};