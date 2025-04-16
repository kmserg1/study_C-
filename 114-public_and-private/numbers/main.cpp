#include <iostream>

class Numbers{
	double m_a;
	double m_b;
	double m_c;

public:
	void setValues(double first,double second,double third){
		m_a=first;
		m_b=second;
		m_c=third;
	}
	void print(){
		std::cout << '<' << m_a << ',' << m_b << ',' << m_c << ">\n";
	}
	bool isEqual(Numbers arg){
        return (m_a==arg.m_a && m_b==arg.m_b && m_c==arg.m_c);
    }
};

int main()
{
	Numbers point1;
	point1.setValues(3.0,4.0, 5.0);

	Numbers point2;
	point2.setValues(3.0,4.0, 5.0);

	if (point1.isEqual(point2))
 		std::cout <<"point1 and point2 are equal\n";
 	else
       	std::cout <<"point1 andpoint2 are not equal\n";

 	Numbers point3;
 	point3.setValues(7.0,8.0, 9.0);

 	if (point1.isEqual(point3))
      	std::cout <<"point1 and point3 are equal\n";
 	else
 		std::cout <<"point1 and point3 are not equal\n";

 return 0;
 }
