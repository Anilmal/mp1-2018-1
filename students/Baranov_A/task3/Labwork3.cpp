#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Console
{
private:
	int x;
	int y;
	int lenght;
	string K;
public:
	Console()//конструктор координат
	{
		x = 0;
		y = 0;
		for (int j = 0; j < y; j++)
		{
			cout << endl;
		}
		for (int i = 0; i < x; i++)
		{
			cout << ' ';
		}

	}
	void Setconsole(int _x, int _y)//установка координат
	{
		x = _x;
		y = _y;
		for (int j = 0; j < y; j++)
		{
			cout << endl;
		}
		for (int i = 0; i < x; i++)
		{
			cout << ' ';
		}

	}
	void Setstring(string _k, int len)//установка строки
	{
		lenght = len;
		K = _k;

	}
	void Show(string _k, int L)//Вывод строки
	{
		if (lenght<L)//при несовпадении длин выводит определенное количество символов
		{
			char *Mass;
			Mass = new char[lenght];
			strcpy(Mass, _k.c_str());
			for (int j = 0;j < lenght;j++)

			{
				cout << Mass[j];
			}
			cout << endl;
		}
		if (lenght == L)
			cout << K << endl;
		if (lenght > L)
		{
			cout << K << endl;
		}
	}
};
int main()
{
	int choice;
	int X = 0;
	int Y = 0;
	int lenght = 0;
	Console M;
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
		cin >> lenght;
		std::string str(lenght, 0);//задание нулевой строки
		cout << "Введите координаты" << endl;
		cin >> X;
		cin >> Y;
		cout << "Введите строку" << endl;
		cin >> str;
		system("cls");
		basic_string <char>::size_type len;
		len = str.length();//длина записанной строки
		M.Setstring(str, lenght);
		M.Setconsole(X, Y);
		M.Show(str, len);
		system("pause");
	}
}