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


void DoubleLink::Remove(int value)
{
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
	Node *head = this->head;
	int i = 1;
	while (head)
	{
		std::cout << i << ":" << head->m_data << std::endl;
		head = head->next;
		i++;
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
		node->next = head;
		head->prev = node;
		head = node;

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


DoubleLink::Iterator DoubleLink::Begin()
{
	return Iterator();
}

DoubleLink::Iterator DoubleLink::End()
{
	return Iterator();
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




