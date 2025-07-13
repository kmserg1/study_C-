#include <iostream>
#include <vector>

int main(){
	int a{1};
	int b{2};
	int c{3};
	int d{4};
	int e{5};

	std::vector<int*>ptra {&a,&b,&c,&d,&e};

	for(int i=0;i<5;++i)
		std::cout << *ptra[i]++ << '\n';
	return 0;
}