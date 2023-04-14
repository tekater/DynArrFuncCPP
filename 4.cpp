#include <iostream>
#include <stdlib.h>  // rand(), srand()
#include <windows.h> // time()
#include <math.h>    // библиотека матеши
#include <time.h>
using namespace std;

template <class T>
void BubbleSort(T arr[], int length) {
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - 1; j++)
		{
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}


template <class T>
void Sort(T* A, T* B, int& length, int& count, int z = 0) {

	for (int i = z; i < count; i++) {
		for (int j = 0; j < length; j++) {
			if (A[j] >= 0) {
				B[i] = A[j];
				A[j] = -1;
				return Sort(A, B, length, count, z + 1);
			}
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
	int* B = new int[length];

	cout << "A: ";
	for (size_t i = 0; i < length; i++)
	{
		A[i] = -5 + rand() % 10;
		cout << A[i] << " ";
	}
	cout << "\nB: ";
	for (size_t i = 0; i < length; i++)
	{
		B[i] = 0;
		cout << B[i] << " ";
	}

	cout << endl;
	BubbleSort(A, length);

	int second = length;

	for (int i = 0; i < second; i++) {
		if (A[i] >= 0) {
			count++;
		}
	}
	length = count;
	Sort(A, B, second, count);

	cout << "\nB: ";
	for (size_t i = 0; i < length; i++)
	{
		cout << B[i] << " ";
	}
}
