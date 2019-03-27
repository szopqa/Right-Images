#include <iostream>
#include <typeinfo>
#include "ImageReader.cpp"
#include "Pixel.cpp"

int main()
{
    ImageReader reader("../input_img");
    Image *img = reader.readImage("../input_img/img.jpg");
   
    // // Saving image data
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
    imgRows[3][3].getInfo();
    imgRows[1][1].getInfo();
    imgRows[1][1].getInfo();
    imgRows[1][2].getInfo();
    imgRows[2][1].getInfo();
    imgRows[3][1].getInfo();

    // Pixel* p1 = img->getSpecificPixel(3, 3);
    // p1->getInfo();
    // Pixel* p2 = img->getSpecificPixel(1, 1);
    // p2->getInfo();
    // Pixel* p3 = img->getSpecificPixel(1, 1);
    // p3->getInfo();
    // Pixel* p4 = img->getSpecificPixel(1, 2);
    // p4->getInfo();
    // Pixel* p5 = img->getSpecificPixel(2, 1);
    // p5->getInfo();
    // Pixel* p6 = img->getSpecificPixel(3, 1);
    // p6->getInfo();

    // Getting each pixel info
    // for(unsigned int y = 0; y < img->getHeight(); y ++)
    // {
    //    for(unsigned int x = 0; x < img->getWidth(); x ++)
    //    {
    //        imgRows[y][x].getInfo();
    //    }
    // }
}
