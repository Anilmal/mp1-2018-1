#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
using namespace std;

class Textredactor
{
private:
	int x;
	int y;
	int length;
	char* text;
public:
	//конструктор по умолчанию
	Textredactor()
	{
		x = 0;
		y = 0;
		length = 0;
		text = new char[length + 1];
		for (int i = 0;i <length + 1;i++)
		{
			text[i] = 0;
		}
	}
	//конструктор с параметрами
	Textredactor(int X, int Y)
	{
		x = X;
		y = Y;
		length = 0;
		text = new char[length + 1];
		for (int i = 0;i <length + 1;i++)
		{
			text[i] = 0;
		}
	}
	//конструктор копирования
	Textredactor(const Textredactor& obj)
	{
		x = obj.x;
		y = obj.y;
		length = obj.length;
		text = new char[length + 1];
		for (int j = 0;j < length + 1;j++)
		{
			text[j] = obj.text[j];
		}
	}
	//Деструктор
	~Textredactor()
	{
		delete[] text;
	}
	//оператор присваивания
	Textredactor& operator=(Textredactor& obj)
	{
		if (&obj != this)
		{
			delete[] text;
			text = new char[length + 1];
		}
		for (int i = 0;i < length + 1;i++)
		{
			text[i] = obj.text[i];
		}
		return *this;
	}
	//Установка координат
	void Setcoordinat(int _x, int _y)//установка координат
	{
		x = _x;
		y = _y;
		for (int j = 0; j < y; j++)
		{
			cout << endl;
		}
		for (int i = 0; i < x; i++)
		{
			cout << "   ";
		}

	}
	//Методы получения координат
	int GetcoordX()
	{
		return x;
	}
	int GetcoordY()
	{
		return y;
	}
	//Установка длины
	void Setlength(int leng)
	{
		length = leng;
	}
	//Получение длины
	int Getlength()
	{
		return length;
	}
	//Ввод строки
	char* Vvod()
	{

		for (int i = 0;i < length;i++)
		{
			text[i] = _getch();
			putchar(text[i]);
		}
		return text;
	}
	//Получение строки
	char* Getline()
	{
		return text;
	}
	//Вывод строки
	friend ostream& operator<<(ostream&, Textredactor&);
};
ostream& operator<<(ostream& os, Textredactor& obj)
{
	os << obj.text;
	return os;
}
int main()
{
	int choice;
	int X = 0;
	int Y = 0;
	int length = 0;
	Textredactor str;
	setlocale(LC_ALL, "Russian");
in:	cout << "\t Желаете ввести строку?\n"
	<< "\t 1-да или 2-нет\n\t";
	cin >> choice;
	system("cls");
	if (choice == 2)
		exit(0);
	if (choice == 1)
	{
		cout << "\t Введите длину строки :\t";
		cin >> length;
		str.Setlength(length);
		cout << "\t Введите координаты X:\t";
		cin >> X;
		cout << "\t Введите координаты Y:\t";
		cin >> Y;
		system("cls");
		str.Setcoordinat(X, Y);
		cout << "Введите строку:\t";
		str.Vvod();
		cout << "\n";
		system("pause");
		system("cls");
		cout << "\t Желаете продолжить?\n"
			<< "\t 1-да,2-нет\n\t";
		cin >> choice;
		if (choice == 2)
			exit(0);
		if (choice == 1)
			goto in;
	}
}