#include <iostream>
#include <cmath>

class Point{
private:
	double m_a, m_b;
public:
	Point(double a=0.0, double b=.0):m_a(a),m_b(b)
	{
	}

	void print(){
		std::cout <<  "Point(" << m_a <<"," << m_b << ")\n";
	}

	friend double distanceFrom(Point &p1,Point &p2);
};

double distanceFrom(Point &p1, Point &p2) {
	return sqrt((p1.m_a - p2.m_a)*(p1.m_a - p2.m_a) + (p1.m_b - p2.m_b)*(p1.m_b - p2.m_b));
}


//Должна выдавать следующий результат:
//Point(0,0)
//Point(2,5)
//Distance between two points: 5.38516


int main()
{
	Point first;
	Point second(2.0,5.0);
	first.print();
	second.print();
	std::cout<< "Distance between two points: " << distanceFrom(first, second) << '\n';
	return 0;

}
