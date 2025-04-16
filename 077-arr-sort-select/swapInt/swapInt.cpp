#include <iostream>

int swapInt(int* a, int* b){
	int c;
	c=*a;
	*a=*b;
	*b=c;
}

int main()
{
	int a = 3;
	int b = 5;
	std::cout<<"Before swap: a=" << a << ", b=" << b << '\n';
	swapInt(&a,&b); // меняем местами значения переменных a и b
 	std::cout << "After swap: a= " << a << ", b= " << b <<'\n';
}
