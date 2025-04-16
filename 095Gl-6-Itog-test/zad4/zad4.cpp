#include <iostream>

void prnChr(const char *s){
	for(; *s!=0;++s)
		std::cout << *s;
}

main(){
	//char *mystring {"Hello world!"};
    prnChr("Hello world!");
	std::cout << "\n";
	return 0;
}
