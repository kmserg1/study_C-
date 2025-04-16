// conversion decimal to bin

#include <iostream>
#include <string>

int decimal2bin(int n){
	(n%2)?std::cout << '0':std::cout << '1';
	if(n>0)
		return decimal2bin(n/2);
	else 
		return n;
}

int main(){
	int inp;
	std::cout << "Введіть ціле число: ";
	std::cin >> inp;
	std::cout << decimal2bin(inp) << "\n";
    return 0;
}
