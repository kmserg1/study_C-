#include <iostream>
#include <string>

class Fruit
{
protected:
	std::string m_name;
	std::string m_color;
public:
	Fruit(std::string n="", std::string c="") : m_name (n), m_color (c)
	{
	}

	std::string getName()
	{
		return m_name;
	}

	std::string getColor()
	{
		return m_color;
	}

};

class Apple: public Fruit
{
public:
	Apple(std::string c="") : Fruit("apple", c)
	{
	}



};

class GrannySmith: public Apple
{
public:
	GrannySmith(): Apple("green")
	{
		m_name="Granny Smith apple";
	}
};

class Banana: public Fruit
{
public:
	Banana(std::string c="yellow") : Fruit("banana", c)
	{
	}

};



int main()
{
	Apple a("red");
	Banana b;
	GrannySmith c;
 
	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
	
	return 0;
}
