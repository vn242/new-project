#pragma once
#include <ctime>
#include <iostream>
#include<string>
using namespace std;
class Date {
    int year, month, day;
public:
    Date();
    Date(int, int, int);
    ~Date();
    string getYear();
    string getMonth();
    string getDay();
    string getDate();

};
