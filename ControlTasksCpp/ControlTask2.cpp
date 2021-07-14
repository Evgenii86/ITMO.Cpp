#include <iostream>
#include <math.h>
#include <ctime>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//������������ ������ 2. ����������� �������.
	//������� 1

	int year;
	cout << "������� ���";
	cin >> year;

	if ((year % 4 == 0 && year % 100 != 0) || year == 2000)
		cout << "��� ����������" << endl;
	else
		cout << "��� ������������" << endl;

	//������� 2
	int a, b, c;
	a = 5, b = 8, c = 11;
	if (a > b && a > c)
		cout << "a = "<< a << " -���������� �� ���� �����" <<endl;
	if (b > a && b > c)
		cout << "b = " << b << " -���������� �� ���� �����" << endl;
	if (c > a && c > b)
		cout << "c = " << c << " -���������� �� ���� �����" << endl;

	//������� 3 (������ ��������)

	int coin1 = 1, coin2 = 2, coin5 = 5, coin10 = 10;
	int sum;
	int counterOfCoin = 0;
	cout << "������� ����� ��� ������";
	cin >> sum;
	while (sum > 0)
	{
		if (sum >= coin10)
		{
			counterOfCoin = 0;
			while (sum >= coin10)
			{
				counterOfCoin++;
				sum -= coin10;
			}
			cout << "���������� ����� " << coin10 << " ���������� " << counterOfCoin << " ����" << endl;
		}
		if (sum >= coin5)
		{
			counterOfCoin = 0;
			while (sum >= coin5)
			{
				counterOfCoin++;
				sum -= coin5;
			}
			cout << "���������� ����� " << coin5 << " ���������� " << counterOfCoin << " ����" << endl;
		}
		if (sum >= coin2)
		{
			counterOfCoin = 0;
			while (sum >= coin2)
			{
				counterOfCoin++;
				sum -= coin2;
			}
			cout << "���������� ����� " << coin2 << " ���������� " << counterOfCoin << " ����" << endl;
		}
		if (sum >= coin1)
		{
			counterOfCoin = 0;
			while (sum >= coin1)
			{
				counterOfCoin++;
				sum -= coin1;
			}
			cout << "���������� ����� " << coin1 << " ���������� " << counterOfCoin << " ����" << endl;
		}
	}


	//������� 4 (�������� �� ������)

	int numberOfShots = 0; int points = 0;
	double x, y;

	while (points < 50)
	{
		cout << "������� ���������� ����� �������� x � y" << endl;
		cin >> x >> y;
		if (x * x + y * y >4)
		{
			numberOfShots += 1;
			cout << "�� ������������" << endl;
		}
		else if (x * x + y * y < 4 && x * x + y * y > 1)
		{
			numberOfShots += 1;
			points += 5;
			cout << "���� ��������� �� ������� 5 �����" << endl;
		}
		else if (x * x + y * y < 1)
		{
			numberOfShots += 1;
			points += 10;
			cout << "���� ��������� �� ������ � ����� ������ � ������� 10 �����" << endl;
		}
	}

	if (numberOfShots < 7)
		cout << "��� ������� - ������� " << " ���������� ��������� - " << numberOfShots << endl;
	else if (numberOfShots <= 10)
		cout << "��� ������� - ������� " << " ���������� ��������� - " << numberOfShots << endl;
	else
		cout << "��� ������� - ������� " << " ���������� ��������� - " << numberOfShots << endl;



	return 0;

	
}