// Знак числа.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;


int main()

{
    uint8_t sgn;
    std::cout << "Введите цифру: 1,0 или -1\n";
    cin >> sgn;
    switch (sgn)
    {
    case -1: cout << "x < 0";
    case 1: cout << "x > 0";
    default: cout << "x = 0";
    }
    
}

