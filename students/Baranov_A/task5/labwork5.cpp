#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Структура взятого кредита 
struct CheckCredit
{
	//Дата взятия кредита
	int date_day;
	int date_month;
	int date_year;
	//Информация о кредите
	int term;
	int sum;
	int procent;
	//Проверка кредита 
	bool emptycredit()
	{
		if (sum == 0)
		{
			date_day = 0;
			date_month = 0;
			date_year = 0;
			term = 0;
			procent = 0;
			return false;
		}
		else
			return true;
	}
	//Начисление 
	void pay(int pay_)
	{
		sum -= pay_;
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

//Структра информации о доступных кредитах
struct Crdt
{
	int sum[4];//сумма кредита
	int interest_rate[4];//ставка
	int srok;//срок
	friend ostream& operator<<(ostream& os, const Crdt& obj);
};
ostream& operator<<(ostream& os, const Crdt& obj)
{
	os << "Срок кредита:\t" << obj.srok << endl;
	for (int i = 0;i < 3;i++)
	{


		os << "Сумма кредита:\t" << obj.sum[i] << "-" << obj.sum[i + 1] << "\t";
		os << "Годовой процент:\t" << obj.interest_rate[i] << "%" << endl;

	}
	os << "Сумма кредита:\t" << obj.sum[3] << "-" << "и т.д" << "\t";
	os << "Годовой процент:\t" << obj.interest_rate[3] << "%" << endl;

	os << "-/ -/ -/ -/ -/ -/ -/ -/ -/ -/ -/ -/ -/ -/ -/ -/" << endl;
	return os;
}

//структура информации о кредите
struct Info
{
	Crdt inf_credit[5];
	Info()
	{
		//установка информации о достпуных кредитах
		inf_credit[0].srok = 1;
		inf_credit[0].sum[0] = 100000;
		inf_credit[0].sum[1] = 500000;
		inf_credit[0].sum[2] = 1000000;
		inf_credit[0].sum[3] = 3000000;

		inf_credit[1].srok = 2;
		inf_credit[1].sum[0] = 100000;
		inf_credit[1].sum[1] = 500000;
		inf_credit[1].sum[2] = 1000000;
		inf_credit[1].sum[3] = 3000000;

		inf_credit[2].srok = 3;
		inf_credit[2].sum[0] = 100000;
		inf_credit[2].sum[1] = 500000;
		inf_credit[2].sum[2] = 1000000;
		inf_credit[2].sum[3] = 3000000;

		inf_credit[3].srok = 5;
		inf_credit[3].sum[0] = 100000;
		inf_credit[3].sum[1] = 500000;
		inf_credit[3].sum[2] = 1000000;
		inf_credit[3].sum[3] = 3000000;

		inf_credit[4].srok = 15;
		inf_credit[4].sum[0] = 100000;
		inf_credit[4].sum[1] = 500000;
		inf_credit[4].sum[2] = 1000000;
		inf_credit[4].sum[3] = 3000000;

		//установка процентной ставки
		for (int i = 0;i < 4;i++)
		{
			for (int l = 0;l < 3;l++)
			{
				inf_credit[i].interest_rate[l] = (inf_credit[i].sum[l] / 3) / (inf_credit[i].srok * 365 * 12);
			}
			inf_credit[i].interest_rate[3] = (inf_credit[i].sum[3] / 8) / (inf_credit[i].srok * 365 * 12);
		}
	}
	//Проверка на возможность взятия кредита
	bool Check(int sum_, int srok_, int cash_)
	{
		int test;
		for (int i = 0;i < 4;i++)
		{
			if (inf_credit[i].srok == srok_)
			{
				for (int l = 0;l < 2;l++)
				{
					if (inf_credit[i].sum[l] < sum_ && sum_ < inf_credit[i].sum[l + 1])
					{
						test = 6 * sum_ / (inf_credit[i].interest_rate[l] / 12);
						if (cash_ >= test)
						{
							return true;
						}
						else
						{
							return false;
						}
					}
				}
			}
		}
	}
	//Выдать кредит для выбранных данных
	int TakeProcent(int sum_, int srok_, int cash_)
	{
		for (int i = 0;i < 4;i++)
		{
			if (inf_credit[i].srok == srok_)
			{
				for (int l = 0;l < 2;l++)
				{
					if (inf_credit[i].sum[l] < sum_ && sum_ < inf_credit[i].sum[l + 1])
					{
						return inf_credit[i].interest_rate[l];
					}
					else
					{
						return 0;
					}
				}
			}
		}
	}
	friend ostream& operator<<(ostream& os, const Info& obj);
};
ostream& operator<<(ostream& os, const Info& obj)
{
	for (unsigned int i = 0;i < 4;i++)
	{
		os << obj.inf_credit[i] << endl;
	}
	return os;
}

//Информация о клиенте
struct Client
{
	string Name;
	string Surname;
	string Patronymic;
	string account_number;//номер зарплатного счета
	int cash;//сумма на зарплатном счете
	string pasword;
	Info Crdit;//доступная информация о кредитах
	CheckCredit mycredit;//имеющийся кредит
	Client operator = (const Client& obj)
	{
		Name = obj.Name;
		Surname = obj.Surname;
		Patronymic = obj.Patronymic;
		account_number = obj.account_number;
		cash = obj.cash;
		pasword = obj.pasword;
		return *this;
	}
	//Устанавливаю кредит
	void SetCheckCredit(int term_, int sum_, int procent_, int day_, int month_, int year_)
	{
		mycredit.term = term_;
		mycredit.sum = sum_;
		mycredit.procent = procent_;
		mycredit.date_day = day_;
		mycredit.date_month = month_;
		mycredit.date_year = year_;
	}
	//проверка имеется ли кредит
	bool HaveMyCredit()
	{
		if (mycredit.emptycredit() == false)
		{
			return true;
		}
		else
			return false;
	}
	//Вывести исмеющийся кредит
	CheckCredit GetMyCredit()
	{
		return mycredit;
	}
	friend ostream& operator<<(ostream& os, Client& obj);
};
ostream& operator<<(ostream& os, Client& obj)
{
	os << obj.Name << endl;
	os << obj.Surname << endl;
	os << obj.Patronymic << endl;
	os << obj.account_number << endl;
	return os;
};

//База клиентов
class ProcessingCenter
{
private:
	vector <Client> person;
	Client new_user;
public:
	//Добавить пользователя
	void SetClient(string Nam, string Sur, string Pat, string pasw, string acc_num, int cash_)
	{
		new_user.Name = Nam;
		new_user.Surname = Sur;
		new_user.Patronymic = Pat;
		new_user.pasword = pasw;
		new_user.account_number = acc_num;
		new_user.cash = cash_;
		person.push_back(new_user);
	}
	//Вывести аккаунт
	string GetAccnum(string Nam, string Sur, string Pat, string pasw)
	{
		for (unsigned i = 0;i < person.size();i++)
		{
			if (person[i].Name == Nam && person[i].Surname == Sur && person[i].Patronymic == Pat && person[i].pasword == pasw)
			{
				return person[i].account_number;
			}
		}
	}
	//Вывести деньги на счете
	int GetCash(string Nam, string Sur, string Pat, string pasw)
	{
		for (unsigned i = 0;i < person.size();i++)
		{
			if (person[i].Name == Nam && person[i].Surname == Sur && person[i].Patronymic == Pat && person[i].pasword == pasw)
			{
				return person[i].cash;
			}
		}
	}
	//Вывести пароль
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
	//Вывести клиента
	Client GetClient(string Nam, string Sur, string Pat, string pasw, string acc_num)
	{
		for (unsigned i = 0;i < person.size();i++)
		{
			if (person[i].Name == Nam && person[i].Surname == Sur && person[i].Patronymic == Pat && person[i].pasword == pasw  && person[i].account_number == acc_num)
			{
				return person[i];
			}
		}
	}
	//вывести инфопмацию о кредите
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

//Класс получения кредит
class Credit
{
private:
	ProcessingCenter request;
	Client man;
public:
	//авторизация клиента
	Client Authorization(string Nam, string Sur, string Pat, string pasw, string acc_num)
	{
		man = request.GetClient(Nam, Sur, Pat, pasw, acc_num);
		man.cash = request.GetCash(Nam, Sur, Pat, pasw);
		return request.GetClient(Nam, Sur, Pat, pasw, acc_num);
	}
	//Показать клиенту инфу
	Info GetInfoCredit()
	{
		return request.GetInfo(man.Name, man.Surname, man.Patronymic);
	}
	//Выбор и проверка кредита
	void ChoiceOfCredit(int sum_, int srok_, int cash_, int day, int month, int year)
	{
		man.Crdit.Check(sum_, srok_, cash_);
		man.SetCheckCredit(srok_, sum_, man.Crdit.TakeProcent(sum_, srok_, cash_), day, month, year);
	}
	//Имеется ли кредит у клиента
	bool CheckGetCredit()
	{
		if (man.HaveMyCredit() == true)
			return true;
		else
			return false;
	}
	//Начисления за кредит
	void PayforCredit(int pay_)
	{
		man.mycredit.pay(pay_);
	}
	//Погашение кредита
	friend int Redemption(Credit&);
};
int Redemption(Credit &obj)
{
	int redem_;
in:	cout << obj.man.mycredit;
	cout << "Введите сумму погашения" << endl;
	cin >> redem_;

	obj.man.mycredit.sum -= redem_;
	if (obj.man.mycredit.emptycredit() == true)
	{
		cout << "Кредит погашен" << endl;
		return 0;
	}
	else
	{
		cout << "Вы не погасили кредит";
		goto in;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string nam;
	string pat;
	string sur;
	string ac_num;
	string pasw;
	int money;
	int srok_of_credit;
	int sum;
	int date_day;
	int date_month;
	int date_year;
	int pay_;
	ProcessingCenter Base;
	Credit Bank;
	cout << "Введите имя:\t";
	cin >> nam;
	cout << "Введите отчество:\t";
	cin >> sur;
	cout << "Введите фамилия:\t";
	cin >> pat;
	cout << "Введите номер зарплатного счета:\t";
	cin >> ac_num;
	cout << "Введите пароль:\t";
	cin >> pasw;
	cout << "Сумму на зарплатном счету:\t";
	cin >> money;
	Base.SetClient(nam, sur, pat, pasw, ac_num, money);
	cout << Base.GetAccnum(nam, sur, pat, pasw) << endl;
	cout << Base.GetCash(nam, sur, pat, pasw) << endl;
	cout << Base.Getpasword(nam, sur, pat, pasw) << endl;
	cout << Base.GetInfo(nam, sur, pat);
	system("pause");
	Bank.Authorization(nam, sur, pat, pasw, ac_num);
	cout << "Введите срок кредита:\t";
	cin >> srok_of_credit;
	cout << "Введите сумму кредита:\t";
	cin >> sum;
	cout << "Введите дату взятия кредита" << endl;
	cout << "День:\t";
	cin >> date_day;
	cout << "Месяц:\t";
	cin >> date_month;
	cout << "Год:\t";
	cin >> date_year;
	Bank.ChoiceOfCredit(sum, srok_of_credit, money, date_day, date_month, date_year);
	cout << "Проверка на наличие кредита" << endl;
	if (Bank.CheckGetCredit() == true)
		cout << "Кредитов нет" << endl;
	if (Bank.CheckGetCredit() == false)
		cout << "У Вас есть активные кредиты" << endl;
	cout << "Оплатите кредит,введите сумму" << endl;
	cin >> pay_;
	Bank.PayforCredit(pay_);
	cout << "Погашение кредита" << endl;
	Redemption(Bank);
	system("pause");
}