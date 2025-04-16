#include <iostream>
#include <string>

int main()
{
	std::cout << "Введите свои имя и фамилию: ";
	std::string fullname;
	std::getline(std::cin, fullname);

	//std::cin.ignore(32767, '\n');

	std::cout << "Введите своЙ возраст: ";
	int age;
	std::cin >> age;

	float yearsOnLetter;

        yearsOnLetter=static_cast<float>(age)/fullname.length();
	std::cout << "На каждую букву вашего полного имени приходится " << yearsOnLetter << " лет." << std::endl;

}