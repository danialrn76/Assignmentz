#include "pch.h"
#include "SingleLink.h"
#include <iostream>


SingleLink::SingleLink()
{
	this->m_length = 0;
	this->head = nullptr;
	this->tail = nullptr;
}


SingleLink::~SingleLink()
{
	Node *previous;
	while (head != nullptr) {
		previous = head;
		head = head->next;
		delete previous;
	}
	std::cout << "Single Link deleted" << std::endl;
}

void SingleLink::Print()
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

void SingleLink::Fill(int a_data)
{
	Node *node = new Node();
	node->m_data = a_data;
	node->next = this->head;
	this->head = node;
	this->m_length++;

}

bool SingleLink::Empty()
{
	return head == nullptr;
}

void SingleLink::PushFront(int a_start)
{
	Node *node = new Node();
	node->m_data = a_start;
	node->next = head;
	head = node;
}



void SingleLink::Insert(int a_iterator, int a_value, E_INSERT a_typeOfInsert)
{
	
		while (a_typeOfInsert != 0 && a_typeOfInsert != 1 && a_typeOfInsert != 2)
		{
			std::cout << "Invalid insertion type, default to 'insert after'" << std::endl;
			a_typeOfInsert = InsertAt;
		}

		Node *current = head, *previous = new Node(), *temp = new Node();

		for (int i = 0; i < (a_iterator - a_typeOfInsert); i++) {
			previous = current;
			current = current->next;
		}

		temp->m_data = a_value;
		previous->next = temp;
		temp->next = current;
	
}

void SingleLink::Erase(int a_iterator)
{
	Node *current = head, *previous = new Node();
	for (int i = 1; i < a_iterator; ++i) {
		previous = current;
		current = current->next;
		
	}
	previous->next = current->next;
}

int SingleLink::begin()
{
	if (!Empty()) {
		return 1;
	}
	else 
	{
		std::cout << "This is an empty list" << std::endl;
	}
}

int SingleLink::end()
{
	Node *current = head;
	int countIterators = 0;
	if (!Empty()) {
		countIterators++;
	}
	else {
		std::cout << "this is an empty list" << std::endl;
		return -1;
	}
	while (current->next != nullptr) {
		current = current->next;
		countIterators++;

	}
	return ++countIterators;
	
}

void SingleLink::PushBack(int a_end)
{
	Node *node = new Node();
	node->m_data = a_end;
	if (Empty()) {
		node->next = head;
		head = node;
	}
	else {
		Node *other = head;
		while (other->next != nullptr) {
			other = other->next;

		}
		node->next = other->next;

		other->next = node;

	}

}

	int SingleLink::First()
	{
		
			if (!Empty()) {
				return head->m_data;

			}
			else
			{
				std::cout << " No elements are in the curent list" << std::endl;
			return -1;	
			}

		
		
	}

	int SingleLink::Last()
	{
		if (!Empty()) {
			Node *current = head;
			while(current->next != nullptr){
				current = current->next;
			}
			return current->m_data;
		}
		else {
			std::cout << "Tere are no elements int the current list " << std::endl;
			return -1;
		}
		
	}
	void SingleLink::Search(int a_wanted)
	{

		if (Empty()) 
		{

			std::cout << "the single linked list is empty..." << std::endl;
		}
		else
		{
			bool check = false;
			Node *node = head;
			while(node != nullptr) 
			{

				if (node->m_data == a_wanted) 
				{
				std::cout << "value was found" << std::endl;

					check = true;
					break;
				}
				else
				{
					node = node->next;

				}
				
			}
			// same as if(check == false)
                if(!check)
				{
				std::cout << "value could niot be found" << std::endl;
				
				
				}

		}
	}
	
	int SingleLink::count()
	{
		Node *head = this->head;
		int i = 0;
		while (head) {
		
			head = head->next;
			i++;
		}
		m_length = i;
		return m_length;

	}
	void SingleLink::Remove(int a_wanted)
	{
		Node *current = head, *previous = nullptr;
		/*std::cout << "this list is empty" << std::endl;*/
		if (Empty()) {
			std::cout << " the list is empty" << std::endl;
		}
		else if (current->m_data == a_wanted) {
			head = current->next;
			delete current;

		}
		else 
		{
			while (current->m_data != a_wanted && current->next != nullptr) {
				previous = current;
				current = current->next;
			}

			if (current->next == nullptr && current->m_data != a_wanted) {
			
				std::cout << "the value (" << a_wanted << ") was not found in the list" << std::endl;
			}
			else
			{
		
				previous->next = current->next;
				delete current;
				

			}
		}

	}
	void SingleLink::PopFront()
	{
		if (Empty()) 
		{
			std::cout << "The list is already empty" << std::endl;
		}

		else 
		
		{
			Node *node = head;
			head = node->next;
			delete node;
		}
	}
	void SingleLink::PopBack()
	{
		if (Empty()) {
			std::cout << "the list is already empty" << std::endl;
		}
		else if (head->next == nullptr)
		{
			Node *node = head;
			head = nullptr;
			delete node;
		
		}
		else {
			Node *current = head, *previous = nullptr;
			while (current->next != nullptr) {
				previous = current;
				current = current->next;
			}
			previous->next = nullptr;
			delete current;

		}
	}
	void SingleLink::Clear()
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
	}

