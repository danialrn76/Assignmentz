#pragma once
class cpArray
{
public:
	cpArray();
	~cpArray();





	class cpArr {

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

		//adds to the end of the array
		void pushBack(int val) {

			adding(counter, val);

		}

		void popBack() {

			cpArr(capacity - 1);

		}


	};
};

