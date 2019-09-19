// DynamicArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>


using namespace std;

int main()
{


	int *dynArr = NULL;

	cout << "**********Welcome to your dynamic array**********" << endl;
	cout << "how many items would you like to add?\n";

	int input;

	cin >> input;

	dynArr = new int[input];



	int val;


	for (int counter = 0; counter < input; counter++) 
	{
		cout << "Please enter number " << counter + 1 << endl;
		cin >> val;
		*(dynArr + counter) = val;
	
	
	}




	cout << "your dynamic array contains the numbers blow\n";

	for (int counter = 0; counter < input; counter++)
	{
		cout <<  "number " << counter + 1 << " is: " <<  *(dynArr + counter) << endl;


	}


	int del;

	cout << "Enter the position of the nuumber which you wanna delete\n";

	cin >> del;
	del--;


	for (int s = del; s < input; s++) 
	{

		int delVal = dynArr[s];
			
		dynArr[s] = dynArr[s + 1];
		dynArr[s + 1] = delVal;

	}

	for (int ind = 0; ind < input - 1; ind++) 
	{
		cout << dynArr[ind] << "  ";
	}


	int search;

	cout << "which number are you looking for?\n";

	cin >> search;


	system("pause");

	/*delete []dynArr;*/
}



