#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib> 
#include <locale> 
#include <fstream>
#include <string>

using namespace std;

//��������� � ������� �������� ���� ���������� � ��� ���������(���)
struct Nabl
{
	int date_day = 0;
	int date_month = 0;
	int date_year = 0;
	int weight = 0;
	//������� ��������� ����(� ��������� �� ����� � ���)
	void SetNabl(int dt_day, int dt_month, int dt_year, int weight_)
	{
		date_day = dt_day;
		date_month = dt_month;
		date_year = dt_year;
		weight = weight_;
		if (date_month == 1 || date_month == 3 || date_month == 5 || date_month == 7 || date_month == 8 || date_month == 10)
		{
			if (date_day > 31)
			{
				date_day = date_day % 31;
				date_month++;
			}
		}
		if (date_month == 12)
		{
			if (date_day > 31)
			{
				date_day = date_day % 31;
				if (date_day == 0)
				{
					date_day = 1;
				}
				date_month = 1;
				date_year++;
			}
		}
		if (date_month == 4 || date_month == 6 || date_month == 9 || date_month == 11)
		{
			if (date_day > 30)
			{
				date_day = date_day % 30;
				date_month++;
			}
		}
		if (date_month == 2)
		{
			if (date_day > 28)
			{
				date_day = date_day % 28;
				date_month++;
			}
			if (date_year % 4 == 0)
			{
				if (date_day > 29)
				{
					date_day = date_day % 29;
					date_month++;
				}
			}
		}
		if (date_month > 12)
		{
			cout << "������������ ��������" << endl;
		}
	}
	//�������� ������������
	Nabl& operator=(const Nabl& obj)
	{
		date_day = obj.date_day;
		date_month = obj.date_month;
		date_year = obj.date_year;
		weight = obj.weight;
		return *this;
	}
	//���������� ��������� ������
	friend ostream& operator<<(ostream& os, Nabl& obj);
};
ostream& operator<<(ostream& os, Nabl& obj)
{
	os << "���� ������:" << obj.date_day << ".";
	os << obj.date_month << ".";
	os << obj.date_year << endl;
	os << "��������� ������:" << obj.weight << endl;
	return os;
}

//��������� � ������� ����� ����������� (� ��� ������������) ������ ����
struct Date
{
	int date_day = 0;
	int date_month = 0;
	int date_year = 0;
	void Setdate(int dt_day, int dt_month, int dt_year)
	{
		date_day = dt_day;
		date_month = dt_month;
		date_year = dt_year;
		if (date_month == 1 || date_month == 3 || date_month == 5 || date_month == 7 || date_month == 8 || date_month == 10)
		{
			if (date_day > 31)
			{
				date_day = date_day % 31;
				date_month++;
			}
		}
		if (date_month == 12)
		{
			if (date_day > 31)
			{
				date_day = date_day % 31;
				if (date_day == 0)
				{
					date_day = 1;
				}
				date_month = 1;
				date_year++;
			}
		}
		if (date_month == 4 || date_month == 6 || date_month == 9 || date_month == 11)
		{
			if (date_day > 30)
			{
				date_day = date_day % 30;
				date_month++;
			}
		}
		if (date_month == 2)
		{
			if (date_day > 28)
			{
				date_day = date_day % 28;
				date_month++;
			}
			if (date_year % 4 == 0)
			{
				if (date_day > 29)
				{
					date_day = date_day % 29;
					date_month++;
				}
			}
		}
	}
	Date& operator=(const Date& obj)
	{
		date_day = obj.date_day;
		date_month = obj.date_month;
		date_year = obj.date_year;
		return *this;
	}
	friend ostream& operator<<(ostream& os, Date& obj);
};
//���������� ��������� ������ ��� ��������� Date
ostream& operator<<(ostream& os, Date& obj)
{
	os << obj.date_day << ".";
	os << obj.date_month << ".";
	os << obj.date_year << endl;
	return os;
}

//��������� ��� ������ �� ������ ��������� ����������� ����������
struct Person
{
	string Name;
	Nabl* zamer;
	//���������� ��� ������� ��������
	~Person()
	{
		delete[] zamer;
	}
	//������ ������ �������
	size_t size()
	{
		return sizeof(zamer);
	}
	friend ostream& operator<<(ostream& os, Person& obj);
};
//���������� ������
ostream& operator<<(ostream& os, Person& obj)
{
	os << "/t" << obj.Name << endl;
	for (unsigned int i = 0;i < obj.size();i++)
	{
		os << obj.zamer[i] << endl;
	}
	return os;
}

