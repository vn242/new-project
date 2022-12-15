#include"SanPham.h"
#include"DoHoa.h"
#include"menu.h"
using namespace std;
ds_sp::ds_sp()
{
	sp = new Node();
	sp->next = NULL;
	slsp = 0;
}
ds_sp::~ds_sp()
{
	//slsp = 0;
	//delete[]sp;
}
void ds_sp::themsp(san_pham x, string a)
{
	x.ma_sp = a;
	cin >> x;
	
	node tmp = makeNode(x);
	if (slsp == 0)
	{
		sp = tmp;
	}
	else
	{
		tmp->next = sp;
		sp = tmp;
	}
	slsp += 1;
}
int ds_sp::timmsp(string maspx)
{
	node p = sp;
	int k = 0;
	while (p != NULL)
	{
		++k;
		if (p->data.ma_sp == "")
		{
			--k;
		}
		
		if (p->data.ma_sp == maspx) return k;
		p = p->next;
	}
	return -1;
	

}
void ds_sp::xoasp(string maspx)
{
	node truoc = NULL, sau = sp;
	int pos = timmsp(maspx);
	if (pos == -1)
	{
		int result;
		char h1[30] = "Khong tim thay san pham";
		char h2[30] = "Thong bao";
		result = MessageBox(NULL, convertCharArrayToLPCWSTR(h1), convertCharArrayToLPCWSTR(h2), MB_OKCANCEL);
		if (result == IDOK)
		{
			TextColor(0);
			system("cls");
			menu();
		}
		else
		{
			exit(0);
		}
	}
	else
	{
		slsp -= 1;

		for (int i = 1; i < pos; i++)
		{
			truoc = sau;
			sau = sau->next;
		}
		if (truoc == NULL)
		{
			sp = sp->next;
		}
		else
		{
			truoc->next = sau->next;
		}
		ghiFile();
		int result;
		char h1[30] = "Da xoa thanh cong";
		char h2[30] = "Thong bao";
		result = MessageBox(NULL, convertCharArrayToLPCWSTR(h1), convertCharArrayToLPCWSTR(h2), MB_OKCANCEL);
		if (result == IDOK)
		{
			TextColor(0);
			system("cls");
			menu();
		}
		else
		{
			exit(0);
		}

	}
	
	
}
void ds_sp::in()
{

	node p = sp;
	while (p != NULL)
	{
		
		cout << p->data << endl;
		p = p->next;
	}
}
void ds_sp::inds()
{
	node p = sp;
	int i = 0;
	while (p != NULL)
	{
		
			gotoXY(12, 8+i); cout << i+1;
			gotoXY(12 + 13, 8+i); cout << p->data.ten_sp;
			gotoXY(12 + 2*13, 8+i); cout << p->data.ma_sp;
			//gotoXY(12 + 3 * 13, 8+i); cout << "NCC";
			gotoXY(12 + 3 * 13, 8+i); cout << p->data.sl;
			gotoXY(12 + 4 * 13, 8+i); cout << p->data.dg_nhap;
			gotoXY(12 + 5 * 13, 8+i); cout << p->data.dg_ban;
			gotoXY(12 + 6 * 13, 8+i); cout << p->data.da_ban;
		
		p = p->next;
		i += 1;
		
	}
}
void ds_sp::inds(string t, int i)
{
	node p = sp;
	
	while (p != NULL)
	{
		if (p->data.ma_sp == t) {
			gotoXY(12, 8 + i); cout << i + 1;
			gotoXY(12 + 13, 8 + i); cout << p->data.ten_sp;
			gotoXY(12 + 2 * 13, 8 + i); cout << p->data.ma_sp;
			//gotoXY(12 + 3 * 13, 8+i); cout << "NCC";
			gotoXY(12 + 3 * 13, 8 + i); cout << p->data.sl;
			gotoXY(12 + 4 * 13, 8 + i); cout << p->data.dg_nhap;
			gotoXY(12 + 5 * 13, 8 + i); cout << p->data.dg_ban;
			gotoXY(12 + 6 * 13, 8 + i); cout << p->data.da_ban;
			
		}
		

		p = p->next;

	}
}
istream& operator >>(istream& in, san_pham& x)
{
	//cout << "Nhap masp: "; in >> x.ma_sp;
	
	gotoXY(12 + 13 +13, 8);
	//in.ignore();
	getline(in, x.ten_sp);
	
	//getline(in, x.ten_sp);
	//fflush(stdin);
	//in >> x.ten_sp;
	//gotoXY(12 + 3*13, 8); in >> x.ma_ncc;
	gotoXY(12 + 3 * 13, 8); in >> x.dg_nhap;
	gotoXY(12 + 4 * 13, 8); in >> x.dg_ban;
	gotoXY(12 + 5 * 13, 8); in >> x.sl;

	in.ignore();
	return in;
}
ostream& operator <<(ostream& out, const san_pham& x)
{
	out << "MaSp: " << x.ma_sp << endl;
	out << "Ten Sp: " << x.ten_sp << endl;
	//out << "Ma NCC: " << x.ma_ncc << endl;
	out << "Don gia nhap: " << x.dg_nhap << endl;
	out << "Don gia ban: " << x.dg_ban << endl;
	out << "So luong: " << x.sl << endl;
	return out;
}
node makeNode(san_pham x)
{
	node tmp = new Node();
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}
int ds_sp::kt_trung(string a)
{
	node p = sp;
	while (p != NULL)
	{
		if (p->data.ma_sp == a)return 1;
		p = p->next;
	}
	return -1;

}
string ds_sp::tao_masp()
{

	string a = "SP0000";
	do
	{
		for (int i = 2; i < a.length(); i++)
		{
			a[i] = rand() % (57 - 48 + 1) + 48;
		}
	} while (kt_trung(a) >= 0);
	return a;
}
void ds_sp::docFile()
{
	ifstream filein;
	filein.open("DsSanPham.txt", ios_base::in);
	while (filein.eof() != true)
	{
		san_pham x;
		getline(filein, x.ma_sp,',');
		getline(filein, x.ten_sp,',');
		filein >> x.dg_nhap;
		filein.ignore();
		filein >> x.dg_ban;
		filein.ignore();
		filein >> x.sl;
		filein.ignore();
		filein >> x.da_ban;
		filein.ignore();
		node tmp = makeNode(x);
		if (slsp == 0)
		{
			sp = tmp;
		}
		else
		{
			tmp->next = sp;
			sp = tmp;
		}
		slsp += 1;

	}
	filein.close();
}
void ds_sp::ghiFile()
{
	node p = sp;
	ofstream fileout;
	fileout.open("DsSanPham.txt", ios_base::out);
	while (p != NULL)
	{
		fileout << p->data.ma_sp << "," << p->data.ten_sp  << "," << p->data.dg_nhap << "," << p->data.dg_ban << "," << p->data.sl <<","<<p->data.da_ban;
		p = p->next;
		if (p != NULL)
		{
			
			fileout << endl;
		}
	}
	fileout.close();
}
int ds_sp::getSLSP()
{
	return slsp;
}
int ds_sp::getSl(string a)
{
	node d = sp;
	while (d != NULL)
	{
		if (d->data.ma_sp == a)return (d->data.sl);
		d = d->next;
	}
	return -1;
}
void ds_sp::set_sl(string a, int b)
{
	ofstream fileout;
	node d = sp;
	fileout.open("DsSanPham.txt", ios_base::out);
	while (d->data.ma_sp != a)
	{
		fileout << d->data.ma_sp << "," << d->data.ten_sp  << "," << d->data.dg_nhap << "," << d->data.dg_ban << "," << d->data.sl << "," << d->data.da_ban;
		if (d != NULL)
		{

			fileout << endl;
		}
		d = d->next;
	}
	d->data.sl -= b;
	while (d != NULL)
	{
		fileout << d->data.ma_sp << "," << d->data.ten_sp  << "," << d->data.dg_nhap << "," << d->data.dg_ban << "," << d->data.sl << "," << d->data.da_ban;
		d = d->next;
		if (d != NULL)
		{

			fileout << endl;
		}
	}


	fileout.close();
}
void ds_sp::set_da_ban(string a, int b)
{
	ofstream fileout;
	node d = sp;
	fileout.open("DsSanPham.txt", ios_base::out);
	while (d->data.ma_sp != a)
	{
		fileout << d->data.ma_sp << "," << d->data.ten_sp  << "," << d->data.dg_nhap << "," << d->data.dg_ban << "," << d->data.sl <<","<<d->data.da_ban;
		if (d != NULL)
		{

			fileout << endl;
		}
		d = d->next;
	}
	d->data.da_ban += b;
	while (d != NULL)
	{
		fileout << d->data.ma_sp << "," << d->data.ten_sp  << "," << d->data.dg_nhap << "," << d->data.dg_ban << "," << d->data.sl << "," << d->data.da_ban;
		d = d->next;
		if (d != NULL)
		{

			fileout << endl;
		}
	}


	fileout.close();
}
int ds_sp::get_gia_ban(string a)
{
	node d = sp;
	while (d != NULL)
	{
		if (d->data.ma_sp == a)return (d->data.dg_ban);
		d = d->next;
	}
	return -1;
}

