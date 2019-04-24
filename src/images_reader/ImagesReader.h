#pragma once
#include "../iterators/Iterable.cpp"
#include "../iterators/Iterator.h"
#include "../representations/Image.h"
#include "../file_system/FsReader.h"
#include "./ImageReader.h"

class ImagesReader: public Iterable<Image*>
{
private:
    std::string workingDir;
public:
    ImagesReader(std::string);

    Iterator<Image*>* getIterator() override;
};