#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib> // для rand() и srand()
#include <ctime> // для time()

int getRandomNumber(int min, int max)
{	srand(static_cast<unsigned int>(time(0))+rand());
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// Равномерно распределяем генерацию значения из диапазона
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

class Creature
{
protected:
	std::string m_name;
	char m_symb;
	int m_health;
	int m_damageAbilities;
	int m_gold;
public:
	Creature(std::string n="", char s=' ', int h=0, int dA=0, int gold=0) 
		: m_name(n), m_symb(s), m_health(h), m_damageAbilities(dA), m_gold(gold)
	{
	}
	std::string getName(){ return m_name; }
	char getSymbol(){ return m_symb; }
	int getHealth() { return m_health; }
	void changeHealth(int i) { m_health+=i; }
	int getDamageAbilities() { return m_damageAbilities; }
	int getGold() { return m_gold; }
	
	void reduceHealth(int loss) // уменьшает здоровье Creature на указанное целочисленное значение
	{
		m_health-=loss; 
	}


	bool isDead() // возвращает true, если здоровье Creature равно 0 или меньше;
	{
		return (m_health <= 0) ;
	}

	void addGold(int profit) // добавляет золото Creature-у.
	{
		m_gold+=profit;
	}
	void getInfo()
	{
	std::cout << "ім'я: " << m_name << ", здоров'я: " << m_health 
				  << ", можливість зроити шкоду: "<< m_damageAbilities 
				  << ", золото: "<< m_gold << "\n";	
	}

};

class Monster;

class Player: public Creature
{
private:
	int m_level;
public:
	Player(std::string name="", char c='@', int health=10, int damageAbilities=1, int gold=0, int level=1)
		: Creature(name,'@',health,damageAbilities, gold), m_level(level)

	{
		if(m_name.length()==0) // якщо не пердали ім'я при створенні, то вводимо вручну
		{
			std::cout << "Enter your name: ";
			std::cin >> m_name;
		}
	}
	
	bool getLevel() { return m_level; }
	bool hasWon() { return m_level >=20; }
	void levelUp()
	{
		++m_level;
		++m_damageAbilities;
	}

	void getInfo()
	{
		std::cout << "рівень: " << m_level << "\n Також ";
		Creature::getInfo();
	}
	
	int fightMonster(Monster &m)
	{
		return 1;
	}
	
	int attackMonster(Monster &m)
	{
		return 1;
	}

};


class Monster : public Creature
{
public:
	enum Type
	{
		DRAGON,
		ORC,
		SLIME,
		MAX_TYPES
	};
	struct MonsterData
	{
		std::string name;
		char symbol; 
		int health, damage, gold;
	};
	
	static MonsterData monsterData[Monster::MAX_TYPES];
	
	Monster(Type type): Creature(monsterData[type].name, monsterData[type].symbol, monsterData[type].health, monsterData[type].damage, monsterData[type].gold)
	{
	}

	static Monster::Type getRandomMonster()
	{
		int i;
		i=getRandomNumber(0, Monster::MAX_TYPES-1);
		return static_cast<Type>(i);
	}
	
	void attackPlayer(Player &p)
	{
		p.changeHealth(-m_damageAbilities);
	}
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{"dragon",'D',20,4,100},
	{"orc",'o',4,2,25},
	{"slime",'s',1,1,10}
};

 
int main()
{
	srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
	rand(); // сбрасываем первый результат
 
	while(1)
	{
		/*create player*/
		std::cout << "Введи своє ім'я (Q - віхід): ";
		std::string name;
		std::cin >> name;
		if(name=="Q") 
			return 0;
		Player p(name);
		std::cout << "Вітаю, " << p.getName() << "! Твій символ '" << p.getSymbol() << "\n";
		p.getInfo();
		std::cout  << "\n";
		// Game loop
		while(1)
		{
			Monster m(Monster::getRandomMonster()); // створили випадкового монстра
			std::cout << "\nНазустріч йде " << m.getName() << "\n";
			m.getInfo();
			std::cout << "\nЩо ти будеш робити (f - Fight or r - Run) ? ";
			char answer;
			std::cin >> answer;

			if(answer == 'f')
			{
				p.attackMonster(m);
				std::cout << "Атакували монстра\n";
			}
			else
			{
				if(answer == 'r')
				{
					std::cout << "Спроба втекти; вірогідність 50%\n";
					bool success {static_cast<bool>(getRandomNumber(0, 1))};
					if(success)
					{
						std::cout << "Вдало втекли\n";
						continue;
					}
					else
					{
						m.attackPlayer(p);
						std::cout << "Монстр атакував нас\n Зараз маємо ";
						p.getInfo();
					}
				}
				else
				{
					return 0;
				}
			}

			if (p.hasWon())  //якщо виграв, то кінець гри
			{
				std::cout << "Ти Виграв!!!\n";	
				p.getInfo();
				break;
			}
		
			if(p.isDead())
			{
				std::cout << "Ти  Програв!!! \n For information:\n ";
				p.getInfo();
				break;
			}
		}
		
	}
	/*for (int i = 0; i < 10; ++i)
	{
		Monster m = Monster::getRandomMonster();
		std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
	}*/
 
	return 0;
}
