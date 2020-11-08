# include <iostream>     /
# include <fstream> 
# include <string>
using namespace std;

void main()
{
    setlocale(LC_ALL, "Russian");
    string st;
    ifstream file("d:\\1\\Копирование.txt"); // связываюсь с файлом
    
    while (!file.eof()) // пока не достигнут конец файла
    {

        getline(file, st); // получаю конец строку
        if (st == "") continue; // пустые строки игнорируются
        cout << st << '\n'; //  
    }
    cout << "-----" << endl;
    cout << ()
   
}