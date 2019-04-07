#include "PortableGrayMap.h"

#define GRAYMAP_MAGIC_NUMBER "P2";
#define GRAYMAP_COLORS 255;
#define GRAYMAP_FILE_EXTENSION "pgm";

PortableGrayMap::PortableGrayMap()
{
  this->magicNumber = GRAYMAP_MAGIC_NUMBER;
  this->numOfColors = GRAYMAP_COLORS;
  this->imageFileExtension = GRAYMAP_FILE_EXTENSION;
}

PortableGrayMap::~PortableGrayMap() {}
