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
	//Деструктор
	~Matrix()
	{
		delete[] Massive;
	}
	//Иницыализация элементов матрицы
	void SetMatrix()
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
				Massive[h][w] = 0;
			}
		}
		for (int h = 0;h < hight;h++)
		{
			for (int w = 0;w < weight;w++)
			{
				cin >> Massive[h][w];
			}
		}

	}
	//Оператор присваивания
	const Matrix & operator = (const Matrix &obj)
	{
		if (&obj != this)
		{
			for (int i = 0;i < hight;i++)
			{
				for (int j = 0;j < weight;j++)
				{
					Massive[i][j] = obj.Massive[i][j];
				}
			}
		}
		return *this;
	}
	//Оператор сложения матриц 
	Matrix & operator + (const Matrix &M)
	{
		if (hight == M.hight && weight == M.weight)
			for (int h = 0;h < hight;h++)
			{
				for (int w = 0;w < weight;w++)
				{
					Massive[h][w] = Massive[h][w] + M.Massive[h][w];
				}
			}
		if (hight != M.hight || weight != M.weight)
		{
			cout << "Операция невозможна!";
			exit(1);
		}
		return *this;
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
	void ShowNum()
	{
		int hig;
		int wei;
		cout << "Введите номер столбца: ";
		cin >> wei;
		cout << "Введите номер строки: ";
		cin >> hig;
		cout << Massive[hig - 1][wei - 1] << endl;;
	}
	//Установка элемента матрицы по индексу
	void SetNum()
	{
		int h;
		int w;
		cout << "Введите номер столбца: ";
		cin >> w;
		cout << "Введите номер строки: ";
		cin >> h;
		cout << "Введите значение элемента: ";
		cin >> Massive[h - 1][w - 1];
	}
	//Проверка на диагональное преобладание
	void Diagonal()
	{
		int sum = 0;
		bool diag = true;
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
					diag = false;
			}
			if (diag == false)
				cout << "В матрице нет диагонального приобладания" << endl;
			if (diag == true)
				cout << "В матрице нет диагонального приобладания" << endl;
		}
	}
};
int main()
{
	int choice, operation;
	Matrix M;
	system("chcp 1251>nul");
in:	cout << "Желаете задать матрицу?" << endl;
	cout << "1-Да,2-Нет" << endl;
	cin >> choice;
	system("cls");
	if (choice != 1)
		goto in;
	if (choice == 1)
	{
		M.SetMatrix();
		system("cls");
		M.ShowMatrix();
		system("pause");
		system("cls");
		cout << "Какие операции хотите сделать" << endl;
		cout << "1-задать элемент по индексу,2-узнать элемент по индексу,3-сложить со второй матрицей,4-проверить на диагональное приобладание,5-выход" << endl;
		cin >> operation;
		if (operation == 1)
		{
			M.SetNum();
			M.ShowMatrix();
			system("pause");
		}
		if (operation == 2)
		{
			M.ShowNum();
			system("pause");
		}
		if (operation == 3)
		{
			Matrix M2;
			M2.SetMatrix();
			system("cls");
			M = M + M2;
			M.ShowMatrix();
			system("pause");
		}
		if (operation == 4)
		{
			M.Diagonal();
			system("pause");
		}
		if (operation == 5)
			return 0;
	}
}