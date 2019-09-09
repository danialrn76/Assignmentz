#include "Marine.h"



Marine::Marine()
{
	/*health = 50;*/
}


Marine::~Marine()
{
}
//
//int Marine::health() {
//	return 50;
//}

int Marine::attack()
{
	return 100;
}

void Marine::takeDamage(int damage)
{
	health -= damage;
}
//int Marine::health() {
//	return 100;
//}
