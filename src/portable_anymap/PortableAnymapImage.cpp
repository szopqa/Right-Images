#pragma once
#include "string"
#include "../representations/Image.cpp"

/*
* Implementation according to following article: https://en.wikipedia.org/wiki/Netpbm_format
*/
class PortableAnymapImage 
{
protected:
  std::string imageFileExtension;
  std::string magicNumber;
  int numOfColors;
  virtual std::string defineHeader(int w, int h);
public:
  PortableAnymapImage();
  ~PortableAnymapImage();

  virtual std::string fromImage(Image* image);
  std::string getImageExtension();
};

PortableAnymapImage::PortableAnymapImage() {}
PortableAnymapImage::~PortableAnymapImage() {}

std::string PortableAnymapImage::getImageExtension() 
{ 
  return this-> imageFileExtension; 
}

std::string PortableAnymapImage::defineHeader(int w, int h)
{
  std::stringstream header;
  header << this->magicNumber << std::endl;
  header << w << " " << h << std::endl;
  header << this->numOfColors << std::endl;
  return header.str();
} 

std::string PortableAnymapImage::fromImage(Image* image)
{
  std::stringstream anymapImage;

  anymapImage << this->defineHeader(image->getWidth(), image->getHeight());

  for (unsigned int w = 0; w < image->getWidth(); w ++)
  {
    for (unsigned int h = 0; h < image->getHeight(); h ++)
    {
      unsigned char* pixRawData = image->getSpecificRawPixel(w + 1, h + 1);
      
      int r = (int)pixRawData[0];
      int g = (int)pixRawData[1];
      int b = (int)pixRawData[2];
      anymapImage << r << " " << g << " " << b << std::endl;
    }
  }
  
  return anymapImage.str();
}