// ConsoleApplication6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>


#include<windows.h>
#include <stdio.h>
using namespace std;

// displaying the menu
void display() {
	cout << "-----------------------------------------------------\n";
	cout << "please chose from one of the following options\n-----------------------------------------------------\n";
	cout << "1) generate new library content and save\n";
	cout << "2) display library content\n";
	cout << "3) add a book\n";
	cout << "4) update\n";
	cout << "5) search\n";
	cout << "6) exit\n\n";

	cout << "INDEX:\n";
	cout << "book status:\n1 = in library\n2 = on loan\n3 = lost\n";
}


void bufferer() {
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();

}


int main()
{
	
	int chose;
	cout << "welcome to your library!\n";
	bool library_is_open = true;

	while (library_is_open == true) {
		display();
		cin >> chose;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "please enter a valid number\n";
			system("pause");
			continue;
		}
		if (chose > 6 || chose < 1) {
			cout << "please enter a valid number\n";
			system("pause");
			continue;
		}

		// if the user choses number one, make a fstream and open a file called library.dat and type the following content which is a book name, the author of that book and the status of that book
		if (chose == 1) {
			fstream library;
			library.open("library.dat", ios::out | ios::binary);


			if (library.is_open()) {
				char bookname1[100] = "fight club";
				library.write((char*)&bookname1, sizeof(char) * 100);
				char authorname1[100] = "Chuck Palahniuk";
				library.write((char*)&authorname1, sizeof(char) * 100);
				char book_stat[100] = "1";
				library.write((char*)&book_stat, sizeof(char) * 100);

				char bookname2[100] = "trainspotting";
				library.write((char*)&bookname2, sizeof(char) * 100);
				char authorname2[100] = "Irvine Welsh";
				library.write((char*)&authorname2, sizeof(char) * 100);
				char book_stat2[100] = "2";
				library.write((char*)&book_stat2, sizeof(char) * 100);

library.close();
			}
			
			
		}
		
		//if the user choses number 2, make a fstream and open library.dat and go through the file library.dat and display everything inside the file
		 if (chose == 2) {

			fstream library;
			library.open("library.dat", ios::in | ios::binary);

			if (library.is_open()) {
				while (!library.eof() && library.peek() != EOF)
				{
					char book_name[100];
					library.read((char*)&book_name, sizeof(char) * 100);
					char author_name[100];
					library.read((char*)&author_name, sizeof(char) * 100);
					char bookStat[100];
					library.read((char*)&bookStat, sizeof(char) * 100);
					cout << "name: " << book_name << endl;
					cout << "author: " << author_name << endl;
					cout << "book statue:" << bookStat << endl;
				}



				library.close();


			}
		}
		

		 if (chose == 3) {
			fstream library2;
			library2.open("library.dat", ios::out | ios::binary | ios::in | ios::_Nocreate | ios::app);

			char newbook[100];
		    char newauthor[100];
			char new_book_stat[100];

			cout << "whats the name of your book?(max 100 characters)\n"  << endl;

			bufferer();
			cin.getline(newbook, 100);
			cin.ignore(cin.rdbuf()->in_avail());

			cout << "who's the author of your book?(max 100 characters)\n" << endl;
			bufferer();
			cin.getline(newauthor, 100);
			cin.ignore(cin.rdbuf()->in_avail());

			cout << "what is the status of this book? (1 = in library, 2 = on loan, 3 = lost)\n" << endl;
			bufferer();
			cin.getline(new_book_stat, 100);
			cin.ignore(cin.rdbuf()->in_avail());
			
			if (library2.is_open()) {

				library2.write((char*)&newbook, sizeof(char) * 100);
				library2.write((char*)&newauthor, sizeof(char) * 100);
				library2.write((char*)&new_book_stat, sizeof(char) * 100);
				cout << newbook << " ";
				cout << newauthor;
				
			}
             library2.close();

		}
		

		 if (chose == 4) {

			cout << "what would you like to update?\n";

			cout << "1) book name\n";
			cout << "2) author name\n";
			cout << "3) book status\n";

			char update;
			static int book_name;
			static int author_name;
			static int new_stat;
			cin >> update;

			if (update == '1') {
				fstream library;
				library.open("library.dat", ios::in | ios::out | ios::binary | ios::_Nocreate | ios::app);

				cout << "which book name would you like to edit?\nPlease specify the name of the book by a number(eg. number one is the book fight club)\n";
				if (library.is_open()) {
					while (!library.eof() && library.peek() != EOF)
					{
						char book_name[100];
						library.read((char*)&book_name, sizeof(char) * 100);
						char author_name[100];
						library.read((char*)&author_name, sizeof(char) * 100);
						char bookStat[100];
						library.read((char*)&bookStat, sizeof(char) * 100);
						cout << "name: " << book_name << endl;
						cout << "author: " << author_name << endl;
						cout << "book statue:" << bookStat << endl;


					}

				}
				library.close();
				cin >> book_name;


				fstream library4;
				library4.open("library.dat", ios::in | ios::out | ios::binary | ios::_Nocreate);
				if (library4.is_open()) {

					char new_book_name1[100];
					cout << "please enter the new book name: \n";
					cin >> new_book_name1;

					library4.seekp((book_name - 1) * 300, ios::beg);
					library4.write((char*)&new_book_name1, sizeof(char) * 100);
                    library4.close();
				}
			    else {
					cout << "please enter a valid number\n";
				}
				


			}

			if (update == '2') {

				fstream library;
				library.open("library.dat", ios::in | ios::out | ios::binary | ios::_Nocreate | ios::app);

				cout << "which author name would you like to chage?\nPlease specify the name of the author by a number(eg number one is the author Chuck Palahniuk)\n";

				if (library.is_open()) {
					while (!library.eof() && library.peek() != EOF)
					{
						char book_name[100];
						library.read((char*)&book_name, sizeof(char) * 100);
						char author_name[100];
						library.read((char*)&author_name, sizeof(char) * 100);
						char bookStat[100];
						library.read((char*)&bookStat, sizeof(char) * 100);
						cout << "name: " << book_name << endl;
						cout << "author: " << author_name << endl;
						cout << "book statue:" << bookStat << endl;


					}

				}
				library.close();
				cin >> author_name;
				fstream library6;
				library6.open("library.dat", ios::in | ios::out | ios::binary | ios::_Nocreate);
				if (library6.is_open()) {

					char new_author_name[100];
					cout << "please enter the new author's name";
					cin >> new_author_name;
					library6.seekp(((author_name -1) * 300 ) + 100, ios::beg);

					library6.write((char*)&new_author_name, sizeof(char) * 100);
                    library6.close();
				}
				else {
					cout << "please enter a valid number\n";
				}
				
				
			
			}
			
			if (update == '3') {
				fstream library;
				library.open("library.dat", ios::in | ios::out | ios::binary | ios::_Nocreate | ios::app);

				cout << "which book status would you like to change? Please specify the status by a number (eg. number one would be the book status of the book fuight club)\n";

				if (library.is_open()) {
					while (!library.eof() && library.peek() != EOF)
					{
						char book_name[100];
						library.read((char*)&book_name, sizeof(char) * 100);
						char author_name[100];
						library.read((char*)&author_name, sizeof(char) * 100);
						char bookStat[100];
						library.read((char*)&bookStat, sizeof(char) * 100);
						cout << "name: " << book_name << endl;
						cout << "author: " << author_name << endl;
						cout << "book statue:" << bookStat << endl;


					}

				}
				library.close();

				cin >> new_stat;
				if (new_stat == 1) {
					fstream library7;
					library7.open("library.dat", ios::in | ios::out | ios::binary | ios::_Nocreate);
					if (library7.is_open()) {
						char new_status[100];
						cout << "Please enter the new status of the relevant book:  (1=in library, 2=on loan, 3=lost)\n";
						cin >> new_status;

						library7.seekp(((new_stat - 1) * 300) + 100, ios::beg);

						library7.write((char*)&new_status, sizeof(char) * 100);
						library7.close();
					}
				}
				else {
					fstream library8;
					library8.open("library.dat", ios::in | ios::out | ios::binary | ios::_Nocreate);
					if (library8.is_open()) {
					
						char new_status2[100];
						cout << "Please enter the new status of the relevant book:  (1=in library, 2=on loan, 3=lost)\n";
						cin >> new_status2;

						library8.seekp(((new_stat - 1) * 300) + 200, ios::beg);

						library8.write((char*)&new_status2, sizeof(char) * 100);
						library8.close();
					}
				
				
				}


			}

			}

		 if (chose == 5) {
			 cout << "what are you looking for?\n";
             cout << "1)book\n";
			 cout << "2)author\n";

			 int search_choice;
			 cin >> search_choice;

			 if (search_choice == 1) {
				 
				 char relevant_book[100];
				 
				 char lookup_book[100];
				 int iterator = 0;
				 cout << "what's the name of the book that you're looking for?\n";
				 bufferer();
				 cin.getline(relevant_book, 100);
				 cin.ignore(cin.rdbuf()->in_avail());
				 ifstream library_lookup;
				 library_lookup.open("library.dat", ios::in | ios::binary);
				 
				 while (strcmp(relevant_book, lookup_book) != 0) {
					 if (library_lookup.is_open()) {
                         library_lookup.seekg(iterator * 300, ios::beg);
						 library_lookup.read(lookup_book, 100);
						 
						 iterator++;
						 if (library_lookup.eof()) {
							 cout << "couldn't find the book";
							 break;

						 }

						 if (strcmp(relevant_book, lookup_book) == 0) {
							 cout << "the book that you're looking for is in the library, it is at index:" << iterator;

						 }
					 }
				 }
				 
				 library_lookup.close();

			 }

			 
			 if (search_choice == 2) {
				 char relevant_author[100];

				 char lookup_author[100];
				 int iterator = 1;
				 cout << "what's the name of the author that you're looking for?\n";
				 bufferer();
				 cin.getline(relevant_author, 100);
				 cin.ignore(cin.rdbuf()->in_avail());
				 ifstream library_lookup_author;
				 library_lookup_author.open("library.dat", ios::in | ios::binary);

				 while (strcmp(relevant_author, lookup_author) != 0) {
					 if (library_lookup_author.is_open()) {
						 library_lookup_author.seekg(iterator * 100, ios::beg);
						 library_lookup_author.read(lookup_author, 100);

						 iterator++;
						 if (library_lookup_author.eof()) {
							 cout << "couldn't find the author";
							 break;

						 }

						 if (strcmp(relevant_author, lookup_author) == 0) {
							 cout << "the author that you're looking for is in the library, it is at index:" << iterator;

						 }
					 }
				 }

				 library_lookup_author.close();
			 
			 }
		 }
		


		 if (chose == 6) {
			cout << "BYE!";
			Sleep(400);
			library_is_open = false;
		}





}
	}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
