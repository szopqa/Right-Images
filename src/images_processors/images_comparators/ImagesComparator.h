#pragma once
#include "../ImagesProcessor.h"
#include "../../images_reader/ImagesReader.h"

class ImagesComparator : public ImagesProcessor
{
private:
  ImagesReader imagesReader;

public:
  void compare();
  ImagesComparator(ImagesReader imagesReader);

  void processImages() override;
};