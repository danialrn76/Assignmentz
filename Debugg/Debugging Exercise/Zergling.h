#pragma once

#include "Entity.h"
class Zergling : public Entity
{
public:
	Zergling();
	~Zergling();
	int health = 100;
	int attack();
	void takeDamage(int damage);

};

