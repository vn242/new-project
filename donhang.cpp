#include"donhang.h"
ds_dh::ds_dh()
{
	dh = new Nodes();
	dh->next = NULL;
	sl = 0;
	
}
ds_dh::~ds_dh()
{
	sl = 0;
	//delete[]dh;
}
nodes makeNodes(don_hang x)
{
	nodes tmp = new Nodes();
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}
int ds_dh::kt_trung(string a)
{
	nodes p = dh;
	while (p != NULL)
	{
		if (p->data.ma_dh == a)return 1;
		p = p->next;
	}
	return -1;
}
string ds_dh::tao_madh()
{
	string a = "DH0000";
	do
	{
		for (int i = 2; i < a.length(); i++)
		{
			a[i] = rand() % (57 - 48 + 1) + 48;
		}
	} while (kt_trung(a) >= 0);
	return a;
}
void ds_dh::themdh(don_hang p, string a, string b)
{
	TextColor(7);
	p.ma_dh = a;
	p.sdt = b;
	ds_sp d;
	ds_dh t;
	t.docFile();
	d.docFile();
	int k = 1;
	int i = 1;
	int h = 0;
	do
	{
		while (k == 1)
		{
			gotoXY(95, 6); cout << "       ";
			gotoXY(95, 8); cout << "        ";
			gotoXY(95, 6); cin >> p.g[i].masp;
			if (d.timmsp(p.g[i].masp) != -1)k = 0;
		}
		while (k == 0)
		{
			gotoXY(95, 8); cout << "        ";
			gotoXY(95, 8); cin >> p.g[i].sl;
			if (d.getSl(p.g[i].masp) >= p.g[i].sl) {

				k = 1;
				d.set_da_ban(p.g[i].masp, p.g[i].sl);
				d.set_sl(p.g[i].masp, p.g[i].sl);
			}
			else
			{
				k = 0;
			}
		}

		char h1[30] = "Ban co muon mua them khong";
		char h2[30] = "Thong bao";
		int result = MessageBox(NULL, convertCharArrayToLPCWSTR(h1), convertCharArrayToLPCWSTR(h2), MB_OKCANCEL);
		if (result == IDOK)
		{

			gotoXY(85, 14 + i - 1); cout << d.getName(p.g[i].masp);
			gotoXY(100, 14 + i - 1); cout << p.g[i].sl;
			i++;

		}
		if (result == IDCANCEL)
		{

			h = 1;
			p.slspmua = i;
			gotoXY(85, 14 + i - 1); cout << d.getName(p.g[i].masp);
			gotoXY(100, 14 + i - 1); cout << p.g[i].sl;
			for (int j = 1; j <= p.slspmua; j++)
			{
				p.tien += (p.g[j].sl * d.get_gia_ban(p.g[j].masp));
			}
			gotoXY(76, 26); cout << "Loai Khach Hang: ";
			if (t.doanhthu(b) <= 300000) {
				cout << "Moi";
				
			}
			else if (t.doanhthu(b) <= 2000000) {
				cout << "Thuong xuyen DISCOUNT :5%";
				p.tien = p.tien * 0.95;
			}
			else {
				cout << "VIP DISCOUT :10%";
				p.tien = p.tien * 0.9;
			}

			gotoXY(76, 28); cout << "Tong tien: " << p.tien;
			nodes tmp = makeNodes(p);
			if (sl == 0)
			{
				dh = tmp;
			}
			else
			{
				tmp->next = dh;
				dh = tmp;
			}
			sl += 1;
			d.ghiFile();

		}
	} while (h == 0);

}

