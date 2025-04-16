#include <iostream>           
                              
 void foo(int *&p)            
 {                            
 }                            
                              
int main()                    
{                             
	int *p; 
 //	foo(p); 
                              
 std::cout << *p; 
                              
 return 0;                    
 }                            
