// DynamicArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "cpArray.h"
#include "DynamicArray.h"

using namespace std;

int main()
{
	

	 DynamicArray arr1;
	




	arr1.adding(0, 4);
	arr1.adding(1, 6);
	arr1.adding(2, 7);
	arr1.adding(3, 4);
	arr1.adding(4, 2);

	

	
	cout << "\n\n";


	for (int i = 0; i < 5; i++) {
	
		cout << arr1[i] << endl;
	}


	cout << "\n\n";

	/*arr1.pushBack(3);*/

	arr1.pushBack(9);


	
	for (int i = 0; i < 6; i++) {

		cout << arr1[i] << endl;
	}

	cout << "\n\n";

	arr1.popBack();



	for (int i = 0; i < arr1.counter; i++) {

		cout << arr1[i] << endl;
	}


	cout << "\n\n";

	arr1.reSize(3);
	

	for (int i = 0; i < arr1.capacity; i++) {

		cout << arr1[i] << endl;
	}




}



