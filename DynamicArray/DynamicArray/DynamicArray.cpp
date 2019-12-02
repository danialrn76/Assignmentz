#include "pch.h"
#include "DynamicArray.h"


DynamicArray::DynamicArray(const int cap )
{
	capacity = cap;
	dynArr = new int[capacity];
}

DynamicArray::DynamicArray(const DynamicArray & dynArr2)
{
	dynArr = new int[dynArr2.capacity];

	for (; counter < capacity; counter++)
	{
		dynArr[counter] = dynArr2.dynArr[counter];

	}

}


DynamicArray::~DynamicArray()
{

	delete[]dynArr;
}

void  DynamicArray::operator=(const DynamicArray & dynArr2)
{
	delete[]dynArr;

	capacity = dynArr2.capacity;

	for (; counter < capacity; counter++)
	{
		dynArr[counter] = dynArr2.dynArr[counter];

	}

}

void DynamicArray::remove(int del)
{
	del--;

	for (int i = del; i < capacity - 1; i++)
	{
		int delVal = dynArr[i];

		dynArr[i] = dynArr[i + 1];

		dynArr[i + 1] = delVal;
	}
}

int & DynamicArray::operator[](int i)
{
	return dynArr[i];
}

void DynamicArray::adding(int index, int value)
{
	if (counter >= capacity) {
		capacity * 2;
		reSize(capacity);
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

void DynamicArray::reSize(int newCap)
{

	int *newArr = new int[newCap];

	if (newCap < capacity) {

		counter = newCap;
	}


	capacity = newCap;

	

	for (int i = 0; i < newCap; i++ ) {
	
		newArr[i] = dynArr[i];
	
	}


}

void DynamicArray::pushBack(int val)
{
	adding(counter, val);
}

void DynamicArray::popBack()
{

	
	dynArr[counter - 1] = 0;
	counter--;


}
