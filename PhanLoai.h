#pragma once
#include<ctime>
#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
#include"DoHoa.h"
#include<cstring>
#include"SanPham.h"
using namespace std;
struct phan_loai {
	string ma_pl;
	string tenpl;
	int slsp;
	string masp[15];
};
struct Nodet
{
	phan_loai data;
	Nodet* next = NULL;
};
typedef struct Nodet* nodet;
class ds_pl {
private:
	nodet pl;
	int sl;
public:
	ds_pl();
	~ds_pl();
	int kt_trung(string a);
	string tao_mapl();
	void docFile();
	void ghiFile();
	void xuat();
	int getSl();
	string* getTenpl();
	void thempl(phan_loai,string);
	int timmpl(string);
	void themsp(string, string);
	string timvitri(int);
	string getMapl(string);
	string getTenpl(string);
	void inds(string);
	void inds1();
};
nodet makeNodet(phan_loai x);