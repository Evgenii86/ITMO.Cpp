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
		cout << "\nФамилия: " << last_name << endl;
		cout << "Имя: " << name << endl;
		cout << "Отчество: " << second_name << endl;
	}
private:
	string name; 
	string last_name; 
	string second_name;
};

class student : public human {
public:
	// Конструктор класса Student
	student(string last_name, string name, string second_name, vector<int> scores) : human(last_name, name,	second_name) 
	{
		this->scores = scores;
	}
	
	float get_average_score()
	{
		// Общее количество оценок
		unsigned int count_scores = this->scores.size();
		// Сумма всех оценок студента
		unsigned int sum_scores = 0;
		// Средний балл
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
		
		cout << "Средний балл студента равен: " << get_average_score() << endl;
	}
private:
	vector<int> scores;
};

class teacher : public human {
	// Конструктор класса teacher
public:
	teacher(string last_name, string name, string second_name, unsigned int work_time) : human(last_name, name,	second_name) 
	{
		this->work_time = work_time;
	}
	// Получение количества учебных часов
	void get_info()
	{
		human::get_info();
		cout << "Количество учебных часов преподавателя: " << this->work_time << endl;
	}
private:
	// Учебные часы
	unsigned int work_time;
};

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Оценкистудента
	vector<int> scores;
	// Добавление оценок студента в вектор
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(4);
	scores.push_back(4);
	scores.push_back(5);

	human* h1 = new student("Петров", "Иван", "Алексеевич", scores);
	h1->get_info();
	delete h1;
	h1 = new teacher("Сергеев", "Дмитрий", "Сергеевич", 40);
	h1->get_info();
	delete h1;

	return 0;
}