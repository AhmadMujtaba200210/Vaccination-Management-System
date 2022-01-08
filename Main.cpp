#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<string.h>
#include"LinkedList.h"
#include"All_Classes.h"
#include"Time.h"
#include"SubMain.h"
#include<windows.h>


int main() {
	int i;
	SUBMENU sb;
	while (1) {
		system("cls");
		gotoxy(x, y);
		cout << "1.Client Side\n";
		gotoxy(++x, y);
		cout << "2.Server Side\n";
		gotoxy(++x, y);
		cout << "3.Exit\n";
		gotoxy(++x, y);
		cout << ">>  ";
		cin >> i;
		switch (i) {
		case 1: {
			cin.ignore();
			system("cls");
			sb.choiceClient();
			break;
		}
		case 2: {
			cin.ignore();
			system("cls");
			sb.choiceServer();
			break;
		}
		case 3: return(0);
		}
	}
}