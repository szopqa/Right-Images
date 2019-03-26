#include <iostream>
#include <typeinfo>
#include "ImageReader.cpp"
#include "Pixel.cpp"

int main()
{
    ImageReader reader("../input_img");
    Image *img = reader.readImage("../input_img/img_3x3.jpg");
   
    // Saving image data
    unsigned char* imageData = img->getData();
   
    // Image memory alocation  
    Pixel** imgRows = new Pixel*[img->getHeight()];	
    for(unsigned int y = 0; y < img->getHeight(); y ++)
    {
	imgRows[y] = new Pixel[img->getWidth()];
    }

    // Filling matrix with image data
    for(unsigned int y = 0; y < img->getHeight(); y ++)
    {
        for(unsigned int x = 0; x < img->getWidth(); x ++)
        {
	    unsigned char* pixImg = imageData + img->getComponentsPerPixel() * x + y * img->getWidth() * img->getComponentsPerPixel();
            int r = (int)pixImg[0];
            int g = (int)pixImg[1];
            int b = (int)pixImg[2];
            int a = img->getComponentsPerPixel() > 3 ? (int)pixImg[3] : 0;
            imgRows[y][x] = Pixel(x, y, r, g, b, a);
        }
    }
    std::cout << "Done!" << std::endl;

    Pixel* p1 = img->getSpecificPixel(3, 3);
    p1->getInfo();

    // Getting each pixel info
    //for(unsigned int y = 0; y < img->getHeight(); y ++)
    //{
    //    for(unsigned int x = 0; x < img->getWidth(); x ++)
    //    {
    //        imgRows[y][x].getInfo();
    //    }
    //}
}
