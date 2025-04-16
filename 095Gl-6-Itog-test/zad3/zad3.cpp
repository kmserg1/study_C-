#include <iostream>

void swapint(int &i, int &j){
	int k;
	k=i;
	i=j;
	j=k;	
}

int main(){
	int a{15}, b{5};
	std::cout << "Before\n a=" << a << "; b=" << b << "\n";
	swapint(a,b);
	std::cout << "After\n a=" << a << "; b=" << b << "\n";
}
