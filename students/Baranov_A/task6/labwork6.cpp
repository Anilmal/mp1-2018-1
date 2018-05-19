#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <ctype.h>
#include <windows.h>

using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

class Game
{
protected:
	vector<int> Slovo;
	int lenght;
public:
	Game()
	{
		lenght = 0;
	}
	int Givelenght()
	{
		return lenght;
	}
	vector <int> GiveNum()
	{
		return Slovo;
	}
	void SetGame(int lenght_)
	{
		lenght = lenght_;
		vector<int> tmp;
		for (int i = 0;i <= 9;i++)
		{
			tmp.push_back(i);
		}
		random_shuffle(tmp.begin(), tmp.end());
		for (int j = 0;j < (lenght + 1);j++)
		{
			Slovo.push_back(tmp[j]);
		}

	}
	void ShowRules()
	{
		cout << "Играют два игрока(человек и компьютер)."
			<< "Игрок выбирает длину загадываемого числа – n."
			<< "Компьютер «задумывает» n - значное число с неповторяющимися цифрами."
			<< "Игрок делает попытку отгадать число – вводит n - значное число с неповторяющимися цифрами."
			<< "Компьютер сообщает, сколько цифр угадано без совпадения с их позициями в загаданном числе(то есть количество коров) и сколько угадано вплоть до позиции в загаданном числе(то есть количество быков)."
			<< "Игрок делает попытки, пока не отгадает всю последовательность."
			<< "Пример:"
			<< "Пусть n = 4."
			<< "Пусть задумано тайное число «3219»."
			<< "Игрок ввел число «2310»."
			<< "Результат: две «коровы»(две цифры : «2» и «3» — угаданы на неверных позициях) и один «бык»(одна цифра «1» угадана вплоть до позиции).";
	}
};
class Player :public Game
{
private:
	vector <int> number;
	int count_of_cows;
	int count_of_bulls;
	int Records[11];
public:
	Player() : Game() {};
	Player(Game obj)
	{
		lenght = obj.Givelenght();
		Slovo = obj.GiveNum();
	}
	bool SetNumber(string num)
	{
		if (lenght == num.size())
		{
			for (int i = 0;i < num.size();i++)
			{

				if (isdigit(num[i]))
				{
					char tmp[2];
					tmp[0] = num[i];
					tmp[1] = '\0';
					number.push_back(atoi(tmp));
				}
				else
				{
					return false;
				}
			}
			return true;
		}
		else
			return false;
	}
	int CheckCows()
	{
		for (int i = 0;i < lenght;i++)
		{
			for (int j = 0;j < lenght;j++)
			{
				if (number[i] == Slovo[j])
				{
					if (i != j)
						count_of_cows++;
				}
			}
		}
		return count_of_cows;
	}
	int CheckBulls()
	{
		for (int i = 0;i < lenght;i++)
		{
			if (number[i] == Slovo[i])
				count_of_bulls++;
		}
		return count_of_bulls;
	}
	void SaveRecords(int steps)
	{
		
		for (int i = 11;i > 0;i--)
		{
			if (Records[i] < steps && Records[i-1]>steps)
			{
				Records[i] = steps;
			}
			if (Records[i] > steps)
			{
				break;
			}
			if (Records[1] < steps)
			{
				Records[i] = steps;
			}
		}
		
	};
	void ShowRecords()
	{
		for (int i = 1;i < 10;i++)
		{
			cout << Records[i] << endl;
		}
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Game Play;
	int lenght;
	string start;
	string rules;
	int play = 0;
	string num;
	cout << "Желаете начать игру?Yes or No" << endl;
	cin >> start;
	if (start == "NO" || start == "no" || start == "No")
	{
		return 0;
	}
	system("cls");
	cout << "Желаете узнать правила,введите: yes " << endl;
	cin >> rules;
	if (rules == "yes")
	{
		Play.ShowRules();
		system("pause");
		cin.get();
		system("cls");
	}
	cout << "Введите кол-во цифр в числе :";
	cin >> lenght;
	Play.SetGame(lenght);
	system("cls");
	while (play == 0)
	{
		Player Me(Play);
		int choice = 0;
		int steps = 0;
		COORD coordinats;
		coordinats.X = 20;
		coordinats.Y = 15;
	in:	cout << "Введите число с неповторяющимися цифрами: ";
		cin >> num;
		if (Me.SetNumber(num) == true)
		{
			steps++;
			cout << "Число коров-" << Me.CheckCows() << endl;
			cout << "Число быков-" << Me.CheckBulls() << endl;
			if (lenght == Me.CheckBulls())
			{
				cout << "Поздравляем!!!Вы победили" << endl;
				cout << "Кол-во ваших шагов-" << steps;
				Me.SaveRecords(steps);
				system("pause");
				play = 1;
			}
			else
			{
				SetConsoleCursorPosition(h, coordinats);
				cout << "Желате продолжить?" << endl;
				coordinats.X = 20;
				coordinats.Y = 16;
				SetConsoleCursorPosition(h, coordinats);
				cout << "1-Да" << endl;
				coordinats.X = 20;
				coordinats.Y = 17;
				SetConsoleCursorPosition(h, coordinats);
				cout << "2-Нет" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
					system("cls");
					steps++;
					goto in;
				case 2:
					system("cls");
					play = 1;
				}
			}
		}
		if (Me.SetNumber(num) == false)
		{
			cout << "Ошибка ввода!Повторите попытку" << endl;
			goto in;
		}
		system("pause");
	}
	return 0;
}
