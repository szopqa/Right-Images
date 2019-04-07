#pragma once
#include <iostream>
#include <experimental/filesystem>
#include "../interfaces/Iterable.cpp"

namespace fs = std::experimental::filesystem;

class FsReader : public Iterable<fs::path>
{
private:
  std::string workingPath;
public:
  FsReader(std::string);
  Iterator<fs::path>* getIterator() override;
};