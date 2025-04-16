#include <iostream>
#include <string>

enum class Monster_type
{
MONSTER_OGRE, 
MONSTER_GOBLIN, 
MONSTER_SKELETON, 
MONSTER_ORC, 
MONSTER_TROLL
};

struct Monster
{
Monster_type type;
std::string name;
int health;
};

void print_monster(Monster x)
{
	std::string type;
	if (x.type==Monster_type::MONSTER_OGRE)
		type="Ogre";
	else if (x.type==Monster_type::MONSTER_GOBLIN)
		type="Goblin";
	else if (x.type==Monster_type::MONSTER_GOBLIN)
	type="Goblin";
	else if (x.type==Monster_type::MONSTER_SKELETON)
		type="Skeleton";
	else if (x.type==Monster_type::MONSTER_ORC)
	type="Orc";
	else if (x.type==Monster_type::MONSTER_TROLL)
		type="Troll";
	else
	type="Something went wrong";

	std::cout << "This " << type << " is named "  << x.name << " and has " << x.health << " heath. " << std::endl;

}

main(){
Monster john{Monster_type::MONSTER_GOBLIN, "John", 170};
Monster james{Monster_type::MONSTER_ORC, "James", 35};
print_monster(john);
print_monster(james);
}

