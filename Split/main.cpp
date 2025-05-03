#include <iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	const int n = 10;
	int arr[n];
	FillRand(arr, n);
	Print(arr, n);

	//1. считаем кол-во четных и нечетных элементов
	// even - четный
	//Odd - нечетный
	int even_count = 0;
	int odd_count = 0;
	for (int i = 0; i < n; i++)
	{
		//if (arr[i] % 2 == 0)even_count++;
		//else odd_count++;
		(arr[i] % 2 == 0 ? even_count : odd_count)++;
	}
	//2 выделяем память для четных и нечетных значений
	int* even_arr = new int[even_count];
	int* odd_arr = new int[odd_count];

	//3 копируем четные и нечетные значения в соответствующие массивы
	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		//if (arr[i] % 2 == 0)even_arr[j++] = arr[i];
		//else odd_arr[k++] = arr[i];
		(arr[i] % 2 == 0 ? even_arr[j++] : odd_arr[k++]) = arr[i];
		
	}
	//4 выводим результат
	Print(even_arr, even_count);
	Print(odd_arr, odd_count);

	//? удаляем память:
	delete[] odd_arr;
	delete[] even_arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
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