#include <iostream>

int main(){
	int a,b;
	char op;
	std::cout << "введіть перше ціле число: ";
	std::cin >> a;
	std::cout << "введіть друге ціле число: ";
	std::cin >> b;
	while(true){
		std::cout << "введіть арифметичну операцію (+ , - , * чи /) : ";
		std::cin >> op;
		if(op=='+' || op=='-' || op=='*' || op=='/') 
			break;
		else
			std::cout << "Помилка в операції. Спробуйте ще раз: \n";
	}
}
