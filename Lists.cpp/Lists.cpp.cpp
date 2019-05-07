// Lists.cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Node.h"
#include "SingleLink.h"
#include "DoubleLink.h"

void singleLinkListCall() {
	SingleLink *singlelist = new SingleLink();
	for (int i = 0; i < 100; i++) {
		singlelist->Fill(rand() % 100);

	}
	/*singlelist->PushFront(222);
	singlelist->PushBack(223);
	singlelist->PushBack(224);*/
	singlelist->Insert(50, 666, singlelist->InsertAt); //or singlelist::InsertAt
	singlelist->Print();
	std::cout << std::endl;

	std::cout << "my first value is: " << singlelist->First();
	std::cout << ", my last value is: " << singlelist->Last() << std::endl;

}

int main() 
{




	/*DoubleLink::Iterator;*/



	SingleLink * singlelist = new SingleLink();

	singlelist->PushFront(222);
	singlelist->PushBack(223);
	singlelist->PushBack(224);
	singlelist->Print();

	std::cout << std::endl;



	singlelist->Remove(224);




	//singlelist->count();
	singlelist->Print();


	/*DoubleLink *doubleList = new DoubleLink();
	doubleList->PushFront(10);
	doubleList->PushFront(9);
	doubleList->PushFront(8);
	doubleList->Print();

	std::cout << std::endl << std::endl;

	doubleList->PushBack(5);
	doubleList->Print();

	std::cout << std::endl << std::endl;

	doubleList->PopFront();
	doubleList->Print();

    std::cout << std::endl;

	doubleList->PopBack();
	doubleList->Print();

	std::cout << std::endl;

	doubleList->count();
	doubleList->Print();*/

	//doubleList->clear();
	//doubleList->Print();



	/*singleLinkListCall();*/



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
