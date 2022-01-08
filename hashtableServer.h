#pragma once
#include<iostream>
#include<string>
#include"All_Classes.h"
using namespace std;
template<typename T>
class Node {
	void gotoxy(short y, short x)
	{
		COORD pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
public:
	string key;
	T value;
	string name, vac_centre, date;
	int age;
	Node* next;

	Node(string key, T value) {
		this->key = key;
		this->value = value;
		next = NULL;
		insert();
	}

	void insert() {

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
		cout << "Vaccine? "; getline(cin, name);
	}
	~Node() {
		if (next != NULL) {
			delete next;
		}
	}
};

template <typename T>
class HashTableServer {
	Node<T>** table;
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

		Node<T>** oldTable = table;
		int oldTs = ts;
		cs = 0;
		ts = 2 * ts + 1;//increasing table size  // for keeping it prime We added 1
		table = new Node<T>*[ts];
		for (int i = 0; i < ts; i++) {
			table[i] = NULL;
		}

		//Copy elements from old table to new table
		for (int i = 0; i < oldTs; i++) {
			Node<T>* temp = oldTable[i];
			//copying each linklist present in the ith index of old Table into new Table
			while (temp != NULL) {
				string key = temp->key;
				T value = temp->value;
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
		table = new Node<T>*[ts];
		for (int i = 0; i < ts; i++) {
			table[i] = NULL;
		}
	}
	void insert(string key, T val) {
		int idx = hashFn(key);
		Node<T>* n = new Node<T>(key, val);
		n->next = table[idx];
		table[idx] = n;
		cs++;

		float load_factor = cs / float(ts);
		if (load_factor > 4.5) {
			rehash();
		}
	}

	void print() {
		for (int i = 0; i < ts; i++) {
			cout << "Bucket " << i << " ";
			Node<T>* temp = table[i];
			while (temp != NULL) {
				cout << temp->key << "->";
				temp = temp->next;
			}
			cout << endl;
		}
	}

	T* search(string key) {
		for (int i = 0; i < ts; i++) {
			Node<T>* temp = table[i];
			while (temp != NULL) {
				if (temp->key == key) {
					return &temp->value;
				}
			}
			return NULL;
		}
	}

	bool empty(string key) {
		int idx = hashFn(key);
		Node<T>* head_ref = table[idx];
		int i = 0;
		while (head_ref != NULL) {
			if (head_ref->key == key)
			{
				// Store head node
				Node<T>* temp = head_ref;
				Node<T>* prev = NULL;

				// If head node itself holds
				// the key to be deleted
				if (temp != NULL && temp->key == key)
				{
					head_ref = temp->next; // Changed head
					delete temp;            // free old head
					return 1;
				}
				else
				{
					while (temp != NULL && temp->key != key)
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

