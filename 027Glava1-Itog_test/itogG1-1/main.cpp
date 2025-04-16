#include <iostream>
#include "io.h"

int main()
{
int a;
int b;
std::cout << "Введіть число a: \n";
a=readNumber();
std::cout << "Введіть число b: \n";
b=readNumber();
std::cout << "a+b=" << a+b << "\n";
}