string ds_sp::getName(string a)
{
	node d = sp;
	while (d != NULL)
	{
		if (d->data.ma_sp == a)return (d->data.ten_sp);
		d = d->next;
	}
	return "";
}
void ds_sp::thaydoi(string a)
{
	int pos = timmsp(a);
	if (pos == -1)
	{
		int result;
		char h1[30] = "Khong tim thay san pham";
		char h2[30] = "Thong bao";
		result = MessageBox(NULL, convertCharArrayToLPCWSTR(h1), convertCharArrayToLPCWSTR(h2), MB_OKCANCEL);
		if (result == IDOK)
		{
			TextColor(0);
			system("cls");
			menu();
		}
		else
		{
			exit(0);
		}
	}
	else
	{
		ofstream fileout;
		fileout.open("DsSanPham.txt", ios_base::out);
		int tt;
		vietChuoi(10, 4, "Chon thong tin can thay doi: ", 7);
		gotoXY(40, 4);
		cout << "1. Ten San Pham";
		gotoXY(40, 5);
		cout << "2. Gia Nhap";
		gotoXY(40, 6);
		cout << "3. Gia Ban";
		gotoXY(40, 7);
		cout << "4. So Luong";
		vietChuoi(10, 8, "Lua Chon Cua Ban La: ", 7);
		gotoXY(40, 8);
		cin >> tt;
		node d = sp;
		while (d->data.ma_sp != a)
		{
			fileout << d->data.ma_sp << "," << d->data.ten_sp  << "," << d->data.dg_nhap << "," << d->data.dg_ban << "," << d->data.sl<<","<<d->data.da_ban;
			if (d != NULL)
			{

				fileout << endl;
			}
			d = d->next;

		}
		if (tt == 1)
		{
			vietChuoi(42, 10, "Ten San Pham truoc khi thay doi:", 7);
			gotoXY(75, 10);
			cout << d->data.ten_sp;
			vietChuoi(42, 11, "Ten San Pham muon thay doi:", 7);
			gotoXY(70, 11);
			cin >> d->data.ten_sp;
		}
		if (tt == 2)
		{
			vietChuoi(42, 10, "Gia nhap truoc khi thay doi:", 7);
			gotoXY(70, 10);
			cout << d->data.dg_nhap;
			vietChuoi(42, 11, "Gia nhap muon thay doi:", 7);
			gotoXY(67, 11);
			cin >> d->data.dg_nhap;
		}
		if (tt == 3)
		{
			vietChuoi(42, 10, "Gia ban truoc khi thay doi:", 7);
			gotoXY(70, 10);
			cout << d->data.dg_ban;
			vietChuoi(42, 11, "Gia ban muon thay doi:", 7);
			gotoXY(67, 11);
			cin >> d->data.dg_ban;
		}
		if (tt == 4)
		{
			vietChuoi(42, 10, "So luong truoc khi thay doi:", 7);
			gotoXY(70, 10);
			cout << d->data.sl;
			vietChuoi(42, 11, "So luong muon thay doi:", 7);
			gotoXY(70, 11);
			cin >> d->data.sl;
		}
		while (d != NULL)
		{
			fileout << d->data.ma_sp << "," << d->data.ten_sp  << "," << d->data.dg_nhap << "," << d->data.dg_ban << "," << d->data.sl << "," << d->data.da_ban;
			d = d->next;
			if (d != NULL)
			{

				fileout << endl;
			}
		}
		fileout.close();
		
	}
}

