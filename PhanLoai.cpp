#include"PhanLoai.h"
ds_pl::ds_pl() {
	pl = new Nodet();
	pl->next = NULL;
	sl = 0;
}
ds_pl::~ds_pl() {
	sl = 0;
}
nodet makeNodet(phan_loai x) {
	nodet tmp = new Nodet();
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}
int ds_pl::kt_trung(string a)
{
	nodet p = pl;
	while (p != NULL)
	{
		if (p->data.ma_pl == a)return 1;
		p = p->next;
	}
	return -1;
}
string ds_pl::tao_mapl()
{
	string a = "PL0000";
	do
	{
		for (int i = 2; i < a.length(); i++)
		{
			a[i] = rand() % (57 - 48 + 1) + 48;
		}
	} while (kt_trung(a) >= 0);
	return a;
}
void ds_pl::ghiFile() {
	nodet p = pl;
	ofstream fileout;
	fileout.open("DsPhanLoai.txt", ios_base::out);
	while (p != NULL) {
		fileout << p->data.ma_pl << "," << p->data.tenpl << "," << p->data.slsp << ",";
		for (int i = 1; i <= p->data.slsp; i++) {
			fileout << p->data.masp[i] << ",";
		}
		p = p->next;
		if (p != NULL) {
			fileout << endl;
		}
	}
	fileout.close();
}
void ds_pl::docFile() {
	ifstream filein;
	filein.open("DsPhanLoai.txt", ios_base::in);
	while (filein.eof() != true) {
		phan_loai p;
		getline(filein, p.ma_pl, ',');
		getline(filein, p.tenpl, ',');
		filein >> p.slsp;
		filein.ignore();
		for (int i = 1; i <= p.slsp; i++) {
			getline(filein, p.masp[i], ',');
		}
		filein.ignore();
		
		nodet tmp = makeNodet(p);
		if (sl == 0) {
			pl = tmp;
		}
		else {
			tmp->next = pl;
			pl = tmp;
		}
		sl+=1;
	}
	filein.close();
}
void ds_pl::xuat() {
	nodet p = pl;
	while (p != NULL) {
		cout << p->data.ma_pl << " ";
		cout << p->data.tenpl << " ";
		cout << p->data.slsp << " ";
		for (int i = 1; i <= p->data.slsp; i++) {
			cout << p->data.masp[i] << " ";
		}
		cout << endl;
		p = p->next;
	}
}
int ds_pl::getSl() {
	return sl;
}
string* ds_pl::getTenpl() {
	int k = sl - 1;
	static string tenpl[10];
	nodet p = pl;
	int i = 1;
	while (p != NULL) {
		tenpl[i] = p->data.tenpl;
		i++;
		p = p->next;
	}
	return tenpl;
}
void ds_pl::thempl(phan_loai p,string a) {
	BackGroundColor(0);
	p.ma_pl = a;
	gotoXY(96, 7); cout << "Ten PL: "; getline(cin,p.tenpl);
	p.slsp = 0;
	nodet tmp = makeNodet(p);
	if (sl == 0) {
		pl = tmp;
	}
	else {
		tmp->next = pl;
		pl = tmp;
	}
	sl += 1;
	
}
int ds_pl::timmpl(string x) {
	nodet p = pl;
	int k = 0;
	while (p != NULL) {
		++k;
		if (p->data.ma_pl == "") {
			--k;
		}
		if (p->data.ma_pl == x)return --k;
		p = p->next;
	}
	return -1;
}
void ds_pl::themsp(string mapl, string masp) {
	nodet p = pl;
	while (p != NULL) {
		if (p->data.ma_pl == mapl) {
			p->data.slsp++;
			p->data.masp[p->data.slsp] = masp;
		}
		p = p->next;
	}
}
string ds_pl::timvitri(int k) {
	nodet p = pl;
	int h = 1;
	
	while (p != NULL) {
		if (h == k) {
			return p->data.ma_pl;
		}
		++h;
		p = p->next;
	}
	return "";
}
string ds_pl::getMapl(string x) {
	nodet p = pl;
	while (p != NULL) {
		if (p->data.tenpl == x) {
			return p->data.ma_pl;
		}
		p = p->next;
	}
	return "";
}
string ds_pl::getTenpl(string x) {
	nodet p = pl;
	while (p != NULL) {
		if (p->data.ma_pl == x) {
			return p->data.tenpl;
		}
		p = p->next;
	}
	return "";
}
void ds_pl::inds(string x) {
	nodet p = pl;
	ds_sp d;
	d.docFile();
	while (p != NULL) {
		if (p->data.ma_pl == x) {
			int e = p->data.slsp;
			for (int i = 1; i <= e; i++) {
				d.inds(p->data.masp[i], i - 1);
			}
		}
		p = p->next;
	}
}
void ds_pl::inds1() {
	nodet p = pl;
	ds_sp d;
	d.docFile();
	int j = 0;
	while (p != NULL) {

		int e = p->data.slsp;
		gotoXY(1, 8 + 1 * j); cout << p->data.tenpl;
		for (int i = 1; i <= e; i++) {
			d.inds1(p->data.masp[i], j);
			j++;
		}
		p = p->next;
	}
	//p = p->next;

}
