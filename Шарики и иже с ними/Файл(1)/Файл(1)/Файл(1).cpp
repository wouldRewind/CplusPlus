// Файл(1).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "stringSplitter.h" // кастомная библиотека

using namespace std;
// разделитель
const char delimiter = '#';

// удобное именование полей
enum ToyFields
{
	Name = 0,
	Price,
	MinAge,
	MaxAge
};





struct Toy {
public:
	string name;
	int  price, minAge, maxAge;
	// констурктор, принимающий массив строк, строки - параметры игрушки: название, цена, нижняя граница, верхняя граница
	Toy(string fields[])
	{
		this->name = fields[Name];
		// atoi() - преобразование массива чаров в число, c_str() переводит строку в массив чаров
		this->price = atoi(fields[Price].c_str());
		this->minAge = atoi(fields[MinAge].c_str());
		this->maxAge = atoi(fields[MaxAge].c_str());
	}
};

string findSuitableToys(vector <Toy> List, int maxPrice,int age) // принимает список игрушек, максимальную цену и возраст ребенка
{
	string total = "";
	string notFounded = "Подходящиих игрушек не найдено!";
	for (int i = 0; i < List.size(); i++)
		if (List[i].price <= maxPrice && age >= List[i].minAge && age <= List[i].maxAge) total += List[i].name + ",";
	if (total == "") return notFounded;
	return total.substr(0, total.size() - 1) + "."; // убираю запятую в конце, добавляю точку
}
int mostExpensive(vector <Toy> List) // находит самую дорогую игрушку
{
	int maxPrice = List[0].price;
	for (int i = 0; i < List.size() - 1; i++)
	{
		if (List[i].price < List[i + 1].price) maxPrice = List[i + 1].price;
	}
	return maxPrice;
}

void suitableSimulteniously(vector <Toy> List,int firstAge,int secondAge) // подходит одновременно детям 4-ех и 10
{
	bool somethin = false;
	for (int i = 0; i < List.size(); i++)
	{
		Toy toy = List[i];
		if ((firstAge >= toy.minAge && firstAge <= toy.maxAge) && (secondAge >= toy.minAge && secondAge <= toy.maxAge))
		{
			somethin = true;
			cout << "Можно купить "  << toy.name << " за " << toy.price <<"руб.";
			cout << endl;
		}
	}
	if (!somethin) cout << "К сожалению, купить ничего нельзя :(";
}

// 1.findSuitableToys - функция, находящая игрушку меньше заданной стоимости для ребенка определенного возраста
// 2. mostExpensive - функция, находящая самую дорогую игрушку
// 3. suitableSimulteniously - функция, выводящая названия и цену игрушек, подходящих детям N-го и K-го возраста одновременно
// 4. splitByDelimiter - функция, разбивающая строку по разделителю
// 5. delimitersInString - функция, возвращающая числл разделителей в строке






int main()
{
	
	setlocale(LC_ALL, "RU"); // русские - вперед!
	ifstream file("d:\\1\\Файл(1).txt"); // подключаю файл

	vector <Toy> List; // список всех игрушек
	vector <int> nums;

;	while (!file.eof())
		{
		string st; // строка "игрушки"
		getline(file, st); // получаю "игрушку"
		Toy toy(splitByDelimiter(st, delimiter)); 	// создаю игрушку Toy, в конструктор передаю массив строк
		List.push_back(toy); // пушу игрушку в список игрушек
		}


	// а)
//cout << "-----а)" << endl;

cout << "Вам подойдут следующие игрушки : " << findSuitableToys(List, 100,4) << endl;
	// б)
//cout << "-----б)" << endl;
cout << "Самая дорогая игрушка в списске стоит " << mostExpensive(List) << " руб." << endl;
	// в

//cout << "-----в)" << endl;
suitableSimulteniously(List, 4, 10);



cout << endl;

string str = "545";
cout << atoi(str.c_str());



}
