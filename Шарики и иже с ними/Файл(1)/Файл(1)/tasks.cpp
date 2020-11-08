
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

string findSuitableToys(vector <Toy> List, int maxPrice, int age) // принимает список игрушек, максимальную цену и возраст ребенка
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

void suitableSimulteniously(vector <Toy> List, int firstAge, int secondAge) // подходит одновременно детям 4-ех и 10
{
	bool somethin = false;
	for (int i = 0; i < List.size(); i++)
	{
		Toy toy = List[i];
		if ((firstAge >= toy.minAge && firstAge <= toy.maxAge) && (secondAge >= toy.minAge && secondAge <= toy.maxAge))
		{
			somethin = true;
			cout << "Можно купить " << toy.name << " за " << toy.price << "руб.";
			cout << endl;
		}
	}
	if (!somethin) cout << "К сожалению, купить ничего нельзя :(";
}