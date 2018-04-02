#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib> 
#include <locale> 
#include <fstream>
#include <string>
#include <vector>

using namespace std;

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
	//Перегрузка оператора вывода
	friend ostream& operator<<(ostream& os, Observation& obj);
};
ostream& operator<<(ostream& os, Observation& obj)
{
	os << obj.nabl;
	os << "Результат замера:" << obj.weight << endl;
	return os;
}
//структура в которой будет содержаться (и вне записываться) первая дата
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
};
//перегрузка оператора вывода для структуры Date
ostream& operator<<(ostream& os, Date& obj)
{
	os << obj.date_day << ".";
	os << obj.date_month << ".";
	os << obj.date_year << endl;
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
	Date StartDate;
public:
	//Конструктор
	FloorWeight()
	{
		people = 0;
		count = 0;

	}
	//Конструктор по параметрам
	FloorWeight(int _peop, int _tim)
	{
		people = _peop;
		count = _tim;
		int j = 0;
		Observation Nab{ 0,0 };//Пустая структура чтобы заполнить наблюдения
		Family = new Person[people];
		for (int i = 0;i < people;i++)
		{
			while (j != count)
			{
				Family[i].zamer.push_back(Nab);
				j++;
			}
		}
	};
	//Деструктор
	~FloorWeight()
	{
		delete[] Family;
	}
	//Установка даты для всего числа наблюдений
	void SetDate(vector <Observation> Fam_, int _peo, int cnt_)
	{
		people = _peo;
		count = cnt_;
		Observation Nab{ 0,0 };
		int a = 0;
		Family = new Person[people];
		for (int i = 0;i < people;i++)
		{
			while (a != count)
			{
				Family[i].zamer.push_back(Nab);
				a++;
			}
			for (int j = 0;j < count;j++)
			{
				Family[i].zamer[j].nabl.date_day = Fam_[j].nabl.date_day;
				Family[i].zamer[j].nabl.date_month = Fam_[j].nabl.date_month;
				Family[i].zamer[j].nabl.date_year = Fam_[j].nabl.date_year;
			}
		}
	}
	//Устанавливает наблюдение для выбранного человека
	void SetNabl(Observation nabl, int number)
	{
				Family[number-1].Name = getchar();//задаю имя взвешенного человека
				Family[number-1].zamer.push_back(nabl);//вношу данные взвешивания

	}
	//установка имен
	void SetName(string *Names)
	{
		for (int i = 0;i < people;i++)
		{
			Family[i].Name = Names[i];
		}
	}
	//Установка первой даты (относится исключительно  к классу
	void Setfirstdate(Date Fd)
	{

		StartDate = Fd;

	}
	//Установка веса для всего числа наблюдений
	void SetWeight(vector <Observation> Fam_)
	{
		for (int i = 0;i < people;i++)
		{
			for (int j = 0;j < count;j++)
			{
				Family[i].zamer[j].weight = Fam_[j].weight;
			}
		}
	}
	//Получение веса в выбранный день для выбранного человека
	int Getweight(int number, int dt_day, int dt_mounth, int dt_year)
	{
		for (int i = 0;i < people;i++)
		{
			if (i == number)
			{
				for (int j = 0;j < count;j++)
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
	int Minweight(int number)
	{
		for (int i = 0; i < people; i++)
		{
			if (i == number)
			{
				for (int j = 1; j < count; j++)
				{
					min = Family[i].zamer[0].weight;
					if (Family[i].zamer[j].weight < min)
						min = Family[i].zamer[j].weight;
				}
			}
		}
		return min;
	}
	//Получить максимальный вес для выбранного человека
	int Maxweight(int number)
	{

		for (int i = 0; i < people; i++)
		{
			if (i == number)
			{
				for (int j = 1; j < count; j++)
				{
					max = Family[i].zamer[0].weight;
					if (Family[i].zamer[j].weight > max)
						max = Family[i].zamer[j].weight;
				}
			}
		}
		return max;
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
	void addfam(string Name, vector <Observation> Fm)
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
		for (int j = 0;j < count;j++)
		{
			Family[people - 1].zamer[j].weight = Fm[j].weight;
			Family[people - 1].zamer[j].nabl.date_day = Fm[j].nabl.date_day;
			Family[people - 1].zamer[j].nabl.date_month = Fm[j].nabl.date_month;
			Family[people - 1].zamer[j].nabl.date_year = Fm[j].nabl.date_year;
		}
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
//К сожаленью пока не стал делать мэин(жду ваших замечаний по классу) 
/*int main()
{
setlocale(LC_ALL, "rus");
Observation *k;
string *Names;
int people;
int count;
FloorWeight K;
Date Fd;
int dt_day;
int dt_month;
int dt_year;
int weight_;
int choice;
cout << "Введите колличество взвешенных людей: ";
cin >> people;
cout << endl;
cout << "Введите колличество взвешиваний: ";
cin >> count;
system("cls");
Names=new string[people];
k=new Observation[count];
for (int i = 0;i < people;i++)
{
cout << "Введите имя: ";
getline(cin,Names[i]);
cout<< endl;
for (int j = 0;j < count;j++)
{

cout << "Введите день:";cin >> dt_day;cout << endl;
cout << "Введите месяц:";cin >> dt_month;cout << endl;
cout << "Введите год:";cin >> dt_year;cout << endl;
cout << "Введите вес:";cin >> weight_;cout << endl;
k[i].SetNabl(dt_day, dt_month, dt_year, weight_);
system("cls");
}
}
K.SetDate(k, 1, 2);
K.SetName(Names);
K.SetWeight(k);
cout << "Что желаете сделать дальше?"
<< "1-установить новую первую дату"
<< "2-узнать первую дату"
<< "3-узнать результаты взвешивания в выбранную дату"
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
cout << K.Getfirstdate(Fd)<<endl;
}
case 3:
{
cout << "Введите день:";cin >> dt_day;cout << endl;
cout << "Введите месяц:";cin >> dt_month;cout << endl;
cout << "Введите год:";cin >> dt_year;cout << endl;
system("cls");
cout << K.Getweight(dt_day, dt_month, dt_year)<<endl;
system("pause");
}
case 4:
{
cout << K.Minweight()<<endl;
system("pause");
}
case 5:
{
cout << K.Maxweight()<<endl;
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
Observation *Fm;
string Name;
cout << "Введите имя: ";
getline(cin, Name);
cout << endl;
Fm = new Observation[count];
for (int j = 0;j < count;j++)
{
cout << "Введите день:";cin >> dt_day;cout << endl;
cout << "Введите месяц:";cin >> dt_month;cout << endl;
cout << "Введите год:";cin >> dt_year;cout << endl;
cout << "Введите вес:";cin >> weight_;cout << endl;
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
}*/