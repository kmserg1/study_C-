#include <iostream>
#include "Point3D.h"
#include "Vector3D.h"

 int main()                                                                        
 {                                                                                 
 	Point3D p(3.0, 4.0, 5.0);                                                    
 	Vector3D v(1.0, 1.0, -2.0);                                                   
                                                                                   
 	p.print();
 	v.print();
 	p.moveByVector(v);
	std::cout<<"Moved  ";
 	p.print();                                                                   
                                                                                   
 	return 0;                                                                    
 }
