#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Textredactor
{
private:
	int x;
	int y;
	int length;
	string txt;
public:
	Textredactor()//конструктор координат
	{
		x = 0;
		y = 0;
		for (int j = 0; j < y; j++)
		{
			cout << endl;
		}
		for (int i = 0; i < x; i++)
		{
			cout << "   ";
		}

	}
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
	int Setlength(int leng)
	{
		length = leng;
		return length;
	}
	char* Getstring()//установка строки
	{
		basic_string <char>::size_type len;
		len = txt.length();//длина записанной строки
		char *Mass;
		Mass = new char[len];
		strcpy(Mass, txt.c_str());
		if (length<len)//при несовпадении длин выводит определенное количество символов

		{
			for (int j = 0;j < len;j++)
			{
				if (j > length - 1)
					Mass[j] = 0;
			}
			return Mass;
		}

		if (length == len)
		{
			return Mass;
		}

		if (length > len)
		{
			return Mass;
		}
		return Mass;
	}
	friend istream& operator >> (istream&, Textredactor&);
};
istream& operator >> (istream& ist, Textredactor& Text)
{
	ist >> Text.txt;
	return ist;
}
int main()
{
	int choice;
	int X = 0;
	int Y = 0;
	int length = 0;
	Textredactor str;
	setlocale(LC_ALL, "Russian");
in:	cout << "Желаете задать координаты?" << endl;
	cout << "1-Да,2-Нет" << endl;
	cin >> choice;
	system("cls");
	if (choice != 1)
		goto in;
	if (choice == 1)
	{
		cout << "Введите длину строки" << endl;
		cin >> length;
		cout << "Введите координаты" << endl;
		cin >> X;
		cin >> Y;
		cout << "Введите строку" << endl;
		cin >> str;
		system("cls");
		str.Setlength(length);
		str.Setcoordinat(X, Y);
		cout << str.Getstring() << endl;
		system("pause");
	}
}