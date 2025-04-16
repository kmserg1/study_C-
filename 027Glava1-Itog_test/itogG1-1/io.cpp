#include <iostream>

int readNumber()
{
int i;
std::cout << "Введіть ціле число: ";
std::cin >> i;
return i;
}

void writeAnswer(int i)
{
std::cout << "Результат: " << i << std::endl;
return;
}
