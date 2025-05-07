#include <iostream>

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
 	Fraction(int numerator=0, int denominator=1):
 		m_numerator(numerator), m_denominator(denominator)
 	{
 		// Мы поместили методreduce() в конструктор,чтобы убедиться, что все дроби, которые у насесть,
 		// Вседроби, которыеперезаписаны, должны быть повторно уменьшены
 		reduce();
 	}

  	// Делаем функцию nod() статической, чтобы она могла быть частью класса Fraction и при этом, для её использования, нам не требовалось бы создавать объект класса Fraction
 	static int nod(int a, int b)
 	{
 		return b == 0 ? a : nod(b, a % b);
 	}

 	void reduce()
 	{
 		int nod = Fraction::nod(m_numerator, m_denominator);
 		m_numerator /=nod;
 		m_denominator /= nod;
 	}

 	friend Fraction operator*(const Fraction &f1, const Fraction &f2);
 	friend Fraction operator*(const Fraction &f1, int value);
 	friend Fraction operator*(int value, const Fraction &f1);

 	friend std::istream& operator>>(std::istream &in, Fraction &f);
 	friend std::ostream& operator<<(std::ostream &out, const Fraction &f);


 	void print()
 	{
 		std::cout << m_numerator << "/" << m_denominator << "\n";
 	}
 };

 Fraction operator*(const Fraction &f1, const Fraction&f2)
 {
 	return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
 }

 Fraction operator*(const Fraction &f1, int value)
 {
 	return Fraction(f1.m_numerator * value, f1.m_denominator);
 }

 Fraction operator*(int value, const Fraction &f1)
 {
 	return Fraction(f1.m_numerator * value, f1.m_denominator);
 }

std::istream& operator>>(std::istream &in, Fraction &f){
	in >> f.m_numerator;
	in >> f.m_denominator;
	return in;
}

std::ostream& operator<<(std::ostream &out, const Fraction &f){
	out << f.m_numerator << '/' << f.m_denominator << '\n';
	return out;
}

int main()
{

	Fraction f1;
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2;
	std::cout << "Enter fraction 2: ";
 	std::cin >> f2;

 	std::cout << f1 <<" * " << f2 <<" is " << f1 * f2 << '\n';

	return 0;
}
