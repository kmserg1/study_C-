#include <iostream>// для std::cout и std::endl

// Объявление функции doPrint(), которую мы будем вызыват
void doPrint() {
std::cout <<"In doPrint()" <<std::endl;
}

// Объявление функции main()
int main()
{
std::cout << "Starting main()" << std::endl;
doPrint(); // прерываем выполнение функции main() вызовом функции doPrint(). Функция main() в данном случае является caller-ом
std::cout << "Ending main()" << std::endl;
return 0;
}
