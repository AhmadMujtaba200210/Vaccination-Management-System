#pragma once
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<string.h>
#include"LinkedList.h"
#include<windows.h>
#include"key.h"
#include<string>
#include "hashtableServer.h"
#include "hashtableClient.h"
int x = 5;  int y = 55;
static int sino_vac = 50;
static int pfizer_vac = 50;
static int canSino_vac = 50;
static int corona_vac = 50;
static int total_vac = sino_vac + pfizer_vac + canSino_vac + corona_vac;
static string chrman, vcchrman, HODirec, HONoti;
HashTableServer<string> tableServer(13);
HashTableClient<string> tableClient;
void gotoxy(short y, short x)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

class Patient {
protected:
	string name, address, gen, Ph_no, id_card;
	uint8_t age;
public:
	Patient() {}
	Patient(string nm, string ph, string id, string add, string g) :name(nm), Ph_no(ph), id_card(id), gen(g) {}
	void set_name(string name) { this->name = name; }
	void set_Phone(string Ph_no) { this->Ph_no = Ph_no; }
	void set_idCard(string id_card) { this->id_card = id_card; }
	void set_Gender(string gen) { this->gen = gen; }
	void set_Address(string address) { this->address = address; }

	string get_name(string name) { return this->name; }
	string get_Phone(string Ph_no) { return this->Ph_no; }
	string get_idCard(string id_card) { return this->id_card; }
	string get_Gender(string gen) { return this->gen; }
	string get_Address(string address) { return this->address; }

	void disPatient() {
		cout << "Displaying Data for Patient\n";
		cout << "Name:" << name << endl;
		cout << "ID Card:" << id_card << endl;
		cout << "Phone:" << Ph_no << endl;
		cout << "Gender:" << gen << endl;
		cout << "Address:" << address << endl;
	}
};


class Guest :public Patient {
protected:
	string status;
public:
	Guest() {}
	Guest(string status) :status(status) {}
	void enterData() {
		cout << "Enter Name:"; cin >> name;
		cout << "Enter ID Card Number:"; cin >> id_card;
		cout << "Enter Gender:"; cin >> gen;
		cout << "Enter Address:"; cin >> address;
		cout << "Phone Number:"; cin >> Ph_no;
	}
	void setStatus(int i) {
		switch (i) {
		case 1: status = "Fully Vaccinated.\n"; break;
		case 2: status = "Partially Vaccinated.\n"; break;
		}
	}
	string chkStatus() {
		return status;
	}
	void displayDataGuest() {
		cout << "ID card Number:" << id_card << endl;
		cout << "Gender:" << gen << endl;
		cout << "Status:" << status << endl;
	}
};


class Member :public Guest {
	string email, password;
public:
	Member() {}
	Member(string em, string pass) :email(em), password(pass) {
		enterMember();
	}
	void enterMember() {

		gotoxy(x = 5, y = 55);
		cout << "Enter Name:"; getline(cin, name);
		gotoxy(++x, y);
		cout << "Enter ID Card Number:"; getline(cin, id_card);
		gotoxy(++x, y);
		cout << "Enter Gender:"; getline(cin, gen);
		gotoxy(++x, y);
		cout << "Enter Age:"; cin >> age;
		gotoxy(++x, y);
		cout << "Enter Address:"; getline(cin, address);
		gotoxy(++x, y);
		cout << "Phone Number:"; getline(cin, Ph_no);
		gotoxy(++x, y);
		cout << "Login Email:"; getline(cin, email);
		gotoxy(++x, y);
		cout << "Login Password:"; getline(cin, password);
		tableClient.insert(email, password, address, age, name, id_card, gen, Ph_no);
	}
	void displayData(string str) {
		NodeClient<string>* n = tableClient.search(str);
		gotoxy(x = 5, y = 55);
		cout << "Name:" << n->name << endl;
		gotoxy(++x, y);
		cout << "ID card Number:" << n->id_card << endl;
		gotoxy(++x, y);
		cout << "Gender:" << n->gender << endl;
		gotoxy(++x, y);
		cout << "Status:" << n->status << endl;
		gotoxy(++x, y);
		cout << "Address:" << n->address << endl;
		gotoxy(++x, y);
		cout << "Contact Number:" << n->ph << endl;
	}

