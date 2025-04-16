#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
                                            
int main()                                  
{                                           
	char text[] = "Print this!";          
	char dest[5]; // обратите внимание, дл
	strcpy_s(dest, text); // переполнение!
	std::cout << dest;                    
                                            
 	return 0;                             
 }                                          
