#include <Windows.h>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // ������������ ������ 6 ������� 1

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int MAX = 300;
    char buffer[MAX];
    cout << "������� ����� �������������" << endl << endl;
    cin.get(buffer, MAX, '$');
    ofstream out("TestFile.txt");
    out << buffer << endl;
    out.close();

    // ������� 2

    const int N = 10;
    int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
    ofstream o("File2.txt");
    for (int i = 0;i < N; i++)
    {
        o << a[i] << '\t' ;
    }
    o << '\n';
    
    cout << "�������� ������ ������� � ����" << endl << endl;
    
    int min = 0; 
    int buf = 0;
    for (int i = 0; i < N; i++)
    {
        min = i; // ����� ������� ������, ��� ������ � ����������� ���������
        // � ����� ������ �������� ����� ������ � ����������� ���������
        for (int j = i + 1; j < N; j++)
            min = (a[j] < a[min]) ? j : min;
        // ������������ ����� ��������, ������� ��� ������� � �������
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

    cout << "��������������� ������ ������� � ����" << endl << endl;
    o.close();









	return 0;
}