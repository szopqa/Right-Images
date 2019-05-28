#pragma once
#include "string"
#include "../images_reader/ImagesReader.h"

class ImagesProcessor
{
private:
public:
  // TODO: change function to return object implementing ProcessingResults interface
  virtual void processImages(std::string imagesDirectory) = 0;
};