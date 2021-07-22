#include <iostream>
#include <Windows.h>
#include <string>
#include <math.h>
using namespace std;

// Практическая работа 9 Контрольное задание 1

class SideError
	{
	public:
		SideError() : message("Длина одной из сторон треугольника больше суммы двух других") { }
		void printMessage() const { cout << message << endl; }
	private:
		string message;
	};

class Triangle
{
public:
	Triangle(double a, double b, double c)
	{
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
		cout << "Площадь заданного треугольника составляет: " << s << endl << endl;
	}
};



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double aa, bb, cc;
	cout << "Введите три стороны треугольника" << endl << endl;
	cin >> aa;
	cin >> bb;
	cin >> cc;
	try
	{
		if ((aa + bb) < cc || (aa + cc) < bb || (bb + cc) < aa)
		{
			throw SideError();
			return 1;
		}
		
		Triangle tr1 = Triangle(aa, bb, cc);
		tr1.get_area();
		
	}
	catch (SideError& error)
		{
			cout << "ОШИБКА: ";
			error.printMessage();
		}
	

	return 0;
}