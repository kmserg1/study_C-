#include <iostream>                         
                                            
int main()                                  
{                                           
unsigned short x = 0; // наименьшее значение
std::cout << "x was:" << x << std::endl;    
x = x - 1; // переполнение!                 
std::cout << "x is now: " << x << std::endl;
return 0;                                   
}                                          
