#pragma once
#include "string"
#include "PortableAnymapImage.cpp"

#define GRAYMAP_MAGIC_NUMBER "P2";
#define GRAYMAP_COLORS 255;
#define GRAYMAP_FILE_EXTENSION "pgm";

class PortableGrayMap: public PortableAnymapImage
{
public: 
  PortableGrayMap();
  ~PortableGrayMap();
};

PortableGrayMap::PortableGrayMap()
{
  this->magicNumber = GRAYMAP_MAGIC_NUMBER;
  this->numOfColors = GRAYMAP_COLORS;
  this->imageFileExtension = GRAYMAP_FILE_EXTENSION;
}

PortableGrayMap::~PortableGrayMap() {}
