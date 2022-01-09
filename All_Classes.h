#pragma once
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<fstream>
#include"LinkedList.h"
#include<windows.h>
#include<string>
#include "hashtableServer.h"
#include "hashtableClient.h"
int x = 5;  int y = 55;
static int sino_vac = 50;
static int pfizer_vac = 50;
static int canSino_vac = 50;
static int corona_vac = 50;
static int total_vac = sino_vac + pfizer_vac + canSino_vac + corona_vac;
static string chrman = "PM Imran Khan", vcchrman = "Asad Omer", HODirec = "Lt Gen Mamood hassan", HOHealth = "Dr Faisal Sultan";
HashTableServer<string> tableServer(13);
HashTableClient<string> tableClient;
static string countries[10][2];
int gen_key(string key, int ts) {
	int idx = 0;
	int power = 1;
	for (auto ch : key) {
		idx = (idx + ch * power) % ts;
		power = (power * 29) % ts;
	}
	return idx;
}


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
	string status = "not Vaccinated";
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
	string announce;
public:
	Member() {}
	Member(string em, string pass) :email(em), password(pass) {
		enterMember();
	}
	void enterMember() {
		ofstream myFile("Member.csv", ios::app | ios::in);
		gotoxy(x = 5, y = 55);
		cout << "Enter Name:"; getline(cin, name);
		gotoxy(++x, y);
		cout << "Enter ID Card Number:"; getline(cin, id_card);
		gotoxy(++x, y);
		cout << "Enter Gender:"; getline(cin, gen);
		gotoxy(++x, y);
		cout << "Enter Age:"; cin >> age;
		cin.ignore();
		cin.ignore();
		gotoxy(++x, y);
		cout << "Enter Address:"; getline(cin, address);
		gotoxy(++x, y);
		cout << "Phone Number:"; getline(cin, Ph_no);
		gotoxy(++x, y);
		cout << "Login Email:"; getline(cin, email);
		gotoxy(++x, y);
		cout << "Login Password:"; getline(cin, password);
		tableClient.insert(email, password, address, age, name, id_card, gen, Ph_no);
		myFile << name << "," << id_card << "," << gen << "," << email << "," << password << "," << address << "," << age << "," << Ph_no << status << endl;
		//filehandling
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
		if (str == "islamabad") {
			cout << "Quaid e Azam International Hospital, Street 9, G-8/2 G 8/2 G-8, Islamabad \t Contact Numbers \t 051-8449100/03345083009" << endl;
			cout << "NIRM, Near Murree Express Highway Islamabad \t Contact Numbers \t 051-9262213/03315377687" << endl;
			cout << "Akbar Niazi Teaching Hospital, Mohran Jejan, Islamabad \t Contact Numbers \t 051-8153000/03335233785" << endl;
			cout << "PIMS Hospital G-8/3, Bhara Kahu, Islamabad \t Contact Numbers \t 051-9261170/ 03332371584" << endl;
			cout << "Polyclinic, Chakshahzad Islamabad \t Contact Numbers \t 051-9220379/ 03003272441" << endl;
			cout << "National Institute of Health (NIH) Vaccination Center, Islamabad, G- Kashmir Hwy, 1, Service Road South, G 9/1 G-9, Islamabad \t Contact Numbers 051-9255566/03319816350" << endl;

		}
		else if (str == "lahore") {
			cout << "";
			cout << "Indus Hospital, Sabzazar \t Contact Numbers \t 0321-4196605 " << endl;
			cout << "Indus Hospital, Raiwind \t Contact Numbers \t 0333-9699948  " << endl;
			cout << "National Hospital, DHA Phase-1, Lahore \t Contact Numbers \t 0309-7060786  " << endl;
			cout << "Data Darbar, Lower Mall, Lahore \t Contact Numbers \t 0324-4673454 " << endl;
			cout << "United Christian Hospital, Main Boulevard, Gulberg \t Contact Numbers \t 03134073644" << endl;
		}
		else if (str == "dikhan") {
			cout << "";
			cout << " BHU Gomal University" << endl;
			cout << "BHU Jabbar Wala" << endl;
			cout << "BHU Maddi Khel " << endl;
			cout << "BHU Giloty" << endl;
			cout << "BHU Maddi Khel " << endl;
		}
		else if (str == "multan") {
			cout << "GOVT. MUSHTAQ LANG THQ HOSP.JALALPUR PIRWALA" << endl;
			cout << "NISHTER INSTITUTE OF DENTISTRY" << endl;
			cout << "Pak Italian Modern Burn Centre, Nishtar Medical University Multan " << endl;
			cout << "Rural Health Centre Makhdoom Rashid" << endl;
			cout << "ddho office,jalalpur pirwala" << endl;
			cout << "Government WAPDA Hospital Multan " << endl;
		}
		else if (str == "faislabad") {
			cout << "" << endl;
			cout << "Rural Health Centre Khurrianwala" << endl;
			cout << "Sports Complex Chak Jhumra" << endl;
			cout << "THQ HOSPITAL CHAK JGovernment WAPDA Hospital Multan HUMRA" << endl;
			cout << "THQ HOSPITAL SUMUNDRI " << endl;
			cout << "THQ Hospital New Building, Tandlianwala" << endl;
		}
		else if (str == "gujranwala") {
			cout << "AC office Kamoke " << endl;
			cout << "Rural Health Center, Ali Pur Chatha , Wazirabad, Gujranwala" << endl;
			cout << "Rural Health Center, Kot Ladha , Nowshera Virkan, Gujranwala" << endl;
			cout << "Wapda Hospital, Gujranwala" << endl;
			cout << "Cantt. General Hospital, Rawali Cantt. Gujranwala " << endl;
			cout << "Commnuity School Hall, Wapda Town, Gujranwala" << endl;

		}
		else if (str == "peshawar") {
			cout << "Hayat Abad Medical Complex Hayatabad 1" << endl;
			cout << "Cantt General Hospital Peshawar" << endl;
			cout << "AL-Khidmat Hospital" << endl;
			cout << "Bacha Khan Air port" << endl;
			cout << "Cantt General Hospital Peshawar" << endl;
			cout << "Clerk Colony/Civil quartar Nothia Qadeem" << endl;

		}
	}


	void worldStatus() {
		gotoxy(x = 5, y = 55);
		for (int i = 0; i < 10; i++) {
			gotoxy(++x, y);
			cout << countries[i][0] << "   " << countries[i][1];
		}
	}
	void apply(string str) {
		ofstream myFile("Applications.csv", ios::app | ios::in);
		NodeClient<string>* n = tableClient.search(str);
		status = "Applied!";
		myFile << n->name << "," << n->id_card << "," << n->gender << "," << n->email << "," << "," << age << "," << Ph_no << status << endl;
		gotoxy(x = 7, y = 55);
		cout << "Successfully Applied!";
		gotoxy(++x, y);
		system("pause");
	}
};
class Country :public Member {
public:
	void status() {
		cout << "";
	}
};
class World :public Country {

};

