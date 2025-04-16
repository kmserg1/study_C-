// conversion decimal to bin

#include <iostream>


int decimal2bin(unsigned int n){
    int res;
	if(n>0){
		res=decimal2bin(n/2);
		(n%2)?std::cout << '1':std::cout << '0';
		}
	else
		res=0;

    return res;
}


int main(){
	int inp;
	std::cout << "Введіть ціле число: ";
	std::cin >> inp;
	decimal2bin(static_cast<unsigned int>(inp));
	std::cout << "\n";
    //std::cout << 1/2 << "\n";
    return 0;
}
