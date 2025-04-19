#include <iostream>
#include "Date.h"

int main(){
	Date first(10,5,2025);
	Date two(9,1,2024);
	std::cout << first.getDay()<<'\n';
	std::cout << first.getMonth()<<'\n';
	std::cout << first.getYear()<<'\n';
	std::cout << '\n';
	std::cout << two.getDay()<<'\n';
	std::cout << two.getMonth()<<'\n';
	std::cout << two.getYear()<<'\n';
}