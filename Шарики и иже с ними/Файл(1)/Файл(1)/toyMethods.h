#pragma once
#include <string>
#include <vector>
#include "����(1).cpp"
using namespace std;

string findSuitableToys(vector <Toy> List, int maxPrice, int age); // ��������� ������ �������, ������������ ���� � ������� �������
int mostExpensive(vector <Toy> List); // ������� ����� ������� �������
void suitableSimulteniously(vector <Toy> List, int firstAge, int secondAge); // �������� ������������ ����� 4-�� � 10