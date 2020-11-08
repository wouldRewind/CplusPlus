#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n = 54, k(0), m(0), h(0);
	string nomera_kupe;
	int** arr = new int*[9];
	for (int i = 0; i < 9; i++)
	{
		arr[i] = new int[6];
	}
	for (int i = 0; i < 36; i += 4)
	{
		arr[m][0] = i + 1;
		arr[m][1] = i + 2;
		arr[m][2] = i + 3;
		arr[m][3] = i + 4;
		arr[m][4] = n;
		arr[m][5] = n - 1;
		m++;
		n -= 2;
	}
	int* mas1 = new int[k];
	cout << "Введите количество мест: ";
	cin >> k;
	cout << "Введите номера мест: ";
	for (int i = 0; i < k; i++)
	{
		cin >> mas1[i];
	}
	if (k < 6) cout << "В вагоне нет свободных купе! ";
	else
	{
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				for (int l = 0; l < 6; l++)
				{
					if (mas1[i] == arr[j][l])
					{
						nomera_kupe = 'j';
						l = 6;
					}
				}
			}
		}
	}
	cout << nomera_kupe;
	return 0;
}