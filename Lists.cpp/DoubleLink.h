#pragma once
#include "Node.h"
class DoubleLink
{
public:
	DoubleLink();
	~DoubleLink();

	class Iterator 
	{
	public:
		Iterator() {};
		Iterator(Node *a_node) : m_node(a_node) {}
		~Iterator();

		//By using  the overloads for operators, 
		// you can make the fuollowing:

		void operator++() { m_node = m_node->next;};
		void operator++(int) { m_node = m_node->next++; }

		const Iterator& operator+(const int a_value) {
			//e.g. Iterator + 12


			Node *l_node = m_node;

			for (int i = 0; i < a_value; ++i) {
			
				if (l_node->next == nullptr)
					break;

				l_node = l_node->next;
			}	

			return Iterator(l_node);
			
		}



		void operator--() { m_node = m_node->prev; }
		void operator--(int) { m_node = m_node->prev; }
		const Iterator& operator-(const int a_value) {
			for (int i = 0; i < a_value; i++) {
				m_node = m_node->prev;
				return Iterator(m_node);
			}
		}

		int& operator*() { return m_node->m_data; }
		int* operator->() { return &m_node->m_data; }
		bool operator == (const Iterator& rhs) { return m_node == rhs.m_node; }
		bool operator != (const Iterator& rhs) { return m_node != rhs.m_node; }
		Node* GetNode() { return m_node; }


		Node *m_node = nullptr;


	};


	void PushFront(int a_value); // add a new value to the front of the list
	void PushBack(int a_value); // add a new value to the end of the list

	//Add a new value after the specified itorator location
	void InsertAfter(Iterator a_iterator, int a_value);

	Iterator Begin(); // return an iterator to the first element
	Iterator End(); // return an iterator to the last element. Hint: nullptr

	Node* First(); //return the first element by value, assert  if no element
	Node* Last(); // return the last element by value, assert if no element

	int count(); // return how many element exist in the list

	void Erase(Iterator a_iterator); // remove an element by its iterator
	void Remove(int value); // remove all elements with matching values

	void PopBack(); // remove the last element
	void PopFront(); // remove the first element

	bool Empty();// return a boolean, true of the list is empty, false otherwise

	void clear(); // remove all elements from the list
	void Print();

	Node *head, *tail;
private:
	int m_size;
};