	void centresVacc(string str) {
		if (str == "islamabad") { cout << ""; }
		else if (str == "lahore") {}
		else if (str == "dikhan") {}
		else if (str == "multan") {}
		else if (str == "faislabad") {}
		else if (str == "karachi") {}
		else if (str == "gujranwala") {}

	}
};
class Country :public Member, Guest {
public:
	void status() {
		cout << "";
	}
};
class World :public Country {

};

class Server : public World {
protected:
	string strEml = "test@case.pk";
	string strPasscode = "Dsaoop123";

public:

	void updateVaccines() {
		string str;
		int key;
		gotoxy(x = 5, y = 55);
		cout << "Enter type of Vaccine you wanna add?\n";
		gotoxy(++x, y);
		cout << ">>";
		getline(cin, str);
		key = hasFn(str, str.length());
		switch (key) {
		case 5: {
			system("cls");
			gotoxy(x = 5, y = 58);
			cout << "Add Number of CanSino Vaccines:";
			cin >> key;
			canSino_vac = canSino_vac + key;
			gotoxy(++x, y);
			cout << "Vaccines added successfully";
			break;
		}
		case 1: {
			system("cls");
			gotoxy(x = 5, y = 58);
			cout << "Add Number of CoronaVac Vaccines:";
			cin >> key;
			corona_vac = corona_vac + key;
			gotoxy(++x, y);
			cout << "Vaccines added successfully";
			break;
		}


		case 4: {
			system("cls");
			gotoxy(x = 5, y = 58);
			cout << "Add Number of Pfizer Vaccines:";
			cin >> key;
			pfizer_vac = pfizer_vac + key;
			gotoxy(++x, y);
			cout << "Vaccines added successfully";
			break;
		}
		case 6: {
			system("cls");
			gotoxy(x = 5, y = 58);
			cout << "Add Number of SinoVac Vaccines:";
			cin >> key;
			sino_vac = sino_vac + key;
			gotoxy(++x, y);
			cout << "Vaccines added successfully";
			break;
		}
		}
		return;
	}
	void disVaccines() {
		gotoxy(x = 5, y = 55);
		cout << "Sinovac Vaccince:" << sino_vac << endl;
		gotoxy(++x, y);
		cout << "CoronaVac Vaccince:" << corona_vac << endl;
		gotoxy(++x, y);
		cout << "Pfizer Vaccine:" << pfizer_vac << endl;
		gotoxy(++x, y);
		cout << "CanSino Vaccine:" << canSino_vac << endl << endl;
		gotoxy(++x, y);
		cout << "Total Vaccines->" << total_vac << endl;
	}
	void disTeam() {
		gotoxy(x = 5, y = 55);
		cout << "Honurable Chairman:";
		cout << chrman;
		gotoxy(++x, y);
		cout << "Vice Chairman:";
		cout << vcchrman;
		gotoxy(++x, y);
		cout << "Head of Director:";
		cout << HODirec;
		gotoxy(++x, y);
		cout << "Head of notification:";
		cout << HONoti;
	}
	void updateTeam() {
		gotoxy(x = 5, y = 55);
		cout << "Change Chairman:";
		getline(cin, chrman);
		gotoxy(++x, y);
		cout << "Change Vice Chairman:";
		getline(cin, vcchrman);
		gotoxy(++x, y);
		cout << "Change Head of Director:";
		getline(cin, HODirec);
		gotoxy(++x, y);
		cout << "Change Head of notification:";
		getline(cin, HONoti);
	}
	void fillPatient() {
		string i;
		string str;
		gotoxy(x = 5, y = 55);
		cout << "Enter patient data\n";
		gotoxy(++x, y);
		cout << "City(key):";
		getline(cin, str);
		gotoxy(++x, y);
		cout << "Enter ID Card Number:";
		cin >> i;

		tableServer.insert(str, i);
	}
};