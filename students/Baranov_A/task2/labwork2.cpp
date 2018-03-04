#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class Matrix
{
private:
	int **Massive;
	int hight;
	int weight;
public:
	//Конструктор класса
	Matrix()
	{
		hight = 0;
		weight = 0;
		Massive = new int*[hight];
		for (int j = 0;j < hight;j++)
		{
			Massive[j] = new int[weight];
		}
		for (int h = 0;h < hight;h++)
		{
			for (int w = 0;w < weight;w++)
			{
				Massive[h][w] = 0;
			}
		}
	}
	//Конструкотр по параметрам
	Matrix(int _hight, int _weight)
	{
		hight = _hight;
		weight = _weight;
		Massive = new int*[hight];
		for (int j = 0;j < hight;j++)
		{
			Massive[j] = new int[weight];
		}
		for (int h = 0;h < hight;h++)
		{
			for (int w = 0;w < weight;w++)
			{
				Massive[h][w] = 0;
			}
		}
	}
	//Деструктор
	~Matrix()
	{
		for (int j = 0;j < hight;j++)
		{
			delete[] Massive[j];
		}
		delete[] Massive;
	}
	//Иницыализация элементов матрицы
	void SetMatrix(int _hight, int _weight, int **Massive_)
	{
		hight = _hight;
		weight = _weight;
		Massive = new int*[hight];
		for (int j = 0;j < hight;j++)
		{
			Massive[j] = new int[weight];
		}
		for (int h = 0;h < hight;h++)
		{
			for (int w = 0;w < weight;w++)
			{
				Massive[h][w] = Massive_[h][w];
			}
		}
	}
	//Оператор присваивания
	Matrix & operator = (const Matrix &obj)
	{
		if (&obj != this)
		{
			for (int j = 0;j < hight;j++)
			{
				delete[] Massive[j];
			}
			delete[] Massive;
			Massive = new int*[hight];
			for (int j = 0;j < hight;j++)
			{
				Massive[j] = new int[weight];
			}
		}
		for (int h = 0;h < hight;h++)
		{
			for (int w = 0;w < weight;w++)
			{
				Massive[h][w] = obj.Massive[h][w];
			}
		}
		return *this;
	}
	//Оператор сложения матриц 
	Matrix operator += (const Matrix &M)
	{
		if (hight == M.hight && weight == M.weight)
			for (int h = 0;h < hight;h++)
			{
				for (int w = 0;w < weight;w++)
				{
					Massive[h][w] = Massive[h][w] + M.Massive[h][w];
				}
			}
		return *this;
	}
	Matrix operator + (const Matrix &M)
	{
		Matrix tmp(hight, weight);//определение новой пустой матрицы чиобы записать в нее сумму
		if (hight == M.hight && weight == M.weight)
			for (int h = 0;h < hight;h++)
			{
				for (int w = 0;w < weight;w++)
				{
					Massive[h][w] += M.Massive[h][w];
					tmp.Massive[h][w] = Massive[h][w];
				}
			}
		return tmp;
	}
	//Вывод на экран матрицы
	void ShowMatrix()
	{
		for (int h = 0;h < hight;h++)
		{
			for (int w = 0;w < weight;w++)
			{
				cout.width(3);
				cout << Massive[h][w];
			}
			cout << endl;
		}
	}
	//Вывод элемента матрицы по заданному индексу
	void ShowNum(int hig, int wei)
	{
		cout << "Введите номер столбца: ";
		cin >> wei;
		cout << "Введите номер строки: ";
		cin >> hig;
		cout << Massive[hig - 1][wei - 1] << endl;;
	}
	//Установка элемента матрицы по индексу
	int SetNum(int h, int w)
	{
		cout << "Введите значение элемента: ";
		cin >> Massive[h - 1][w - 1];
		return Massive[h - 1][w - 1];
	}
	//Проверка на диагональное преобладание
	bool Diagonal()
	{
		int sum = 0;
		for (int h = 0;h < hight;h++)
		{
			for (int w = 0;w < weight;w++)
			{
				if (h != w)
				{
					sum += Massive[h][w];
				}
			}
			for (int i = 0;i < hight; i++)
			{
				if (abs(Massive[i][i]) < sum)
					return 0;
			}
		}
		return 1;
	}
};
int main()
{
	int choice, operation;
	int hight;
	int weight;
	Matrix M;
	int **Massive;
	system("chcp 1251>nul");
in:	cout << "Желаете задать матрицу?" << endl;
	cout << "1-Да,2-Нет" << endl;
	cin >> choice;
	system("cls");
	if (choice != 1)
		goto in;
	if (choice == 1)
	{
		cout << "Введите количество строк" << endl;
		cin >> hight;
		cout << "Введите количество столбцов" << endl;
		cin >> weight;
		cout << "Введите элементы матирцы" << endl;
		Massive = new int*[hight];
		for (int j = 0;j < hight;j++)
		{
			Massive[j] = new int[weight];
		};
		for (int h = 0;h < hight;h++)
		{
			for (int w = 0;w < weight;w++)
			{
				cin >> Massive[h][w];
			}
		}
		M.SetMatrix(hight, weight, Massive);
		system("cls");
		M.ShowMatrix();
		system("pause");
		system("cls");
		cout << "Какие операции хотите сделать" << endl;
		cout << "1-задать элемент по индексу,2-узнать элемент по индексу,3-сложить со второй матрицей,4-проверить на диагональное приобладание,5-выход" << endl;
		cin >> operation;
		if (operation == 1)
		{
			cout << "Введите номер столбца: ";
			cin >> weight;
			cout << "Введите номер строки: ";
			cin >> hight;
			M.SetNum(hight, weight);
			M.ShowMatrix();
			system("pause");
		}
		if (operation == 2)
		{
			cout << "Введите номер столбца: ";
			cin >> weight;
			cout << "Введите номер строки: ";
			cin >> hight;
			M.ShowNum(hight, weight);
			system("pause");
		}
		if (operation == 3)
		{
			Matrix M2;
			Matrix M3;
			cout << "Введите количество строк" << endl;
			cin >> hight;
			cout << "Введите количество столбцов" << endl;
			cin >> weight;
			cout << "Введите элементы матирцы" << endl;
			Massive = new int*[hight];
			for (int j = 0;j < hight;j++)
			{
				Massive[j] = new int[weight];
			};
			for (int h = 0;h < hight;h++)
			{
				for (int w = 0;w < weight;w++)
				{
					cin >> Massive[h][w];
				}
			}
			M2.SetMatrix(hight, weight, Massive);
			system("cls");
			M3 = M + M2;
			M3.ShowMatrix();
			system("pause");
		}
		if (operation == 4)
		{
			M.Diagonal();
			cout << M.Diagonal() << " " << endl;
			system("pause");
		}
		if (operation == 5)
			return 0;
	}
}