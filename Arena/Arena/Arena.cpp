// Arena.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <time.h>
#include <random>
#include <chrono>
#include <thread>
#include "TeamA.h"
#include "TeamB.h"
#include <string>
#include <time.h>
#include <algorithm>

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

int main()  
{
	TeamA a;
	TeamB b;



	Hero Cj;
	Hero Bigsmoke;
	Hero Ryder;


	Hero Michael;
	Hero Trevor;
	Hero Lamar;

	srand (time(NULL));


	int rnd = rand() % 2;
	/*int rndb = rand() % 2;*/

	Cj.SetHeroName("cj");
	Bigsmoke.SetHeroName("Big Smoke");
	Ryder.SetHeroName("Ryder");



	Michael.SetHeroName("Michael");
	Trevor.SetHeroName("Trever");
	Lamar.SetHeroName("Lamar");

	a.Heroesa.push_back(Cj);
	a.Heroesa.push_back(Bigsmoke);
	a.Heroesa.push_back(Ryder);



	b.Heroesb.push_back(Michael);
	b.Heroesb.push_back(Trevor);
	b.Heroesb.push_back(Lamar);

	


	bool gameState = true;




	while (gameState) {

		sleep_for(1300000000ns);

		cout << b.Heroesb[rnd].GetHeroName() << " shot " << a.Heroesa[rnd].GetHeroName() << "\n";

		a.Heroesa[rnd].takeHit();

		cout << a.Heroesa[rnd].GetHeroName() << "'s health is " << a.Heroesa[rnd].health << "\n\n";

		sleep_for(1300000000ns);

		cout << a.Heroesa[rnd].GetHeroName() << " shot " << b.Heroesb[rnd].GetHeroName() << "\n";

		b.Heroesb[rnd].takeHit();

		cout << b.Heroesb[rnd].GetHeroName() << "'s health is " << b.Heroesb[rnd].health << "\n\n";


		for (int i = 0; i < a.Heroesa.size(); i++) {

			if (a.Heroesa[rnd].health == 0) {

				b.Heroesb[i].GetHeroName().erase();
			}
		}

		for (int i = 0; i < b.Heroesb.size(); i++)
		{

			if (b.Heroesb[rnd].health == 0) {

				b.Heroesb[i].GetHeroName().erase();
			}
		}


		/*if (Cj.health == 0) {
		
			gameState = false;
		}*/


		if (Cj.health == 0 || Bigsmoke.health == 0 || Ryder.health == 0) {
			cout << "Game Over!\nlosantos won!!!";
			break;
		}


		if (Michael.health == 0 || Lamar.health == 0 || Trevor.health == 0) {
			cout << "Game Over!\nGrove street won!!!";
			break;
		}

	}



	
	

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
