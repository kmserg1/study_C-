#include <iostream>

struct Rational
{
int numerator;
int denominator;
};

double multiply(Rational n1, Rational n2)
{
double res;
res=static_cast<double>(n1.numerator)*static_cast<double>(n2.numerator);
res/=static_cast<double>(n1.denominator)*static_cast<double>(n2.denominator);
std::cout << res << std::endl;
return res;
}

int main()
{
Rational num1, num2;
std::cout << "Введите числитель первого числа (целое):";
std::cin >> num1.numerator;
std::cout << "Введите знаменатель первого числа (целое):";
std::cin >> num1.denominator;

std::cout << "Введите числитель второго числа (целое):";
std::cin >> num2.numerator;
std::cout << "Введите знаменатель второго числа (целое):";
std::cin >> num2.denominator;

std::cout << "Результат перемножения этих двух чисел: ";
multiply(num1, num2);
return 0;
}
