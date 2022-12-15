#pragma once
#include<ctime>
#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
#include"Nguoi.h"
#include"DoHoa.h"
#include"donhang.h"
using namespace std;
class nhan_vien:public Person
{
private:
	string ma_nv;
	string chuc_vu;
	int luong;
	int sldh;
	string madh[20];

public:
	nhan_vien();
	~nhan_vien();
	friend istream& operator >>(istream&, nhan_vien&);
	friend ostream& operator <<(ostream&, const nhan_vien&);
	void in();
	void set_ma_nv(string a);
	void set_chuc_vu(string);
	void set_luong(int);
	string get_ma_nv();
	string get_chuc_vu();
	int get_luong();
	void set_sldh(int);
	void set_madh(string, int);
	int get_sldh();
	string get_madh(int);
	void themdh(string);
	//string get_tennv(string);
	virtual void nhap();
	int getsldh();
	
};
class ds_nv
{
private:
	nhan_vien n[10];
	int sl5;
	
public:
	ds_nv();
	~ds_nv();
	void docFile();
	void ghiFile();
	void in();
	int getSl();
	void nhap();
	void xuat();
	void themdh1(string, string);
	void inttnv();
	void inttnv1();
	bool checkManv(string);
	string getManvban(string);
	string get_tennv(string);
	int getsldh(string);
	void getdh(string);
	int get_tongluong();
	int getThuong(string);
	int getTongThuong();
	int getDt(string);
	string getMaxdt();
};
