#include "pch.h"
#include "DoubleLink.h"
#include <iostream>

using namespace std;
DoubleLink::DoubleLink()
{
	this->m_size = 0;
	this->head = nullptr;
	this->tail = nullptr;

}


DoubleLink::~DoubleLink()
{
	Node *previous;
	while (head != nullptr) {
		previous = head;
		head = head->next;
		delete previous;
	}
	std::cout << "Single Link deleted" << std::endl;

}


void DoubleLink::Erase(Iterator a_iterator)
{
	Node * next;
	Node * current;
	Node * previous;

	current = a_iterator.GetNode();
	previous = current->prev;
	next = current->next;

	previous->next = current->next;
	next->prev = current->prev;

	delete current;




	



	//Node *current = head, *previous = new Node();

	//for (int i = 1; i < a; i++) {
	//	a_iterator + a;
	//	previous = current;
	//	current = current->next;
	//}
	//previous->next = current->next;


	
}



void DoubleLink::Remove(int value)
{

	Node *current = head, *previous = nullptr;
	/*std::cout << "this list is empty" << std::endl;*/
	if (Empty()) {
		std::cout << " the list is empty" << std::endl;
	}
	else if (current->m_data == value) {
		head = current->next;
		delete current;

		/*Iterator temp;
		
		Erase(temp, value);
*/


	}
	else
	{
		while (current->m_data != value && current->next != nullptr) {
			previous = current;
			current = current->next;
		}

		if (current->next == nullptr && current->m_data != value) {

			std::cout << "the value (" << value << ") was not found in the list" << std::endl;
		}
		else
		{

			previous->next = current->next;
			delete current;


		}
	}


}

void DoubleLink::PopBack()
{
	if (Empty()) {
		cout << "The list is empty";
	}

	else if(tail->next == nullptr){
		
		Node *node = tail;
		tail = node->prev;
		tail->next = nullptr;
		delete node;

	
	}
	
	
}

void DoubleLink::PopFront()
{

	if (Empty()) {
	
		cout << "the list is already empty";
	}
	else {

		Node *node = head;
		head = node->prev;
		head = node->next;
		delete node;
	}	
	
}

bool DoubleLink::Empty()
{
	return head == nullptr;
}

void DoubleLink::clear()
{
	Node *node = head->next;
	while (node != nullptr)
	{
		head->next = node->next;
		node->next = nullptr;
		delete node;
		node = head->next;
	}
	PopFront();

	if (Empty()) {

		cout << "the list is empty";
	}
}

void DoubleLink::Print()
{
	//Node *head = this->head;
	//int i = 1;
	//while (head)
	//{
	//	std::cout << i << ":" << head->m_data << std::endl;
	//	head = head->next;
	//	i++;
	//}

	Node * current = head;
	int count = 0;
	while (current != nullptr)
	{
		count++;
		std::cout << count << ":" << current->m_data << std::endl;
		if (current->prev != nullptr) { std::cout << "previous: " << current->prev->m_data << std::endl; }
		if (current->next != nullptr) { std::cout << "next: " << current->next->m_data << std::endl; }
		current = current->next;
	}

}


void DoubleLink::PushFront(int a_value)
{

	Node* node = new Node();
	node->m_data = a_value;
	node->next = nullptr;
	node->prev = nullptr;


	if (head == nullptr) {
		head = node;
		tail = node;

	
	}
	else
	{
		node->next = nullptr;
		node->prev = tail;

		tail->next = node;

		tail = node;

	}

}


void DoubleLink::PushBack(int a_value)
{
	Node* node = new Node();
	node->m_data = a_value;
	node->next = nullptr;
	node->prev = nullptr;


	if (tail == nullptr) {
		head = node;
		tail = node;


	}
	else
	{

		node->prev = tail;
		tail->next = node;
        tail = node;

	}
}


void DoubleLink::InsertAfter(Iterator a_iterator, int a_value)
{
	Node *current = head, *previous = new Node(), *temp = new Node();
	
	

	//while (a_value != current->m_data) {
	//	
	//}
	//cout << "asggasdf";
}

DoubleLink::Iterator DoubleLink::Begin()
{
	return head;
}


DoubleLink::Iterator DoubleLink::End()
{
	return tail;
}

Node * DoubleLink::First()
{
	
	return head;

}

Node * DoubleLink::Last()
{
	return tail;
}

int DoubleLink::count()
{
	Node *head = this->head;
	int i = 0;
	while (head) {

		head = head->next;
		i++;
	}
	m_size = i;
	return m_size;
	
}

DoubleLink::Iterator::~Iterator()
{
}
