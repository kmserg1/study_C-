#include <iostream>
#include <string>
#include <ctime> // для time()
#include <cstdlib> // для rand() и srand()


class Monster {

public:
	enum MonsterType {
		DRAGON, 
		GOBLIN, 
		OGRE, 
		ORC, 
		SKELETON,
		TROLL, 
		VAMPIRE, 
		ZOMBIE, 
		MAX_MONSTER_TYPES
	};

private:
	MonsterType m_type;
	std::string m_name;
	int m_health;

public:
	Monster(MonsterType type=TROLL, std::string name="vova", int health=3):
		m_type{type}, m_name{name}, m_health{health}
	{
	}

	std::string getTypeString(){
		switch (m_type){
			case DRAGON: return "dragon";
			case GOBLIN: return "goblin";
			case OGRE: return "ogre";
			case ORC: return "orc";
			case SKELETON: return "skeleton";
			case TROLL: return "troll";
			case VAMPIRE: return "vampire";
			case ZOMBIE: return "zombie";
			default: return "ERROR";
		}
	}

	friend void print(Monster&);
};


void print(Monster &a){
std::cout << a.m_name << " is the " << a.getTypeString() << " that has "<< a.m_health << " health points.\n";
}


class MonsterGenerator{
private:


public:

	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX)+ 1.0); // используем static, так как это значение нужно вычислить единожды
		// Равномерно распределяем вычисление значения из нашего диапазона
		return static_cast<int>(rand() * fraction * (max-min + 1) + min);
	}

	Monster::MonsterType randType(){
		return static_cast<Monster::MonsterType>(getRandomNumber(0,Monster::MAX_MONSTER_TYPES-1));
	}

	static std::string randName(){
		static const int qtyNames{10};
		static std::string name[qtyNames] {"Name1","Name2","Name3","Name4","Name5","Name6","Name7","Name8","Name9","Name10"};
		return name[getRandomNumber(0,qtyNames-1)];
	}

	int randHealth(){
		const int qtyHealth{99};
		return getRandomNumber(1,qtyHealth);
	}

	static Monster generateMonster(){
		int t {static_cast<Monster::MonsterType>(randType())};
		std::string n {randName()};
		int h {randHealth()};
		Monster randMonster(static_cast<Monster::MonsterType>(t), n, h);
		return randMonster;
	}
	
};


 
int main()
{
	srand(static_cast<unsigned int>(time(0))); // используем системные часы в качестве стартового значения
	rand(); // пользователям Visual Studio: делаем сброс первого случайного числа
	MonsterGenerator mG;
	Monster m = mG.generateMonster();
	print(m);
 
    return 0;
}
