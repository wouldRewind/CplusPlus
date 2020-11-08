// bubbleSort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;

vector <int> bubbleSort(vector <int> arr)
{
	const int sz = arr.size(); // размер массива

	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			if (arr[j] > arr[i])
			{
				// перестановка двух переменных без использованией третьей
				arr[j] = arr[j] + arr[i];
				arr[i] = arr[j] - arr[i];
				arr[j] = arr[j] - arr[i];
			}
		}
	}
	return arr;
}
void displayArray(vector <int> arr)
{
	for (int i = 0; i < arr.size(); i++) // отображаю отсортированный массив
		cout << arr[i] << " ";
}

int main()
{
	setlocale(LC_ALL, "rus");

	vector <int> unsorted = {5,1,4,2,3}; // произвольный массив
	vector<int> sorted = bubbleSort(unsorted); // сортирую и возвращаю отсортированный массив

	displayArray(sorted); // отображаю отсортированный массив
}


