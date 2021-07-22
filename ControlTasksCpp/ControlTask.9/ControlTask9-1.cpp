#include <iostream>
#include <Windows.h>
#include <string>
#include <math.h>
using namespace std;

// ������������ ������ 9 ����������� ������� 1

class SideError
	{
	public:
		SideError() : message("����� ����� �� ������ ������������ ������ ����� ���� ������") { }
		void printMessage() const { cout << message << endl; }
	private:
		string message;
	};

class Triangle
{
public:
	Triangle(double a, double b, double c)
	{
		if ((a + b) < c || (a + c) < b || (b + c) < a)
		{
			throw SideError();
		}
		this->a = a;
		this->b = b;
		this->c = c;
		this->p = (a + b + c / 2);
	}
	double a, b, c, p;
	void get_area() const
	{
		double s;
		s = sqrt(this->p * (this->p - this->a) * (this->p - this->b) * (this->p - this->c));
		cout << "������� ��������� ������������ ����������: " << s << endl << endl;
	}
};



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double aa, bb, cc;
	cout << "������� ��� ������� ������������" << endl << endl;
	cin >> aa;
	cin >> bb;
	cin >> cc;
	try
	{
		Triangle tr1 = Triangle(aa, bb, cc);
		tr1.get_area();
	}
	catch (SideError& error)
		{
			cout << "�������� ����������: ";
			error.printMessage();
		}
	
	return 0;
}