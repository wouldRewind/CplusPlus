// Ряды(1).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
using namespace std;
// рекурсивный подсчёт синуса
double recursiveSinus(int n)
{
    if (n == 1) return sin(n);
    return sin(n) + recursiveSinus(n - 1);
}
// по сути замена циклу for - циклу подсчёта 
double recursiveSum(int n)
{
    if (n == 1) return n / recursiveSinus(n);
    return n / recursiveSinus(n) + recursiveSum(n - 1);
}

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Введите n : ";
    int n;
    cin >> n;
    if (n <= 0) cout << "Неверные входные данные";
    else cout << "y = " << recursiveSum(n);
   
}

