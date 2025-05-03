#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "¬ведите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "введите добовл€емое значение: "; cin >> value;

	//1 создаем буферный массив нужного размера:
	int* buffer = new int[n + 1];

	//2 копируем все содержимое исходного массива в новый буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	//3 удал€ем исходный массив
	delete[] arr;

	//4 подмен€ем адрес в указателе arr адресом нового массива
	arr = buffer;

	//5 только после всего этого в конце массива по€вл€етс€ элемент, который можно сохранить добовл€емое значение:
	arr[n] = value;

	//6 после того как в массив добавилс€ элемент, количество его элементов увеличиваетс€ на 1:
	n++;

	//7 значение жобавлено, провер€ем результат:
	Print(arr, n);

	delete[] arr;
	//Memory leak
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		//Index operator, Subscript operator;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}