#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib> 
#include <locale> 
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Date
{
	int date_day = 0;
	int date_month = 0;
	int date_year = 0;
	Date& operator=(const Date& obj)
	{
		date_day = obj.date_day;
		date_month = obj.date_month;
		date_year = obj.date_year;
		return *this;
	}
	friend ostream& operator<<(ostream& os, Date& obj);
	void Setdate(int dt_day, int dt_month, int dt_year)
	{
		date_day = dt_day;
		date_month = dt_month;
		date_year = dt_year;
	}
};
//перегрузка оператора вывода для структуры Date
ostream& operator<<(ostream& os, Date& obj)
{
	os << obj.date_day << ".";
	os << obj.date_month << ".";
	os << obj.date_year << endl;
	return os;
}

//структура в которой хранится дата наблюдения и его результат(вес)
struct Observation
{
	Date nabl;
	int weight = 0;
	//оператор присваивания
	Observation& operator=(const Observation& obj)
	{
		nabl.date_day = obj.nabl.date_day;
		nabl.date_month = obj.nabl.date_month;
		nabl.date_year = obj.nabl.date_year;
		weight = obj.weight;
		return *this;
	}
	void SetObservation(int dt_day, int dt_month, int dt_year, int weight_)
	{
		nabl.date_day = dt_day;
		nabl.date_month = dt_month;
		nabl.date_year = dt_year;
		weight = weight_;
	}
	//Перегрузка оператора вывода
	friend ostream& operator<<(ostream& os, Observation& obj);
};
ostream& operator<<(ostream& os, Observation& obj)
{
	os << obj.nabl;
	os << "Результат замера:" << obj.weight << endl;
	return os;
}

//Структура для записи за каждым человеком результатов наблюдений
struct Person
{
	string Name;
	vector <Observation> zamer;//Теперь через вектор вводим данные
	friend ostream& operator<<(ostream& os, Person& obj);
};
//перегрузка вывода
ostream& operator<<(ostream& os, Person& obj)
{
	os << "/t" << obj.Name << endl;
	for (unsigned int i = 0;i < obj.zamer.size();i++)
	{
		os << obj.zamer[i] << endl;
	}
	return os;
}

