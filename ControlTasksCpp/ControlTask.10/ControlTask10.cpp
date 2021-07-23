#include <iostream>
#include <string>
#include <Windows.h>
#include "Triangle.h"
#include "TriangleAgreg.h"
using namespace std;

int main()
{
	//����������� ������� 10 ����������

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*Triangle* tr1 = new Triangle(Dot(3.5, 5.7), Dot(2.4, 8.8), Dot(0.0, 6.3));
	double lenghtA, lenghtB, lenghtC;
	tr1->GetSides(lenghtA, lenghtB, lenghtC);
	double per = tr1->GetPerimeter(lenghtA, lenghtB, lenghtC);
	double pper = per / 2;
	double area = tr1->GetArea(lenghtA, lenghtB, lenghtC, pper);

	cout << "����� ������ ������������: " << lenghtA << " " << lenghtB << " " << lenghtC << endl;
	cout << "�������� ������������ �����: " << per << endl;
	cout << "������� ������������ ����������: " << area << endl;

	delete tr1;*/

	// ���������

	Dot* dot1 = new Dot();
	Dot* dot2 = new Dot(3.95, 5.11);
	Dot* dot3 = new Dot(5.17, 9.2);
	{
		Triangle tr2 = Triangle(dot1, dot2, dot3);
		double lenA, lenB, lenC;
		tr2.GetSides(lenA, lenB, lenC);
		double perimeter = tr2.GetPerimeter(lenA, lenB, lenC);
		double semi_perimeter = perimeter / 2;
		cout << "�������� ������� ������������ �����: " << tr2.GetPerimeter(lenA, lenB, lenC) << endl;
		cout << "������� ������� ������������ ����������: " << tr2.GetArea(lenA, lenB, lenC, semi_perimeter) << endl;
	}

	cout << "\n���������� ����� ������� 1 � 2: " << dot1->distanceTo(*dot2) << endl;    // �������-����� ���������� ������������ � ����� ��������� ���������� ����� ������������
	cout << "���������� ����� ������� 2 � 3: " << dot2->distanceTo(*dot3);

	return 0;
}