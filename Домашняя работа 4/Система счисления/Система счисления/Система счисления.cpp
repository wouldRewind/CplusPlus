// Сначала перевожу в десятичную, а затем последовательно делю на основании системы счисления, собирая остатки(работаю только с целымми числами)
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
// если функция возвращает отрицательное число - ошибка
int dec(string st,int base)
{
    int n = 0; // число в десятичной системе счисления
    for (int i = 0; i < st.size(); i++)
    {
        switch (st[i])
        {
        case '0':
        {
            // нулевой разряд пропускаем
            break;
        }
        case '1':
        {
            if (1 > base - 1) return -1;
            n += 1 * pow(base, st.size() - 1 - i);
            break;
        }
        case '2':
        {
            if (2 > base - 1) return -1;
            n += 2 * pow(base, st.size() - 1 - i);
            break;
        }
        case '3':
        {
            if (3 > base - 1) return -1;
            n += 3 * pow(base, st.size() - 1 - i);
            break;
        }
        case '4':
        {
            if (4 > base - 1) return -1;
            n += 4 * pow(base, st.size() - 1 - i);
            break;
        }
        case '5':
        {
            if (5 > base - 1) return -1;
            n += 5 * pow(base, st.size() - 1 - i);
            break;
        }
        case '6':
        {
            if (6 > base - 1) return -1;
            n += 6 * pow(base, st.size() - 1 - i);
            break;
        case '7':
        {
            if (7 > base - 1) return -1;
            n += 7 * pow(base, st.size() - 1 - i);
            break;
        }
        case '8':
        {
            if (8 > base - 1) return -1;
            n += 8 * pow(base, st.size() - 1 - i);
            break;
        }
        case '9':
        {
            if (9 > base - 1) return -1;
            n += 9 * pow(base, st.size() - 1 - i);
            break;
        }
        case 'A':
        {
            if (10 > base - 1) return -1;
            n += 10 * pow(base, st.size() - 1 - i);
            break;
        }
        case 'B':
        {
            if (11 > base - 1) return -1;
            n += 11 * pow(base, st.size() - 1 - i);
            break;
        }
        case 'C':
        {
            if (12 > base - 1) return -1;
            n += 12 * pow(base, st.size() - 1 - i);
            break;
        }
        case 'D':
        {
            if (13 > base - 1) return -1;
            n += 13 * pow(base, st.size() - 1 - i);
            break;
        }
        case 'E':
        {
            if (14 > base - 1) return -1;
            n += 14 * pow(base, st.size() - 1 - i);
            break;
        }
        case 'F':
        {
            if (15 > base - 1) return -1;
            n += 15 * pow(base, st.size() - 1 - i);
            break;
        }
        }

        default:
            return -1; // отрицательное число возвращаю, если есть ошибка
            break;
        }
    }
    return n;
}
// принимает число в десятичной и переводит в произвольное основание
string transfer(int dec,int base)
{
    string res = "";
    while (dec >= base)
    {
        int rest = dec % base;
        switch (rest)
        {
        case 10: {
            res += "A";
            break;
        }
        case 11: {
            res += "B";
            break;
        }
        case 12: {
            res += "C";
            break;
        }
        case 13: {
            res += "D";
            break;
        }
        case 14: {
            res += "E";
            break;
        }
        case 15: {
            res += "F";
            break;
        }
        default:
            res += to_string(rest);
            break;
        }
        dec /= base;
    }
    switch (dec % base)
    {
    case 10: {
        res += "A";
        break;
    }
    case 11: {
        res += "B";
        break;
    }
    case 12: {
        res += "C";
        break;
    }
    case 13: {
        res += "D";
        break;
    }
    case 14: {
        res += "E";
        break;
    }
    case 15: {
        res += "F";
        break;
    }
    default:
        res += to_string(dec % base);
        break;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string n; // исходная система счисления
    int finite, init; // конечная и начальная системы счисления
    setlocale(LC_ALL, "Ru");
    cout << "Введите исходную и конечную системы счисления, а также число в исходной системе счилсления: ";
    cin >> init >> finite >> n;
    int dc = dec(n, init);// число в десятичной
    if (finite < 2 || init < 2) cout << "Ошибка - системы счисления с таким основанием не существует!";
    else if (dc == -1) cout << "Ошибка - такое число не существует в заданной вами системе счисления!";
    else cout << "Результат = " << transfer(dc, finite);
}


