#include"NhanVien.h"
#include<string>
char nd_qldh1[5][30] = { "STT","Ma DH","So SP","Ngay ban","Tong tien"};
nhan_vien::nhan_vien():Person()
{
	chuc_vu = "";
	ma_nv = "";
	
	//cmnd = "";
//	name = "";
	//age = 0;
	//dia_chi = "";
	//sdt = "";
}
nhan_vien::~nhan_vien()
{}
istream& operator >>(istream& in, nhan_vien& p)
{
	cout << "Nhap CMND: "; in >> p.cmnd;
	cout << "Nhap ten: "; in >> p.name;
	cout << "Nhap tuoi: "; in >> p.age;
	cout << "Nhap dia chi: "; in >> p.dia_chi;
	cout << "Nhap sdt: "; in >> p.sdt;
	cout << "Nhap chuc vu: "; in >> p.chuc_vu;
	return in;
}
ostream& operator <<(ostream& out, const nhan_vien& p)
{
	out << "CMND: " << p.cmnd << endl;
	out << "Ho va ten: " << p.name << endl;
	out << "Tuoi: " << p.age << endl;
	out << "Dia chi: " << p.dia_chi << endl;
	out << "SDT: " << p.sdt << endl;
	out << "Chuc vu: " << p.chuc_vu << endl;
	return out;
	
}
void nhan_vien::set_chuc_vu(string a)
{
	chuc_vu = a;
}
void nhan_vien::set_sldh(int a) {
	sldh = a;
}
void nhan_vien::set_madh(string x, int a) {
	madh[a] = x;
}
void nhan_vien::in()
{
	Person::in();
	cout << "Chuc vu: " << chuc_vu << endl;
}
void nhan_vien::themdh(string a) {
	sldh += 1;
	madh[sldh] = a;
}
void nhan_vien::set_ma_nv(string a)
{
	ma_nv = a;
}
void nhan_vien::set_luong(int a) {
	luong = a;
}
string nhan_vien::get_chuc_vu()
{
	return chuc_vu;
}
string nhan_vien::get_ma_nv()
{
	return ma_nv;
}
void ds_nv::themdh1(string x, string a) {
	for (int i = 1; i <= sl5; i++) {
		if (n[i].get_ma_nv() == x) {
			n[i].themdh(a);
		}
	}
}
void ds_nv::docFile()
{
	ifstream filein;
	filein.open("DsNhanVien.txt", ios_base::in);
	int i = 1;

	while (filein.eof() != true)
	{
		//cin.ignore();
		string ma_nv = "";
		getline(filein,ma_nv, ',');
		n[i].set_ma_nv(ma_nv);
		string name = "";
		getline(filein, name, ',');
		n[i].setName(name);
		string cmnd = "";
		getline(filein, cmnd, ',');
		n[i].setCmnd(cmnd);
		string diachi = "";
		getline(filein, diachi, ',');
		n[i].setDiaChi(diachi);
		string sdt = "";
		getline(filein, sdt, ',');
		n[i].setSdt(sdt);
		string chucvu = "";
		getline(filein, chucvu, ',');
		n[i].set_chuc_vu(chucvu);
		int age;
		filein >> age;
		n[i].setAge(age);
		filein.ignore();
		int luong;
		filein >> luong;
		n[i].set_luong(luong);
		filein.ignore();
		int sldh;
		filein >> sldh;
		filein.ignore();
		n[i].set_sldh(sldh);
		for (int j = 1; j <= sldh; j++) {
			string madh;
			getline(filein, madh, ',');
			//filein >> madh;
			//filein.ignore();
			n[i].set_madh(madh, j);
			//filein.ignore();
		}

		i += 1;
		filein.ignore();
		
		//filein.ignore();
		sl5 += 1;
		//filein.ignore();


	}
	filein.close();
	//sl5 -= 1;
	
	
};
int nhan_vien::get_sldh() {
	return sldh;

}
string nhan_vien::get_madh(int a) {
	return madh[a];
}
int nhan_vien::get_luong() {
	return luong;
}
ds_nv::ds_nv()
{
	sl5 = 0;
}
ds_nv::~ds_nv()
{
	sl5 = 0;
}
void ds_nv::xuat() {
	for (int i = 1; i <= getSl(); i++) {
		n[i].get_sldh();
	}
}
void ds_nv::in()
{
	TextColor(7);

	for (int i = 1; i <= getSl(); i++)
	{
		gotoXY(2 , 8+i-1); cout << i;
		gotoXY(2 + 13*1, 8+i-1); cout << n[i].getName();
		gotoXY(2 + 13*2, 8 + i - 1); cout << n[i].get_ma_nv();
		gotoXY(2 + 13*3, 8 + i - 1); cout << n[i].getCmnd();
		gotoXY(2 + 13*4, 8 + i - 1); cout << n[i].get_dia_chi();
		gotoXY(2 + 13*5, 8 + i - 1); cout << n[i].get_sdt();
		gotoXY(2 + 13*6, 8 + i - 1); cout << n[i].get_chuc_vu();
		gotoXY(2 + 13*7, 8 + i - 1); cout << n[i].getAge();
		gotoXY(2 + 13 * 8, 8 + i - 1); cout << n[i].get_luong();
	}

	
}
int ds_nv::getSl()
{
	return sl5;
}
void ds_nv::ghiFile()
{
	ofstream fileout;
	fileout.open("DsNhanVien.txt", ios_base::out);
	int i = 1;
	while (i <= sl5)
	{
		fileout << n[i].get_ma_nv() << "," << n[i].getName() << "," << n[i].getCmnd() << "," << n[i].get_dia_chi() << "," << n[i].get_sdt() << "," << n[i].get_chuc_vu() << "," << n[i].getAge() << "," << n[i].get_luong() << ",";
		fileout << n[i].get_sldh() << ",";
		for (int j = 1; j <= n[i].get_sldh(); j++) {
			//if (j == n[i].get_sldh())continue;
			fileout << n[i].get_madh(j);
			fileout << ",";

		}
		i += 1;
		if (i <= sl5)
		{
			fileout << endl;
		}
	}
	fileout.close();
}
void nhan_vien::nhap()
{
	gotoXY(15, 8);
	
	getline(cin , ma_nv);
	//cin.ignore();
	Person::nhap();
	//gotoXY(15, 8); cin >> ma_nv;
	gotoXY(93,8); 
	getline( cin , chuc_vu);
	gotoXY(106, 8);
	cin >> luong;
	cin.ignore();
	//cin.ignore();
	sldh = 0;
	
}
void ds_nv::nhap()
{
	sl5++;
	n[sl5].nhap();
	
}
void ds_nv::inttnv() {
	for (int i = 1; i <= sl5; i++) {
		gotoXY(62, 8 + 2 * (i - 1)); cout << n[i].getName();
		gotoXY(77, 8 + 2 * (i - 1)); cout << n[i].get_ma_nv();
	}
}
void ds_nv::inttnv1() {
	for (int i = 1; i <= sl5; i++) {
		gotoXY(12, 8 + 2 * (i - 1)); cout << n[i].getName();
		gotoXY(27, 8 + 2 * (i - 1)); cout << n[i].get_ma_nv();
	}
}
bool ds_nv::checkManv(string a) {
	for (int i = 1; i <= sl5; i++) {
		if (n[i].get_ma_nv() == a)return true;
	}
	return false;
}
string ds_nv::getManvban(string a) {
	for (int i = 1; i <= sl5; i++) {
		for (int j = 1; j <= n[i].get_sldh(); j++) {
			if (a == n[i].get_madh(j))return n[i].get_ma_nv();
		}
	}
	return "";
}
string ds_nv::get_tennv(string a) {
	for (int i = 1; i <= sl5; i++) {
		if (n[i].get_ma_nv() == a)return n[i].getName();
	}
	return "";
}
int nhan_vien::getsldh() {
	return sldh;
}
int ds_nv::getsldh(string a) {
	for (int i = 1; i <= sl5; i++) {
		if (n[i].get_ma_nv() == a) {
			return n[i].getsldh();
		}
	}
	return -1;
}
int ds_nv::getThuong(string a) {
	ds_dh p;
	p.docFile();
	for (int i = 1; i <= sl5; i++) {
		if (n[i].get_ma_nv() == a) {
			if (getsldh(a) > 0) {

				int f = 0;

				for (int j = 1; j <= getsldh(a); j++) {

					f += p.inmnv1(n[i].get_madh(j), j);

				}
				int thuong;
				if (f <= 2000000)thuong = 0;
				else if (f <= 500000) thuong = 500000;
				else thuong = 1000000;
				return thuong;
			}
			else return 0;
		}
	}
}
int ds_nv::getDt(string a) {
	int f = 0;
	ds_dh p;
	p.docFile();
	for (int i = 1; i <= sl5; i++) {
		if (n[i].get_ma_nv() == a) {


			//int f = 0;

			for (int j = 1; j <= getsldh(a); j++) {

				f += p.inmnv1(n[i].get_madh(j), j);

			}

		}
	}
	return f;
}
string ds_nv::getMaxdt() {
	//string name;
	int max = 0;
	for (int i = 1; i <= sl5; i++) {
		if (getDt(n[i].get_ma_nv()) >= max) {
			max = getDt(n[i].get_ma_nv());
		}
	}
	for (int i = 1; i <= sl5; i++) {
		if (getDt(n[i].get_ma_nv()) == max)
		{
			return   n[i].get_ma_nv();
		}
	}
	return "";
	//gotoXY(0, 0); cout << name;
}
int ds_nv::getTongThuong() {
	int sum = 0;
	for (int i = 1; i <= sl5; i++) {
		sum += getThuong(n[i].get_ma_nv());
	}
	return sum;
}
void ds_nv::getdh(string b) {
	ds_dh p;
	p.docFile();
	int o = 1;
	while (o == 1) {
		string a = b;
		for (int i = 1; i <= sl5; i++) {
			if (n[i].get_ma_nv() == a) {
				if (getsldh(a) > 0) {
					int sl = 5;
					vietChuoi(62, 3, "Danh Sach Don Hang Da Ban", 3);
					vietChuoi(43, 4, "Ten NV: " + n[i].getName(), 7);
					n_box_dai(42, 5, 14, 2, 2, 5, nd_qldh1, sl);
					box11(42, 7, 14 * sl, 2 * 6, 2);
					gotoXY(42, 7); cout << char(195);
					gotoXY(42 + sl * 14, 7); cout << char(180);
					for (int i = 1; i <= sl; i++)
					{
						for (int iy = 6; iy <= 6 + 2 * 6; iy++)
						{
							gotoXY(42 + 14 * i, iy);
							cout << char(179);
						}
					}
					int f = 0;
					TextColor(7);
					for (int j = 1; j <= getsldh(a); j++) {
						gotoXY(45, 6 + 2 * j); cout << j;
						f += p.inmnv(n[i].get_madh(j), j);
						//cout << n[i].get_madh(j) << endl;
					}
					int thuong;
					if (f <= 2000000)thuong = 0;
					else if (f <= 500000) thuong = 500000;
					else thuong = 1000000;
					gotoXY(45, 21); cout << "Tong so don hang: " << getsldh(a);
					gotoXY(45, 23); cout << "Tong don hang da ban: " << f;
					gotoXY(45, 25); cout << "Thuong doanh so: " << thuong;
					o = 0;

				}
				else {
					int result;
					char h1[30] = "Chua co don hang";
					char h2[30] = "Thong bao";
					result = MessageBox(NULL, convertCharArrayToLPCWSTR(h1), convertCharArrayToLPCWSTR(h2), MB_OKCANCEL);
					if (result == IDOK)
					{
						o = 1;
						gotoXY(19, 23); cout <<"         ";
						gotoXY(19, 23); cin >> a;
					}
				};
			}
		}
	}
	
	
}
int ds_nv::get_tongluong() {
	int sum = 0;
	for (int i = 1; i <= sl5; i++) {
		sum += n[i].get_luong();
	}
	return sum;
}