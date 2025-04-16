#include <iostream>

namespace animals
{
enum animal {
	chicken, 
	lion, 
	giraffe, 
	elephant, 
	duck,  
	snake,
	num_animals
};
}

int const paws[animals::num_animals]={2,4,4,4,2,0};

int main(){
	std::cout << "Слон має " << paws[animals::lion] << " лап\n";
}
