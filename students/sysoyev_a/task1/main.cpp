#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

void Vlogenie(int &hor, int &min, int &sec)//���� ������
{
	cout << "������� �� : ��: �� " << endl;
	cin >> hor;cout << ":";cin >> min;cout << ":";cin >> sec;
}


class Time
{
private:
	int hor, min, sec;
	void time()//����������� ����������
	{
		if (sec > 59)
		{
			while (sec >= 60)
				min++;
			sec -= 60;
		}
		if (min >= 59)
		{
			while (min >= 60)
				hor++;
			min -= 60;
		}
		if (hor >= 23)
		{
			while (hor >= 23)
				hor = hor - 23;
		}
	}
public:
	//�����������
	void ConstructTime(int _hor, int _min, int _sec)
	{
		int hor(_hor);
		int min(_min);
		int sec(_sec);
	}
	//����� �� �����
	void ShowTime()
	{
		cout << hor << " : " << min << " : " << sec << endl;
	}
	//�������� ������������
	Time operator = (const Time obj)
	{
		hor = obj.hor;
		min = obj.min;
		sec = obj.sec;
		return *this;
	}
	//����� ������� � ������� �������
	Time operator - (Time t2)
	{
		int sec_ = sec - t2.sec;
		int min_ = min - t2.min;
		int hor_ = hor - t2.hor;
		if (sec_ < 0)
			sec_ = 60 + sec_;
		min_--;
		if (min_ < 0)
			min_ = 60 + min_;
		hor_--;
		return *this;
	}
	//����� ������� � ������� �������
	Time operator + (Time t2)
	{
		int sec_ = sec + t2.sec;
		int min_ = min + t2.min;
		int hor_ = hor + t2.hor;
		if (sec_ > 59)
			sec_ = sec_ - 60;
		min_++;
		if (min_ > 59)
			min_ = min_ - 60;
		hor_++;
		if (hor_ > 23)
			hor_ = hor_ - 23;
		return *this;
	}
	//������� ����� ��������� ���������
	/*Time Raznica(Time t1,Time t2,Time t3)
	{
	int choice;

	if (t1.hor > t2.hor)
	t3 = t1 - t2;
	if (t1.hor < t2.hor)
	t3 = t2 - t1;
	cout << "������� � ���:" << endl;
	cout << "1-� �����" << endl;
	cout << "2-� �������" << endl;
	cout << "3-� ��������" << endl;
	cout << "4-������ �������" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
	t3.hor = t3.hor;
	t3.min = 0;
	t3.sec = 0;
	cout << "����� � ����� :" << t3.hor << endl;
	case 2:
	t3.min = t3.min + 60 * t3.hor;
	t3.hor = 0;
	t3.sec = 0;
	cout << "����� � ������� :" << t3.min << endl;
	case 3:
	t3.min = t3.min + 60 * t3.hor;
	t3.sec = t3.sec + 60 * t3.min;
	t3.hor = 0;
	t3.min = 0;
	cout << "����� � �������� :" << t3.sec << endl;
	case 4:
	t3.ShowTime();
	}
	return *this;
	}*/
};

int main()
{
  cout << "Hello!" << endl;
  int choice, change;
  int hor = 0;
  int min = 0;
  int sec = 0;
  Time T;
  Time time2;
  Time time3;
  time3.ConstructTime(hor, min, sec);
  cout << "������� ������ �����?" << endl;
in:		cout << "1-��,2-���" << endl;
  cin >> choice;
  if (choice == 1)
  {
	  Vlogenie(hor, min, sec);
	  T.ConstructTime(hor, min, sec);
	  T.ShowTime();
	  system("pause");
	  system("cls");
  }
  if (choice != 0)
	  goto in;
  choice = 0;
  cout << "����� �������� ������ �������" << endl;
  cout << "1-�������� �����,2-��������� �������,3-�����" << endl;
  cin >> choice;
  if (choice == 1)
  {
	  cout << "� ������� �������-1,� ������� �������-2" << endl;
	  cin >> change;
	  if (change == 1)
		  Vlogenie(hor, min, sec);
	  time2.ConstructTime(hor, min, sec);
	  T = T + time2;
	  if (change == 2)
		  Vlogenie(hor, min, sec);
	  time2.ConstructTime(hor, min, sec);
	  T = T - time2;
  }
  if (choice == 2)
	  Vlogenie(hor, min, sec);
  time2.ConstructTime(hor, min, sec);
  time3 = T - time2;
  time3.ShowTime();
  if (choice == 3)
	  return 0;
}
