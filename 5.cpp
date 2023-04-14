#include <iostream>
#include <stdlib.h>  // rand(), srand()
#include <windows.h> // time()
#include <math.h>    // библиотека матеши
#include <time.h>
using namespace std;

template <class T>
void AddNumbers(T A[], T arr[], int length, int z, int num, int k = 0) {
	for (int i = z; i < length; i++) {
		for (int j = k; j < num; j++) {
			A[i] = arr[j];
			return AddNumbers(A, arr, length, z + 1, num, k + 1);
		}
	}
}


int main()
{
	setlocale(0, "");
	srand(time(NULL));
	//system("color B5");
	int length = 10, count = 0;

	int* A = new int[length];
	
	cout << "A: ";
	for (size_t i = 0; i < length; i++)
	{
		A[i] = 1 + rand() % 10;
		cout << A[i] << " ";
	}

	cout << endl;
	int z = length;

	cout << "Введите величину блока массива:\n";
	int num = 0; cin >> num; length += num;
	int* arr = new int[num];

	for (int i = 0; i < num; i++) {
		cout << "Введите " << i+1 << " цифру:\n";
		cin >> arr[i];
	}

	AddNumbers(A, arr, length, z, num);
	system("cls");

	cout << "A: ";
	for (int i = 0; i < length; i++) {
		cout << A[i] << " ";
	}

}
