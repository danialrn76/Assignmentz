
#include "pch.h"
#include <iostream>
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

	//creating the heros

	Hero Cj;
	Hero Bigsmoke;
	Hero Ryder;


	Hero Michael;
	Hero Trevor;
	Hero Lamar;

	//generating the random function
	srand(time(NULL));


	
	//giving names to heros using the set hero naem function
	Cj.SetHeroName("cj");
	Bigsmoke.SetHeroName("Big Smoke");
	Ryder.SetHeroName("Ryder");

	Michael.SetHeroName("Michael");
	Trevor.SetHeroName("Trever");
	Lamar.SetHeroName("Lamar");


	//adding the heros to the relevant vector 
	a.Heroesa.push_back(Cj);
	a.Heroesa.push_back(Bigsmoke);
	a.Heroesa.push_back(Ryder);



	b.Heroesb.push_back(Michael);
	b.Heroesb.push_back(Trevor);
	b.Heroesb.push_back(Lamar);

	

	//creating a boolean for the game loop
	bool gameState = true;


	
	
	//game loop
	while (gameState) {


		//displays healthy values of team B
		for (int i = 0; i < b.Heroesb.size(); i++) {

			cout << b.Heroesb[i].GetHeroName() << "'s health = " << b.Heroesb[i].health << "\n\n";
		}


		//displays health values of teasm A
		for (int i = 0; i < a.Heroesa.size(); i++) {

			cout << a.Heroesa[i].GetHeroName() << "'s health = " << a.Heroesa[i].health << "\n\n";
		}


		

		//Init random person to attack at the start of the event cycle
		int rnda = rand() % (int)(a.Heroesa.size() );
		int rndb = rand() % (int)(b.Heroesb.size() );

		

		cout << "Press enter to continue:\n";
		cin.ignore();


		//showing the heros name and the hero who is attacking and the amount of damage(which is a random number for the attack value)
		cout << b.Heroesb[rndb].GetHeroName() << " shot " << a.Heroesa[rnda].GetHeroName() << " and took " << b.Heroesb[rndb].attack << " of his health !!!" <<"\n\n";

			//taking the damage amount of the hero's health value by using the take hit function
			a.Heroesa[rnda].takeHit();

			


			//going through the list of team A and checking their health value
			for (int i = 0; i < a.Heroesa.size(); i++) {

				//if the hero is dead, show a message and delete he hero from the vector
				if (a.Heroesa[i].health <= 0) {
					cout << a.Heroesa[i].GetHeroName() << " is dead \n\n ";

					a.Heroesa.erase(a.Heroesa.begin() + i);

					
					
				}
			}

					//if all of the heros of team A are dead show "game over " text and show both teams health values and exit the game loop
					if (a.Heroesa.size() == 0) {

						for (int i = 0; i < b.Heroesb.size(); i++) {

							cout << b.Heroesb[i].GetHeroName() << "'s health = " << b.Heroesb[i].health << "\n";
						}

						cout << "Cj's health = 0\n Big smoke's health = 0\n Ryder's healthh = 0 \n THEY'RE ALL DEAD!!! \N";

						cout << "Game Ovver\n\n **********Losantos Won!!!!!**********\n\n";
						

						gameState = false;
						
						break;
					}
	
					

			// Regenerate New Random Attacks from the remaining team member size
			rnda = rand() % (int)(a.Heroesa.size());
			rndb = rand() % (int)(b.Heroesb.size());

			//ignore the input
			cin.ignore();


			//showing the heros name and the hero who is attacking and the amount of damage(which is a random number for the attack value)
			cout << a.Heroesa[rnda].GetHeroName() << " shot " << b.Heroesb[rndb].GetHeroName() << " and took " << a.Heroesa[rnda].attack << " of his life "  "\n\n";


			//taking the damage amount of the hero's health value by using the take hit function
			b.Heroesb[rndb].takeHit();

		





			//going through the list of team B and checking their health value
			for (int i = 0; i < b.Heroesb.size(); i++)
			{

				if (b.Heroesb[i].health <= 0) {

					cout << b.Heroesb[i].GetHeroName() << " is dead \n\n ";

					b.Heroesb.erase(b.Heroesb.begin() + i);

					
				}
			}


					//if all of the heros of team A are dead show "game over " text and show both teams health values and exit the game loop
					if (b.Heroesb.size() == 0) {

						for (int i = 0; i < a.Heroesa.size(); i++) {
						
							cout << a.Heroesa[i].GetHeroName() << "'s health = " << a.Heroesa[i].health << "\n";
						}

						cout << "Michael's health = 0\n Lamar's health = 0\n Trever's healthh = 0\n  THEY'RE ALL DEAD!!! \N";
						cout << "Game Ovver\n\n **********Groove Street won!!!!!**********\n";
						gameState = false;

						break;
					}

					


					//clear the screen
					system("CLS");
		

	}



	
	

}

