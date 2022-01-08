#pragma once
#include<iostream>
#include<cmath>
#include <ctime>
#include"All_Classes.h"
using namespace std;

void Time()
{
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    gotoxy(2, 85);
    cout << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 ;
    gotoxy(4, 85);
    cout << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << ":" << (tPtr->tm_sec) ;
}
