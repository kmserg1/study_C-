#include <iostream>
#include <string>


class Monster {

public:
	enum MonsterType {
		Dragon, 
		Goblin, 
		Ogre, 
		Orc, 
		Skeleton,
		Troll, 
		Vampire, 
		Zombie, 
		MAX_MONSTER_TYPES
	};

private:
	MonsterType m_type;
	std::string m_name;
	int m_health;
};

int main(){return 0;}