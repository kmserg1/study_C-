#include <iostream>

int main(){
	int array[] = { 7, 5, 6, 4, 9, 8, 2, 1, 3 };
	const int arrayLength = sizeof(array) / sizeof(array[0]);
	int num {-1};

	for(;true;){
		std::cout << "Введіть число від 1 до 9: ";
		std::cin >> num;
		if (std::cin.fail() or !(num>=1 and num<=9))
		{
			std::cin.clear(); 
			std::cin.ignore(32767, '\n'); 
		}
		else 
		{
			std::cout << "\n";
			break;
		}
	}
    int index;
	std::cout << "Масив:\n";
	for(int i=0; i<arrayLength; ++i){
		std::cout << array[i] << " ";
		if(array[i]==num) index=i;
	}
	std::cout << "\n Число " << num << " стоїть на " << index+1 << " місці \n";
	return 0;
}

