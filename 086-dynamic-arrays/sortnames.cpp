#include <iostream> 
#include <string> 
#include <algorithm> // для std::swap

void sortSringAr(std::string *ar, int length){
 
	// Перебираем каждый элемент массива (кроме последнего, он уже будет отсортирован к тому времени, когда мы до него доберемся)
	for (int startIndex = 0; startIndex < length - 1; ++startIndex)
	{
		// В переменной smallestIndex хранится индекс наименьшего значения, которое мы нашли в этой итерации.
		// Начинаем с того, что наименьший элемент в этой итерации - это первый элемент (индекс 0)
		int smallestIndex = startIndex;
 
		// Затем ищем элемент поменьше в остальной части массива
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			// Если мы нашли элемент, который меньше нашего наименьшего элемента,
			if (ar[currentIndex] < ar[smallestIndex])
				// то запоминаем его
				smallestIndex = currentIndex;
		}
 
		// smallestIndex теперь наименьший элемент. 
	        // Меняем местами наше начальное наименьшее число с тем, которое мы обнаружили
		std::swap(ar[startIndex], ar[smallestIndex]);
	}
}

 
int main()
{
int numNames{7};
//std::cout << "Enter countities of nasmes: ";
//std::cin >> numNames;

std::string *arNames = new std::string[numNames]{
    "Alex",
    "Syn",
    "Bob",
    "Zack",
    "Jason",
    "John",
    "Marry"
};

/*for(int i=0; i<numNames; ++i){
	std::cout << "Enter  " << i+1 <<"-th name: ";
	std::cin >> arNames[i];
	}*/

sortSringAr(arNames, numNames);

std::cout << "Sorted names:\n";
// Теперь, когда весь массив отсортирован - выводим его на экран
for (int index = 0; index < numNames; ++index)
	std::cout << arNames[index] << '\n';
delete[] arNames;
arNames = nullptr;
return 0;
}
