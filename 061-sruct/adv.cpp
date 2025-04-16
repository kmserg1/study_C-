#include <iostream>

struct Advertising
{
	int pokazy;
	int percent_press;
	double aver_earnings;
};

void printAdv(Advertising x)
{
std::cout << "Показов за день: " << x.pokazy<< std::endl;
std::cout << "Процент нажатий " << x.percent_press << std::endl;
std::cout << "Плата за нажатие: " << x.aver_earnings<< std::endl;
std::cout << "Заработок за день: " << (x.pokazy+0.0)*(static_cast<double>(x.percent_press)/100)*x.aver_earnings << std::endl;
}


int main()
{
Advertising ad;
std::cout << "Введите число показов за день (целое): ";
std::cin >> ad.pokazy;
std::cout << "Введите процент нажатий (целое): ";
std::cin >> ad.percent_press;
std::cout << "Введите плату за нажатие (с плавающей точкой): ";
std::cin >> ad.aver_earnings;
printAdv(ad);
return 0;
}
