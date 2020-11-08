// Ряды(2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<math.h>
using namespace std;

// подсчёт факториала нат.чисел
int fact(int n)
{
	if (n == 1) return n;
	return n * fact(n - 1);
}
// рекурсивный подсчёт выражения под корнем
int sum(int n,int *cur)
{
	int sum = 0;
	for (int i = 0; i < n; i++) {
		*cur += 1;
		sum += *cur;
	}
	return sum;
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите число n > 0 : ";
	int n;
	cin >> n;
	//  накопитель
	double y = 0;
	// текущее число
	int *cur = new int(0);
	// реализация
	// cur - переменная, которая будет меняться в теле рекурсии
	for (int i = 0; i < n; i++)
	{
		int f = fact(n - i);
		int s = sum(i + 1, cur);
		//cout << "------------" << endl;
		//cout << "Факториал = " << f << endl;
		//cout << "Под корнем = " << s << endl;
		y += f / sqrt(s);
	}
	cout << "y = " << y;

}

// Суханов Никита