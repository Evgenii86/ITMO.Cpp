#include <iostream>
#include <string>
#include <map>
#include <Windows.h>
using namespace std;

struct StudentGrade
{
	StudentGrade(string n, char c) { name = n; grade = c; }
	string name;
	char grade;
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	map<string, char> StudMap;
	map < string, char>::iterator iter;
	StudentGrade st1 = StudentGrade("Василий", 'Z');
	StudentGrade st2 = StudentGrade("Николай", 'Z');
	StudentGrade st3 = StudentGrade("Олег", 'Z');
	StudentGrade st4 = StudentGrade("Глеб", 'Z');
	StudentGrade st5 = StudentGrade("Иннокентий", 'Z');

	StudMap.insert(make_pair(st1.name, st1.grade));
	StudMap.insert(make_pair(st2.name, st2.grade));
	StudMap.insert(make_pair(st3.name, st3.grade));
	StudMap.insert(make_pair(st4.name, st4.grade));
	StudMap.insert(make_pair(st5.name, st5.grade));

	string search;
	char gr;
	for (int i = 0; i < 5;++i)
	{
		cout << "Введите имя студента для поиска" << endl;
		cin >> search;
		cout << "Введите оценку для этого студента" << endl;
		cin >> gr;
		if (StudMap.find(search) != StudMap.end())
			StudMap.at(search) = gr;
	}
	
	iter = StudMap.begin();
	while (iter != StudMap.end())
	{
		cout << iter->first << " оценка " << iter->second << " ";
		++iter;
	}


	return 0;
}