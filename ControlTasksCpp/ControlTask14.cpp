#include <iostream>

using namespace std;

template<class T>
T average(T arr[], int size) 
{
    T sum = 0;
    for (int i = 0; i < size-1; i++) { sum += arr[i]; }
    return (sum / size);
}


int main()
{
    int a1[] = { 73,36,27,8,12,14,87,47,55 };
    int s1 = sizeof(a1) / sizeof(a1[0]);
    cout << average(a1, s1) << endl;

    double a2[] = { 34.6,45.3,6.7,11.4,53.5,23.7,78.8 };
    int s2 = sizeof(a2) / sizeof(a2[0]);
    cout << average(a2, s2) << endl;

    char a3[] = "Hello, word";
    int s3 = sizeof(a3) / sizeof(a3[0]);
    cout << average(a3, s3) << endl;

    long a4[] = { 7345634556, 683204839, 985620856437, 4826389562085, 675098547382};
    int s4 = sizeof(a4) / sizeof(a4[0]);
    cout << average(a4, s4) << endl;

    return 0;
}