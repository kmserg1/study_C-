#include <iostream>



class Point{
private:
	double m_a, m_b;
public:
	Point(double a=0.3, double b=.5):m_a(a),m_b(b)
	{
	}
	void print(){
		std::cout <<  "Point(" << m_a <<"," << m_b << ")\n";
	}
};

// Должна выдавать следующий результат:
// Point(0,0)
// Point(2,5)

int main()
{
	Point first;
	Point second(2.12,5.24);

	first.print();
	second.print();

 	return 0;
 }

