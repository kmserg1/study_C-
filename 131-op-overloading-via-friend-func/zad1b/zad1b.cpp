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
	friend Fraction operator*(const Fraction &v1, const Fraction &v2);
	friend Fraction operator*(int value, const Fraction &v);
	friend Fraction operator*(const Fraction &v, int value);
};

Fraction operator*(const Fraction &v1, const Fraction &v2){
	return 	Fraction(v1.m_chislitel*v2.m_chislitel, v1.m_znamenatel*v2.m_znamenatel);
}

Fraction operator*(int value, const Fraction &v){
	return 	Fraction(value*v.m_chislitel, v.m_znamenatel);
}

Fraction operator*(const Fraction &v, int value){
	return 	value*v;
}

int main()
{
	Fraction f1(3, 4);
	f1.print();

	Fraction f2(2, 7);
	f2.print();

	Fraction f3 = f1 * f2;
	f3.print();

	Fraction f4 = f1 * 3;
	f4.print();

	Fraction f5=3*f2;
	f5.print();

	Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
	f6.print();
}
