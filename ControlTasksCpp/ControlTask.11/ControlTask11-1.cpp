#include <iostream>
#include <Windows.h>
using namespace std;

class Time
{
public:
	Time() : hours(0), minutes(0), seconds(0) {}
	Time(int h, int m, int s)
	{
		Time::hours = h;
		Time::minutes = m;
		Time::seconds = s;
		if (s / 60 >= 1)
		{
			int temp = (s / 60);
			Time::seconds = s % 60;
			Time::minutes += temp;
		}
		if (Time::minutes / 60 >= 1)
		{
			int temp = (Time::minutes / 60);
			Time::minutes = Time::minutes % 60;
			Time::hours += temp;
		}
	}

	void TimeDisplay() const
	{
		cout << "Текущее время -- " << this->hours << ":" << this->minutes << ":" << this->seconds << endl << endl;
	}

	Time& AddTime2(const Time* t) const
	{
		Time tRes;
		tRes.hours = this->hours + t->hours;
		tRes.minutes = this->minutes + t->minutes;
		tRes.seconds = this->seconds + t->seconds;
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
		return Time::hours;
	}
	int get_minutes()
	{
		return Time::minutes;
	}
	int get_seconds()
	{
		return Time::seconds;
	}
	friend Time operator+ (const Time& t, float value)
	{
		int temp = static_cast<int>(value);
		int hou = t.hours + temp;
		int min = t.minutes + (value - temp) * 60;
		int sec = t.seconds;
		return Time(hou, min, sec);

	}
	friend Time operator+ (float value, const Time& t)
	{
		int temp = static_cast<int>(value);
		int hou = t.hours + temp;
		int min = t.minutes + (value - temp) * 60;
		int sec = t.seconds;
		return Time(hou, min, sec);

	}

	Time operator+ (const Time& t) const
	{
		int h = hours + t.hours;
		int m = minutes + t.minutes;
		int s = seconds + t.seconds;
		if (s >= 60)
		{
			s -= 60;
			++m;
		}
		if (m >= 60)
		{
			m -= 60;
			++h;
		}
		return Time(h, m, s);
	}
	Time operator- (const Time& t) const
	{
		int h, m, s;
		h = m = s = 0;
		if (hours > t.hours)
		{
			h = hours - t.hours;
			m = minutes - t.minutes;
			s = seconds - t.seconds;
			if (s < 0)
			{
				s = 60 + s;
				--m;
			}
			if (m < 0)
			{
				m = 60 + m;
				--h;
			}

		}
		else if (hours < t.hours)
		{
			h = t.hours - hours;
			m = t.minutes - minutes;
			s = t.seconds - seconds;
			if (s < 0)
			{
				s = 60 + s;
				--m;
			}
			if (m < 0)
			{
				m = 60 + m;
				--h;
			}
		}
		else if (hours == t.hours)
		{
			if (minutes > t.minutes)
			{
				m = minutes - t.minutes;
				s = seconds - t.seconds;
				if (s < 0)
				{
					s = 60 + s;
					--m;
				}
			}
			if (minutes < t.minutes)
			{
				m = t.minutes - minutes;
				s = t.seconds - seconds;
				if (s < 0)
				{
					s = 60 + s;
					--m;
				}
			}
			if (minutes == t.minutes)
			{
				if (seconds > t.seconds)
					s = seconds - t.seconds;
				else if (seconds <= t.seconds)
					s = t.seconds - seconds;
			}
		}
		return Time(h, m, s);
	}

	bool operator== (Time& t)
	{
		return (hours == t.hours && minutes == t.minutes && seconds == t.seconds);
	}
	bool operator != (Time& t)
	{
		return (hours != t.hours && minutes != t.minutes && seconds != t.seconds);
	}
	bool operator> (Time& t)
	{
		if (hours > t.hours)
			return true;
		else if (hours < t.hours)
			return false;
		else if (hours == t.hours && minutes == t.minutes)
			return seconds > t.seconds;
		else if (hours == t.hours && minutes != t.minutes)
			return minutes > t.minutes;
	}
	bool operator< (Time& t)
	{
		if (hours < t.hours)
			return true;
		else if (hours > t.hours)
			return false;
		else if (hours == t.hours && minutes == t.minutes)
			return seconds < t.seconds;
		else if (hours == t.hours && minutes != t.minutes)
			return minutes < t.minutes;
	}
	bool operator>= (Time& t)
	{
		if (*this > t || *this == t)
			return true;
		else
			return false;
	}
	bool operator<= (Time& t)
	{
		if (*this < t || *this == t)
			return true;
		else
			return false;
	}

	friend ostream& operator<< (ostream& out, const Time& t)
	{
		out << t.hours << ":" << t.minutes << ":" << t.seconds << endl;
		return out;
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

	Time time1 = Time(8, 35, 17);
	Time time2 = Time(3, 48, 56);
	Time time3 = time1 + time2;
	Time time4 = time2 - time1;
	Time time5 =  time2 + 1.9;
	Time time6 = 2.7 + time3;
	cout << (time3 > time2) << endl;
	cout << (time2 > time3) << endl;
	cout << (time1 <= time4) << endl;
	cout << (time3 != time4) << endl;
	cout << time5 << endl;
	cout << time6 << endl;

	return 0;
}