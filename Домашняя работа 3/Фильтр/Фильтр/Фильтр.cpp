// Фильтр.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	double nums[10];
	fstream fout("d:\\1\\Файл.txt");
	//  прошу у пользователя числа и заполняю массив
	cout << "Введите 10 вещественных чисел : ";
	for (int i = 0; i < 10; i++)
		cin >> nums[i];
	// заполняю файл
	for (int i = 0; i < 10; i++)
		fout << nums[i] << " ";
	// закрываю файл
	fout.close();
	// открываю файл заново
	ifstream file("d:\\1\\Файл.txt");
	double b = 0, sum = 0;
	do
	{
		// пробуем считать число
		if (file >> b)
		{
			// если считали число - выводим
			sum+=b;
		}
		else
		{
			// если считали не число, очищаем ошибки
			file.clear();
			// пропускаем символы до следующего пробела
			file.ignore(1, ' ');
		}
	} while (!file.eof());
	file.close();
	cout << sum;
	return 0;
	
}

