// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

#include <iostream>
#include <vector>
#include "Marine.h"
#include "Zergling.h"

using std::vector;
using std::cout;
using std::endl;

int main()
{
	vector<Marine> squad;
	vector<Zergling> swarm;

	int squadSize = 10;
	int swarmSize = 20;
	typedef int size_t;

	// Set up the Squad and the Swarm at their initial sizes listed above
	Zergling z;
	Marine m;
	Entity e;

	for (size_t i = 0; i < squadSize; i++)
	{
		squad.push_back(m);
	}

	for (size_t i = 0; i < swarmSize; i++)
	{
		swarm.push_back(z);
	}
	
	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!" << endl;
	// Attack each other until only one team is left alive
	while (squadSize > 0 && swarmSize > 0) // If anyone is left alive to fight . . .
	{
		
			for (int i = 0; i < squadSize; i++ ) // go through the squad
			{
				
				// if there is no more zergs left, stop attacking
				if (swarmSize == 0) {
					break;
				}
				// each marine will attack the first zergling in the swarm

				cout << "A marine fires for " << squad[0].attack() << " damage. " << endl;
				
					int damage = squad[0].attack();
					swarm[0].takeDamage(damage);
					cout << "Zergling health is: " << swarm[0].health << "\n";
				
				if (swarm[0].health == 0) // if the zergling dies, it is removed from the swarm
				{
					cout << "The zergling target dies" << endl;
					swarm.erase(swarm.begin());
					
					swarmSize--;
				}
			}
		
			
		cout << "\n";
		if (swarmSize > 0) // if there's at least one zergling alive
		{
			for (int i = 0; i < swarmSize; i++) // loop through zerglings
			{
				// if there is no more marine left, stop attacking
			if (squadSize == 0) {
					
				break;
				}

			// each marine will attack the first zergling in the swarm
				cout << "A zergling attacks for " << swarm[0].attack() << " damage." << endl;
				
				int damage = swarm[0].attack();
				squad[0].takeDamage(damage);
				cout << "marine health is:" << squad[0].health << "\n";

				if (squad[0].health == 0)// if the zergling dies, it is removed from the swarm
				{
					cout << "the marine target dies\n" << endl;
					squad.erase(squad.begin());
					squadSize--;
					
				}
				
				
			}
			
		}
		
	}
	
	

	// Once one team is completely eliminated, the fight ends and one team wins
	cout << "The fight is over. \n";


	if (squadSize > swarmSize)
	{
		cout << "The Marines win." << endl;
	} 
	if(swarmSize > squadSize)
	{
		cout << "The Zerg win." << endl;
	}
if (squadSize == swarmSize) {
		cout << "draw";
	}
}


