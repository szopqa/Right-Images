#pragma once
#include <fstream>
#include "string"

#include "../representations/Image.h"
#include "../representations/Image.h"

#include "./PortableGrayMap.h"
#include "./PortablePixMap.h"

class PortableAnymapImagesFactory 
{
private:
public:
  void saveImage(Image*, std::string);
  PortableAnymapImage* createAnymapImage(Image*);
};