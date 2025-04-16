#include <iostream>

int doubleNumber(int a)
{
return 2*a;
}

int main(){
std::cout << "Введіть ціле число: ";
int i;
std::cin >> i;
std::cout << doubleNumber(i) << std::endl;
return 0;
}
