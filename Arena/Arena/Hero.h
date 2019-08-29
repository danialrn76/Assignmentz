#pragma once

#include <string> 
#include <iostream>
#include <time.h>
#include <random>
#include <chrono>
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

	Hero itSelf();
	

private:
	string heroName;


};

