// Ханой.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

void hanoi(int n, int i, int k) // сколько всего колец, с какого стрежня на какой
{
	if (n == 1) cout << "Move disk 1 from " << i << " to " << k << endl;
	else {
		// вычисляю временный столбец
		int tmp = 6 - i - k;
		hanoi(n - 1, i, tmp);
		cout << "Move disk " << n << " from " << i << " to " << k  << endl;
		hanoi(n - 1, tmp, k);
		
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	hanoi(3, 1, 2);

}

