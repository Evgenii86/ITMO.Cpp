#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
using namespace std;

class human {
public:
	
	human(string last_name, string name, string	second_name)
	{
		this->last_name = last_name;
		this->name = name;
		this->second_name = second_name;
	}
	
	virtual void get_info()
	{
		cout << "\n�������: " << last_name << endl;
		cout << "���: " << name << endl;
		cout << "��������: " << second_name << endl;
	}
private:
	string name; 
	string last_name; 
	string second_name;
};

class student : public human {
public:
	// ����������� ������ Student
	student(string last_name, string name, string second_name, vector<int> scores) : human(last_name, name,	second_name) 
	{
		this->scores = scores;
	}
	
	float get_average_score()
	{
		// ����� ���������� ������
		unsigned int count_scores = this->scores.size();
		// ����� ���� ������ ��������
		unsigned int sum_scores = 0;
		// ������� ����
		float average_score;
		for (unsigned int i = 0; i < count_scores; ++i) {
			sum_scores += this->scores[i];
		}
		average_score = (float)sum_scores / (float)count_scores;
		return average_score;
	}

	void get_info()
	{
		human::get_info();
		
		cout << "������� ���� �������� �����: " << get_average_score() << endl;
	}
private:
	vector<int> scores;
};

class teacher : public human {
	// ����������� ������ teacher
public:
	teacher(string last_name, string name, string second_name, unsigned int work_time) : human(last_name, name,	second_name) 
	{
		this->work_time = work_time;
	}
	// ��������� ���������� ������� �����
	void get_info()
	{
		human::get_info();
		cout << "���������� ������� ����� �������������: " << this->work_time << endl;
	}
private:
	// ������� ����
	unsigned int work_time;
};

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ��������������
	vector<int> scores;
	// ���������� ������ �������� � ������
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(4);
	scores.push_back(4);
	scores.push_back(5);

	human* h1 = new student("������", "����", "����������", scores);
	h1->get_info();
	delete h1;
	h1 = new teacher("�������", "�������", "���������", 40);
	h1->get_info();
	delete h1;

	return 0;
}