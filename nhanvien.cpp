#include "nhanvien.h";
using namespace std;
int Date::validate(string& datt)
{
	stringstream ss(datt);
	int day, month, year;

	ss >> day >> month >> year;
	if (year >= 1000 && year <= 3000)
	{
		if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 0 && day <= 31)
			return 1;
		else
			if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 0 && day <= 30)
				return 1;
			else
				if (month == 2)
				{
					if ((year % 4 == 0 || year % 400 == 0) && day > 0 && day <= 29)
						return 1;
					else if (day > 0 && day < 30)return 1;
				}
				else
					return 0;
	}
	else
		return 0;
	return 0;
}
void Date::nhap()
{
	getline(cin, this->date);
	while (validate(this->date) == 0)
	{
		cout << "Ban chua nhap dung dinh dang ngay thang, VD: 14 5 1999 \n";
		cout << "Nhap ngay thang nam sinh: ";
		getline(cin, this->date);
	}
}
void Employee::diemdanh_1(int i)
{
	this->cr[i].diemdanh();
}
string Date::getDate()
{
	return date;
}
void Date::setdate(string date)
{
	this->date = date;
}
void Diemdanh::diemdanh()
{
	cout << "Nhap ngay thang ";
	Date::nhap();
	cout << "1.DL: Di lam \t2.DLNN: di lam nua ngay \t3.N: nghi\t4.NP: nghi phep \n";
	getline(cin, this->Trangthai);
	while (checl_tt(this->Trangthai) == 0)
	{
		cout << "Ban chua nhap dung dinh dang , VD: NL\n";
		getline(cin, this->Trangthai);
	}
}
int Diemdanh::checl_tt (string tt) // Kiem tra trang thai di lam 
{
	if (tt == "DL" || tt == "DLNN" || tt == "N" || tt == "NP")
		return 1;
	else return 0;
}
void Diemdanh::set_tt(string trangthai)
{
	this->Trangthai = trangthai;
}
void Person::nhap()
{
	cout << "Nhap Ho va Ten: ";
	getline(cin, this->hovaten);
	cout << "Nhap Ngay thang nam sinh ";
	this->birth.nhap();
	cout << "Nhap dia chi noi o : ";
	getline(cin, this->adress);
	while (this->adress.empty())
	{
		cout << "Dia chi khong duoc bo trong \n";
		cout << "Moi ban nhap lai dia chi \n";
		getline(cin, this->adress);
	}
}
void Employee::nhap()
{
	Check* p = new Check;
	cout << "Nhap ma nhan vien: ";
	getline(cin, this->id);
	while (p->checkid(this->id) == 0)									//KIEM TRA co trung ma nhan vien khong
	{
		cout << "Ma nhan vien bi trung, moi ban nhap lai:  \n";
		cout << "Nhap ma nhan vien(VD: 01): ";
		getline(cin, this->id);
	}
	Person::nhap();
	cout << "Nhap bo phan cong tac: ";
	getline(cin, this->team);
	while (this->team.empty())
	{
		cout << "Bo phan cong tac khong duoc bo trong \n";
		cout << "Moi ban nhap lai bo phan cong tac \n";
		getline(cin, this->team);
	}
}
void Check:: setFILE(string name)
{
	this->file = name;
}
int Check::checkid(string id)  // Kiem tra xem co trung ma Nhan Vien khong
{

	string line;
	ifstream fileInput(this->file, ios::in);
	if (fileInput.is_open())
	{
		string str = id;
		while (!fileInput.eof())
		{
			getline(fileInput, line);
			string epl = line;
			istringstream stm(epl);
			string token;
			getline(stm, token, ',');
			if (token == str)
			{
				return 0;
			}

		}
		fileInput.close();
	}
	return 1;
}
Check::Check()
{
	this->file = "text.txt";
}
search::search()
{
	this->file = "text.txt";
}
void search::setFile(string name)
{
	this->file = name;
}
void Person::setName(string name)
{
	this->hovaten = name;
}
void  Person::setbirth(string date,int i)
{
	
	if (this->birth.validate(date) == 0)
	{
		this->birth.setdate("Loi Dinh Dang dd/mm/yy");
		cout << "Dong " << i << "Loi dinh dang dd/mm/yy" << endl;
	}		//Loi dinh dang neu validate == 0
	else this->birth.setdate(date);
}
void  Person::setadr(string adress,int i)
{
	if (adress == "" || adress == " ")
	{
		this->adress = "Khong co dia chi nha";
		cout << "Dong " << i << "Khong co dia chi nha " << endl;
	}// Loi ko co dia chi
	else this->adress = adress;
}
void Employee::setid(string id)
{
	this->id = id;
}
void Employee::setteam(string team,int i)
{
	//this->team = team;
	if (team == "" || team == " ")
	{
		this->team = "Khong co bo phan";
		cout << "Dong " << i << "Khong co bo phan " << endl;
	}// loi ko co bo phan
	else this->team = team;
}
void Employee::setcheck(int n)
{
	this->check = n;
}
void Employee::diemdanh(int i, string date, string TT) // gan diemdanh
{
	this->cr[i].setdate(date);
	this->cr[i].set_tt(TT);
}
string Employee::getid()
{
	return this->id;
}
int Employee::getcheck()
{
	return this->check;
}
string Diemdanh::get_tt()
{
	return this->Trangthai;
}
void Employee::getdd(int i)
{
	//
	if (this->cr[i].get_tt() == "N")
		cout << this->cr[i].getDate() << ": X" << endl;
	else cout << this->cr[i].getDate() << ": " << this->cr[i].get_tt() << endl;
}
string Employee::getddall(int i)	
{
	stringstream ss;
	ss << this->cr[i].getDate() << ":" << this->cr[i].get_tt() << endl;
	return ss.str();
}
string Person::getbirth()
{
	//
	return this->birth.getDate();
}
string Person::getadress()
{
	return this->adress;
}
string Person::getname()
{
	return this->hovaten;
}
string Employee::getteam()
{
	return this->team;
}
Employee search::Searcheid(string id)
{
	int count = 0;			// Dem so dong
	Employee* p = new Employee;
	string line;
	ifstream fileinput(this->file, ios::in);
	string str = id;
	while (!fileinput.eof())
	{
		count++;
		getline(fileinput, line);
		string epl = line;
		istringstream stm(epl);
		string token;
		getline(stm, token, ',');
		if (token == str)
		{
			p->setid(id);
			getline(stm, token, ',');
			p->setName(token);
			getline(stm, token, ',');
			p->setbirth(token,count);
			getline(stm, token, ',');
			p->setadr(token,count);
			getline(stm, token, ',');
			p->setteam(token,count);
			getline(stm, token, ',');
			int n;
			stringstream ss(token);
			ss >> n;
			if (n == 0)
			{
				p->setcheck(n);
			}
			else
			{
				p->setcheck(n);
				for (int i = 0; i < n; i++)
				{
					getline(stm, token, ':');
					string tok = token;
					getline(stm, token, ',');
					p->diemdanh(i, tok,token);
				}
			}
		}
	}
	return *p;
}
void Other::Print(Employee p)													// Ham In ra thong tin (Bai 2)
{
	cout << "Ma NV: " << p.getid() << endl;
	cout << "Ten NV: " << p.getname() << endl;
	cout << "Ngay thang nam sinh: " << p.getbirth() << endl;
	cout << "Dia chi: " << p.getadress() << endl;
	cout << "Bo phan cong tac: " << p.getteam() << endl;
	if (p.getcheck() == 0)
	{
		cout << "Khong co du lieu diem danh cua nhan vien" << endl;
	}
	else
	{
		int n = p.getcheck();
		for (int i = 0; i < n; i++)
		{
			p.getdd(i);
		}
	}
}
void search::Searchnv(string name)
{
	int count = 0;	//Dem so dong
	string line;
	ifstream fileinput(this->file, ios::in);
	string str = name;
	while (!fileinput.eof())
	{
		Employee* p = new Employee;
		count++;
		getline(fileinput, line);
		string epl = line;
		istringstream stm(epl);
		string token;
		getline(stm, token, ',');
		string id = token;
		getline(stm, token, ',');
		if (token == str)
		{
			p->setid(id);
			p->setName(name);
			getline(stm, token, ',');
			p->setbirth(token,count);
			getline(stm, token, ',');
			p->setadr(token,count);
			getline(stm, token, ',');
			p->setteam(token,count);
			getline(stm, token, ',');
			int n;
			stringstream ss(token);
			ss >> n;
			if (n == 0)
			{
				p->setcheck(n);
			}
			else
			{
				p->setcheck(n);
				for (int i = 0; i < n; i++)
				{
					getline(stm, token, ':');
					string tok = token;
					getline(stm, token, ',');
					p->diemdanh(i, tok, token);
				}
			}
			Other a;
			a.Print(*p);
		}
	}
}
void search::Searchall() //alll
{
	int count = 0;
	string line;
	ifstream fileinput(this->file, ios::in);
	while (!fileinput.eof())
	{
		Employee* p = new Employee;
		count++;
		getline(fileinput, line);
		string epl = line;
		istringstream stm(epl);
		string token;
		getline(stm, token, ',');
		
			p->setid(token);
			getline(stm, token, ',');
			p->setName(token);
			getline(stm, token, ',');
			p->setbirth(token,count);
			getline(stm, token, ',');
			p->setadr(token,count);
			getline(stm, token, ',');
			p->setteam(token,count);
			getline(stm, token, ',');
			int n;
			stringstream ss(token);
			ss >> n;
			if (n == 0)
			{
				p->setcheck(n);
			}
			else
			{
				p->setcheck(n);
				for (int i = 0; i < n; i++)
				{
					getline(stm, token, ':');
					string tok = token;
					getline(stm, token, ',');
					p->diemdanh(i, tok, token);
				}
			}
			Other a;
			a.setFile("data.cvs");
			a.Printfcvs(*p,n);
	}
	
}
void search::Searchteam(string team)
{
	int count = 0;			// Dem so dong
	Employee* p = new Employee;
	string line;
	ifstream fileinput(this->file, ios::in);
	string str = team;
	while (!fileinput.eof())
	{
		count++;
		getline(fileinput, line);
		string epl = line;
		istringstream stm(epl);
		string token;
		getline(stm, token, ',');
		string id = token;
		getline(stm, token, ',');
		string name = token;
		getline(stm, token, ',');
		string birth = token;
		getline(stm, token, ',');
		string add;
		getline(stm, token, ',');
		if (token == str)
		{
			p->setid(id);
			p->setName(name);
			p->setbirth(birth, count);
			p->setadr(add, count);
			p->setteam(token, count);
			getline(stm, token, ',');
			int n;
			stringstream ss(token);
			ss >> n;
			if (n == 0)
			{
				p->setcheck(n);
			}
			else
			{
				p->setcheck(n);
				for (int i = 0; i < n; i++)
				{
					getline(stm, token, ':');
					string tok = token;
					getline(stm, token, ',');
					p->diemdanh(i, tok, token);
				}
			}
			Other a;
			a.setFile("data.cvs");
			a.Printfcvs(*p,n);
		}
	}
}
void Other::setFile(string file)
{
	this->file = file;
}
void Other::History(Employee a, int i)		//  luu vao File history.txt;
{
	ofstream output("history.txt", ios::app);
	output << "Ma NV: " << a.getid() << " Ho va Ten " << a.getname() << "Da duoc them vao " << a.getddall(i);
	a.getdd(i);
}
void Other::Printfcvs(Employee p,int n = 0)
{
	ofstream myfile(this->file, ios::app);
	myfile << p.getid() << ',' << p.getname() << ',' << p.getbirth() << ',' << p.getadress() << ',' << p.getteam() << ',' << n;
	for (int i = 0; i < n; i++)
	{
		myfile << ',' << p.getddall(i);
		if (i == n - 1)myfile << endl;
	}
}