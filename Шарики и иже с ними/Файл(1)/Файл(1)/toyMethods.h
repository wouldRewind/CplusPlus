#pragma once
#include <string>
#include <vector>
#include "Файл(1).cpp"
using namespace std;

string findSuitableToys(vector <Toy> List, int maxPrice, int age); // принимает список игрушек, максимальную цену и возраст ребенка
int mostExpensive(vector <Toy> List); // находит самую дорогую игрушку
void suitableSimulteniously(vector <Toy> List, int firstAge, int secondAge); // подходит одновременно детям 4-ех и 10