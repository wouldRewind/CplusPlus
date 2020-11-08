// Сортировка букв.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str;
    cout << "Input a word: ";
    cin >> str;
    // функция сортировки библиотеки algorith, в аргументе - откуда и ДО куда сортировать
    sort(str.begin(), str.end());
    cout << str;
}


