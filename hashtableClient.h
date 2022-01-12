#pragma once
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include"All_Classes.h"
using namespace std;
template<typename T>
class NodeClient {
	void gotoxy(short y, short x)
	{
		COORD pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
public:
	string email;
	T pass_code;
	string name, address, status, id_card, gender, ph;
	int age;
	NodeClient* next;

	NodeClient(string key, T pass_code, string add, int age, string name, string id, string gen, string ph) {
		this->email = key;
		this->pass_code = pass_code;
		this->address = add;
		this->name = name;
		this->age = age;
		this->status = "Non Vaccinated!";
		this->id_card = id;
		this->gender = gen;
		this->ph = ph;
		next = NULL;
	}
	~NodeClient() {
		if (next != NULL) {
			delete next;
		}
	}
};

template <typename T>
class HashTableClient {
	void gotoxy(short y, short x)
	{
		COORD pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
	NodeClient<T>** table;
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
	string cut(string str) {
		stringstream ss(str); //convert my_string into string stream

		vector<string> tokens;
		string temp_str;

		while (getline(ss, temp_str, '@')) { //use comma as delim for cutting string
			tokens.push_back(temp_str);
		}

		string strnew = tokens[1];
		return strnew;
	}
	void rehash() {  //Tricky but Interesting
		//We saved the old Table pointer and will do insertion to the new table


		NodeClient<T>** oldTable = table;
		int oldTs = ts;
		cs = 0;
		ts = 2 * ts + 1;//increasing table size  // for keeping it prime We added 1
		table = new NodeClient<T>*[ts];
		for (int i = 0; i < ts; i++) {
			table[i] = NULL;
		}

		//Copy elements from old table to new table
		for (int i = 0; i < oldTs; i++) {
			NodeClient<T>* temp = oldTable[i];
			//copying each linklist present in the ith index of old Table into new Table
			while (temp != NULL) {
				string key = temp->email;
				T pass = temp->pass_code;
				string add = temp->address;
				string nam = temp->name;
				string id = temp->email;
				string gen = temp->gender;
				string ph = temp->ph;
				int age = temp->age;
				//happen in the new table
				insert(key, pass, add, age, nam, id, gen, ph);
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
	HashTableClient(int default_size = 5) {
		cs = 0;
		ts = default_size;
		table = new NodeClient<T>*[ts];
		for (int i = 0; i < ts; i++) {
			table[i] = NULL;
		}
	}
	void insert(string key, T pass, string add, int age, string nam, string id, string gen, string ph) {
		string str = cut(key);
		int idx = hashFn(str);
		NodeClient<T>* n = new NodeClient<T>(key, pass, add, age, nam, id, gen, ph);
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
			NodeClient<T>* temp = table[i];
			while (temp != NULL) {
				cout << temp->email << "->";
				temp = temp->next;
			}
			cout << endl;
		}
	}

	NodeClient<T>* search(string key) {
		string str = cut(key);
		int idx = hashFn(str);
		NodeClient<T>* temp = table[idx];
		while (temp != NULL) {
			if (temp->email == key) {
				return temp;
			}
		}
		return NULL;
	}

	bool searchEmail(string key) {
		string str = cut(key);
		int idx = hashFn(str);
		NodeClient<T>* temp = table[idx];
		while (temp != NULL) {
			if (temp->email == key) {
				return 1;
			}
		}
		return 0;
	}

	bool searchPass(string key, string pass) {
		string str = cut(key);
		int idx = hashFn(str);
		NodeClient<T>* temp = table[idx];
		while (temp != NULL) {
			if (temp->pass_code == pass) {
				return 1;
			}
		}
		return 0;

	}
	bool empty(string key) {
		int idx = hashFn(key);
		NodeClient<T>* head_ref = table[idx];
		int i = 0;
		while (head_ref != NULL) {
			if (head_ref->email == key)
			{
				// Store head node
				NodeClient<T>* temp = head_ref;
				NodeClient<T>* prev = NULL;

				// If head node itself holds
				// the key to be deleted
				if (temp != NULL && temp->email == key)
				{
					head_ref = temp->next; // Changed head
					delete temp;            // free old head
					return 1;
				}
				else
				{
					while (temp != NULL && temp->email != key)
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


