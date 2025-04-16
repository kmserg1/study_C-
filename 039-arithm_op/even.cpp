#include <iostream>

bool isEven(int i){
if(i%2==0) 
	return true;
return false;
}

int main(){
std::cout << "Введите целое число: ";
int i;
std::cin >> i;
if(isEven(i))
	std::cout << "Число " << i << " является четным\n";
else
    std::cout << "Число " << i << " является НЕчетным\n";
return 0;
}