//Класс Напольные весы
class FloorWeight
{
private:
	Person *Family;
	int people;
	int count;
	int min;
	int max;
	int mid;
	int mid_of_month;
	Date StartDate;
public:
	//Конструктор
	FloorWeight()
	{
		people = 0;
	}
	//Конструктор по параметрам
	FloorWeight(int _peop)
	{
		people = _peop;
		Family = new Person[people];
	};
	//Деструктор
	~FloorWeight()
	{
		delete[] Family;
	}
	//Устанавливает наблюдение для выбранного человека
	void SetNabl(Observation nabl, string nam)
	{
		for (int i = 0;i < people;i++)
		{
			if (Family[i].Name == nam)
			{
				Family[i].zamer.push_back(nabl);
			}
		}

	}
	//установка имени
	void SetName()
	{
		for (int i = 0;i < people;i++)
		{
			Family[i].Name = getchar();
		}
	}
	//изменения имени
	void ChangeName(int number, string Nam)
	{

		Family[number - 1].Name = Nam;

	}
	//Установка первой даты (относится исключительно  к классу
	void Setfirstdate(Date Fd)
	{

		StartDate = Fd;

	}
	//Получение веса в выбранный день для выбранного человека
	int Getweight(string Nam, int dt_day, int dt_mounth, int dt_year)
	{
		for (int i = 0;i < people;i++)
		{
			if (Family[i].Name == Nam)
			{
				for (unsigned int j = 0;j < Family[i].zamer.size();j++)
				{
					if (Family[i].zamer[j].nabl.date_day == dt_day && Family[i].zamer[j].nabl.date_month == dt_mounth && Family[i].zamer[j].nabl.date_year == dt_year)
					{
						return Family[i].zamer[j].weight;
					}
				}
			}
		}
		return 0;
	}
	//Получить начальную дату
	Date Getfirstdate()
	{

		return StartDate;
	}
	//Получить минимальный вес для выбранного человека
	int Minweight(string Nam)
	{
		min = 0;

		for (int j = 1; j < people; j++)
		{
			if (Family[j].Name == Nam)
			{
				for (unsigned int i = 0;i < Family[j].zamer.size();i++)
				{
					if (Family[j].zamer[i].weight < min)
					{
						min = Family[j].zamer[j].weight;
					}
				}
			}
		}
		return min;
	}
	//Получить максимальный вес для выбранного человека
	int Maxweight(string Nam)
	{
		max = 0;
		for (int j = 1; j < people; j++)
		{
			if (Family[j].Name == Nam)
			{
				for (unsigned int i = 0;i < Family[j].zamer.size();i++)
				{
					if (Family[j].zamer[i].weight > max)
					{
						max = Family[j].zamer[j].weight;
					}
				}
			}
		}
		return max;
	}
	//Получить средний вес человека за все время наблюдений
	int Midweight(string Nam)
	{
		for (int i = 0;i < people;i++)
		{
			if (Family[i].Name == Nam)
			{
				for (unsigned int j = 0;j <= Family[i].zamer.size();j++)
				{
					mid += Family[i].zamer[j].weight;
					count++;
				}
				mid = mid / count;
				return mid;
			}
		}
	}
	//Получить средний вес человека в выбранном месяце
	int Midweightofmonth(string Nam, int dt_month)
	{
		for (int i = 0;i < people;i++)
		{
			if (Family[i].Name == Nam)
			{
				for (unsigned int j = 0;j <= Family[i].zamer.size();j++)
				{
					if (Family[i].zamer[j].nabl.date_month == dt_month)
					{
						mid_of_month += Family[i].zamer[j].weight;
						count++;
					}
				}
				mid_of_month = mid_of_month / count;
				return mid_of_month;
			}
		}
	}
	//Запись в файл результатов
	void writetofile()
	{
		ofstream file;
		file.open("result.txt");//создание файла
		for (int i = 0;i < people;i++)//заполнение 
		{
			file << Family[i].Name;
			file << endl;
			for (int j = 0;j < count;j++)
			{

				file << Family[i].zamer[j];
				file << endl;
			}
		}
		file.close();//завершение
	}
	//Запись из файла
	void writefromfile()
	{
		ifstream file("result.txt");
		char str[100];//временное хранение 
		char tmp[100];//символов файла
		for (int i = 0;i < people;i++)//заполнение из файла 
		{
			file.getline(str, 12, '\n');
			Family[i].Name = atoi(str);
			for (int j = 0;j < count;j++)
			{

				file.getline(tmp, 12, ':');
				file.getline(str, 2, '.');
				Family[i].zamer[j].nabl.date_day = atoi(str);
				file.getline(str, 2, '.');
				Family[i].zamer[j].nabl.date_month = atoi(str);
				file.getline(str, 4, '\n');
				Family[i].zamer[j].nabl.date_year = atoi(str);
			}
		}
	}
	//Добавить члена семьи
	void addfam(string Name, Observation Fm)
	{
		people += 1;//увеличиваем праметр колличества людей
		Person *NewFamily;//создаем временный ммассив в который запише старые данные и новые
		Observation Nab{ 0,0 };
		int a = 0;
		int b = 0;
		NewFamily = new Person[people];
		for (int i = 0;i < (people - 2);i++)
		{
			while (a != count)
			{
				Family[i].zamer.push_back(Nab);
				a++;
			}
		}
		NewFamily[people - 1].Name = Name;

		NewFamily[people - 1].zamer[0].weight = Fm.weight;
		NewFamily[people - 1].zamer[0].nabl.date_day = Fm.nabl.date_day;
		NewFamily[people - 1].zamer[0].nabl.date_month = Fm.nabl.date_month;
		NewFamily[people - 1].zamer[0].nabl.date_year = Fm.nabl.date_year;
		delete[] Family;//очищаем старый массив
		Family = new Person[people];//задаем ему нужный размер
		for (int k = 0;k < people;k++)
		{
			while (b != count)
			{
				Family[k].zamer.push_back(Nab);
				a++;
			}
			for (int l = 0;l < count;l++)
			{
				Family[k].zamer[l] = NewFamily[k].zamer[l];//заполяем 
			}
		}
	}
};
int main()
{
	setlocale(LC_ALL, "rus");
	Observation k;
	string Name;
	int people;
	int count;
	int num;
	FloorWeight K;
	Date Fd;
	int dt_day;
	int dt_month;
	int dt_year;
	int weight_;
	int choice;
	int ch;
	cout << "Введите колличество взвешенных людей: ";
	cin >> people;
	cout << endl;
	system("cls");
	for (int i = 0;i < people;i++)
	{
		cout << "Введите имя:";cin >> Name;cout << endl;
		cout << "Задайте наблюдение" << endl;
		cout << "Введите день:";cin >> dt_day;cout << endl;
		cout << "Введите месяц:";cin >> dt_month;cout << endl;
		cout << "Введите год:";cin >> dt_year;cout << endl;
		cout << "Введите вес:";cin >> weight_;cout << endl;
		k.SetObservation(dt_day, dt_month, dt_year, weight_);
		K.SetNabl(k, Name);
	}
	cout << "Что желаете сделать дальше?"
		<< "1-установить первую дату"
		<< "2-узнать первую дату"
		<< "3-узнать для выбранного члена семьи средний результат взвешивания "
		<< "4-узнать минимальный вес "
		<< "5-узнать максимальный вес"
		<< "6-записать все данные в текстовый файл"
		<< "7-записать данные из в файла в класс"
		<< "8-Добавить члена семьи"
		<< "9-выход";
	switch (choice)
	{
	case 1:
	{
		cout << "Введите день:";cin >> dt_day;cout << endl;
		cout << "Введите месяц:";cin >> dt_month;cout << endl;
		cout << "Введите год:";cin >> dt_year;cout << endl;
		Fd.Setdate(dt_day, dt_month, dt_year);
		K.Setfirstdate(Fd);
	}
	case 2:
	{
		cout << K.Getfirstdate() << endl;
	}
	case 3:
	{
		cout << "1-За все время наблюдений,2- в выбранный месяц" << endl;
		cin >> ch;
		if (ch == 2)
		{
			cout << "Введите имя:";cin >> Name;cout << endl;
			cout << "Введите месяц:";cin >> dt_month;cout << endl;
			system("cls");
			cout << K.Midweightofmonth(Name, dt_month);
			system("pause");

		}
		if (ch = 1)
		{
			cout << "Введите имя:";cin >> Name;cout << endl;
			system("cls");
			cout << K.Midweight(Name);
			system("pause");
		}
	}
	case 4:
	{
		cout << "Введите имя члена семьи";cin >> Name;cout << endl;
		cout << K.Minweight(Name) << endl;
		system("pause");
	}
	case 5:
	{
		cout << "Введите имя  члена семьи";cin >> Name;cout << endl;
		cout << K.Maxweight(Name) << endl;
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
		Observation Fm;
		string Name;
		cout << "Введите имя: ";
		getline(cin, Name);
		cout << endl;
		cout << "Введите день:";cin >> dt_day;cout << endl;
		cout << "Введите месяц:";cin >> dt_month;cout << endl;
		cout << "Введите год:";cin >> dt_year;cout << endl;
		cout << "Введите вес:";cin >> weight_;cout << endl;
		Fm.SetObservation(dt_day, dt_month, dt_year, weight_);
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