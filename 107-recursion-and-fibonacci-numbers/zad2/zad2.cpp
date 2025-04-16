// sum all figures of noumber

#include <iostream>
#include <string>

int sumFigures(int n){
int sum {0};
if(n>0)
    sum=n%10+sumFigures(n-n%10);
return sum;
}

int main(){
	int inp;
	std::cout << "Введіть ціле число: ";
	std::cin >> inp;
	std::cout << sumFigures(inp) << "\n";
    return 0;
}
