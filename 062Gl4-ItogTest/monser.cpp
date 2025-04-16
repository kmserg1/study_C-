#include <iostream>
#include <string>

enum Monster_type
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
	if (x.type==MONSTER_OGRE)
		type="Ogre";
	else if (x.type==MONSTER_GOBLIN)
		type="Goblin";
	else if (x.type==MONSTER_GOBLIN)
	type="Goblin";
	else if (x.type==MONSTER_SKELETON)
		type="Skeleton";
	else if (x.type==MONSTER_ORC)
	type="Orc";
	else if (x.type==MONSTER_TROLL)
		type="Troll";
	else
	type="Something went wrong";

	std::cout << "This " << type << " is named "  << x.name << " and has " << x.health << " heath. " << std::endl;

}

main(){
Monster john, james;

john.type=MONSTER_GOBLIN;
john.name="John";
john.health=170;

james.type=MONSTER_ORC;
james.name="James";
james.health=35;

print_monster(john);
print_monster(james);
}
