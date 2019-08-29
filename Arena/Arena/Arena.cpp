
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


	cout << "Let the battle between Losantos and groove street begin!!!!!\n\n";


	TeamA a;
	TeamB b;



	vector<int>::iterator it;

	Hero Cj;
	Hero Bigsmoke;
	Hero Ryder;


	Hero Michael;
	Hero Trevor;
	Hero Lamar;

	srand(time(NULL));


	

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


		//Init random person to attack at the start of the event cycle
		int rnda = rand() % (int)(a.Heroesa.size() );
		int rndb = rand() % (int)(b.Heroesb.size() );

		

		cout << "Press enter to continue:\n";
		cin.ignore();

			cout << b.Heroesb[rndb].GetHeroName() << " shot " << a.Heroesa[rnda].GetHeroName() << "\n";

			a.Heroesa[rnda].takeHit();

			cout << a.Heroesa[rnda].GetHeroName() << "'s health is " << a.Heroesa[rnda].health << "\n\n";



			for (int i = 0; i < a.Heroesa.size(); i++) {

				if (a.Heroesa[i].health <= 0) {
					cout << a.Heroesa[i].GetHeroName() << " is dead\n ";

					a.Heroesa.erase(a.Heroesa.begin() + i);

					
					
				}
			}
					if (a.Heroesa.size() == 0) {

						cout << "Game Ovver\n\n **********Losantos Won!!!!!**********\n";
						gameState = false;
						
											break;
					}
	


			// Regenerate New Random Attacks from the remaining team member size
			rnda = rand() % (int)(a.Heroesa.size());
			rndb = rand() % (int)(b.Heroesb.size());

			cout << "Press enter to continue:\n";
			cin.ignore();

			cout << a.Heroesa[rnda].GetHeroName() << " shot " << b.Heroesb[rndb].GetHeroName() << "\n";

			b.Heroesb[rndb].takeHit();

			cout << b.Heroesb[rndb].GetHeroName() << "'s health is " << b.Heroesb[rndb].health << "\n\n";






			for (int i = 0; i < b.Heroesb.size(); i++)
			{

				if (b.Heroesb[i].health <= 0) {

					cout << b.Heroesb[i].GetHeroName() << " is dead\n ";

					b.Heroesb.erase(b.Heroesb.begin() + i);

					
				}
			}
					if (b.Heroesb.size() == 0) {

						cout << "Game Ovver\n\n **********Groove Street!!!!!**********\n";
						gameState = false;

						break;
					}


		



		

	}



	
	

}

