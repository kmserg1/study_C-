#include <iostream>

int factorial(int n){
	    return ((n>1) ? factorial(n-1)*n : n);
}

int main(){
int n{8};
std::cout << factorial(n)<<std::endl;
}
