#include <iostream>
#include <Windows.h>
#include "Time.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Time time1 = Time(11,364,125);
	time1.TimeDisplay();
	Time time2 = Time(4, 78, 93);
	time2.TimeDisplay();
	Time time3;
	time3 = time1.AddTime2(time2);
	time3.TimeDisplay();

	return 0;
}