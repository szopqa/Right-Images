#include "./ImagesReader.h"

ImagesReader::ImagesReader(std::string workingDir) 
    : workingDir(workingDir) {}

Iterator<Image*>* ImagesReader::getIterator()
{
    class ImagesIterator: public Iterator<Image*>
	{
	private:
		Iterator<fs::path>* fsIterator;
		ImageReader imageReader;

		bool processedAllFiles;
	public:
		ImagesIterator(FsReader fsReader)
		{
			this->fsIterator = fsReader.getIterator();
			this->imageReader = ImageReader();
		}

		Image* getNext() override
		{
			fs::path image_path = this->fsIterator->getNext();
			if(!this->hasNext())
			{
				return nullptr;
			}
			
			return this->imageReader.readImage(image_path.string());
		}
		
		bool hasNext() override 
		{ 
			return this->fsIterator->hasNext();
		}
	};

	return new ImagesIterator(FsReader(this->workingDir));
}