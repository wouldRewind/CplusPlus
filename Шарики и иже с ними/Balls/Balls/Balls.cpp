// Шарики.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

int fact(int n) {
	if (n == 1) return 1;
	return n * fact(n - 1);
}
bool isSuitable(int* arr, int n) {
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == i + 1) return true;
	}
	return false;
}



int main()
{
	setlocale(LC_ALL, "rus");
	int n = 10;
	int count = 0;
	for (int a = 0; a < n; a++)
	{
		for (int b = 0; b < n; b++)
		{
			if (b == a) continue;
			for (int c = 0; c < n; c++)
			{
				if (c == a || c == b) continue;
				for (int d = 0; d < n; d++)
				{
					if (d == a || d == b || d == c) continue;
					for (int e = 0; e < n; e++)
					{
						if (e == a || e == b || e == c || e == d) continue;
						for (int f = 0; f < n; f++)
						{
							if (f == a || f == b || f == c || f == d || f == e) continue;
							for (int g = 0; g < n; g++)
							{
								if (g == a || g == b || g == c || g == d || g == e || g == f) continue;
								for (int h = 0; h < n; h++)
								{
									if (h == a || h == b || h == c || h == d || h == e || h == f || h == g) continue;
									for (int i = 0; i < n; i++)
									{
										if (i == a || i == b || i == c || i == d || i == e || i == f || i == g || i == h) continue;
										for (int j = 0; j < n; j++)
										{
											if (j == a || j == b || j == c || j == d || j == e || j == f || j == g || j == h || j == i) continue;
											// создаю массив
											int* arr = new int[n];
											arr[0] = a;
											arr[1] = b;
											arr[2] = c;
											arr[3] = d;
											arr[4] = e;
											arr[5] = f;
											arr[6] = g;
											arr[7] = h;
											arr[8] = i;
											arr[9] = j;
											if (isSuitable(arr, n)) count++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << count;
}

