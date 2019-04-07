#include "PortablePixMap.h"

#define PIXMAP_MAGIC_NUMBER "P3";
#define PIXMAP_COLORS 255;
#define PIXMAP_FILE_EXTENSION "ppm";

PortablePixMap::PortablePixMap()
{
  this->magicNumber = PIXMAP_MAGIC_NUMBER;
  this->numOfColors = PIXMAP_COLORS;
  this->imageFileExtension = PIXMAP_FILE_EXTENSION;
}

PortablePixMap::~PortablePixMap() {}