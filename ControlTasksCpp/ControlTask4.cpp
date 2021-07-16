
#include <Windows.h>
#include <iostream>
#include <cmath>
using namespace std;

int Myroot(double, double, double, double&, double&);
int Input(int, int);

int main()
{
    //������������ ������ 4 ����������� ������� 1

    SetConsoleOutputCP(1251);
    double a, b, c;
    double x1, x2;
    int res;
    cout << "������� ��� �������� ������ ����������� ���������" << endl << endl;
    cin >> a >> b >> c;
    res = Myroot(a, b, c, x1, x2);
    if (res == -1)
        cout << "��������� �� ����� ������, ������� �� �������� ��������������� �������" << endl << endl;
    if (res == 0)
        cout << "��������� ����� ��� �����, ������� ����� ���� �����: x1 = x2= " << x1 << endl << endl;
    if (res == 1)
        cout << "��������� ����� ��� �����: x1 = " << x1 << "\tx2 = " << x2 << endl << endl;
    if (res == 10)
        cout << "���  ������������ a = 0 ��������� �� �������� ����������" << endl << endl;

    // ����������� ������� 2

    int aa = 0, bb = 0;
    if (Input(aa, bb) == false) // if(!Input(a,b))
    {
        cerr << "error";
        return 1;
    }
    int s = aa + bb;

    return 0;
}


int Myroot(double a, double b, double c, double& x1, double& x2)
{
    if (a == 0) {
        cout << "��������� �� �������� ����������" << endl << endl;
        return 10;
    }

    double d = b * b - 4 * a * c;
    double sqrtVal = sqrt(abs(d));

    if (d > 0) {

        x1 = (double)(-b + sqrtVal) / (2 * a);
        x2 = (double)(-b - sqrtVal) / (2 * a);
        return 1;
    }
    else if (d == 0) {

        x1 = x2 = -(double)b / (2 * a);
        return 0;
    }
    else
    {
        return -1;
    }
}

int Input(int aa, int bb)
{
    cout << "������� ��� ����� �����" << endl << endl;
    cin >> aa >> bb;
    if (!cin)
    {
        return 0;
    }
    else
        return 1;
}