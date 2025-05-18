#include<iostream>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n---------------------------------------\n"

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);
int* insert(int arr[], int& n, const int value, int index);

int* pop_back(int arr[], int& n);
int* pop_fron(int arr[], int& n);
int* erase(int arr[], int& n,const int index);

int** push_row_back(int** arr, int& rows, const int cols);
int** push_row_front(int** arr, int& rows, const int cols);
int** insert_row(int** arr, int index, int& rows, const int cols);

void push_col_back(int** arr, const int rows, int& cols);
void push_col_front(int** arr, const int rows, int& cols);
void insert_col(int** arr, int index, const int rows, int& cols);

int** pop_row_back(int** arr, int& rows, const int cols);
int** pop_row_front(int** arr, int& rows, const int cols);
int** erase_row(int** arr, int index, int& rows, const int cols);

int** Allocate(const int rows);
void Clear(int** arr);


#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);
	//cout << arr << endl;
	/*cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;*/

	int value;
	cout << "Введите добовляемое значение: "; cin >> value;

	arr = push_back(arr, n, value);

	Print(arr, n);


	cout << "Введите добовляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите позицию для вставки значения: "; cin >> index;
	cout << "Введите значение для вставки в массив: "; cin >> value;
	arr = insert(arr, n, value, index);
	Print(arr, n);


	arr = pop_fron(arr, n);
	Print(arr, n);

	cout << "Введите позицию для удаления значения: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

	delete[] arr;
	//Memory leak  
#endif // DYNAMIC_MEMORY_1

	//int rows;das
	//int cols;
	//cout << "Введите количество строк: "; cin >> rows;
	//cout << "Введите количество колонок: "; cin >> cols;

	//int** arr = new int* [rows];

	//for (int i = 0; i < rows; i++)
	//{
	//	arr[i] = new int[cols];
	//}

	//FillRand(arr, rows, cols);
	//Print(arr, rows, cols);

	//arr = push_row_back(arr, rows, cols);
	//Print(arr, rows, cols);

	//for (int i = 0; i < rows; i++)
	//{
	//	delete[] arr[i];
	//}

	//delete[] arr;

}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		//Index operator, Subscript operator;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int arr[], const int n)
{
	//cout << arr << ":\n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << delimiter << endl;
	cout << endl;
}

int* push_back(int arr[], int& n, const int value)
{

	int* buffer = new int[n + 1];

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	delete[] arr;

	arr = buffer;

	arr[n] = value;

	n++;

	return arr;
}

int* push_front(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}
int* insert(int arr[], int& n, const int value, int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < index; i++)
		buffer[i] = arr[i];
	for (int i = index; i < n; i++)
		buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[index] = value;
	n++;
	return buffer;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int* pop_fron(int arr[], int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 1; i < n; i++)
	{
		buffer[i-1] = arr[i];
	}
	delete[] arr; 
	n--;
	return buffer;
}

int* erase(int arr[], int& n, const int index)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index + 1; i < n; i++)
	{
		buffer[i - 1] = arr[i];
	}
	delete[] arr;
	n--;
	return buffer;
}

//методы добавления
int** push_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];

	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}

	delete[] arr;

	buffer[rows] = new int[cols] {};

	rows++;

	return buffer;
}

int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];

	buffer[0] = new int[cols] {};

	for (int i = 1; i <= rows; i++)
	{
		buffer[i] = arr[i];
	}

	delete[] arr;

	rows++;

	return buffer;
}

int** insert_row(int** arr, int index, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];

	buffer[index] = new int[cols] {};

	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}

	for (int i = index + 1; i < rows + 1; i++)
	{
		buffer[i] = arr[i];
	}


	delete[] arr;
	rows++;
	return buffer;
}

void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int [cols + 1];

		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}

		buffer[cols + 1] = 0;

		delete[] arr[i];

		arr[i] = buffer;
	}

	cols++;
}

void push_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1];
		buffer[0] = 0;

		for (int j = 1; j < cols + 1; j++)
		{
			buffer[j] = arr[i][j];
		}

		delete[] arr[i];

		arr[i] = buffer;
	}

	cols++;
}

void insert_col(int** arr, int index, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1];
		buffer[index] = 0;

		for (int j = 0; j < index; j++) {
			buffer[j] = arr[i][j];
		}
		for (int j = index + 1; j < cols + 1; j++) {
			buffer[j] = arr[i][j];
		}

		delete[] arr[i];

		arr[i] = buffer;

	}

	cols++;

}
//\\

//методы удаления
int** pop_row_back(int** arr, int& rows, const int cols) 
{
	int** buffer = new int* [rows - 1];

	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = arr[i];
	}

	delete[] arr;
	rows--;

	return buffer;
}

int** pop_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows - 1];

	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}

	delete[] arr;
	rows--;

	return buffer;
}

int** erase_row(int** arr, int index, int& rows, const int cols) 
{
	int** buffer = new int* [rows - 1];

	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}

	for (int i = index + 1; i < rows; i++)
	{
		buffer[i - 1] = arr[i];
	}

	delete[] arr;
	rows--;

	return buffer;

}
//\\

//общие
int** Allocate(const int rows)
{
	return new int*[rows];
}

void Clear(int** arr)
{
	delete[] arr;
}