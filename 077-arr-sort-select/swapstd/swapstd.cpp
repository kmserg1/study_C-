#include <iostream> 
#include <algorithm> // для std::swap. В C++11 используйте заголовок <utility>
 
int main()
{
    int a = 3;
    int b = 5;
    std::cout << "Before swap: a = " << a << ", b = " << b << '\n';
    std::swap(a, b); // меняем местами значения переменных a и b
    std::cout << "After swap:  a = " << a << ", b = " << b << '\n';
}