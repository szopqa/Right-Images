#pragma once
#include "string"

class ImagesProcessor
{
private:
public:
  virtual void processImages(std::string imagesDirectory) = 0;
};