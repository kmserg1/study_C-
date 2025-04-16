#include <iostream>

int getInteger1();

int main()
{
    int x = getInteger1();
    int y = getInteger1();
    std::cout << x << " + " << y << " is " << x + y << '\n';
    std::cout << x << " + " << y << " is " << x + y << '\n';
    std::cout << x << " + " << y << " is " << x + y << '\n';
    std::cout << x << " + " << y << " is " << x + y << '\n';
    std::cout << x << " + " << y << " is " << x + y << '\n';
    return 0;
}
