#include"khachhang.h"
ds_kh::ds_kh()
{
	sl = 0;
}
ds_kh::~ds_kh()
{
	sl = 0;
	//delete[]n;
}
void ds_kh::docFile()
{
	
	ifstream filein;
	filein.open("DsKhachHang.txt", ios_base::in);
	int i = 1;

	while (filein.eof() != true)
	{
		string name = "";
		getline(filein, name, ',');
		n[i].setName(name);
		string sdt = "";
		getline(filein, sdt, ',');
		n[i].setSdt(sdt);
		int a;
		//filein.ignore();
		filein >> a;
		n[i].setSldh(a);
		i += 1;
		filein.ignore();
		sl += 1;
		filein.ignore();
		
	}
	filein.close();
}
int ds_kh::getsl()
{
	return sl;
}
void ds_kh::in()
{
	ds_dh d;
	d.docFile();
	for (int i = 1; i <= sl; i++)
	{
		gotoXY(14, 8 + 2*i - 2); cout << i;
		//cout << "Ho va ten: " << n[i].getName() << endl;
		//cout << "SDT: " << n[i].get_sdt() << endl;
		gotoXY(29, 8 + 2 * i - 2); cout << n[i].getName();
		gotoXY(44, 8 + 2 * i - 2); cout << n[i].get_sdt();
		gotoXY(59, 8 + 2 * i - 2); cout << d.demDh(n[i].get_sdt());
		gotoXY(75, 8 + 2 * i - 2); cout << d.doanhthu(n[i].get_sdt());
		gotoXY(92, 8 + 2 * i - 2);
		if (d.doanhthu(n[i].get_sdt()) <= 300000) {
			cout << "Moi";
		}
		else if (d.doanhthu(n[i].get_sdt()) <= 2000000) {
			cout << "Thuong xuyen";
		}
		else cout << "VIP";


	}
}
void ds_kh::them_kh()
{
	int g = 1;
	while (g == 1)
	{
		string name;
		gotoXY(22, 4); 
		cin >> name;
		//cin.ignore();
		
		string sdt;
		gotoXY(22, 6); cin >> sdt;
		
		int a = timSdt(sdt);
		if (a != -1)
		{
			int result;
			char h1[30] = "SDT da ton tai";
			char h2[30] = "Thong bao";
			result = MessageBox(NULL, convertCharArrayToLPCWSTR(h1), convertCharArrayToLPCWSTR(h2), MB_OKCANCEL);
			if (result == IDOK)
			{

				gotoXY(22, 4); cout << "          ";
				gotoXY(22, 6); cout << "          ";

			}
			else
			{
				TextColor(0);
				system("cls");
				menu_chinh();
				break;

			}
		}
		else
		{
			g = 0;
			sl += 1;
			n[sl].setName(name);
			n[sl].setSdt(sdt);
			
		}
	}

	
}

string ds_kh::getSdt(int a)
{
	return n[a].get_sdt();
}
int ds_kh::timSdt(string a)
{
	for (int i = 1; i <= sl; i++)
	{
		if(a == n[i].get_sdt())return i;
	}
	return -1;
}
void ds_kh::xoaKh(string b)
{
	int a = timSdt(b);
	if (a == -1)cout << "Khong tim thay khach hang";
	else
	{
		for (int i = a; i <= sl; i++)
		{
			string name = n[i + 1].getName();
			string sdt = n[i + i].get_sdt();
			n[i].setName(name);
			n[i].setSdt(sdt);
		}
		sl -= 1;
	}

}
void ds_kh::ghiFile()
{
	ofstream fileout;
	fileout.open("DsKhachHang.txt", ios_base::out);
	int i = 1;
	while (i <= sl)
	{
		fileout << n[i].getName() << "," << n[i].get_sdt() << "," << n[i].getSldh() << ",";
		i += 1;
		if (i <= sl)
		{
			fileout << endl;
		}
	}
	fileout.close();
}
void ds_kh::set_sdt(string b, string c)
{
	int a = timSdt(b);
	n[a].setSdt(c);
}
void ds_kh::set_name(string b, string c)
{
	int a = timSdt(b);
	n[a].setName(c);
}
string ds_kh::getName(string b)
{
	int a = timSdt(b);
	return n[a].getName();
}
string ds_kh::getAdd(string b)
{
	int a = timSdt(b);
	return n[a].get_dia_chi();
}
