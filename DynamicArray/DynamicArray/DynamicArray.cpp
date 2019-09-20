// DynamicArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>


using namespace std;



class cpArr{

	int *dynArr;
	int capacity;
	int counter = 0;

	public:

	cpArr(const int cap = 6) 
	{
		capacity = cap;
		dynArr = new int[capacity];

	}

	~cpArr() {
	
		delete[]dynArr;
	}

	cpArr(const cpArr &cpArr2) 
	{
		dynArr = new int[cpArr2.capacity];

		for (; counter < capacity; counter++)
		{
			dynArr[counter] = cpArr2.dynArr[counter];

		}

	}

	cpArr& operator=(const cpArr &cpArr2)
	{
		
		delete[]dynArr;

		capacity = cpArr2.capacity;

		for (; counter < capacity; counter++)
		{
			dynArr[counter] = cpArr2.dynArr[counter];

		}

	}


	void remove(int del)
	{
		del--;

		for (int i = del; i < capacity - 1; i++) 
		{
			int delVal = dynArr[i];

			dynArr[i] = dynArr[i + 1];

			dynArr[i + 1] = delVal;
		}
	
	}


	int &operator[](int i) 
	{
		return dynArr[i];
	}


	void adding(int index, int value) {
	
		if (counter >= capacity) {
		
		}

			for (int i = counter; i < capacity; i++)
			{
				if (i == capacity - 1)
					break;

				int temp = dynArr[i + 1];
				dynArr[i + 1] = dynArr[i];
				dynArr[i] = temp;

			}

			dynArr[index] = value;
			counter++;
	
	}


	void resize(int newCap) {


		if (newCap < capacity) {
			dynArr[newCap];
		}
	
	}


	void pushBack(int val) {


		adding(counter, val);

		/*
		for(int i = counter)*/



	}


	
};




int main()
{
	

	cpArr arr1;
	
	/*arr1[0] = 15;
	arr1[1] = 4;
	arr1[2] = 56;
	arr1[3] = 12;
	arr1[4] = 34;

    


	for (int i = 0; i < 5; i++) {

		cout << arr1[i] << endl;
	}*/



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



	//arr1.resize(4);


	//for (int i = 0; i < 4; i++) {

	//	cout << arr1[i] << endl;
	//}
	//
	//
	//

//	int *dynArr /*= NULL*/;
//
//	cout << "**********Welcome to your dynamic array**********" << endl;
//	cout << "how many items would you like to add?\n";
//
//	int input;
//
//	cin >> input;
//
//	dynArr = new int[input];
//
//
//
//	int val;
//
//
//	for (int counter = 0; counter < input; counter++) 
//	{
//		cout << "Please enter number " << counter + 1 << endl;
//		cin >> val;
//		*(dynArr + counter) = val;
//	
//	
//	}
//
//
//
//
//	cout << "your dynamic array contains the numbers blow\n";
//
//	for (int counter = 0; counter < input; counter++)
//	{
//		cout <<  "number " << counter + 1 << " is: " <<  *(dynArr + counter) << endl;
//
//
//	}
//
//
//	int del;
//
//	cout << "Enter the position of the nuumber which you wanna delete\n";
//
//
//cin >> del;
//	del--;
//
//
//	for (int s = del; s < input; s++) 
//	{
//
//		int delVal = dynArr[s];
//			
//		dynArr[s] = dynArr[s + 1];
//		dynArr[s + 1] = delVal;
//
//	}
//
//	for (int ind = 0; ind < input - 1; ind++) 
//	{
//		cout << dynArr[ind] << "  ";
//	}
//
//
//	int search;
//
//	cout << "which number are you looking for?\n";
//
//	cin >> search;
//
//
//	system("pause");

	/*delete []dynArr;*/

}



