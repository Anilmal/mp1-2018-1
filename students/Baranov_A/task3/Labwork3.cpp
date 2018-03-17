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
	Textredactor()//конструктор координат
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
	~Textredactor()
	{
		delete[] text;
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
	int GetcoordX()
	{
		return x;
	}
	int GetcoordY()
	{
		return y;
	}
	void Setlength(int leng)
	{
		length = leng;
	}
	char* Vvod()
	{

		for (int i = 0;i < length;i++)
		{
			text[i] = _getch();
			cout << text[i];
		}
		return text;
	}
	char* Getline()
	{
		return text;
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
		str.Setlength(length);
		cout << "Введите строку" << endl;
		str.Setcoordinat(X, Y);
		str.Vvod();
		cout << endl;
		system("pause");
		exit(0);
	}
}