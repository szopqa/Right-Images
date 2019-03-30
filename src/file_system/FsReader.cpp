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
		fs::directory_entry workingDir;

		int num;
	public:
		FsIterator(std::string workingPath)
		{
			this->num = 0;
			
			this->workingPath = workingPath;
			this->workingDir = fs::directory_entry(this->workingPath);
			std::cout << "FS Iterator set up at : " << this->workingDir << std::endl;
		}

		fs::path getNext() override
		{
			std::cout << "Getting next el! Current val : " << this->num<<std::endl; 
			this->num += 1;
			return this->workingPath;
		}
		
		bool hasNext() override
		{
			std::cout << "Checkin" << std::endl;
			return this->num  < 5;
		}	
	};

	return new FsIterator(this->workingPath);
};