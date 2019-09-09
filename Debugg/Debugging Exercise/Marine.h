#pragma once
#include "Entity.h"

class Marine : public Entity
{
public:
	Marine();
	~Marine();
	int health = 100;
	int attack();
	void takeDamage(int damage);
	
};

