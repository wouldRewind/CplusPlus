#include <vector>
#include <string>
#include "‘айл(1).cpp"
using namespace std;
string findSuitableToys(vector <Toy> List, int maxPrice, int age) // принимает список игрушек, максимальную цену и возраст ребенка
{
	string total = "";
	string notFounded = "ѕодход€щиих игрушек не найдено!";
	for (int i = 0; i < List.size(); i++)
		if (List[i].price <= maxPrice && age >= List[i].minAge && age <= List[i].maxAge) total += List[i].name + ",";
	if (total == "") return notFounded;
	return total.substr(0, total.size() - 1) + "."; // убираю зап€тую в конце, добавл€ю точку
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

void suitableSimulteniously(vector <Toy> List, int firstAge, int secondAge) // подходит одновременно дет€м 4-ех и 10
{
	bool somethin = false;
	for (int i = 0; i < List.size(); i++)
	{
		Toy toy = List[i];
		if ((firstAge >= toy.minAge && firstAge <= toy.maxAge) && (secondAge >= toy.minAge && secondAge <= toy.maxAge))
		{
			somethin = true;
			cout << "ћожно купить " << toy.name << " за " << toy.price << "руб.";
			cout << endl;
		}
	}
	if (!somethin) cout << "  сожалению, купить ничего нельз€ :(";
}