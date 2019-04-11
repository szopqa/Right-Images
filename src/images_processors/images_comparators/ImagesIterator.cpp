#include "./ImagesIterator.h"

ImagesIterator::ImagesIterator(std::string imagesDirectory) 
	: imagesDirectory(imagesDirectory) { }

Iterator<Image*>* ImagesIterator::getIterator()
{
  class ImagesIter: public Iterator<Image*>
  {
  private:
    Iterator<fs::path>* fsIterator;
    ImageReader reader;
  public:
    ImagesIter(std::string imagesDirectory)
    {
      this->fsIterator = FsReader(imagesDirectory).getIterator();
      this->reader = ImageReader();
    }

    Image* getNext() override
    {
      fs::path image_path = this->fsIterator->getNext();
      return reader.readImage(image_path.string());
    }

    bool hasNext() override
    {
      return this->fsIterator->hasNext();
    }
  };

  return new ImagesIter(this->imagesDirectory);
}