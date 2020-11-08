// DynamicArray.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;


int main()
{
	int length;
	cout << "Enter array's length:" << endl;
	cin >> length;
	// создаю динамический массив
	int* arr = new int[length];
	// fill
	cout << "Fill the array :";
	for (int i = 0; i < length; i++)
		cin >> arr[i];
}