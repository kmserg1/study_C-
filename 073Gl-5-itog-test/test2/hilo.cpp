#include <iostream>
#include <cstdlib>
#include <ctime>


int getRandomNumber(int min, int max)
{
 	static const double fraction=1.0/(static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max-min+1) + min);
}

int main(){
	const int nSprob{7};
 	srand(static_cast<unsigned int>(time(0))); 
	int answer{getRandomNumber(1,100)};
	int ntry;
	char loop;
	int i;
	do
	{
		// pervoe soobschenie
		std::cout << "Це гра Hi-Lo. Граємо! Я загадала число від 1 до 100. Ти повинен вгадувати, а я буду казати \"Моє число більше / менше\". В тебе " << nSprob << " спроб..\n";
		
		for (i=1;i<=nSprob;++i){ // cikl - sem popitok ugadat. esli ugadal - pozdravlenie і break */
			std::cout << "Спроба № " << i << ". Вгадай число: ";
			std::cin >> ntry;
            if(answer<ntry)
                	std::cout << "Моє число менше\n";
                    
                	std::cout << "Моє число більше\n";
            else if(answer==ntry){
                	std::cout << "Ти вгадав! Ура! Перемога!!!\n";
                	break;
            }			
		}
		if (i>nSprob) 
			std::cout << "Ти програв. Правильна відповідь була " << answer << "\n";

		std::cout << "Чи не хочеш зіграти ще раз? Якщо хочеш, натисни літеру 'y'\n";
		std::cin >> loop;
		if(loop!='y') break;
	} 
	while (true);
	return 0;
}