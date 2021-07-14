#include <iostream>
#include <math.h>
#include <ctime>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Практическая работа 2. Контрольные задания.
	//задание 1

	int year;
	cout << "Введите год";
	cin >> year;

	if ((year % 4 == 0 && year % 100 != 0) || year == 2000)
		cout << "Год високосный" << endl;
	else
		cout << "Год невисокосный" << endl;

	//задание 2
	int a, b, c;
	a = 5, b = 8, c = 11;
	if (a > b && a > c)
		cout << "a = "<< a << " -наибольшее из трех чисел" <<endl;
	if (b > a && b > c)
		cout << "b = " << b << " -наибольшее из трех чисел" << endl;
	if (c > a && c > b)
		cout << "c = " << c << " -наибольшее из трех чисел" << endl;

	//задание 3 (жадный алгоритм)

	int coin1 = 1, coin2 = 2, coin5 = 5, coin10 = 10;
	int sum;
	int counterOfCoin = 0;
	cout << "Введите сумму для выдачи";
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
			cout << "Количество монет " << coin10 << " составляет " << counterOfCoin << " штук" << endl;
		}
		if (sum >= coin5)
		{
			counterOfCoin = 0;
			while (sum >= coin5)
			{
				counterOfCoin++;
				sum -= coin5;
			}
			cout << "Количество монет " << coin5 << " составляет " << counterOfCoin << " штук" << endl;
		}
		if (sum >= coin2)
		{
			counterOfCoin = 0;
			while (sum >= coin2)
			{
				counterOfCoin++;
				sum -= coin2;
			}
			cout << "Количество монет " << coin2 << " составляет " << counterOfCoin << " штук" << endl;
		}
		if (sum >= coin1)
		{
			counterOfCoin = 0;
			while (sum >= coin1)
			{
				counterOfCoin++;
				sum -= coin1;
			}
			cout << "Количество монет " << coin1 << " составляет " << counterOfCoin << " штук" << endl;
		}
	}


	//задание 4 (стрельба по мишени)

	int numberOfShots = 0; int points = 0;
	double x, y;

	while (points < 50)
	{
		cout << "Введите координаты точки выстрела x и y" << endl;
		cin >> x >> y;
		if (x * x + y * y >4)
		{
			numberOfShots += 1;
			cout << "Вы промахнулись" << endl;
		}
		else if (x * x + y * y < 4 && x * x + y * y > 1)
		{
			numberOfShots += 1;
			points += 5;
			cout << "Этим выстрелом вы набрали 5 очков" << endl;
		}
		else if (x * x + y * y < 1)
		{
			numberOfShots += 1;
			points += 10;
			cout << "Этим выстрелом вы попали в центр мишени и набрали 10 очков" << endl;
		}
	}

	if (numberOfShots < 7)
		cout << "Ваш уровень - снайпер " << " Количество выстрелов - " << numberOfShots << endl;
	else if (numberOfShots <= 10)
		cout << "Ваш уровень - стрелок " << " Количество выстрелов - " << numberOfShots << endl;
	else
		cout << "Ваш уровень - новичек " << " Количество выстрелов - " << numberOfShots << endl;



	return 0;

	
}