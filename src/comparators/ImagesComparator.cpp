#include "../file_system/FsReader.h"

class ImageComparator
{
private:
    FsReader* fsReader;
public:
    ImageComparator(FsReader*);
    ~ImageComparator();    
};

ImageComparator::ImageComparator(FsReader* fsReader)
    : fsReader(fsReader) {}

ImageComparator::~ImageComparator()
{
}