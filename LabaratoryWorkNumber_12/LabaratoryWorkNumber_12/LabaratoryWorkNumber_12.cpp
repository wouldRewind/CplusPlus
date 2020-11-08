// LabaratoryWorkNumber_12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Вариант 22
// Решаю в общем случае: матрица размера M x M, числа заполняю в диапазоне от 0 до n, n >=0
// в конструкторе строю матрицу по её размеру и в цикле заполняю(все это происходит при инициализцаии объекта)
// потом исключаю все числа в массиве, принадлежащие ряду фибоначчи, сортирую оставшиеся и вывожу все дело в консоль


/*Поля класса Matrix:
1) matrix - двумерный массив, размерность будет зависит от ввода пользователя
2) fibonachiNumbers - массив чисел из ряда Фибоначчи, будет заполнен в ходе программы
3) sortedNumbers - отсортированные в порядке убывания числа, оставшиеся после исключения чисел Фиббоначи
*/

/* Методы класса Matrix
* 1) fillMatrix - заполняет матрицу по мере пользовательского ввода
* 2) handleMatrix - ищет числа фибоначчи в матрице matrix и заполняет массив fibonachiNumbers, числа не принадлежащие Фиббоначи пушит в массив и сортирует
* 3) displayData - отображает массив Фибоначи и оставшиеся числа в порядке убывания
*/

/*
* 1) dataInput - предохраненный ввод данных
* 2) isNumFibonachi - проверяет, принадлежит ли число ряду фибоначчи
* 3) comp - функция компаратор для сортировки
*/

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
bool isNumFibonachi(int num,int beforePrevious = 0,int previous = 1)
{
	if (num == 0 || num == 1) return true;

	const int currentFib = beforePrevious + previous;
	if (currentFib == num) return true;
	if (currentFib > num) return false;
	return isNumFibonachi(num, previous, currentFib);
}
bool comp(int a, int b) // компаратор для сравнения по убыванию
{
	return a > b;
} 

class Matrix {
private:
	vector <vector<int>> matrix;
	vector <int> fibonachiNumbers;
	vector <int> restNumbers;
	bool boundaryError(int dimension, int range) // выходит ли заданное число за границы
	{
		for (int i = 0; i < dimension; i++)
			for (int j = 0; j < dimension; j++) {
				int number = this->matrix[i][j];
				if (number > range || number < 0)
					return true;
			}
		return false;
	}
public:
	Matrix(int dimension, int range) // range - максимальное число(положительное), какое только можно положить в ячейку
	{
		fillMatrix(dimension, range); // заполняю матрицу
		// будем заполнять до посинения
		while (this->boundaryError(dimension,range))
		{
			cout << "Матрица заполнена некорректно. Пожалуйста, повторите заполнение и не выходите за заданный диапазон." << endl;
			fillMatrix(dimension, range);
		}
		cout << "Матрица успешно заполнена!" << endl;
	}
	void handleMatrix(int range,int dimension)
	{
		for (int i = 0; i < dimension; i++)
		{
			for (int j = 0; j < dimension; j++)
			{
				const int currentNumber = this->matrix[i][j];
				// если число из матрицы принадлежит числу Фиббоначи - пушим его в массив чисел Фибоначчи, иначе - в массив "rest" чисел
				if (isNumFibonachi(currentNumber))
					this->fibonachiNumbers.push_back(currentNumber);
				else this->restNumbers.push_back(currentNumber);
			}
		}
		sort(this->restNumbers.begin(), this->restNumbers.end(),comp);
		
	}
	void fillMatrix(int dimension, int range)
	{
		cout << "Заполните матрицу : ";
		for (int i = 0; i < dimension; i++)
		{
			vector <int> line; // строка в матрице
			for (int j = 0; j < dimension; j++)
			{
				int number; // вводимое пользователем число
				dataInput(&number, "");
				line.push_back(number); // добавляю число в строку
			}
			this->matrix.push_back(line); // добавляю строку в матрицу
		}
	}
	void displayData() {
		const int fibSize = this->fibonachiNumbers.size();
		const int restSize = this->restNumbers.size();
		// Фиббоначи
		cout << "Числа Фибоначчи : " << endl;
		for (int i = 0; i < fibSize; i++) {
			cout << this->fibonachiNumbers[i] << " ";
		}
		cout << endl; // перевод каретки
		// НЕ Фибоначи
		cout << "Оставшиеся числа в порядке убывания: " << endl;
		for (int i = 0; i < restSize; i++) {
			cout << this->restNumbers[i] << " ";
		}
	}
};



int main()
{
	setlocale(LC_ALL, "rus");
	int dimension, range = -1; // размерность матрицы и рейндж чисел в ней
	dataInput(&dimension, "Введите размерность матрицы : ");
	while(range < 0) dataInput(&range, "Введите, до какого, начиная от нуля, вы собираетесь вводить цифры в матрицу : ");

	// создаю матрицу
	Matrix matrix(dimension, range);
	// обрабатываю матрицу
	matrix.handleMatrix(range, dimension);
	// отображаю результат в соотвествии с заданием
	matrix.displayData();
}


