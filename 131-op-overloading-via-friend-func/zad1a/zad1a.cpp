#include <iostream>
class Fraction{
private:
	int m_chislitel;
	int m_znamenatel;
public: 
	Fraction(int a, int b):m_chislitel{a},m_znamenatel{b}
	{
	}

	void print(){std::cout << m_chislitel << '/' << m_znamenatel << '\n';}
};

#include <iostream>

int main()
{
	Fraction f1(1, 4);
	f1.print();

	Fraction f2(1, 2);
	f2.print();
}