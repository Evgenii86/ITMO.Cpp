#include <Windows.h>
#include <iostream>
using namespace std;

int Sum(const int Arr[], const int N);
double Average(const int Arr[], const int N);
int sumNeg(const int Arr[], const int N);
int sumOddIndices(const int Arr[], const int N);
int sumEvenIndices(const int Arr[], const int N);
void selectionSort(int Arr[], int N);
void printArray(int arr[], int size);
int* max_vect(int size, int a[], int b[]);

int main()
{
	// Практическая работа 5
	// Задание 1
	SetConsoleOutputCP(1251);

	const int N = 10;
	int mas[N];
	for (int i = 0; i < N; i++)
	{
		cout << "mas[" << i << "]=";
		cin >> mas[i];
	}

	cout << "Сумма элементов массива равна: " << Sum(mas, N) << endl << endl;
	cout << "Среднее значение элемента массива равно: " << Average(mas, N) << endl << endl;
	cout << "Сумма отрицательных элементов массива равна: " << sumNeg(mas, N) << endl << endl;
	cout << "Сумма элементов массива с нечетными индексами равна: " << sumOddIndices(mas, N) << endl << endl;
	cout << "Сумма элементов массива с четными индексами равна: " << sumEvenIndices(mas, N) << endl << endl;
	cout << "Массив до сортировки: " << endl << endl;
	printArray(mas, N);
	cout << "Массив после сортировки выбором: " << endl << endl;
	selectionSort(mas, N);
	printArray(mas, N);
	cout << "----------------------------------------------------------" << endl << endl;

	// Задание 2

	int a[] = { 8,9,3,4,5,6,7,2 };
	int b[] = { 7,6,5,4,7,7,1,9 };
	int kc = sizeof(a) / sizeof(a[0]); //Количество элементов массива
	int* c; //Указатель на результирующий массив
	c = max_vect(kc, a, b); //вызов функции для создания массива
	for (int i = 0;i < kc; i++) //Вывод результата.
		cout << c[i] << " ";
	cout << endl;
	delete[]c;

	return 0;
}

int Sum(const int Arr[], const int N)
{
	int s = 0;
	for (int i = 0; i < N; i++)
	{
		s += Arr[i];
	}
	return s;
}

double Average(const int Arr[], const int N)
{
	int s = 0;
	for (int i = 0; i < N; i++)
	{
		s += Arr[i];
	}
	double av = s / N;
	return av;

}

int sumNeg(const int Arr[], const int N)
{
	int negS = 0;
	for (int i = 0; i < N; i++) {
		if (Arr[i] < 0)
			negS+= Arr[i];
	}
	return negS;
}
int sumOddIndices(const int Arr[], const int N)
{
	int oddInd = 0;
	for (int i = 0; i < N; i++) {
		if (i % 2 != 0)
			oddInd += Arr[i];
	}
	return oddInd;
}
int sumEvenIndices(const int Arr[], const int N)
{
	int evenInd = 0;
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0)
			evenInd += Arr[i];
	}
	return evenInd;
}
void selectionSort(int Arr[], int N)
{
	int min = 0;
	int buf = 0;
	for (int i = 0; i < N; i++)
	{
		min = i; 
		
		for (int j = i + 1; j < N; j++)
			min = (Arr[j] < Arr[min]) ? j : min;
		
		if (i != min)
		{
			buf = Arr[i];
			Arr[i] = Arr[min];
			Arr[min] = buf;
		}
	}
}
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int* max_vect(int size, int a[], int b[])
{
	int* resArray = new int[size];
	for (int i = 0; i < size; i++)
	{
		if (a[i] >= b[i])
		{
			resArray[i] = a[i];
		}
		else if (a[i] < b[i])
		{
			resArray[i] = b[i];
		}
	}
	return resArray;
}