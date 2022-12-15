#pragma once

#include<ctime>
#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
#include"DoHoa.h"

using namespace std;
class Person
{
protected:
	string cmnd;
	string name;
	int age;
	string dia_chi;
	string sdt;
public:
	Person();
	~Person();
	friend istream& operator >>(istream&,Person&);
	friend ostream& operator <<(ostream&, const Person&);
	int getAge();
	string getName();
	string getCmnd();
	string get_dia_chi();
	string get_sdt();
	void setName(string);
	void setAge(int);
	void setCmnd(string);
	void setDiaChi(string);
	void setSdt(string);
	void in();
	virtual void nhap();

};
 