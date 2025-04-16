#include <iostream>                                        
                                                           
void printO()                                              
{                                                          
std::cout <<"O";                               
}                                                          
                                                           
void printK()                                              
{                                                          
 std::cout <<"K"<< std::endl;                              
 }                                                         
                                                           
 // Функция printOK() вызывает как printO(), так и printK()
 void printOK()                                            
 {                                                         
 printO();                                                 
 printK();                                                 
 }                                                         
                                                           
 // Объявление main()                                      
 int main()                                                
 {                                                         
 std::cout <<"Starting main()"<< std::endl;                
 printOK();                                                
 std::cout <<"Ending main()"<< std::endl;                  
 return 0;                                                 
 }                                                         
