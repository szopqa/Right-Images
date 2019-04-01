#pragma once
#include <iostream>

#include "../interfaces/Iterable.cpp"
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

class FsReader : public Iterable<fs::path>
{
private:
  std::string workingPath;
public:
  FsReader(std::string);
  Iterator<fs::path>* getIterator() override;
};

FsReader::FsReader(std::string workingPath) 
	: workingPath(workingPath) { }

Iterator<fs::path>* FsReader::getIterator()
{
	class FsIterator: public Iterator<fs::path>
	{
	private:
		fs::path workingPath;
		fs::directory_iterator dir_iterator;

		bool processedAllFiles;
	public:
		FsIterator(std::string workingPath)
		{
			this->processedAllFiles = false;
			
			this->workingPath = workingPath;
			this->dir_iterator = fs::directory_iterator(this->workingPath);
			this->currentElement = dir_iterator->path();
			std::cout << "[DEBUG]: FS Iterator set up at : " << this->workingPath << std::endl << std::endl;
		}

		fs::path getNext() override
		{
			try {
				fs::directory_entry dir = *this->dir_iterator;
				this->currentElement = dir.path();
				std::cout<< "Current path: " << this->currentElement << std::endl;
			
				++this->dir_iterator;
			} catch (const fs::filesystem_error& e) {
				this->processedAllFiles = true;
			}

			return this->currentElement;
		}
		
		bool hasNext() override { return !this->processedAllFiles; }
	};

	return new FsIterator(this->workingPath);
};