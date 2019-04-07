#include "Pixel.h"

Pixel::Pixel() { }

Pixel::Pixel(unsigned short int x, unsigned short int y, unsigned short int r, unsigned short int g, unsigned short int b, unsigned short int a)
	: x_pos(x), y_pos(y), r_value(r), g_value(g), b_value(b)
{                                                                                
    this->a_value = a ? a : 0; 
}    

void Pixel::getInfo()
{
     std::cout << "x: " << x_pos << " y: "<< y_pos << ". R: " << r_value << " g: " << g_value << " b: " << b_value << " a: " << a_value << std::endl;
}
