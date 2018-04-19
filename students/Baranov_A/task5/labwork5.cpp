#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct CheckCredit
{
	//Дата взятия кредита
	int date_day;
	int date_month;
	int date_year;
	//
	int term;
	int sum;
	int procent;
	CheckCredit()
	{
		term = 0;
		sum = 0;
		procent = 0;
		date_day = 0;
		date_month = 0;
		date_year = 0;

	}
	bool emptycredit()
	{

		if (term == 0 && sum == 0 && procent == 0 && date_day == 0 && date_month == 0 && date_year == 0)
		{
			return false;
		}
		else
			return true;
	}
	friend ostream& operator<<(ostream& os, CheckCredit& obj);
};
ostream& operator<<(ostream& os, CheckCredit& obj)
{
	os << obj.date_day << ".";
	os << obj.date_month << ".";
	os << obj.date_year << endl;
	os << "Срок кредита:\t" << obj.term << endl;
	os << "Сумма кредита:\t" << obj.sum << endl;
	os << "Годовой процент:\t" << obj.procent << endl;
	return os;
}
struct Crdt
{
	int sum[4];//сумма кредита
	int interest_rate[4];//ставка
	int srok;//срок
	friend ostream& operator<<(ostream& os, Crdt& obj);
};
ostream& operator<<(ostream& os, Crdt& obj)
{
	os << "Срок кредита:\t" << obj.srok << endl;
	for (int i = 0;i < 4;i++)
	{
		os << "Сумма кредита:\t" << obj.sum;
		os << "Годовой процент:\t" << obj.interest_rate << endl;
	}
	os << "-/ -/ -/ -/ -/ -/ -/ -/ -/ -/ -/ -/ -/ -/ -/ -/" << endl;
	return os;
}
struct Info//структура информации о кредите
{
	Crdt inf_credit[20];
	Info()
	{
		for (int j1 = 0;j1 < 3;j1++)
		{
			inf_credit[j1].srok = 1;
			inf_credit[j1].sum[0] = 100000;
			inf_credit[j1].sum[1] = 500000;
			inf_credit[j1].sum[2] = 1000000;
			inf_credit[j1].sum[3] = 3000000;
		}
		for (int j2 = 4;j2 < 7;j2++)
		{
			inf_credit[j2].srok = 2;
			inf_credit[j2].sum[0] = 100000;
			inf_credit[j2].sum[1] = 500000;
			inf_credit[j2].sum[2] = 1000000;
			inf_credit[j2].sum[3] = 3000000;
		}
		for (int j3 = 8;j3 < 11;j3++)
		{
			inf_credit[j3].srok = 3;
			inf_credit[j3].sum[0] = 100000;
			inf_credit[j3].sum[1] = 500000;
			inf_credit[j3].sum[2] = 1000000;
			inf_credit[j3].sum[3] = 3000000;
		}
		for (int j4 = 12;j4 < 15;j4++)
		{
			inf_credit[j4].srok = 5;
			inf_credit[j4].sum[0] = 100000;
			inf_credit[j4].sum[1] = 500000;
			inf_credit[j4].sum[2] = 1000000;
			inf_credit[j4].sum[3] = 3000000;
		}
		for (int j5 = 16;j5 < 19;j5++)
		{
			inf_credit[j5].srok = 15;
			inf_credit[j5].sum[0] = 100000;
			inf_credit[j5].sum[1] = 500000;
			inf_credit[j5].sum[2] = 1000000;
			inf_credit[j5].sum[3] = 3000000;
		}
		for (unsigned int i = 0;i < 19;i++)
		{
			for (int l = 0;l<4;l++)
				inf_credit[i].interest_rate[l] = 100 * inf_credit[i].sum[l] / (inf_credit[i].srok * 12);
		}
	}
	bool Chech(int sum_, int interest_rate_, int srok_, int cash_)
	{
		int test;
		test = 6 * sum_ / (interest_rate_ / 12);
		if (cash_ >= test)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	friend ostream& operator<<(ostream& os, Info& obj);
};
ostream& operator<<(ostream& os, Info& obj)
{
	for (unsigned int i = 0;i < 20;i++)
	{
		os << obj.inf_credit[i] << endl;
	}
	return os;
}
struct Client
{
	string Name;
	string Surname;
	string Patronymic;
	string account_number;//номер зарплатного счета
	int cash;//сумма на зарплатном счете
	string pasword;
	Info Crdit;
	CheckCredit mycredit;
	void SetCheckCredit(int term_, int sum_, int procent_, int day_, int month_, int year_)
	{
		mycredit.term = term_;
		mycredit.sum = sum_;
		mycredit.procent = procent_;
		mycredit.date_day = day_;
		mycredit.date_month = month_;
		mycredit.date_year = year_;
	}
	bool HaveMyCredit()
	{
		if (mycredit.emptycredit() == false)
		{
			return true;
		}
		else
			return false;
	}
	CheckCredit GetMyCredit()
	{
		return mycredit;
	}
	friend ostream& operator<<(ostream& os, Client& obj);
};
ostream& operator<<(ostream& os, Client& obj)
{
	string choice;
	os << "Здравствуйте," << obj.Name << "!";
	os << "Желаете узнать информацию о доступных кредитах?";
	cin >> choice;
	if (choice == "Да")
	{
		cout << obj.Crdit;
	}
	if (choice != "Да")
	{
		os << "Прощайте,Удачного Дня!" << endl;
	}
	return os;
};
class ProcessingCenter
{
private:
	vector <Client> person;

public:
	ProcessingCenter()
	{

	}
	void SetClient(string Nam, string Sur, string Pat)
	{
		Client user;
		user.Name = Nam;
		user.Surname = Sur;
		user.Patronymic = Pat;
		person.push_back(user);
	}
	void SetAccount(string Nam, string Sur, string Pat, string pasw, string acc_num, int cash_)
	{
		for (unsigned i = 0;i < person.size();i++)
		{
			if (person[i].Name == Nam && person[i].Surname == Sur && person[i].Patronymic == Pat)
			{

				person[i].account_number = acc_num;
				person[i].pasword = pasw;
				person[i].cash = cash_;
			}
		}
	}
	string GetAccnum(string Nam, string Sur, string Pat, string pasw)
	{
		for (unsigned i = 0;i < person.size();i++)
		{
			if (person[i].Name == Nam && person[i].Surname == Sur && person[i].Patronymic == Pat && person[i].pasword == pasw)
			{
				person[i].account_number;
			}
		}
	}
	int GetCash(string Nam, string Sur, string Pat, string pasw)
	{
		for (unsigned i = 0;i < person.size();i++)
		{
			if (person[i].Name == Nam && person[i].Surname == Sur && person[i].Patronymic == Pat && person[i].pasword == pasw)
			{
				person[i].cash;
			}
		}
	}
	string Getpasword(string Nam, string Sur, string Pat, string acc_num)
	{
		for (unsigned i = 0;i < person.size();i++)
		{
			if (person[i].Name == Nam && person[i].Surname == Sur && person[i].Patronymic == Pat && person[i].account_number == acc_num)
			{
				return person[i].pasword;;
			}
		}
	}
	Client GetClient(string Nam, string Sur, string Pat, string pasw)
	{
		for (unsigned i = 0;i < person.size();i++)
		{
			if (person[i].Name == Nam && person[i].Surname == Sur && person[i].Patronymic == Pat && person[i].pasword == pasw)
			{
				return person[i];
			}
		}
	}
	Info GetInfo(string Nam, string Sur, string Pat)
	{
		for (unsigned i = 0;i < person.size();i++)
		{
			if (person[i].Name == Nam && person[i].Surname == Sur && person[i].Patronymic == Pat)
			{
				return person[i].Crdit;
			}
		}
	}
};
class Credit
{
private:
	ProcessingCenter request;
	Client man;
public:
	Credit()
	{

	}
	Client Authorization(string Nam, string Sur, string Pat, string pasw)
	{
		man = request.GetClient(Nam, Sur, Pat, pasw);
		man.account_number = request.GetAccnum(Nam, Sur, Pat, pasw);
		man.cash = request.GetCash(Nam, Sur, Pat, pasw);
		return request.GetClient(Nam, Sur, Pat, pasw);
	}
	Info GetInfoCredit()
	{
		return request.GetInfo(man.Name, man.Surname, man.Patronymic);
	}
	void ChoiceOfCredit(int sum_, int interest_rate_, int srok_, int cash_, int day, int month, int year)
	{
		man.Crdit.Chech(sum_, interest_rate_, srok_, cash_);
		man.SetCheckCredit(srok_, sum_, interest_rate_, day, month, year);
	}
	bool CheckGetCredit()
	{

		if (man.HaveMyCredit() == true)
			return true;
		else
			return false;
	}
};
