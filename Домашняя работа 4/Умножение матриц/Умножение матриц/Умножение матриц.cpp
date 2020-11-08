
#include <iostream>
#include<algorithm>
#include <string>
using namespace std;



int main()
{
	setlocale(LC_ALL, "rus");
	const int sellers = 3, goods = 4, fields = 2; // количество продавцов, количество товаров, количество полей в поле B - цена и комиссионные
	// массив продавцов и товаров
	double A[sellers][goods];
	// массив цену за товар и комиссию за него
	double B[goods][fields];
	cout << "Заполните массив A : " << endl;
	// заполняю массив A

	for (int i = 0; i < sellers; i++)
	{
		for (int j = 0; j < goods; j++)
			cin >> A[i][j];
	}
	cout << "Заполните массив B : " << endl;
	// заполняю массив B
	for (int i = 0; i < goods; i++)
	{
		for (int j = 0; j < fields; j++)
			cin >> B[i][j];
	}
	// создаю массив C
	double C[sellers][fields];
	// A*B = C, в массиве C первый столбец - прибыль первого, второго и третьего продавца, второй - вырученные коммисионные этих же продавцов
	//
	for (int i = 0; i < sellers; i++)
	{
		for (int j = 0; j < fields; j++)
		{
			double sum = 0; // накопитель
			for (int g = 0; g < goods; g++)
			{
				sum += A[i][g] * B[g][j];
			}
			C[i][j] = sum;
		}
	}
	// проверка
	cout << endl;
	cout << "Матрица C имеет следующий вид : " << endl;
	for (int i = 0; i < sellers; i++)
	{
		for (int j = 0; j < fields; j++)
		{
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	// ОТВЕТЫ НА ВОПРОСЫ ПО ЗАДАНИЯМ
	double min = C[0][0];
	int maxIndex = 0;
	int minIndex = 0;
	double max = C[0][0];
	for (int i = 0; i < sellers; i++)
	{
		if (C[i][0] >= max)
		{
			max = C[i][0];
			maxIndex = i + 1;
		}
		if (C[i][0] <= min)
		{
			min = C[i][0];
			minIndex = i + 1;
		}
	}
	cout << "Больше всех заработал продавец под номером " << maxIndex << " : " << max << " рублей" << endl;
	cout << "Меньше всех заработал продавец под номером " << minIndex<< " : " << min << " рублей" << endl;
	double maxCom = C[0][1];
	double minCom = C[0][1];
	maxIndex = 0;
	minIndex = 0;
	for (int i = 0; i < sellers; i++)
	{
		if (C[i][1] >= maxCom)
		{
			maxCom = C[i][1];
			maxIndex = i + 1;
		}
		if (C[i][1] <= maxCom)
		{
			minCom = C[i][1];
			minIndex = i + 1;
		}
	}
	cout << "Больше всего комиссионных получил продавец под номером " << maxIndex << " : " << maxCom << " рублей" << endl;
	cout << "Больше всего комиссионных получил продавец под номером " << minIndex << " : " << minCom << " рублей" << endl;
	// всего комиссионных и выплат
	double sold = 0;
	double sumCommission = 0;
	for (int i = 0; i < sellers; i++)
	{
		sold += C[i][0];
		sumCommission += C[i][1];

	}

	cout << endl;
	cout << "Общая сумма комиссионных : " << sumCommission << " рублей" << endl;
	cout << "Общая сумма проданных товаров : " << sold << " рублей" << endl;
	cout << "Общая сумма денег, прошедших через руки продавцов(сумма общих выплат и коммисионных) : " << sold + sumCommission << " рублей";
	
}