//����� ��������� ����
class Floorweight
{
private:
	Person *Family;
	int people;
	int count;
	int min;
	int max;
public:
	//�����������
	Floorweight()
	{
		people = 0;
		count = 0;
		Family = new Person[people];//������ ������-���-�� ������ �����
		for (int i = 0;i < people;i++)
		{
			Family[i].zamer = new Nabl[count];//����� �������
			for (int j = 0;j < count;j++)
			{
				Family[i].zamer[j] = { 0,0,0,0 };
			}
		}

	}
	//����������� �� ����������
	Floorweight(int _peop, int _tim)
	{
		people = _peop;
		count = _tim;

		Family = new Person[people];
		for (int i = 0;i < people;i++)
		{
			Family[i].zamer = new Nabl[count];
			for (int j = 0;j < count;j++)
			{
				Family[i].zamer[j] = { 0,0,0,0 };
			}
		}
	};
	//����������
	~Floorweight()
	{
		delete[] Family;
	}
	//��������� ���� ��� ����� ����� ����������
	void Setdate(Nabl* Fam_, int _peo, int cnt_)
	{
		people = _peo;
		count = cnt_;
		Family = new Person[people];
		for (int j = 0;j < people;j++)
		{
			Family[j].zamer = new Nabl[count];
		}
		for (int i = 0;i < people;i++)
		{
			for (int j = 0;j < count;j++)
			{
				Family[i].zamer[j].date_day = Fam_[j].date_day;
				Family[i].zamer[j].date_month = Fam_[j].date_month;
				Family[i].zamer[j].date_year = Fam_[j].date_year;
			}
		}
	}
	//��������� ����
	void Setname(string *Names)
	{
		for (int i = 0;i < people;i++)
		{
			Family[i].Name = Names[i];
		}
	}
	//��������� ������ ����
	void Setfirstdate(Date Fd)
	{
		Family[0].zamer[0].date_day = Fd.date_day;
		Family[0].zamer[0].date_month = Fd.date_month;
		Family[0].zamer[0].date_year = Fd.date_year;
	}
	//��������� ���� ��� ����� ����� ����������
	void Setweight(Nabl* Fam_)
	{
		for (int i = 0;i < people;i++)
		{
			for (int j = 0;j < count;j++)
			{
				Family[i].zamer[j].weight = Fam_[j].weight;
			}
		}
	}
	//��������� ���� � ��������� ����(�� ������� �� ������ ���� �����)
	int Getweight(int dt_day, int dt_mounth, int dt_year)
	{
		for (int i = 0;i < people;i++)
		{
			for (int j = 0;j < count;j++)
			{
				if (Family[i].zamer[j].date_day == dt_day && Family[i].zamer[j].date_month == dt_mounth && Family[i].zamer[j].date_year == dt_year)
				{
					return Family[i].zamer[j].weight;
				}
			}
		}
		return 0;
	}
	//�������� ��������� ����
	Date Getfirstdate(Date Firstdate)
	{
		Firstdate.Setdate(Family[0].zamer[0].date_day, Family[0].zamer[0].date_month, Family[0].zamer[0].date_year);
		return Firstdate;
	}
	//�������� ����������� ��� �� ���� �������
	int Minweight()
	{
		min = Family[0].zamer[0].weight;
		for (int i = 0; i < people; i++)
		{
			for (int j = 0; j < count; j++)
			{
				if (Family[i].zamer[j].weight < min)
					min = Family[i].zamer[j].weight;
			}
		}
		return min;
	}
	//�������� ������������ ��� �� ���� �������
	int Maxweight()
	{
		max = Family[0].zamer[0].weight;
		for (int i = 0; i < people; i++)
		{
			for (int j = 0; j < count; j++)
			{
				if (Family[i].zamer[j].weight > max)
					max = Family[i].zamer[j].weight;
			}
		}
		return max;
	}
	//������ � ���� �����������
	void writetofile()
	{
		ofstream file;
		file.open("result.txt");//�������� �����
		for (int i = 0;i < people;i++)//���������� 
		{
			file << Family[i].Name;
			file << endl;
			for (int j = 0;j < count;j++)
			{

				file << Family[i].zamer[j];
				file << endl;
			}
		}
		file.close();//����������
	}
	//������ �� �����
	void writefromfile()
	{
		ifstream file("result.txt");
		char str[100];//��������� �������� 
		char tmp[100];//�������� �����
		for (int i = 0;i < people;i++)//���������� �� ����� 
		{
			file.getline(str, 12, '\n');
			Family[i].Name = atoi(str);
			for (int j = 0;j < count;j++)
			{

				file.getline(tmp, 12, ':');
				file.getline(str, 2, '.');
				Family[i].zamer[j].date_day = atoi(str);
				file.getline(str, 2, '.');
				Family[i].zamer[j].date_month = atoi(str);
				file.getline(str, 4, '\n');
				Family[i].zamer[j].date_year = atoi(str);
			}
		}
	}
	//�������� ����� �����
	void addfam(string Name, Nabl* Fm)
	{
		people += 1;//����������� ������� ����������� �����
		Person *NewFamily;//������� ��������� ������� � ������� ������ ������ ������ � �����
		NewFamily = new Person[people];
		for (int i = 0;i < (people - 2);i++)
		{

			NewFamily[i] = Family[i];
		}
		NewFamily[people - 1].Name = Name;
		for (int j = 0;j < count;j++)
		{
			Family[people - 1].zamer[j].weight = Fm[j].weight;
			Family[people - 1].zamer[j].date_day = Fm[j].date_day;
			Family[people - 1].zamer[j].date_month = Fm[j].date_month;
			Family[people - 1].zamer[j].date_year = Fm[j].date_year;
		}
		delete[] Family;//������� ������ ������
		Family = new Person[people];//������ ��� ������ ������
		for (int i = 0;i < people;i++)
		{
			Family[i].zamer = new Nabl[count];
			for (int j = 0;j < count;j++)
			{
				Family[i].zamer[j] = NewFamily[i].zamer[j];//�������� 
			}
		}
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	Nabl *k;
	string *Names;
	int people;
	int count;
	Floorweight K;
	Date Fd;
	int dt_day;
	int dt_month;
	int dt_year;
	int weight_;
	int choice;
	cout << "������� ����������� ���������� �����: ";
	cin >> people;
	cout << endl;
	cout << "������� ����������� �����������: ";
	cin >> count;
	system("cls");
	Names = new string[people];
	k = new Nabl[count];
	for (int i = 0;i < people;i++)
	{
		cout << "������� ���: ";
		getline(cin, Names[i]);
		cout << endl;
		for (int j = 0;j < count;j++)
		{

			cout << "������� ����:";cin >> dt_day;cout << endl;
			cout << "������� �����:";cin >> dt_month;cout << endl;
			cout << "������� ���:";cin >> dt_year;cout << endl;
			cout << "������� ���:";cin >> weight_;cout << endl;
			k[i].SetNabl(dt_day, dt_month, dt_year, weight_);
			system("cls");
		}
	}
	K.Setdate(k, 1, 2);
	K.Setname(Names);
	K.Setweight(k);
	cout << "��� ������� ������� ������?"
		<< "1-���������� ����� ������ ����"
		<< "2-������ ������ ����"
		<< "3-������ ���������� ����������� � ��������� ����"
		<< "4-������ ����������� ��� "
		<< "5-������ ������������ ���"
		<< "6-�������� ��� ������ � ��������� ����"
		<< "7-�������� ������ �� � ����� � �����"
		<< "8-�������� ����� �����"
		<< "9-�����";
	switch (choice)
	{
	case 1:
	{
		cout << "������� ����:";cin >> dt_day;cout << endl;
		cout << "������� �����:";cin >> dt_month;cout << endl;
		cout << "������� ���:";cin >> dt_year;cout << endl;
		Fd.Setdate(dt_day, dt_month, dt_year);
		K.Setfirstdate(Fd);
	}
	case 2:
	{
		cout << K.Getfirstdate(Fd) << endl;
	}
	case 3:
	{
		cout << "������� ����:";cin >> dt_day;cout << endl;
		cout << "������� �����:";cin >> dt_month;cout << endl;
		cout << "������� ���:";cin >> dt_year;cout << endl;
		system("cls");
		cout << K.Getweight(dt_day, dt_month, dt_year) << endl;
		system("pause");
	}
	case 4:
	{
		cout << K.Minweight() << endl;
		system("pause");
	}
	case 5:
	{
		cout << K.Maxweight() << endl;
		system("pause");
	}
	case 6:
	{
		K.writetofile();
	}
	case 7:
	{
		K.writefromfile();
	}
	case 8:
	{
		Nabl *Fm;
		string Name;
		cout << "������� ���: ";
		getline(cin, Name);
		cout << endl;
		Fm = new Nabl[count];
		for (int j = 0;j < count;j++)
		{
			cout << "������� ����:";cin >> dt_day;cout << endl;
			cout << "������� �����:";cin >> dt_month;cout << endl;
			cout << "������� ���:";cin >> dt_year;cout << endl;
			cout << "������� ���:";cin >> weight_;cout << endl;
			Fm[j].SetNabl(dt_day, dt_month, dt_year, weight_);
		}
		K.addfam(Name, Fm);
	}
	case 9:
	{
		return 0;
	}
	}
	system("pause");
	return 0;
}