#pragma once  
#include <iostream>

class Pixel                                                        
{                                                                                    
private:                                                                   
    unsigned short int x_pos;
    unsigned short int y_pos;
    unsigned short int r_value;                                     
    unsigned short int g_value;             
    unsigned short int b_value;                                              
    unsigned short int a_value;                                       
public:                                                                 
    Pixel(unsigned short int, unsigned short int, unsigned short int, unsigned short int, unsigned short int, unsigned short int);        
    Pixel();
    unsigned short int getX();
    unsigned short int getY();
    void getInfo(); 
}; 