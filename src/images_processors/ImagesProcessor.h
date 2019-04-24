#pragma once
#include "string"

class ImagesProcessor
{
private:
public:
  // TODO: change function to return object implementing ProcessingResults interface
  virtual void processImages(std::string imagesDirectory) = 0;
};