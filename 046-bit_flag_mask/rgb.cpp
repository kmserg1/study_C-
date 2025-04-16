# include <iostream>                                                                                          
                                                                                                              
int main()                                                                                                    
{                                                                                                             
const unsigned int redBits = 0xFF000000;                                                                      
const unsigned int greenBits = 0x00FF0000;                                                                    
const unsigned int blueBits = 0x0000FF00;                                                                     
const unsigned int alphaBits = 0x000000FF;                                                                    
                                                                                                              
 unsigned int pixel;                                                                                          
 std::cout << "Entera 32-bit RGBA color value in hexadecimal (e.g.FF7F3300):";                                
 std::cin >> std::hex >> pixel; // std::hex позволяет вводить шестнадцатеричные значения                      
                                                                                                              
 // Используем побитовое И для изоляции красных пикселей, а затем сдвигаем значение вправо в диапазон 0-255   
 unsigned char red=(pixel&redBits) >> 24;                                                                     
                                                                                                              
unsigned char blue = (pixel & blueBits) >> 8;                                                                  
                                                                                                              
unsigned char green = (pixel&greenBits) >> 16;                                                                 
                                                                                                              
unsigned char alpha = pixel & alphaBits;                                                                       
                                                                                                              
 std::cout << "Your color contains:\n";                                                                       
 std::cout << static_cast<int>(red) << " of 255 red\n";                                                       
 std::cout << static_cast<int>(green) << " of 255 green\n";                                                   
 std::cout << static_cast<int>(blue) << " of 255 blue\n";                                                      
                                                                                                              
 std::cout << static_cast<int>(alpha)<< " of 255 alpha\n";                                                    
 return 0;                                                                                                    
 }                                                                                                            
