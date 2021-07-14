#include <iostream>
#include<math.h>
#include <Windows.h>
#include <cmath>
using namespace std;

double sideOfTr(double, double, double, double);
double areaOfaTriangle(double, double, double, double);
double cRoot(double);
double cRoot2(double);
double getArea1(double);
double getArea2(double, double, double);
int sumOfNumbers(int);
int toBinary(int number);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Практическая работа 3. контрольное задание 1
	
	// координаты вершин пятиугольника
	double x1 = 0, y1 = 0, x2 = 2, y2 = 3, x3 = 6, y3 = 4, x4 = 9, y4 = 2, x5 = 8, y5 = 0;
	//стороны треугольников, составляющих пятиугольник
	double a, b, c, d, e, f, g;
	// находим длины сторон треугольников
	a = sideOfTr(x1, y1, x2, y2);
	b = sideOfTr(x1, y1, x5, y5);
	c = sideOfTr(x4, y4, x5, y5);
	d = sideOfTr(x3, y3, x4, y4);
	e = sideOfTr(x2, y2, x3, y3);
	f = sideOfTr(x2, y2, x5, y5);
	g = sideOfTr(x2, y2, x4, y4);

	//площади треугольников
	double s1 = areaOfaTriangle((a + b + f) / 2, a, b, f);
	cout << "Площадь первого треугольника составляет: " << s1 << endl << endl;
	double s2 = areaOfaTriangle((f + g + c) / 2, f, g, c);
	cout << "Площадь второго треугольника составляет: " << s2 << endl <<endl;
	double s3 = areaOfaTriangle((e + d + g) / 2, e, d, g);
	cout << "Площадь третьего треугольника составляет: " << s3 << endl << endl;
	//площадь пятиугольника
	double s5 = s1 + s2 + s3;
	cout << "Площадь пятиугольника составляет: " << s5 << endl << endl;


	//задание 2(извлечение кубического корня)
	double q;
	double res, res2;
	cout << "Введите число для извлечения кубического корня" << endl;
	cin >> q;
	res = cRoot(q);
	res2 = cRoot2(q);
	cout << "Кубический корень из введеннного числа с использованием стандартной функции составляет: " << res << endl << endl;
	cout << "Кубический корень из введеннного числа с использованием пользовательской функции составляет: " << res << endl << endl;

	// задание3 (Работа с различными треугольниками)

	int choice;
	double sss, eqSide, aaa,bbb,ccc;
	cout << "Если хотите рассчитать площадь равностороннего треугольника -- введите 1, если разностороннего --введите любое другое число";
	cin >> choice;
	if (choice == 1)
	{
		cout << "Введите длину стороны равностороннего треугольника";
		cin >> eqSide;
		sss = getArea1(eqSide);
		cout << "Площадь равностороннего треугольника составляет: " << sss << endl << endl;
	}
	else
	{
		cout << "Введите стороны разностороннего треугольника" << endl;
		cin >> aaa;
		cin >> bbb;
		cin >> ccc;
		sss = getArea2(aaa,bbb,ccc);
		cout << "Площадь разностороннего треугольника составляет: " << sss << endl << endl;
	}

	//задание 4 (Рекурсивная функция суммы ряда)

	int z;
	cout << "Введите число членов ряда" << endl << endl;
	cin >> z;
	cout << "Сумма ряда составляет: " << sumOfNumbers(z) << endl << endl;

	//задание 5 (Применение рекурсии для перевода целого числа в двоичный код)

	int number10, binaryRes;
	cout << "Введите число для преобразования его в двоичное" << endl << endl;
	cin >> number10;
	binaryRes = toBinary(number10);
	cout << "Заданное число в двоичном исчислении: " << binaryRes << endl << endl;




	return 0;
}


double sideOfTr(double xb, double yb, double xc, double yc)
{
	double l;
	l = sqrt((pow(xb - xc, 2)) + (pow(yb - yc, 2)));
	return l;
}

double areaOfaTriangle(double pp, double aa, double bb, double cc)
{
	double s = sqrt(pp * (pp - aa) * (pp - bb) * (pp - cc));
	return s;
}

double cRoot(double g)
{
	return pow(g, 1.0 / 3.0);
}

double cRoot2(double g)
{
	if (g == 0) return (double)0;
	double x1 = 0;
	double x = 1;
	while (1)
	{

		x1 = (2 * x + g / (x * x)) / 3;

		if (fabs(x1 - x) < 0.0001)
		{
			break;
		}
		x = x1;
	}
	return x1;
}

double getArea1(double side)
{
	double s = sqrt((side * 3 / 2) * (side * 3 / 2 - side) * (side * 3 / 2 - side) * (side * 3 / 2 - side));
	return s;
}
double getArea2(double aaa, double bbb, double ccc)
{
	double s = sqrt((aaa + bbb + ccc / 2) * ((aaa + bbb + ccc / 2) - aaa) * ((aaa + bbb + ccc / 2) - bbb) * ((aaa + bbb + ccc / 2) - ccc));
	return s;
}

int sumOfNumbers(int n)
{
	if (n == 1)
		return 5;
	return 5*n + sumOfNumbers(n - 1);
}

int toBinary(int number)
{
	if (number == 0)
		return 0;
	else
		return (number % 2 + 10 *
			toBinary(number / 2));
}