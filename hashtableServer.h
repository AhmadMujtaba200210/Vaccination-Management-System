#pragma once
#include<iostream>
#include<string>
#include"All_Classes.h"
using namespace std;
template<typename T>
class NodeServer {
	void gotoxy(short y, short x)
	{
		COORD pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
public:
	string city;
	T id_card;
	string name, vac_centre, date, status;
	int age;
	string vacc;
	NodeServer* next;

	NodeServer(string key, T value) {
		this->city = key;
		this->id_card = value;
		next = NULL;
		insert();
	}

	void insert() {
		ofstream myFile("Patient.txt", ios::app | ios::in);
		int x, y;
		gotoxy(x = 8, y = 55);
		cin.ignore();
		cout << "Enter Patient Name:"; getline(cin, name);
		gotoxy(++x, y);
		cout << "Age:"; cin >> age;
		cin.ignore();
		gotoxy(++x, y);
		cout << "Enter Vaccincation Center:"; getline(cin, vac_centre);
		gotoxy(++x, y);
		cout << "Enter Vaccination Date(DD-MM-YY):"; getline(cin, date);
		gotoxy(++x, y);
		cout << "Vaccine? "; getline(cin, vacc);
		gotoxy(++x, y);
		cout << "Update Status: "; getline(cin, status);
		myFile << name << "," << age << "," << vacc << "," << vac_centre << "," << status << endl;
		//filehandling
		return;
	}
	~NodeServer() {
		if (next != NULL) {
			delete next;
		}
	}
};

template <typename T>
class HashTableServer {
	void gotoxy(short y, short x)
	{
		COORD pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
	NodeServer<T>** table;
	int cs; //total entries
	int ts; //size of table

	int hashFn(string key) {
		int idx = 0;
		int power = 1;
		for (auto ch : key) {
			idx = (idx + ch * power) % ts;
			power = (power * 29) % ts;
		}
		return idx;
	}

	void rehash() {  //Tricky but Interesting
		//We saved the old Table pointer and will do insertion to the new table

		NodeServer<T>** oldTable = table;
		int oldTs = ts;
		cs = 0;
		ts = 2 * ts + 1;//increasing table size  // for keeping it prime We added 1
		table = new NodeServer<T>*[ts];
		for (int i = 0; i < ts; i++) {
			table[i] = NULL;
		}

		//Copy elements from old table to new table
		for (int i = 0; i < oldTs; i++) {
			NodeServer<T>* temp = oldTable[i];
			//copying each linklist present in the ith index of old Table into new Table
			while (temp != NULL) {
				string key = temp->city;
				T value = temp->id_card;
				//happen in the new table
				insert(key, value);
				temp = temp->next;
			}

			//deleting each linklist present in the ith index of old table
			if (oldTable[i] != NULL) {
				delete oldTable[i];
			}
		}
		//And at the end it is deleting whole old table
		delete[] oldTable;
	}

public:
	HashTableServer(int default_size = 5) {
		cs = 0;
		ts = default_size;
		table = new NodeServer<T>*[ts];
		for (int i = 0; i < ts; i++) {
			table[i] = NULL;
		}
	}
	void insert(string key, T val) {
		int idx = hashFn(key);
		NodeServer<T>* n = new NodeServer<T>(key, val);
		n->next = table[idx];
		table[idx] = n;
		cs++;

		float load_factor = cs / float(ts);
		if (load_factor > 4.5) {
			rehash();
		}
	}

	void print() {
		int x, y;
		gotoxy(x = 5, y = 55);
		for (int i = 0; i < ts; i++) {
			gotoxy(++x, y);
			cout << "Bucket " << i << " ";
			NodeServer<T>* temp = table[i];
			while (temp != NULL) {
				cout << temp->name << "->";
				temp = temp->next;
			}
			cout << endl;
		}
	}

	T* search(string key) {
		for (int i = 0; i < ts; i++) {
			NodeServer<T>* temp = table[i];
			while (temp != NULL) {
				if (temp->city == key) {
					return &temp->id_card;
				}
			}
			return NULL;
		}
	}

	bool empty(string key) {
		int idx = hashFn(key);
		NodeServer<T>* head_ref = table[idx];
		int i = 0;
		while (head_ref != NULL) {
			if (head_ref->city == key)
			{
				// Store head node
				NodeServer<T>* temp = head_ref;
				NodeServer<T>* prev = NULL;

				// If head node itself holds
				// the key to be deleted
				if (temp != NULL && temp->city == key)
				{
					head_ref = temp->next; // Changed head
					delete temp;            // free old head
					return 1;
				}
				else
				{
					while (temp != NULL && temp->city != key)
					{
						prev = temp;
						temp = temp->next;
					}

					// If key was not present in linked list
					if (temp == NULL)
						return 0;

					// Unlink the node from linked list
					prev->next = temp->next;

					// Free memory
					delete temp;
				}
				return 1;
			}
			i++;
			head_ref = head_ref->next;
		}
		return 0;
	}


};

