#include <iostream>
#include <string>
#include <Windows.h>
#include "Triangle.h"
#include "TriangleAgreg.h"
using namespace std;

int main()
{
	//Контрольное задание 10 Композиция

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*Triangle* tr1 = new Triangle(Dot(3.5, 5.7), Dot(2.4, 8.8), Dot(0.0, 6.3));
	double lenghtA, lenghtB, lenghtC;
	tr1->GetSides(lenghtA, lenghtB, lenghtC);
	double per = tr1->GetPerimeter(lenghtA, lenghtB, lenghtC);
	double pper = per / 2;
	double area = tr1->GetArea(lenghtA, lenghtB, lenghtC, pper);

	cout << "Длины сторон треугольника: " << lenghtA << " " << lenghtB << " " << lenghtC << endl;
	cout << "Периметр треугольника равен: " << per << endl;
	cout << "Площадь треугольника составляет: " << area << endl;

	delete tr1;*/

	// Агрегация

	Dot* dot1 = new Dot();
	Dot* dot2 = new Dot(3.95, 5.11);
	Dot* dot3 = new Dot(5.17, 9.2);
	{
		Triangle tr2 = Triangle(dot1, dot2, dot3);
		double lenA, lenB, lenC;
		tr2.GetSides(lenA, lenB, lenC);
		double perimeter = tr2.GetPerimeter(lenA, lenB, lenC);
		double semi_perimeter = perimeter / 2;
		cout << "Периметр второго треугольника равен: " << tr2.GetPerimeter(lenA, lenB, lenC) << endl;
		cout << "Площадь второго треугольника составляет: " << tr2.GetArea(lenA, lenB, lenC, semi_perimeter) << endl;
	}

	cout << "\nРасстояние между точками 1 и 2: " << dot1->distanceTo(*dot2) << endl;    // Объекты-точки продолжают существовать и после окончания жизненного цикла треугольника
	cout << "Расстояние между точками 2 и 3: " << dot2->distanceTo(*dot3);

	return 0;
}