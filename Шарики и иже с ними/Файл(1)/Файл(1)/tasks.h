#include <vector>
#include <string>

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
	// конструктор по умолчанию
	Toy()
	{

	}
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
#pragma once
void suitableSimulteniously(vector <Toy> List, int firstAge, int secondAge);
int mostExpensive(vector <Toy> List);
string findSuitableToys(vector <Toy> List, int maxPrice, int age);