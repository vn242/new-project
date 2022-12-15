#pragma once
#include<ctime>
#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
#include"SanPham.h"
#include"DoHoa.h"
#include <windows.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include"khachhang.h"
#include"NhanVien.h"
#include"Date1.h"
using namespace std;
struct sp
{
	string masp = "";
	int sl = 0;
};
typedef struct sp SP;
struct don_hang
{
	string sdt;
	string ma_dh;
	SP g[10];
	int tien=0;
	int slspmua = 0;
	Date date;
	
};
struct Nodes
{
	don_hang data;
	Nodes* next = NULL;
};
typedef struct Nodes* nodes;
class ds_dh
{
private:
	nodes dh;
	int sl;
	//int dt;
public:
	ds_dh();
	~ds_dh();
	int kt_trung(string a);
	string tao_madh();
	void themdh(don_hang, string, string);
	void docFile();
	void ghiFile();
	string getSdt(string);
	int getSlsp(string);
	string getMsp(string, int);
	int getSlspmua(string, int);
	//void docFile();
	int demDh(string);
	int demDh();
	int doanhthu(string);
	void InHoaDon(string);
	int getTien(string);
	int getTongDT();
	void in(string);
	bool checkMdh(string);
	int getDt();
	int getMax();
	string getPerson();
	string getIdMax();
	int inmnv(string,int);
	int inmnv1(string, int);
	string getDate(string);
	
};
nodes makeNodes(don_hang x);
