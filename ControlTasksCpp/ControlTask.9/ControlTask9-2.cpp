#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

// ������������ ������ 9 ����������� ������� 2

class Time
{
public:
	class TimeError
	{
	public:
		TimeError(int e) 
		{
			message = "���������� ������ ������ ���� ������ 60";
			ErrValue = e;
		}
		string message;
		int ErrValue;
	};
	class TimeError2
	{
	public:
		TimeError2(int j)
		{
			message2 = "���������� ����� ������ ���� ������ 60";
			ErrValue2 = j;
		}
		string message2;
		int ErrValue2;
	};
	// ������������ Time
	Time() : hours(0), minutes(0), seconds(0) {}
	Time(int h, int m, int s)
	{
		hours = h;
		minutes = m;
		seconds = s;
		if (seconds > 60)
		{
			throw TimeError(seconds);
		}
		if (minutes > 60)
		{
			throw TimeError2(minutes);
		}
	}

	void TimeDisplay() const
	{
		cout << "������� ����� -- " << this->hours << ":" << this->minutes << ":" << this->seconds << endl << endl;
	}

	Time AddTime2(const Time& t) const
	{
		Time tRes;
		tRes.hours = this->hours + t.hours;
		tRes.minutes = this->minutes + t.minutes;
		tRes.seconds = this->seconds + t.seconds;
		if (tRes.seconds >= 60)
		{
			tRes.seconds -= 60;
			++tRes.minutes;
		}
		if (tRes.minutes >= 60)
		{
			tRes.minutes -= 60;
			++tRes.hours;
		}
		return tRes;
	}

	int get_hours()
	{
		return hours;
	}
	int get_minutes()
	{
		return minutes;
	}
	int get_seconds()
	{
		return seconds;
	}
private:
	int hours;
	int minutes;
	int seconds;
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try
	{
		Time time1 = Time(11, 363, 12);
		time1.TimeDisplay();
	}

	catch(Time::TimeError &err)
	{
		cout << "\n������ � ���������� ������ " << err.message;
		cout << "\n��������� �������� ������ " << err.ErrValue <<	" ��������\n";
	}
	catch (Time::TimeError2 & error)
	{
		cout << "\n������ � ���������� ����� " << error.message2;
		cout << "\n��������� �������� ����� " << error.ErrValue2 << " ��������\n";
	}
	

	return 0;
}