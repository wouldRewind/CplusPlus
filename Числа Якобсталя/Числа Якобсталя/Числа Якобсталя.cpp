// Числа Якобсталя.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


#include <iostream>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

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

void displayYakobstalNums(int m,int n,int beforePrevious = 0,int previous = 1)
{
	if ((m == 0 || m == 1) && m<=n) 
	{
		cout << m << " ";
		displayYakobstalNums(m + 1, n, beforePrevious, previous);
	}
	else if (m < 0) displayYakobstalNums(m + 1, n,beforePrevious,previous);
	else if(m <=n) {
		unsigned long int cur = previous + 2 * beforePrevious;
		cout << cur << " ";
		displayYakobstalNums(m + 1, n, previous, cur);
	}
}



int main()
{
	int m, n;
	setlocale(LC_ALL, "rus");
	cout << "Введите два числа интервала [m,n] : " << endl;
	dataInput(&m, "Введите m : ");
	dataInput(&n, "Введите n : ");
	if (n < m)
	{
		cout << "Диапазон задан неверно. Повторите попытку!";
	}
	else if (m < 0) {
		cout << "Чисел Якобсталя в заданном диапазоне не существует!";
	}
	else {
		cout << "Я нашел следующие числа Якобсталя : ";
		displayYakobstalNums(m, n);
	}
		
	
}

