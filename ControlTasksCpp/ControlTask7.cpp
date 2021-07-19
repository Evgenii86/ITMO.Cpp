#include <Windows.h>
#include <iostream>
using namespace std;

struct Time
{
	int hours;
	int minutes;
	int seconds;

	Time AddTime(const Time& t1, const Time& t2)
	{
		Time tRes;
		tRes.hours = t1.hours + t2.hours;
		tRes.minutes = t1.minutes + t2.minutes;
		tRes.seconds = t1.seconds + t2.seconds;
		if (tRes.seconds > 59)
		{
			tRes.seconds -= 60;
			tRes.minutes++;
		}
		if (tRes.minutes > 59)
		{
			tRes.minutes -= 60;
			tRes.hours++;
		}
		return tRes;
	}
	Time SubtractTime(Time t1, Time t2)
	{
		Time tRes;
		if (t2.seconds > t1.seconds)
		{
			--t1.minutes;
			t1.seconds += 60;
		}

		tRes.seconds = t1.seconds - t2.seconds;
		if (t2.minutes > t1.minutes)
		{
			--t1.hours;
			t1.minutes += 60;
		}
		tRes.minutes = t1.minutes - t2.minutes;
		tRes.hours = t1.hours - t2.hours;

		return tRes;
	}

};

struct RootsOfQE
{
	double x1;
	double x2;
};

RootsOfQE QuadraticEquation(double a, double b, double c)
{
	RootsOfQE solution;
	solution.x1 = 0;
	solution.x2 = 0;

	
	if (a == 0) {
		cout << "��������� �� �������� ����������" << endl << endl;
		return solution;
	}

	double d = b * b - 4 * a * c;
	double sqrtVal = sqrt(abs(d));

	if (d > 0) {

		solution.x1 = (double)(-b + sqrtVal) / (2 * a);
		solution.x2 = (double)(-b - sqrtVal) / (2 * a);
		return solution;
	}
	else if (d == 0) {

		solution.x1 = solution.x2 = -(double)b / (2 * a);
		return solution;
	}
	else
	{

		return solution;
	}

}

void ShowSeconds(Time time)
{
	int seconds;
	seconds = time.hours * 3600 + time.minutes * 60 + time.seconds;
	cout << "���������� ������ � �������� ������� ����������: " << seconds << endl << endl;

}

Time InputTime()
{
	Time t;
	
	while (1)
	{
		cout << "������� ���������� ����� �� 0 �� 23" << endl << endl;
		cin >> t.hours;
		if (t.hours < 0 || t.hours > 23)
		{
			cin.clear();
			cout << "������� ���������� ����� � ��������� �������" << endl << endl;
		}
		else
			break;
	}
	
	while (1)
	{
		cout << "������� ���������� ����� �� 0 �� 59" << endl << endl;
		cin >> t.minutes;
		if (t.minutes < 0 || t.minutes > 59)
		{
			cin.clear();
			cout << "������� ���������� ����� � ��������� �������" << endl << endl;
		}
		else
			break;
	}
	
	while (1)
	{
		cout << "������� ���������� ������ �� 0 �� 59" << endl << endl;
		cin >> t.seconds;
		if (t.seconds < 0 || t.seconds > 59)
		{
			cin.clear();
			cout << "������� ���������� ������ � ��������� �������" << endl << endl;
		}
		else
			break;
	}
	return t;
}

int main()
{
	SetConsoleOutputCP(1251);

	// ������������ ������ 7 �������1

	Time time1 = { 8,45,27 };
	ShowSeconds(time1);
	Time time2 = InputTime();
	Time time3,time4;
	time4 = time3.AddTime(time1, time2);
	cout << "����������� �������� ���� ��������� ����������� ����� ��������� �������� ��������� �����: " << time4.hours << " ����� " << time4.minutes << " ����� " << time4.seconds << " ������" << endl << endl;
	time4 = time3.SubtractTime(time1, time2);
	cout << "����������� ��������� ���� ��������� ����������� ����� ��������� �������� ��������� �����: " << time4.hours << " ����� " << time4.minutes << " ����� " << time4.seconds << " ������" << endl << endl;

	// ������� 2

	double a, b, c;
	cout << "������� ��� ����� -- ������������ ����������� ��������� � ��������� ����" << endl << endl;
	cin >> a >> b >> c;
	RootsOfQE r1 = QuadraticEquation(a, b, c);
	if(r1.x1 ==0 && r1.x2 == 0)
		cout << "��������� �� ����� ������ -- �������������� ����� ��� ������� ����������� ����� ����" << endl << endl;
	else if(r1.x1 == r1.x2 && r1.x1 != 0)
		cout << "��������� ����� ��� �����, ������� ����� ���� �����: x1 = x2= " << r1.x1 << endl << endl;
	else if(r1.x1 != r1.x2)
		cout << "��������� ����� ��� �����: x1 = " << r1.x1 << "\tx2 = " << r1.x2 << endl << endl;


	return 0;
}