

#include <iostream>
using namespace std;
// рекурсивный подсчёт
int recursion(int a, int c, int m, int s,int i, int start = 1)
	{
	int cur = (a * s + c) % m;
	if (i > start) 
		return recursion(a, c, m, cur, i - 1, start);
	return cur;
	}

int main()
{
	setlocale(LC_ALL, "rus");
   // задаю константы вручную
	const int  a = 3, c = 37, m = 64,s = 4;
	// задаваемая пользователем переменная i
	int i;
	cout << "Введите переменную i : " << endl;
	cin >> i;
	cout << "Псвевдослучайное число = " << recursion(a,c,m,s,i);
}
