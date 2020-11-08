// Обработка текстовых файлов.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
using namespace std;

int stringFrequency(string st,char symbol)
{
	int frequency = 0;
	for (int i = 0; i < st.size(); i++)
	{
		if (st[i] == symbol) frequency++;
	}
	return frequency;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	ifstream file("d:\\1\\Обработка текстовых файлов.txt");
	if (file.is_open())
	{
		char sym;
		int allFileFrequency = 0;
		cout << "Введите, какой символ в текстовом файле вы хотите найти: " << endl;
		cin >> sym;
		{
			while (!file.eof())
			{
				string st;
				getline(file, st);
				allFileFrequency += stringFrequency(st, sym);
			}
			cout << "Ваш символ встретился " << allFileFrequency << " раз";
		}
	}
}

// почему-то не чита