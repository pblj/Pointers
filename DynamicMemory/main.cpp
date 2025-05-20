#include <iostream>
using namespace std;

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n---------------------------------------\n"

void FillRand(int arr[], const int n);
void FillRand(double arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);

int FillElement(int divider);

int** Allocate(const int rows,const int cols);
template <typename T> void Clear(T** arr, int& rows);

template <typename T>void Print(T arr[], const int n);
template <typename T>void Print(T** arr, const int rows, const int cols);

template <typename T>T** CopyArray(T** arr, const int rows, const int size_buffer);

template <typename T>T* push_back(T arr[], int& n, const T value);
template <typename T>T* push_front(T arr[], int& n, const T value);
template <typename T>T* insert(T arr[], int& n, const T value, int index);

template <typename T>T* pop_back(T arr[], int& n);

template <typename T>T** push_row_back(T** arr, int& rows, const int cols);
template <typename T>T** pop_row_back(T** arr, int& rows, const int cols);

template <typename T> void push_col_back(T** arr, const int rows, int& cols);
template <typename T> void pop_col_back(T** arr, const int rows, int& cols);


//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	double* arr = new double[n];

	FillRand(arr, n);
	Print(arr, n);
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
	/*
	----------------------------------
	+, -, ++, --;
	----------------------------------
	*/

	double value;
	cout << "Введите добавляемое значение: "; cin >> value;

	arr = push_back(arr, n, value);
	n++;

	//7) Значение добавлено, проверяем результат:
	Print(arr, n);


	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	delete[] arr;
	//Memory leak  
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2

	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	////1) Создаем массив указателей:
	//int** arr = new int* [rows];

	////2) Выделяем память под строки двумерного динамического массива:
	//for (int i = 0; i < rows; i++)
	//{
	//	arr[i] = new int[cols];
	//}

	int** arr = Allocate(rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	//int   - 'int';
	//int*  - Указатель на 'int';
	//int** - Указатель на указатель на 'int';

	cout << "Добавление строки в конец" << endl;
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Добавление колонки в конец" << endl;
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Удаление строки в конце" << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Удаление колонки в конце" << endl;
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);


	/*cout << "Память выделена, для добавления столбца" <<endl;
	system("PAUSE");


	push_col_back(arr, rows, cols);

	cout << "Столбец добавлен" << endl;*/

	Clear(arr, rows);
	////1) Сначала удаляем строки:
	//for (int i = 0; i < rows; i++)
	//{
	//	delete[] arr[i];
	//}

	////2) Удаляем массив указателей:
	//delete[] arr;
#endif // 
}

int FillElement(int divider)
{
	return rand() % divider;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = FillElement(100);
	}
}
void FillRand(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = FillElement(10000);
		arr[i] /= 100;
	}
}

void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		FillRand(arr[i], rows);
	}
}
void FillRand(double** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		FillRand(arr[i], rows);
	}
}

int** Allocate(const int rows, const int cols)
{
	int** arr = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}

template <typename T> void Clear(T** arr, int& rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}

	delete[] arr;
	rows = 0;
}

template <typename T> void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template <typename T>void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		Print(arr[i], cols);
	}
	cout << delimiter << endl;
	cout << endl;
}

template <typename T>T* push_back(T arr[], int& n, const T value)
{

	//1) Создаем буферный массив нужного размера:
	T* buffer = new T[n + 1];

	//2) Копируем все содержимое исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	//3) Удаляем исходный массив:
	delete[] arr;

	//4) Подменяем адрес в указателе 'arr' адресом нового массива:
	arr = buffer;

	//5) Только после всего этого в конце массива появляется элемент, 
	//	 в который можно сохранить добавляемое значение:
	arr[n] = value;

	//6) После того как в массив добавился элемент, 
	//	 количество его элементов увеличивается на 1:
	//n++; переносим увеличение элементов на место вызова

	return arr;
}
template <typename T>T* push_front(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}
template <typename T>T* insert(T arr[], int& n, const T value, int index)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < index; i++)
		buffer[i] = arr[i];
	for (int i = index; i < n; i++)
		buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[index] = value;
	n++;
	return buffer;
}
template <typename T>T* pop_back(T arr[], int& n)
{
	T* buffer = new T[n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

//служебные
template <typename T>T** CopyArray(T** arr, const int rows, const int size_buffer)
{
	T** buffer = new T * [size_buffer];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	return buffer;
}

template <typename T>T** push_row_back(T** arr, int& rows, const int cols)
{

	T** buffer = CopyArray(arr, rows, rows + 1);
	delete[] arr;

	buffer[rows] = new T[cols]{};

	rows++;

	return buffer;
}
template <typename T>T** pop_row_back(T** arr, int& rows, const int cols)
{
	rows--;
	T** buffer = CopyArray(arr, rows, rows);
	delete[] arr[rows];
	delete[] arr;
	return buffer;
}
template <typename T>void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = push_back(arr[i], cols,0); //добовляю просто 0
	}
	cols++;
}
template <typename T>void pop_col_back(T** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		arr[i] = pop_back(arr[i], cols);
	}
}