#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <ctype.h>

using namespace std;

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
				if (number[i] == Slovo[j] && i != j)
				{
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
		Records[11] = steps;
		int left = 0;
		int right = 10;
		while (left < right)
		{
			while ((Records[right] >= steps) && (left < right))
				right--;
			if (left != right)
			{
				Records[left] = Records[right];
				left++;
			}
			while ((Records[left] <= steps) && (left < right))
				left++;
			if (left != right)
			{
				Records[right] = Records[left];
				right--;
			}

		}
	};
	void ShowRecords()
	{
		for (int i = 0;i < 10;i++)
		{
			cout << Records[i] << endl;
		}
	}
	void EndOfStep()
	{
		count_of_bulls = 0;
		count_of_cows = 0;
		number.clear();
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
		vector<int> Mycows;
		vector<int> Mybulls;
		vector<string> Mynumber;
		int choice = 0;
		int steps = 1;
	in:	cout << "Введите число с неповторяющимися цифрами: ";
		cin >> num;
		if (Me.SetNumber(num) == true)
		{
			int bulls = 0;
			int cows = 0;
			bulls = Me.CheckBulls();
			cows = Me.CheckCows();
			cout << "Число коров-" << cows << endl;
			cout << "Число быков-" << bulls << endl;
			Mycows.push_back(cows);
			Mybulls.push_back(bulls);
			Mynumber.push_back(num);
			Me.EndOfStep();
			if (steps > 1)
			{
				cout << "Ваши ходы: " << endl;
				for (int i = 0;i < steps;i++)
				{
					cout << i + 1 << "." << "K-" << Mycows[i] << ",Б-" << Mybulls[i] << "," << "Ваше число-" << Mynumber[i] << endl;
				}
			}
			if (bulls == lenght)
			{
				cout << "Поздравляем!!!Вы победили" << endl;
				cout << "Кол-во ваших шагов-" << steps << endl;
				Me.SaveRecords(steps);
				play = 1;
			}
			if (bulls<lenght)
			{
				cout << "Желате продолжить?" << endl;
				cout << "1-Да" << endl;
				cout << "2-Нет" << endl;
				cin >> choice;
				system("cls");
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
	}
	system("pause >> NULL");
	return 0;
}
