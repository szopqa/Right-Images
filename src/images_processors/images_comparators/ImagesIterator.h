#pragma once
#include <experimental/filesystem>
#include "../../iterators/Iterator.h"
#include "../../iterators/Iterable.cpp"
#include "../../representations/Image.h"
#include "../../file_system/FsReader.h"
#include "../../images_reader/ImageReader.h"

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
