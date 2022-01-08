#pragma once
#include<iostream>
#include<string>
#include"All_Classes.h"
#include"hashtableClient.h"
using namespace std;
HashTableClient<string> table;
class SUBMENU :public Server {
	int i = 0;
	string strEmail;
	string strPass;
	string loginEmail;
	string loginPass;
public:
	SUBMENU() {}
	int choiceClient() {
		gotoxy(x = 5, y = 55);
		cout << "1.Login\n";
		gotoxy(++x, y);
		cout << "2.Guest\n";
		gotoxy(++x, y);
		cout << "3.Get Register Now?\n";
		gotoxy(++x, y);
		cout << "4.Exit\n";
		gotoxy(++x, y);
		cout << ">> ";
		cin >> i;
		switch (i) {
		case 1: {
			gotoxy(x = 3, y = 55);
			cout << "\t\t\tWelcome to Vaccination Managment System\n";
			gotoxy(++x, y);
			cout << "\t\tPlease Enter your Log in ID\n";
			gotoxy(++x, y);
			cout << "Email:"; getline(cin, loginEmail);
			gotoxy(++x, y);
			if (table.searchEmail(loginEmail)) {
				cout << "Password:"; getline(cin, loginPass);
				if (table.searchPass(loginEmail, loginPass)) {
					while (1) {
						system("cls");
						gotoxy(x = 5, y = 55);
						cout << "1.Check Your Status\n";
						gotoxy(++x, y);
						cout << "2.Check Country status\n";
						gotoxy(++x, y);
						cout << "3.Check World status\n";
						gotoxy(++x, y);
						cout << "4.Check Near Vaccination Centre\n";
						gotoxy(++x, y);
						cout << "5.Any Newest Update\n";
						gotoxy(++x, y);
						cout << "6.Apply for Vaccination\n";
						gotoxy(++x, y);
						cout << "7.Logout\n";
						gotoxy(++x, y);
						cout << ">> ";
						cin >> i;
						switch (i) {
						case 1:

							break;
						case 2:
							break;
						case 3:
							break;
						case 4:
							break;
						case 5:
							break;
						case 6:
							break;
						case 7:
							break;
						}
						break;
					}
				}
			}
		}
		case 2: {
			while (1) {
				system("cls");
				gotoxy(x = 5, y = 55);
				cout << "1.Check Country Status";
				gotoxy(++x, y);
				cout << "2.Wanna Apply for Vaccination?? Get Register Now";
				gotoxy(++x, y);
				cout << "3.Exit\n";
				gotoxy(++x, y);
				cout << ">> ";
				cin >> i;
				switch (i) {
				case 1:

					break;
				case 2:
					enterMember();
					break;
				case 3:
					return 0;
				}
				break;
			}
		}
		}

		return 0;
	}

	void choiceServer() {

		gotoxy(x = 3, y = 55);
		cout << "\t\t\tWelcome to Server\n";
		gotoxy(++x, y);
		cout << "\t\tPlease Enter your Server Log in ID\n";
		gotoxy(++x, y);
		cout << "Email:"; getline(cin, strEmail);
		gotoxy(++x, y);
		if (strEmail == strEml) {
			cout << "Password:"; getline(cin, strPass);
			if (strPass == strPasscode) {
				while (1) {
					system("cls");
					gotoxy(x = 5, y = 55);
					cout << "1.Update Vaccines";
					gotoxy(++x, y);
					cout << "2.Display Vaccines";
					gotoxy(++x, y);
					cout << "3.Display Team";
					gotoxy(++x, y);
					cout << "4.Update Team";
					gotoxy(++x, y);
					cout << "5.Add Vaccinated patient.";
					gotoxy(++x, y);
					cout << "6.Logout";
					gotoxy(++x, y);
					cout << ">>  ";
					cin >> i;
					cin.ignore();
					switch (i) {
					case 1:
						system("cls");
						updateVaccines();
						break;
					case 2:

						system("cls");
						disVaccines();
						break;
					case 3:

						system("cls");
						disTeam();
						break;
					case 4:

						system("cls");
						updateTeam();
						break;
					case 5:
						system("cls");
						fillPatient();
						break;
					case 6:
						return;
					}
				}
			}
			else {
				gotoxy(++x, y);
				cout << "Password Not Matched!\n";
				gotoxy(++x, y);
				cout << "(Kindly read Confidential Note Given in Documents)\n";
			}
		}
		else {
			gotoxy(++x, y);
			cout << "Email Not Matched!\n";
			gotoxy(++x, y);
			cout << "(Kindly read Confidential Note Given in Documents)\n";
		}
	}
};
