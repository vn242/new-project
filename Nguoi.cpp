#include"Nguoi.h"
Person::Person()
{
	cmnd = "";
	name = "";
	age = 0;
	dia_chi = "";
	sdt = "";
}
Person::~Person()
{
}
istream& operator >>(istream& in, Person& p)
{
	cout << "Nhap CMND: "; in >> p.cmnd;
	cout << "Nhap ten: "; in >> p.name;
	cout << "Nhap tuoi: "; in >> p.age;
	cout << "Nhap dia chi: "; in >> p.dia_chi;
	cout << "Nhap sdt: "; in >> p.sdt;
	return in;
	
}
ostream& operator <<(ostream& out, const Person& p)
{
	out << "CMND: " << p.cmnd << endl;
	out << "Ten: " << p.name << endl;
	out << "Tuoi: " << p.age << endl;
	out << "Dia chi: " << p.dia_chi << endl;
	out << "SDT: " << p.sdt << endl;
	return out;

}
string Person::get_dia_chi()
{
	return dia_chi;
}
string Person::get_sdt()
{
	return sdt;
}
int Person::getAge()
{
	return age;
}
string Person::getName()
{
	return name;
}
string Person::getCmnd()
{
	return cmnd;
}
void Person::setDiaChi(string a)
{
	dia_chi = a;
}
void Person::setSdt(string a)
{
	sdt = a;
		 
}
void Person::setAge(int a)
{
	age = a;
}
void Person::setCmnd(string b)
{
	cmnd = b;
}
void Person::setName(string c)
{
	name = c;
}
void Person::in()
{
	cout << "CMND: " << cmnd << endl;
	cout << "Ten: " << name << endl;
	cout << "Tuoi: " << age << endl;
	cout << "Dia chi: " << dia_chi << endl;
	cout << "SDT: " << sdt << endl;
}
void Person::nhap()
{
	gotoXY(28,8); 
	//cin.ignore();
	getline(cin, name);
	//cin.ignore();
	gotoXY(41,8); 
	
	//cin.ignore();
	cin >> cmnd;
	cin.ignore();
	gotoXY(54,8); 
	
	//cin.ignore();
	getline( cin , dia_chi);
	//cin.ignore();
	gotoXY(67,8);
	//cin.ignore(); 
	cin >> sdt;
	cin.ignore();
	gotoXY(80,8); cin >> age;
	cin.ignore();
}