#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include<stdlib.h>
#include<cstdlib>
#include<string>
#include"Nguoi.h"
#include"DoHoa.h"
#include"menu.h"
#include"donhang.h"
using namespace std;
class khach_hang :public Person
{
private:
	int sldh;
public:
	khach_hang()
	{
		sldh = 0;
	}
	~khach_hang()
	{
	}
	void setSldh(int a)
	{
		sldh = a;
	}
	int getSldh()
	{
		return sldh;
	}
};
class ds_kh
{
private:
	int sl;
	khach_hang n[20];
public:
	ds_kh();
	~ds_kh();
	void docFile();
	void ghiFile();
	int timSdt(string);
	int getsl();
	void them_kh();
	void in();
	string getSdt(int);
	void xoaKh(string);
	void set_sdt(string, string);
	void set_name(string, string);
	string getName(string);
	string getAdd(string);
	
};
