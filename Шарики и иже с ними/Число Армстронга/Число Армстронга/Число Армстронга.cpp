// Число Армстронга.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;


int lastDigit(int num,int n)
{
	return pow(num % 10,n);
}

int cubedDigitsSum(int num,int n) // рекурсивный подсчёт
{
	int cubedDigit = lastDigit(num, n);
	if (num < 10) return cubedDigit;
	return	cubedDigit + cubedDigitsSum(num / 10,n);
}

void dataInput(int* data, string message = "Введите данные")
{
	cout << message << endl;
	while (!(cin >> *data) || cin.get() != '\n')
	{
		cout << "Повторите попытку" << endl;
		cin.clear(); // сбрасывает все биты потока, тоесть поток становится "хорошим"
		cin.sync();//Удалим данные из буффера
		string str;
		getline(cin, str);
	}
}

void displayArmstrongNums(int n) // n - скольки значные цифры мы рассматриваем
{
	// диапазон поиска
	int start = pow(10, n - 1);
	int end = pow(10, n);
	// поиск в диапазоне
	cout << "Я нашел следующие " << n << "-значные числа Армстронга : ";
	for (int cur = start; cur < end; cur++)
		if (cur == cubedDigitsSum(cur, n))
			cout << cur << " ";
	
}


int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	dataInput(&n, "Введите n : ");
	if (n < 0 || n > 10)
		cout << "Ничего личного, повторите попытку!";
	else
		displayArmstrongNums(n);
	
}


