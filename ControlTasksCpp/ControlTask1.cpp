#include <iostream>
#include<math.h>
#include <Windows.h>

using namespace std;

//������ ������� ������������� �� ������� ������

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout.precision(3);
    double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;
    cout << "������� ���������� ������ ������� \n";
    cin >> x1 >> y1;
    cout << "������� ���������� ������ ������� \n";
    cin >> x2 >> y2;
    cout << "������� ���������� ������� ������� \n";
    cin >> x3 >> y3;
    cout << "������� ���������� ��������� ������� \n";
    cin >> x4 >> y4;
    cout << "������� ���������� ����� ������� \n";
    cin >> x5 >> y5;

    double s;
    s = 0.5 * abs(x1*y2+x2*y3+x3*y4+x4*y5+x5*y1-x2*y1-x3*y2-x4*y3-x5*y4-x1*y5);

    cout << "������� ��������� ������������� ����������\n" << s;


    
}