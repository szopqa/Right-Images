#pragma once
#include <iostream>
#include <sstream>
#include "string"
#include "../representations/Image.h"

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