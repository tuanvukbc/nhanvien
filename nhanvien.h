#pragma once
#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;
class Date	// BASE CLASS DATE
{
private:
	string date;
public:
	int validate(string& datt);
	void nhap();
	string getDate();
	void setdate(string date);
};
class Diemdanh :public Date		// DIEMDANH // DELi CLASS
{
private:
	string Trangthai;
public:
	void diemdanh();
	string get_tt();
	int checl_tt(string tt);// Kiem tra trang thai di lam 
	void set_tt(string trangthai);
};
class Person		// Base CLASS PERSON
{
private:
	string hovaten;
	Date birth;
	string adress;
public:
	void nhap();
	string getname();
	string getbirth();
	string getadress();
	void setName(string name);
	void setbirth(string date,int i);
	void setadr(string adress,int i);
};
class Employee :public Person // Deli CLASS 
{
private:
	string id;
	string team;
	int check = 0; // so ngay diem danh duoc luu vao ; 
	Diemdanh* cr = new Diemdanh[31];
public:
	
	void setcheck(int n);
	void nhap();
	string getid();
	int getcheck();					
	void getdd(int i);				// Trang thai diem danh, neu Nghi se danh dau X
	string getddall(int i);		//Lay THong tin trang thai diem danh
	string getteam();
	void diemdanh_1(int i);		// diem danh tng cr
	void setid(string id);
	void setteam(string team,int i);
	void diemdanh(int i,string date,string TT);
};
class Check
{
private:
	string file;		//Da co file san text.txt
public:
	Check();
	 void setFILE(string name);
	 int checkid(string id);  // Kiem tra xem co trung ma Nhan Vien khong
};
class search
{
private:
	string file;	//Da co file san text.txt
public:
	search();
	void setFile(string name);
	Employee Searcheid(string id); // search theo id
	void Searchnv(string name);// search theo ten nhan vien
	void Searchall(); //alll
	void Searchteam(string team); // search theo team
};
class Other
{
private:
	string file;	//Da co file san List.txt
public:
	void setFile(string file);	// thay doi File
	void History(Employee a,int i);						// Lich su diem danh 
	void Print(Employee p);		// Xuat ra man hinh 
	void Printfcvs(Employee p,int n); // Xuat ket qua ra file csv	n la so ngay da duoc diem danh
};
class Menu	 // Chua xong 
{
private:
	bool button;
public:
	void menu()
	{
		system("cls");
		cout << "============================================== \n";
		cout << "= 1 - Nhap thong tin nhan vien               = \n";
		cout << "= 2 - Tim thong tin nhan vien                = \n";
		cout << "= 3 - Import danh sach nhan vien             = \n";
		cout << "= 4 - Lich Su diem danh                      = \n";
		cout << "= 5 - Tim Thong tin nhan vien theo Ten       = \n";
		cout << "= 6 - Tim Thong tin nhan vien theo Bo phan   = \n";
		cout << "= 7 - Tim Tat Ca Thong tin nhan vien         = \n";
		cout << "============================================== \n";
	}
	void CASE1()
	{
		int n = 0;
		cout << "Moi nhap thong tin nhan vien \n";
		Employee a;
		a.nhap();
		Other file;
		file.setFile("text.txt");
		file.Printfcvs(a,n);
	}
	void CASE2()
	{
		string id;
		cout << "Moi nhap ma nhan vien can tim kiem: ";
		getline(cin, id);
		Check* p = new Check;
		p->setFILE("text.txt");
		while (p->checkid(id) != 0) {
			cout << "Ma nhan vien khong ton tai \n";
			cout << "Moi ban nhap lai ma nhan vien can tim kiem: ";
			getline(cin, id);
		}
		cout << "Thong tin cua nhan vien co ma nhan vien: " << id << endl;
		Other a;
		search b;
		b.setFile("text.txt");
		a.Print(b.Searcheid(id));
		system("pause");
		system("pasue");
	}
	void CASE3()
	{
		string id;
		Check a;
		Other c;
		search d;
		a.setFILE("data.csv");
		d.setFile("data.csv");
		cout << "Nhap ma nhan vien \n";
		getline(cin, id);
		while (a.checkid(id))
		{
			cout << "Ma so nhan vien khong khong ton tai\n";
			getline(cin, id);
		}
		Employee e = d.Searcheid(id);
		int n;
		c.Print(d.Searcheid(id));
		cout << "===Diem Danh====\n";
		cout << "So ngay diem danh \n";

		cin >> n;

		cin.ignore();
		for (int i = 0; i < n; i++)
		{
			e.diemdanh_1(i);
			c.History(e, i);
		}
		c.setFile("ImportData.txt");
		c.Printfcvs(e, n);
	}
	void CASE4()
	{
		cout << "LICH SU DIEM DANH !" << endl;
		string line;
		ifstream fileInput("history.txt", ios::in);
		if (fileInput.is_open())
		{
			while (!fileInput.eof())
			{
				getline(fileInput, line);
				string epl = line;
				cout << epl << endl;
			}
			
		}
		
	}
	void CASE5()
	{
		string name;
		cout << "Nhap Ten nhan vien ";
		getline(cin, name);
		search a;
		a.setFile("text.txt");
		a.Searchnv(name);
	}
	void CASE6()
	{
		string team;
		cout << "Nhap bo phan can tim " << endl;
		getline(cin, team);
		search a;
		a.setFile("text.txt");
		a.Searchteam(team);
	}
	void CASE7()
	{
		search a;
		a.setFile("text.txt");
		a.Searchall();
	}
};