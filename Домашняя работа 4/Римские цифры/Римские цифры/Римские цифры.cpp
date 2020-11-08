#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isFilled(string st,int* arr) // принимает массив арабских чисел и его длинну, заполняет его соответсвующими цифрами в римской системе
{
	for (int i = 0; i <st.size(); i++)
	{
		switch (st[i])
		{
		case 'I':
		{
			arr[i] = 1;
			break;
		}
		case 'V':
		{
			arr[i] = 5;
			break;
		}
		case 'X':
		{
			arr[i] = 10;
			break;
		}
		case 'L':
		{
			arr[i] = 50;
			break;
		}
		case 'C':
		{
			arr[i] = 100;
			break;

		}
		case 'D':
		{
			arr[i] = 500;
			break;
		}
		case 'M':
		{
			arr[i] = 1000;
			break;
		}
		default:
			// Такого числа нет в римской сс
			return false;
		}
	}
	return true;
}
bool isDec(int n) // является ли число степенью 10-ти(1,10,100,100)

{
	for (int i = 0; i < 4; i++)
		if (n == pow(10, i)) return true;
	return false;
}
bool substactionError(int *arr,int N) // проверяет ошибку вычитания
{
	for (int i = 1; i < N; i++)
	{
		// если вычитается не стпень десятки - ошибка
		if( i - 1 >=0 && arr[i - 1] < arr[i] && !isDec(arr[i - 1])) return true;
		// если вычитание допустимо, но перед вычитаемым стоит число, меньше уменьшаемого, ошибка
		if (i - 2 >= 0 && arr[i - 1] < arr[i] && isDec(arr[i - 1]) && arr[i - 2] < arr[i]) return true;
		// если операция вычитания повторяется несколько раз - ошибка
		if (i - 1 >= 0 && i + 2 < N && arr[i - 1] < arr[i] && arr[i - 1] == arr[i + 1] && arr[i] == arr[i + 2]) return true;
		// если вычитание допустимо, но разность уменьшаемого и вычитаемого меньше, чем число после уменьшаемого - ошибка
		if ( i - 1 >= 0 && i + 1 < N && arr[i - 1] < arr[i] && isDec(arr[i - 1]) && arr[i + 1] > arr[i] - arr[i - 1]) return true;
		//
		// т.е если вычитание допустимо, но цифра после уменьшаемого лежит в диапазоне между уменьшаемым и вычитаемым - ошибка
		if (i - 1 >= 0 && i + 1 < N && arr[i - 1] < arr[i] && isDec(arr[i - 1]) && arr[i + 1] <= arr[i] && arr[i + 1] >= arr[i - 1])  return true;
		// если вычитаемое в 
		if (arr[i - 1] < arr[i] && arr[i] > arr[i - 1] * 10) return true;
	}
	// если ошибок в вычитании нет - значит, все хорошо :)
	return false;

}
bool isRepeat(int *arr,int N, int j) // если число, не равное степени десятки иои единицы, встретилось в записи больше 1-го раза, ошибка
{
	for (int i = 0; i < N; i++)
		if (arr[i] == arr[j] && i != j)
			return true; // повтор найден - ошибка
	return false; // повтора нет - ошибки нет :)
	
}
bool isValid(int* arr, int N,string st)// проверяет правила записи цифр
{
	// если массив не заполнен, значит, введены некорректные данные
	if (!isFilled(st, arr)) return false;
	int count = 1; // сколько раз встречается единица или степень 10-ки
	for (int i = 0; i < N; i++)
	{
		// если число не является степенью 10-ки или единицой, проверяем наличие повторений
		if (!isDec(arr[i]) && isRepeat(arr, N, i)) return false;
		// проверяем допустимое количество подряд идущих единичек или степеней десятки
		if (i + 1 != N && isDec(arr[i]) && arr[i] == arr[i + 1]) count++;
		else count = 1;
		// если встретилось больше 4-ех подряд идудущих единичек или степеней десятки, кидаем ошибку
		if (count == 4) return false;
	}
	if (substactionError(arr, N)) return false;
	return true;
}
// функция подсчета в арабской системе счисления 
int ArabicMapping(int *arr,int N) // подсчёт валидного римского числа
{
	// 
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		// если следом идём меньшее число - разности нет, и текущее прибавляем к сумме
		if (i + 1 < N && arr[i] >= arr[i + 1])
		{
			sum += arr[i];
			continue;
		}
		// если следом идёт большее число - есть разность
		if (i + 1 < N && arr[i] < arr[i + 1])
		{
			// в сумму добавляем разность уменьшаемого и вычитаемого
			sum += arr[i + 1] - arr[i];
			// перескакиваем через уменьшаемое
			i++;
			continue;
		}
		// если не выполнились два условия "сверху" - значит, число последнее, его можно прибавить к сумме
		sum += arr[i];
		
	}
	return sum;
}



int main()
{
	setlocale(LC_ALL, "rus");
	// сообщение об ошибке
	string error = "Что-то пошло не так...";
	string st; // строка римских цифр
	cout << "Введите число в римской системе счисления : ";
	cin >> st;
	// массив арабских чисел
	int* arr = new int[st.size()];

	if (isValid(arr,st.size(),st)) // проверка на валидность
	{
		cout << "Число в арабской системе счисления = " << ArabicMapping(arr, st.size()); // вывожу сумму в консоль
	}
	else cout << error; // если заполнение невалидное, ошибка
}
// MXIC - можно или нет?
// MMCDM
// CIXI
// CIM - особенный случай(так нельзя)
//  CMIII