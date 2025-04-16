#include <iostream>
#include <string>

int main(){
	std::string names[]{"Sasha", "Ivan", "John", "Orlando", "Leonardo", "Nina", "Anton", "Molly"};
	std::cout << "Enter one name: ";
	std::string onename;
	std::cin >> onename;
	for(const std::string &a: names)
		if(a==onename){
			std::cout << "The name " << onename << " is presented in array names\n";
            return 0;
        }
    std::cout << "The name " << onename << " is not presented in array names\n";
	return 0;
}
