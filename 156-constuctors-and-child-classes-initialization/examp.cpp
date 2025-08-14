/*
Реализуем наш пример с Фруктом, о котором мы говорили на уроке No 153. Создайте родительский класс Fruit, который имеет
два закрытых члена: name (std::string) и color (std::string). Создайте класс Apple, который наследует свойства Fruit. У Apple
должен быть дополнительный закрытый член: fiber (тип double). Создайте класс Banana, который также наследует класс Fruit.
Banana не имеет дополнительных членов.
*/

#include <iostream>
#include <string>

class Fruit
{
private:
	std::string m_name;
	std::string m_color;
public:
	Fruit(std::string n="", std::string c="")
		: m_name(n), m_color(c)
	{
	}
	std::string getName()const {return m_name;}
	std::string getColor()const {return m_color;}

};

class Apple: public Fruit
{
private:
	double m_fiber;
public:
	Apple(std::string n, std::string c, double f)
		:Fruit(n,c), m_fiber(f)
	{
	}

	friend std::ostream& operator<< (std::ostream &out, const Apple &a);
};


std::ostream& operator<< (std::ostream &out, const Apple &a)
{
	out << "Apple(" << a.getName() << ", color=" << a.getColor() << ", fiber=" << a.m_fiber << ")";
	return out;
}


class Banana: public Fruit
{
public:
	Banana(std::string n, std::string c)
		:Fruit(n,c)
	{
	}

	std::ostream& operator<< (std::ostream &out)
	{
		out << "Banana(" << getName() << ", color=" << getColor() << ")";
		return out;
	}

};





//Следующий код:
int main()
{
	const Apple a("Reddelicious","red", 7.3);
	std::cout << a;
	std::cout << '\n';


	const Banana b("Cavendish","yellow");
	std::cout << b.getName();
	std::cout << '\n';


	return 0;
}

/*
Должен выдавать следующий результат:
Apple(Red delicious,red,7.3)
Banana(Cavendish, yellow)
*/
