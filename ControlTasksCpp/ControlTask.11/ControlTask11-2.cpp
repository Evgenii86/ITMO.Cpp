#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // для алгоритма сортировки
#include <math.h>
#include <Windows.h>
using namespace std;

class Point
{
public:
	Point(double xx, double yy) : x(xx), y(yy) {}
	double x;
	double y;
	double distanceToCenter()
	{
		return sqrt(pow(0 - x, 2) + pow(0 - y, 2));
	}

	friend ostream& operator<< (ostream& out, const Point& p)
	{
		out << "Точка с координатами: " << p.x << " : " << p.y << endl << endl;
		return out;
	}

	bool operator< (Point& p)
	{
		if (this->distanceToCenter() < p.distanceToCenter())
			return true;
		else
			return false;
	}

};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<Point> v;
	v.push_back(Point(1, 2));
	v.push_back(Point(10, 12));
	v.push_back(Point(21, 7));
	v.push_back(Point(4, 8));
	sort(v.begin(), v.end()); // требуется перегрузка оператора < для класса Point

	for (auto& point : v)
		cout << point << '\n'; // требуется перегрузка оператора << для класса Point

	return 0;
}