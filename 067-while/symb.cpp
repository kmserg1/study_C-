#include <iostream>

int main(){
char symb{'a'};
while (symb<='z'){
	std::cout << symb << '\t' << static_cast<int>(symb)<< '\n';
	++symb;
	}
return 0;
}