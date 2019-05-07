#pragma once
#include "Node.h"
class SingleLink
{
public:
	SingleLink();
	~SingleLink();

	enum E_INSERT
	{

		InsertAfter = 0,
		InsertAt = 1,
		InsertBefore = 2
	};

	Node *head, *tail; //beginning and end of the list
	int m_length;

	void Print();

	void Fill(int a_data); // add information to the list

	bool Empty(); // this will return a boolean, true if the list is empty, false otherwise

	void PushFront(int a_start); // add a new value to the front of the list
	void PushBack(int a_end); // add a new value to the end of the list

	void Insert(int a_iterator, int a_value, E_INSERT a_typeOfInsert); // insert a value at a certain location

	void Erase(int a_iterator); // remove value at this iterator
	int begin(); // return an iterator fo the first element
	int end(); // return an iterator for the last element
	int First();
	int Last();

	void Search(int a_wanted); // prints out wether a value exist in our list
	int count(); 

	void Remove(int a_wanted); // remove all elements with matching value
	void PopFront(); // Remove the first element
	void PopBack(); //  Remove the last element
	void Clear(); // Remove all the elements

};