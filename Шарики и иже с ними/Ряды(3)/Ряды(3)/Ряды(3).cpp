// Ряды(3).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


#include <iostream>
#include <math.h>
using namespace std;
// сумма синусов 
double sinusSumRecursive(int n)
{
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += sin(2 * i);
    }
    return sum;
}
int fact(int n)
{
    if (n == 1) return n;
    return n * fact(n - 1);
}

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Введите n : ";
    int n;
    cin >> n;
    double y = 1;
    for (int i = 1; i <= n; i++)
    {
        y *= fact(i) / sinusSumRecursive(i);
    }
    cout << "y = " << y;
}

