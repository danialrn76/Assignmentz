#include "Entity.h"



Entity::Entity()
{
}


Entity::~Entity()
{
}

int Entity::attack()
{
	return 0;
}

void Entity::takeDamage(int damage)
{
	health -= damage;
}

int Entity::isAlive()
{
	return health = 0;
}

int Entity::damage()
{
	return 0;
}

