#include <iostream>                                                                                         
                                                                                                            
int main()                                                                                                  
{                                                                                                           
unsigned short x = 65535; // наибольшее значение, которое может хранить 16-битная unsigned переменная       
std::cout << "x was:" << x << std::endl;                                                                    
x = x + 1; // 65536 - это число больше максимально допустимого числа из диапазона допустимых значений. Следо
std::cout << "x is now: " << x << std::endl;                                                                
return 0;                                                                                                   
 }                                                                                                          
                                                                                                            
