#include <iostream>

typedef int (*arithmeticFcn)(int,int);

int add(int a, int b){
	return a+b;
}
int subtract(int a, int b){
	return a-b;
}
int multiply(int a, int b){
	return a*b;
}
int divide(int a, int b){
	return a/b;
}

arithmeticFcn getArithmeticFcn(char op){
	if(op=='+')
		return add;
	else if(op=='-')
		return subtract;
	else if(op=='*')
		return multiply;
	else if(op=='/')
		return divide;
	else
	{
		std::cout << "getArithmeticFcn отримала помилковий аргумент op. Це " << op << ". Шукайте помилку.\n";
		return 0;
	}
}

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
	arithmeticFcn arfunc;
	arfunc=getArithmeticFcn(op);
	std::cout << a << op << b << "=" << arfunc(a,b) << "\n";
	return 0;
}
