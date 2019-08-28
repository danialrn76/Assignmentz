#pragma once

#include <string> 
#include <iostream>
#include <time.h>

using namespace std;

class Hero
{
public:
	Hero();
	~Hero();

	int health = 100;
	int attack = 20;

	void SetHeroName(string newHeroName);

	void takeHit();
	
	string GetHeroName();

	

private:
	string heroName;


};