void ds_dh::ghiFile()
{
	nodes p = dh;
	ofstream fileout;
	fileout.open("DsDonHang.txt", ios_base::out);
	while (p != NULL)
	{
		fileout << p->data.ma_dh << "," << p->data.sdt << "," << p->data.slspmua << ",";
		for (int i = 1; i <= p->data.slspmua; i++)
		{
			fileout << p->data.g[i].masp << ",";
			fileout << p->data.g[i].sl << ",";
		}
		fileout << p->data.tien << ",";
		fileout << p->data.date.getDay() << ",";
		fileout << p->data.date.getMonth() << ",";
		fileout << p->data.date.getYear() << ",";
		p = p->next;
		if (p != NULL)
		{
			fileout << endl;
		}
	}

	fileout.close();
	
}
void ds_dh::docFile()
{
	ifstream filein;
	filein.open("DsDonHang.txt", ios_base::in);
	while (filein.eof() != true)
	{
		don_hang p;
		getline(filein, p.ma_dh,',');
		getline(filein, p.sdt, ',');
		filein >> p.slspmua;
		filein.ignore();
		for (int i = 1; i <= p.slspmua; i++)
		{
			getline(filein, p.g[i].masp, ',');
			filein >> p.g[i].sl;
			filein.ignore();
		}
		filein >> p.tien;
		filein.ignore();
		int day, month, year;
		filein >> day;
		filein.ignore();
		filein>>month;
		filein.ignore();
		filein >> year;
		filein.ignore();
		
		//getline()
		filein.ignore();
		//filein.ignore();
		p.date = Date(day, month, year);
		nodes tmp = makeNodes(p);
		if (sl == 0)
		{
			dh = tmp;
		}
		else
		{
			tmp->next = dh;
			dh = tmp;
		}
		sl += 1;
	}
	filein.close();
}
int ds_dh::demDh(string b)
{
	nodes p = dh;
	int k = 0;
	while (p != NULL)
	{
		if (p->data.sdt == b)k += 1;
		p = p->next;
	}
	return k;
}
int ds_dh::doanhthu(string b)
{
	nodes p = dh;
	int k = 0;
	while (p != NULL)
	{
		if (p->data.sdt == b)
		{
			k += p->data.tien;
		}
		p = p->next;
	}
	return k;
}
void ds_dh::InHoaDon(string a)
{
	nodes p = dh;
	while (p != NULL)
	{
		if (p->data.ma_dh == a)
		{

		}
	}

}
string ds_dh::getSdt(string a)
{
	nodes p = dh;
	while (p != NULL)
	{
		if (p->data.ma_dh == a)return p->data.sdt;
		p = p->next;
	}
	return "hello";
}
int ds_dh::getSlsp(string a)
{
	nodes p = dh;
	while (p != NULL)
	{
		if (p->data.ma_dh == a)return p->data.slspmua;
		p = p->next;
	}
	return -1;
}
string ds_dh::getMsp(string a, int n)
{
	nodes p = dh;
	while (p != NULL)
	{
		if (p->data.ma_dh == a)
		{
			return p->data.g[n].masp;
		}
		p = p->next;
	}
	return "";
}
int ds_dh::getSlspmua(string a, int n)
{
	nodes p = dh;
	while (p != NULL)
	{
		if (p->data.ma_dh == a)
		{
			return p->data.g[n].sl;
		}
		p = p->next;
	}
	return -1;

}
int ds_dh::getTongDT() {
	nodes p = dh;
	int sum = 0;
	while (p != NULL)
	{
		sum += p->data.tien;
		p = p->next;
	}
	return sum;
}
int ds_dh::getTien(string a)
{
	nodes p = dh;
	while (p != NULL)
	{
		if (p->data.ma_dh == a)
		{
			return p->data.tien;
		}
		p = p->next;
	}
	return -1;
}
string ds_dh::getDate(string a) {
	nodes p = dh;
	while (p != NULL) {
		if (p->data.ma_dh == a) {
			return p->data.date.getDate();
			
		}
		p = p->next;
	}
	return "";
}
void ds_dh::in(string a)
{
	ds_nv t;
	t.docFile();
	int i = 0;
	nodes p = dh;
	while (p != NULL)
	{
		if (p->data.sdt == a)
		{
			gotoXY(20, 8+2*i); cout << p->data.ma_dh;
			gotoXY(38, 8+2*i); cout << p->data.slspmua;
			gotoXY(52, 8+2*i); cout << p->data.tien;
			gotoXY(70, 8 + 2 * i); cout << t.get_tennv(t.getManvban(p->data.ma_dh));
			gotoXY(85, 8 + 2 * i); cout << p->data.date.getDate();
			i++;
		}
		p = p->next;
	}

}
int ds_dh::inmnv(string a,int i) {
	int sum = 0;
	nodes p = dh;
	while (p != NULL) {
		if (p->data.ma_dh == a) {
			gotoXY(60, 6 + 2 * i); cout << p->data.ma_dh;
			gotoXY(72, 6 + 2 * i); cout << p->data.slspmua;
			gotoXY(100, 6 + 2 * i); cout << p->data.tien;
			gotoXY(85, 6 + 2 * i); cout << p->data.date.getDate();

			sum += p->data.tien;
			//gotoXY(70, 8 + 2 * i); cout << t.get_tennv(t.getManvban(p->data.ma_dh));
		}
		p = p->next;
	}
	return sum;
}
int ds_dh::inmnv1(string a, int i) {
	int sum = 0;
	nodes p = dh;
	while (p != NULL) {
		if (p->data.ma_dh == a) {
			

			sum += p->data.tien;
			//gotoXY(70, 8 + 2 * i); cout << t.get_tennv(t.getManvban(p->data.ma_dh));
		}
		p = p->next;
	}
	return sum;
}
bool ds_dh::checkMdh(string a)
{
	nodes p = dh;
	while (p != NULL)
	{
		if (p->data.ma_dh == a)return true;
		p = p->next;
	}
	return false;
}
int ds_dh::getDt()
{
	int dt = 0;
	nodes p = dh;
	while (p != NULL)
	{
		dt += p->data.tien;
		p = p->next;
	}
	return dt;
}
int ds_dh::getMax()
{
	int max = 0;
	nodes p = dh;
	while (p != NULL)
	{
		if (p->data.tien > max)
		{
			max = p->data.tien;
		}
		p = p->next;
	}
	return max;
}
string ds_dh::getPerson()
{
	nodes p = dh;
	int k = 0;
	string h;
	while (p != NULL)
	{
		if (doanhthu(p->data.sdt) > k)
		{
			k = doanhthu(p->data.sdt);
			h = p->data.sdt;
		}
		p = p->next;
	}
	return h;
}
int ds_dh::demDh()
{
	nodes p = dh;
	int k = 0;
	while (p != NULL)
	{
		++k;
		p = p->next;
	}
	return k;
}
string ds_dh::getIdMax()
{
	nodes p = dh;
	while (p != NULL)
	{
		if (p->data.tien == getMax())
		{
			return p->data.ma_dh;
		}
		p = p->next;
	}
	return "";
}