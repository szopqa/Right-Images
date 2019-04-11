#pragma once
#include <experimental/filesystem>
#include "../../interfaces/Iterator.h"
#include "../../interfaces/Iterable.cpp"
#include "../../representations/Image.h"
#include "../../file_system/FsReader.h"
#include "../../ImageReader.h"

namespace fs = std::experimental::filesystem;

class ImagesIterator: public Iterable<Image*>
{
private:
  std::string imagesDirectory;
public:
  ImagesIterator(std::string);
  ~ImagesIterator();

  Iterator<Image*>* getIterator() override;
};