void ds_sp::inds1()
{
	node p = sp;
	int i = 0;
	while (p != NULL)
	{

		gotoXY(12, 8 + i); cout << i + 1;
		gotoXY(12 + 13, 8 + i); cout << p->data.ten_sp;
		gotoXY(12 + 2 * 13, 8 + i); cout << p->data.ma_sp;
		//gotoXY(12 + 3 * 13, 8+i); cout << "NCC";
		gotoXY(12 + 3 * 13, 8 + i); cout << p->data.sl;
		//gotoXY(12 + 4 * 13, 8 + i); cout << p->data.dg_nhap;
		gotoXY(12 + 4 * 13, 8 + i); cout << p->data.dg_ban;
		//gotoXY(12 + 6 * 13, 8 + i); cout << p->data.da_ban;

		p = p->next;
		i += 1;

	}
}
void ds_sp::inds1(string t, int i)
{
	node p = sp;
	//int i = 0;
	while (p != NULL)
	{
		if (p->data.ma_sp == t) {
			gotoXY(12, 8 + i); cout << i + 1;
			gotoXY(12 + 13, 8 + i); cout << p->data.ten_sp;
			gotoXY(12 + 2 * 13, 8 + i); cout << p->data.ma_sp;
			//gotoXY(12 + 3 * 13, 8+i); cout << "NCC";
			gotoXY(12 + 3 * 13, 8 + i); cout << p->data.sl;
			//gotoXY(12 + 4 * 13, 8 + i); cout << p->data.dg_nhap;
			gotoXY(12 + 4 * 13, 8 + i); cout << p->data.dg_ban;
			//gotoXY(12 + 6 * 13, 8 + i); cout << p->data.da_ban;
		}
		

		p = p->next;
		

	}
}
int ds_sp::kt_hang(string msp,int sl)
{
	node p = sp;
	while (p != NULL)
	{
		while (p->data.ma_sp == msp)
		{
			if (sl <= p->data.sl)return 1;
			else return -1;
		}
		p = p->next;
	}
	return -1;
}
int ds_sp::get_tiennhap() {
	int sum = 0;
	node p = sp;
	while (p != NULL) {
		sum += (p->data.dg_nhap*p->data.sl);
		p = p->next;
	}
	return sum;
}