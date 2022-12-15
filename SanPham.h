#pragma once
#include<ctime>
#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>

using namespace std;
struct san_pham
{
	string ma_sp;
	string ten_sp;
	//string ma_ncc;
	int dg_nhap = 0;
	int dg_ban = 0;
	int sl = 0;
	int da_ban = 0;
};
struct Node
{
	san_pham data;
	Node* next = NULL;
};
typedef struct Node* node;
class ds_sp
{
private:
	node sp;
	int slsp;
public:
	ds_sp();
	~ds_sp();
	int kt_trung(string a);
	string tao_masp();
	void themsp(san_pham, string);
	int timmsp(string maspx);
	void docFile();
	void ghiFile();
	void xoasp(string);
	void thaydoi(string);
	void in();
	int getSLSP();
	void inds();
	void inds(string, int);
	string getName(string);
	int get_gia_ban(string);
	void set_da_ban(string, int);
	void inds1();
	void inds1(string, int);
	void set_sl(string, int);
	int kt_hang(string msp,int sl);
	int getSl(string);
	int get_tiennhap();
	
	
};
node makeNode(san_pham x);
istream& operator >>(istream& in, san_pham& x);
ostream& operator <<(ostream& out, const san_pham& x);

