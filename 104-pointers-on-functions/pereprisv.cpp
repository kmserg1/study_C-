#include <iostream>

int boo()                                                    
{                                                            
return 7;                                                    
}                                                            
                                                             
int doo()                                                    
{                                                            
return 8;                                                    
}                                                            
                                                             
 int main()                                                  
 {                                                           
 int (*fcnPtr)()=boo; 
 //std::cout << reinterpret_cast<void*>(boo) << std::endl;
 std::cout << fcnPtr << std::endl;
 std::cout << reinterpret_cast<void*>(fcnPtr) << std::endl;
 std::cout << (*fcnPtr)() << std::endl;
 
 fcnPtr=doo; 
 std::cout << fcnPtr << std::endl;
 std::cout << reinterpret_cast<void*>(fcnPtr) << std::endl;
 std::cout << (*fcnPtr)() << std::endl;
// тест коментарів                      
 return 0;                                                   
 }                                                           
