/*
Напишите свой собственный класс-массив целых чисел IntArray (не используйте std::array или std::vector). Пользователи
должны передавать размер массива при создании объекта этого класса, а сам массив (переменная-член) должен
выделяться динамически. Используйте стейтменты assert для проверки передаваемых значений, а также свой конструктор
копирования и перегрузку оператора присваивания, если это необходимо, чтобы следующий код:
*/

#include <iostream>
#include <cassert>

class IntArray{
private:
	int *m_arr;
	int m_size;
public:
	IntArray(int size) : m_size(size)
	{
		assert(size>0);
		m_arr=new int[m_size];
	}

	~IntArray() 
	{
		delete[] m_arr; 
		m_arr = nullptr;
	}

	IntArray(const IntArray &ia) : m_size(ia.m_size)
	{
		m_arr=new int[m_size];
		for(int i=0; i<m_size;++i)
			m_arr[i]=ia.m_arr[i];
	}

	int& operator[] (const int index);

 	IntArray& operator= (const IntArray &ia)
 	{
 		// Выполняем копирование значений
                m_size=ia.m_size;
		for(int i=0; i<m_size;++i)
			m_arr[i]=ia.m_arr[i];
 		// Возвращаем текущий объект, чтобы иметь возможность связать в цепочку выполнение нескольких операций присваивания
 		return *this;
 	}


	friend std::ostream& operator<<(std::ostream &in, IntArray &ia);

};

int& IntArray::operator[] (const int index)
{
	return m_arr[index];
}

std::ostream& operator<<(std::ostream &in, IntArray &ia)
{
	for(int i=0; i<ia.m_size;++i)
		in << ia.m_arr[i];
	return in;
}


IntArray fillArray()
{
	IntArray a(6);
	a[0]=6;
	a[1]=7;
	a[2]=3;
	a[3]=4;
 	a[4]=5;
 	a[5]=8;

 	return a;
 }

 int main()
 {
 	IntArray a = fillArray();
 	std::cout << a <<'\n';

 	IntArray b(1);
 	a = a;
 	b = a;

 	std::cout <<b<<'\n';

 	return 0;
 }
