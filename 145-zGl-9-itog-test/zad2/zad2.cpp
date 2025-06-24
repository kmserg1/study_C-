/*
Напишите класс Average, который будет вычислять среднее значение всех передаваемых ему целых чисел. 
Используйте два члена: первый должен быть типа int32_t и использоваться для вычисления суммы всех передаваемых чисел, 
второй должен быть типа int8_t и использоваться для вычисления количества передаваемых чисел. 
Чтобы найти среднее значение, нужно разделить сумму на количество.
*/
#include <iostream>

class Average{
private:
	int32_t m_sum;
	int8_t m_quantity;
public:
	Average(int32_t a=0) : m_sum(a), m_quantity(0)
	{
	}
	void print()
	{
			std::cout << "Numbers cuontity: " << m_quantity << ", Average value: " << (m_quantity<=0)?0:m_sum/m_quantity << '\n';
	}

	void add()
	{
		int i;
		std::cout << "Enter int number:";
		std::cin >> i;
		++m_quantity;
		m_sum+=i;
	}

	Average& operator+=(int i)
	{
		++m_quantity;
		m_sum+=i;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream &o, const Average &a);

};

std::ostream& operator<<(std::ostream &o, const Average &a)
{
	o << "Numbers quantity: " << static_cast<int>(a.m_quantity) << ", Average value: " << a.m_sum/a.m_quantity << '\n';
	return o;
}




//a) Следующий код функции main(): 

int main()
{
	Average avg;
	
	avg += 5;
	std::cout << avg << '\n'; // 5 / 1 = 5
	
	avg += 9;
	std::cout << avg << '\n'; // (5 + 9) / 2 = 7
 
	avg += 19;
	std::cout << avg << '\n'; // (5 + 9 + 19) / 3 = 11
 
	avg += -9;
	std::cout << avg << '\n'; // (5 + 9 + 19 - 9) / 4 = 6
 
	(avg += 7) += 11; // выполнение цепочки операций
	std::cout << avg << '\n'; // (5 + 9 + 19 - 9 + 7 + 11) / 6 = 7
 
	Average copy = avg;
	std::cout << copy << '\n';
 
	return 0;
}

/*Должен выдавать следующий результат:

5
7
11
6
7
7
*/