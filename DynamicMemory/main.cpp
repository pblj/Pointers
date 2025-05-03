#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int* push_back(int arr[],const int n, const int value);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	for (int i = 0; i < n; i++)
	{
		cout << arr + i << "\t";
	}

	cout << endl;

	int value;
	cout << "������� ����������� ��������: "; cin >> value;

	arr = push_back(arr, n, value);
	
	n++;

	//7 �������� ���������, ��������� ���������:
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

int* push_back(int arr[], const int n, const int value)
{
	int* buffer = new int[n + 1];

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	delete[] arr;

	arr = buffer;

	arr[n] = value;

	return arr;
 
}