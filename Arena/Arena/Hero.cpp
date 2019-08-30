#include "pch.h"
#include "Hero.h"


Hero::Hero()
{
}

//setting a name for the heero
void Hero::SetHeroName(string NewHeroName)
{
	heroName = NewHeroName;
}

//substracting attak value from health
void Hero::takeHit()
{

	health -= attack;
}


//this is used to desplay the hero's name, it retunr the hero name value
string Hero::GetHeroName()
{
	return heroName;
}
	


Hero::~Hero()
{
}
