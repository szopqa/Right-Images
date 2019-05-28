#pragma once
#include "../ImagesProcessor.h"
#include "../../images_reader/ImagesReader.h"

class ImagesComparator : public ImagesProcessor
{
private:
  ImagesReader imagesReader;

public:
  ImagesComparator(ImagesReader imagesReader);

  void processImages(std::string imagesDirectory) override;
};