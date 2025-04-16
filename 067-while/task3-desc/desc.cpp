#include <iostream>
 
 int main()
 {
     int outer = 5;
     
     while (outer > 0)
	    {
        	 int inner = 1;
	         while (inner <= outer){
        	    std::cout << outer-inner+1 << " ";
                ++inner;
             }
	         // new string here
        	 std::cout << "\n";
	         --outer;
	     }
  
     return 0;
 }
