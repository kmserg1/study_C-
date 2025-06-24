/*
написать класс для реализации значений типа с фиксированной точкой с двумя цифрами после точки
(например, 11.47, 5.00 или 1465.78). Диапазон класса должен быть от -32768.99 до 32767.99, в дробной части могут
быть любые две цифры, не допускайте проблем с точностью.
*/

#include <iostream>
#include <cassert>
#include <cmath>

class Fixed2{
private:
	int16_t m_int;
	int8_t m_frac;
	const int8_t m_frac_limit{100};
	const int16_t m_int_limit{32767};
	
public:
	Fixed2(int16_t int_part=0, int8_t frac_part=0): m_int(int_part),m_frac(frac_part)
	{
		assert(m_frac > -m_frac_limit && m_frac < m_frac_limit);
		assert(m_int >= -m_int_limit-1 && m_int <= m_int_limit);
	}

        Fixed2(double a)
	{
		m_int=static_cast<int16_t>(round(a));
		m_frac=static_cast<int8_t>(round((a-round(a))*100));

	}


	void print()
	{
		std::cout << static_cast<int>(m_int) <<'.' << static_cast<int>(m_frac) << '\n';
	}

	Fixed2 operator-() const
	{
		Fixed2 a(-m_int,m_frac);
		return a;
	}

	Fixed2& operator= (const Fixed2 &a)
	{
		if (this == &a) // Проверка на самоприсваивание
			return *this;
		m_int=a.m_int;
		m_frac=a.m_frac;
		return *this;
	}
	
	operator double()
	{
		double a{static_cast<double>(m_int)};
		a+=static_cast<double>(m_frac)/100;
		return a;
	}

	friend std::ostream& operator<< (std::ostream &out, Fixed2 &first);
	friend std::istream& operator>> (std::istream &in, Fixed2 &first);
	friend Fixed2 operator+ (const Fixed2 &first, const Fixed2 &second);
	friend Fixed2 operator- (const Fixed2 &first, const Fixed2 &second);
	friend Fixed2 operator* (Fixed2 &first,Fixed2 &second);
	friend Fixed2 operator/ (Fixed2 &first,Fixed2 &second);
	friend bool operator== (const Fixed2 &a, const Fixed2 &b);
/*
Fixed2 operator+= (Fixed2 &first);
Fixed2 operator-= (Fixed2 &first);
Fixed2 operator*= (Fixed2 &first);
Fixed2 operator/= (Fixed2 &first);
*/
};


bool operator== (const Fixed2 &a, const Fixed2 &b)
{
	return ((a.m_int==b.m_int) && (a.m_frac==b.m_frac));
}

std::istream& operator>> (std::istream &in, Fixed2 &first)
{
	double a;
	in>>a;
	first.m_int=round(a);
	first.m_frac=round((a-round(a))*100);
//	assert(first.m_int<=-first.m_int_limit-1 && first.m_int>=first.m_int_limit);
	return  in;
}




std::ostream& operator<< (std::ostream &out, Fixed2 &first)
{
	
	if(first.m_int>=0 && first.m_frac>=0 ) //невід'ємні частини числа, мінусу у виводі нема
	{
		if(abs(first.m_frac<10))
			out << static_cast<int>(first.m_int) <<".0" << static_cast<int>(first.m_frac);
		else
			out << static_cast<int>(first.m_int) <<'.' << static_cast<int>(first.m_frac);
	}
	else //є хоч одна від'ємна частина, мінусу у виводі є
	{
		out << '-';
		if(abs(static_cast<int>(first.m_frac))<10) //якщо дробова частина менше 10, то виводимо 0 перед нею
			out << abs(static_cast<int>(first.m_int)) <<".0" << abs(static_cast<int>(first.m_frac));
		else
			out << abs(static_cast<int>(first.m_int)) <<'.' << abs(static_cast<int>(first.m_frac));
	}

	return out;
}
                                                
Fixed2 operator+ (const Fixed2 &first,const Fixed2 &second)
{
	assert(first.m_int+second.m_int >= -first.m_int_limit-1 && first.m_int+second.m_int <= first.m_int_limit);
	Fixed2 a;
	a.m_int=first.m_int+second.m_int;
	a.m_frac=first.m_frac-second.m_frac;
	if(a.m_frac<100)
	{
		a.m_int-=1;
		a.m_frac+=100;
	}
	if(a.m_frac>100)
	{
		a.m_int+=1;
		a.m_frac-=100;
	}

	return a;
}

Fixed2 operator- (const Fixed2 &first,const Fixed2 &second)
{
	Fixed2 a;
	a=first+(-second);
	return a;
}

Fixed2 operator* (Fixed2 &first,Fixed2 &second)
{
	Fixed2 a;
	double dfirst(static_cast<double>(first));
	double dsecond(static_cast<double>(second));
	double c(dfirst*dsecond);
	a=static_cast<Fixed2>(c);
	return a;
}

Fixed2 operator/ (Fixed2 &first,Fixed2 &second)
{
	Fixed2 a;
	double dfirst(static_cast<double>(first));
	double dsecond(static_cast<double>(second));
	double c(dfirst/dsecond);
	a=static_cast<Fixed2>(c);
	return a;
}

void SomeTest()
{
	std::cout << std::boolalpha;
	std::cout <<(Fixed2(0.75) + Fixed2(1.23)== Fixed2(1.98))<< '\n'; //обазначенияположительные, никакого
	std::cout <<(Fixed2(0.75) + Fixed2(1.50)== Fixed2(2.25))<< '\n'; //обазначенияположительные, переполн
	std::cout <<(Fixed2(-0.75)+Fixed2(-1.23)== Fixed2(-1.98)) <<'\n';// оба значения отрицательные,никак
	std::cout <<(Fixed2(-0.75)+Fixed2(-1.50)== Fixed2(-2.25)) <<'\n';// оба значения отрицательные,переп
	std::cout <<(Fixed2(0.75) + Fixed2(-1.23) ==Fixed2(-0.48))<< '\n'; //второе значение отрицательное,ник
	std::cout <<(Fixed2(0.75) + Fixed2(-1.50) ==Fixed2(-0.75))<< '\n'; //второе значение отрицательное,воз
	std::cout <<(Fixed2(-0.75)+Fixed2(1.23) ==Fixed2(0.48)) <<'\n';// первоезначениеотрицательное, ника
	std::cout <<(Fixed2(-0.75)+Fixed2(1.50) ==Fixed2(0.75)) <<'\n';// первоезначениеотрицательное, возм
}


int main()
{
//	SomeTest();
	Fixed2 a(-0.75);
	Fixed2 b(1.23);
	Fixed2 c(1.25);
	Fixed2 e;
	bool res;
	e=a+b;
	res=(c==e);
	std::cout << std::boolalpha;
	std::cout << res <<'\n';
	std::cout << -a << '\n';
	std::cout << "Enter a number:"; //введите 5.678
	std::cin >> a;
	std::cout << "You entered: " << a << '\n';
	return 0;
}
