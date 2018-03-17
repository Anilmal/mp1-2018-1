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
	//Методы узнать координаты
	int GetcoordX()
	{
		return x;
	}
	int GetcoordY()
	{
		return y;
	}
	//Установка длины
	int Setlength(int leng)
	{
		length = leng;
		return length;
	}
	//Узнать длину
	int Getlength()
	{
		return length;
	}
	//Ввод текста
	void Vvod()
	{
		char *tx;
		tx = new char[length];
		for (int i = 0;i < length;i++)
		{
			tx[i] = _getch();
			putchar(tx[i]);
		}
	}
};
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
		system("cls");
		cout << "Введите строку" << endl;
		str.Setlength(length);
		str.Setcoordinat(X, Y);
		str.Vvod();
		cout << endl;
		system("pause");

	}
}