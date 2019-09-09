#include "Zergling.h"



Zergling::Zergling()
{
}


Zergling::~Zergling()
{
}


int Zergling::attack()
{
	return 20;
}


void Zergling::takeDamage(int damage)
{
	health -= damage;
	
}
