#include <vector>
#include <string>
#include "����(1).cpp"
using namespace std;
string findSuitableToys(vector <Toy> List, int maxPrice, int age) // ��������� ������ �������, ������������ ���� � ������� �������
{
	string total = "";
	string notFounded = "����������� ������� �� �������!";
	for (int i = 0; i < List.size(); i++)
		if (List[i].price <= maxPrice && age >= List[i].minAge && age <= List[i].maxAge) total += List[i].name + ",";
	if (total == "") return notFounded;
	return total.substr(0, total.size() - 1) + "."; // ������ ������� � �����, �������� �����
}
int mostExpensive(vector <Toy> List) // ������� ����� ������� �������
{
	int maxPrice = List[0].price;
	for (int i = 0; i < List.size() - 1; i++)
	{
		if (List[i].price < List[i + 1].price) maxPrice = List[i + 1].price;
	}
	return maxPrice;
}

void suitableSimulteniously(vector <Toy> List, int firstAge, int secondAge) // �������� ������������ ����� 4-�� � 10
{
	bool somethin = false;
	for (int i = 0; i < List.size(); i++)
	{
		Toy toy = List[i];
		if ((firstAge >= toy.minAge && firstAge <= toy.maxAge) && (secondAge >= toy.minAge && secondAge <= toy.maxAge))
		{
			somethin = true;
			cout << "����� ������ " << toy.name << " �� " << toy.price << "���.";
			cout << endl;
		}
	}
	if (!somethin) cout << "� ���������, ������ ������ ������ :(";
}