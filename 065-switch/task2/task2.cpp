# include <iostream>
# include <string>

enum class Animal{
	PIG, 
	CHICKEN, 
	GOAT, 
	CAT, 
	DOG,
	OSTRICH
};

std::string getAnimalName(Animal x){
	switch(x){
		case Animal::PIG:
			return "pig";
		case Animal::CHICKEN:
			return "chicken";
		case Animal::GOAT:
			return "goat";
		case Animal::CAT:
			return "cat";
		case Animal::DOG:
			return "dog";
		case Animal::OSTRICH:
			return "ostrich";
		default:
			return "ERROR!";			
	}
}

int printNumberOfLegs(Animal x)
{
	switch(x){
		case Animal::CHICKEN:
		case Animal::GOAT:
			return 2;
		case Animal::CAT:
		case Animal::DOG:
		case Animal::OSTRICH:
		case Animal::PIG:
			return 4;
		default:
			return -1;
	}
}

int main(){
Animal p1{Animal::GOAT};
Animal p2{Animal::PIG};
std::cout << "A " << getAnimalName(p1) << " has " << printNumberOfLegs(p1) << " legs.\n";
std::cout << "A " << getAnimalName(p2) << " has " << printNumberOfLegs(p2) << " legs.\n";
}