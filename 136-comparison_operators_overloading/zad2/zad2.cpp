#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Car
{
private:
	std::string m_company;
	std::string m_model;

public:
	Car(std::string company, std::string model)
		: m_company(company), m_model(model)
	{
	}

	friend bool operator== (const Car &c1, const Car &c2);
	friend bool operator!= (const Car &c1, const Car &c2);
	friend bool operator< (const Car &c1, const Car &c2);
	friend std::ostream& operator<< (std::ostream &in, const Car &car);
};

bool operator== (const Car &c1, const Car &c2)
{
	return (c1.m_company == c2.m_company &&
	c1.m_model == c2.m_model);
}

bool operator!= (const Car &c1, const Car &c2)
{
	return !(c1 == c2);
}

bool operator< (const Car &c1, const Car &c2){
	if(c1.m_company<c2.m_company) return true;
	if(c1.m_model<c2.m_model) return true;
	return false;
}

std::ostream& operator<< (std::ostream &in, const Car &car){
	in <<'(' << car.m_company << ", " << car.m_model << ')';
	return in;
}

int main()
{
	std::vector<Car> v;
	v.push_back(Car("Ford", "Mustang"));
 	v.push_back(Car("Renault", "Logan"));
	v.push_back(Car("Ford", "Ranger"));
	v.push_back(Car("Renault", "Duster"));

	std::sort(v.begin(), v.end()); // требуется перегрузка оператора < для класса Car

	for (auto &car : v)
		std::cout << car << '\n'; // требуется перегрузка оператора << для класса Car

	return 0;
}
