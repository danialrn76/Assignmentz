#pragma once
class Entity
{
public:
	Entity();
	~Entity();

	virtual int attack();
	virtual void takeDamage(int damage);
	int isAlive();
	int damage();
private:
	int health;
	int maxHealth;
};

