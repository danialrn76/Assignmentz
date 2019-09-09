#pragma once

#include <string> 
#include <iostream>
#include <time.h>
#include <random>
#include <chrono>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <thread>
#include <algorithm>
#include <Windows.h>
#include <cstdlib>
#include "pch.h"

using namespace std;
using namespace std::chrono;

class Hero
{
public:
	Hero();
	~Hero();



	int health = 100;


	int attack = rand() %  20 + 10;

	void SetHeroName(string newHeroName);

	void takeHit();
	
	string GetHeroName();

	
	

	private:
	
		string heroName;


};

