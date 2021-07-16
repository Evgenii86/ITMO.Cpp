
#include <Windows.h>
#include <iostream>
#include <cmath>
using namespace std;

int Myroot(double, double, double, double&, double&);
int Input(int, int);

int main()
{
    //Практическая работа 4 Контрольное задание 1

    SetConsoleOutputCP(1251);
    double a, b, c;
    double x1, x2;
    int res;
    cout << "Введите три значения членов квадратного уравнения" << endl << endl;
    cin >> a >> b >> c;
    res = Myroot(a, b, c, x1, x2);
    if (res == -1)
        cout << "Уравнение не имеет корней, которые бы являлись действительными числами" << endl << endl;
    if (res == 0)
        cout << "Уравнение имеет два корня, которые равны друг другу: x1 = x2= " << x1 << endl << endl;
    if (res == 1)
        cout << "Уравнение имеет два корня: x1 = " << x1 << "\tx2 = " << x2 << endl << endl;
    if (res == 10)
        cout << "При  коэффициенте a = 0 уравнение не является квадратным" << endl << endl;

    // Контрольное задание 2

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
        cout << "Уравнение не является квадратным" << endl << endl;
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
    cout << "Введите два целых числа" << endl << endl;
    cin >> aa >> bb;
    if (!cin)
    {
        return 0;
    }
    else
        return 1;
}