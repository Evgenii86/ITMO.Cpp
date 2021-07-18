#include <Windows.h>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Практическая работа 6 Задание 1

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int MAX = 300;
    char buffer[MAX];
    cout << "Введите текст стихотворения" << endl << endl;
    cin.get(buffer, MAX, '$');
    ofstream out("TestFile.txt");
    out << buffer << endl;
    out.close();

    // Задание 2

    const int N = 10;
    int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
    ofstream o("File2.txt");
    for (int i = 0;i < N; i++)
    {
        o << a[i] << '\t' ;
    }
    o << '\n';
    
    cout << "Исходный массив записан в файл" << endl << endl;
    
    int min = 0; 
    int buf = 0;
    for (int i = 0; i < N; i++)
    {
        min = i; // номер текущей ячейки, как ячейки с минимальным значением
        // в цикле найдем реальный номер ячейки с минимальным значением
        for (int j = i + 1; j < N; j++)
            min = (a[j] < a[min]) ? j : min;
        // перестановка этого элемента, поменяв его местами с текущим
        if (i != min)
        {
            buf = a[i];
            a[i] = a[min];
            a[min] = buf;
        }
    }

    if (o.is_open())
    {
        for (int i = 0;i < N; i++)
        {
            o << a[i] << '\t';
        }
    }

    cout << "Отсортированный массив записан в файл" << endl << endl;
    o.close();









	return 0;
}