class Server : public World {
	void updateCountries() {
		countries[0][0] = "USA";
		countries[1][0] = "UK";
		countries[2][0] = "Dubai";
		countries[3][0] = "Sauida Arabia";
		countries[4][0] = "China";
		countries[5][0] = "Iran";
		countries[6][0] = "Russia";
		countries[7][0] = "Australia";
		countries[8][0] = "New Zealand";
		countries[9][0] = "India";
	}
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
		key = gen_key(str, str.length());
		switch (key) {
		case 5: {
			system("cls");
			gotoxy(x = 5, y = 58);
			cout << "Add Number of CanSino Vaccines:";
			cin >> key;
			canSino_vac = canSino_vac + key;
			gotoxy(++x, y);
			cout << "Vaccines added successfully";
			gotoxy(++x, y);
			system("pause");
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
			gotoxy(++x, y);
			system("pause");
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
			gotoxy(++x, y);
			system("pause");
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
			gotoxy(++x, y);
			system("pause");
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
		gotoxy(++x, y);
		system("pause");
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
		cout << "Head of Health Dep:";
		cout << HOHealth;
		gotoxy(++x, y);
		system("pause");
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
		getline(cin, HOHealth);
		gotoxy(++x, y);
		cout << "Team Updated Succesfully";
		gotoxy(++x, y);
		system("pause");
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
		gotoxy(x = 14, y);
		cout << "Patient Added Succesfuly";
		gotoxy(++x, y);
		system("pause");
		return;
	}
	void upWorldStatus() {
		updateCountries();
		string str;
		int i;
		while (1) {
			gotoxy(x = 5, y = 55);
			cout << "1.Specific country you wanna update?";
			gotoxy(++x, y);
			cout << "2.All countries?";
			cin >> i;
			cin.ignore();
			switch (i) {
			case 1:
				gotoxy(++x, y);
				cout << "Enter country name:";
				getline(cin, str);
				for (int i = 0; i < 10; i++) {
					if (str == countries[i][0]) {
						gotoxy(++x, y);
						cout << "Write new number of cases report in " << countries[i][0] << "::";
						getline(cin, countries[i][1]);
						gotoxy(++x, y);
						cout << "Country Updated Successfully";
						gotoxy(++x, y);
						system("pause");
						break;
					}
				}
				break;
			case 2:
				gotoxy(++x, y);
				cout << "Update All countries data.";
				for (int j = 0; j < 10; j++) {
					gotoxy(++x, y);
					cout << countries[j][0] << "::";
					getline(cin, countries[j][1]);
				}
				gotoxy(++x, y);
				cout << "All Country Updated Successfully";
				gotoxy(++x, y);
				system("pause");
				break;
			}
			break;
		}
		return;
	}
	void upCountryStatus() {

	}
	void chkApplications() {

	}
	void chkPatients() {
		tableServer.print();
		gotoxy(++x, y);
		system("pause");
		return;
	}
	void chkTotalMembers() {
		tableClient.print();
		gotoxy(++x, y);
		system("pause");
		return;
	}
};