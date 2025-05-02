#include <iostream>
#include <string>


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


int main()
{
	Monster jack(Monster::ORC, "Jack", 90);
	Monster vova;
	print(jack);
	print(vova);
	return 0;
}
