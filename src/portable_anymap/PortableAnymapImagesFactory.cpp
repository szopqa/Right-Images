#pragma once
#include <fstream>
#include "string"
#include "../representations/Image.cpp"
#include "./PortablePixMap.cpp"
#include "./PortableGrayMap.cpp"

class PortableAnymapImagesFactory 
{
private:
public:
  void saveImage(Image*, std::string);
  PortableAnymapImage* createAnymapImage(Image*);
};

PortableAnymapImage* PortableAnymapImagesFactory::createAnymapImage(Image* imageRepresentation)
{
  switch (imageRepresentation->getComponentsPerPixel())
  {
    case 3:
      return new PortablePixMap();
    case 1:
      return new PortableGrayMap();
    default:
      throw std::invalid_argument("Unhandled number of colors per pixel. Unable to instantiate anymap image");
      break;
  }
}

void PortableAnymapImagesFactory::saveImage(Image* imageRepresentation, std::string pathToSave)
{
  PortableAnymapImage* portableImage = this->createAnymapImage(imageRepresentation);
  
  std::string imageFilename = pathToSave + "." +  portableImage->getImageExtension();

  std::ofstream imageFile(imageFilename);
  imageFile << portableImage->fromImage(imageRepresentation);

  delete portableImage;
}
