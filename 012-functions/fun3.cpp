#include <iostream>                                                                                     
                                                                                                        
// Функция getValueFromUser() получает значение от пользователя, а затем возвращает его обратно в caller
int getValueFromUser()                                                                                   
{                                                                                                       
std::cout <<"Enter an integer: ";                                                                       
int x;                                                                                                  
std::cin>> x;                                                                                           
return x;                                                                                               
 }                                                                                                      
                                                                                                        
 int main()                                                                                             
 {                                                                                                      
  int a = getValueFromUser(); //первый вызов функции getValueFromUser()                                 
  int b = getValueFromUser(); //второй вызов функции getValueFromUser()                                 
                                                                                                        
  std::cout <<a<< " + " <<b<< " = " <<a+b<< std::endl;                                                  
  return 0;                                                                                             
                                                                                                        
 }                                                                                                      
