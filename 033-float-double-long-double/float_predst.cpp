#include<iostream>          
                            
int main()                  
{                           
float f;                    
f = 9.87654321f;            
std::cout<< f << std::endl; 
f = 987.654321f;            
std::cout<< f << std::endl; 
 f = 987654.321f;           
 std::cout<< f << std::endl;
 f = 9876543.21f;           
 std::cout<< f << std::endl;
 f = 0.0000987654321f;      
 std::cout<< f << std::endl;


 double zero=0.0;                                                 
 double posinf=5.0 / zero; // положительная бесконечность         
 std::cout<< posinf <<"\n";                                       
                                                                  
 double neginf=-5.0/zero; // отрицательная бесконечность           
std::cout<< neginf <<"\n";                                      
                                                                
double nan = zero / zero;// нечисло (математически некорректно)  
std::cout<< nan << "\n";                                        
                                                             
return 0;                   
}                          
