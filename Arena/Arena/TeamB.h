#pragma once
#include <iostream>
#include <string>
#include "Hero.h"
#include <vector>

using namespace std;

class TeamB : Hero
{
public:
	TeamB();
	~TeamB();

	Hero Michael;
	Hero Trevor;
	Hero Lamar;

	vector<Hero> Heroesb;

	
	
};

