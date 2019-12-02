#pragma once
class DynamicArray
{

	

public:

	int *dynArr;
	int capacity;
	int counter = 0;


	DynamicArray(const int cap = 6);
	DynamicArray(const DynamicArray &dynArr2);
	~DynamicArray();

	void operator=(const DynamicArray &dynArr2);

	 void remove(int del);

	 int &operator[](int i);

	 void adding(int index, int value);

	 void reSize(int newCap);

	 void pushBack(int val);

	 void popBack();



};

