#include "pch.h"
#include "Hero.h"


Hero::Hero()
{
}


void Hero::SetHeroName(string NewHeroName)
{
	heroName = NewHeroName;
}

void Hero::takeHit()
{

	health -= attack;
}

string Hero::GetHeroName()
{
	return heroName;
}

Hero Hero::itSelf()
{
	return Hero();
}





Hero::~Hero()
{
}
