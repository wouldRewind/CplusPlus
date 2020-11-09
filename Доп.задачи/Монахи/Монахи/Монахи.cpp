// Монахи.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// через производный класс можно обращаться ко всем открытым членам базового класса

#include <iostream>
#include <string>
#include <vector>
using namespace std;


void dataInput(int* data, string message = "Введите данные")
{
	cout << message << endl;
	while (!(cin >> *data) || cin.get() != '\n')
	{
		cout << "Повторите попытку" << endl;
		cin.clear(); // сбрасывает все биты потока, тоесть поток становится "хорошим"
		cin.sync();//Удалим данные из буффера
		string str;
		getline(cin, str);
	}
}




class Monk {
private:
	Monk* sensei; // ссылка на учителя
	int id; // у каждого монаха свой уникальный номер. Сенсей - тоже монах :)
public:
	Monk( int id, Monk* sensei = NULL) // если в конструктор не передаётся указатель на сенсея, то создаваемый объект - сенсей
	{
		this->sensei = sensei;
		this->id = id;
	}
	int getId() { return this->id; }
	void setSensei(Monk* sensei = NULL) { this->sensei = sensei; };
	Monk* getSensei() { return this->sensei; }
};

// если находит монаха в династии монахов c данным id, возвраащет указатель на него
Monk *getMonk(vector <Monk*> *dynasty,int id = 0)
{
	// пробегаем по массиву монахов и ищем подходящего
	for (int i = 0; i < dynasty->size(); i++)
	{
		Monk* curMonk = (*dynasty)[i];
		if (curMonk->getId() == id) // если этот монах уже есть в списке и у него нет сенсея, то он чей-то сенсей
			return curMonk;
	}
			
		return NULL;
}

// пушит монаха в династию. Если монах уже в династии
void pushToDynasty(int id, int first, int second, int third, vector <Monk*>* dynasty)
{
	// если сенсея нет в массиве монахов, пушим его. Если он есть - возвращаем его и в качестве ставим его ученикам
	
	Monk* sensei = getMonk(dynasty, id);
	// если сенсея нет - пушим сенсея в массив династии и добавляем ссылку на него, чтобы потом добавить ученикам, если сенсей есть - имеем ссылку на него
	if (sensei == NULL) 
	{
		sensei = new Monk(id);
		dynasty->push_back(sensei);
	} 
	// если монах уже есть в династии, то он сенсей, а значит достаточно сеттером установить его сенсея в sensei

	if (first != 0)
	{
		Monk* student = getMonk(dynasty, first);

		if (student != NULL) // если ученик уже в династии, значит, он монах, и достаточно изменить его сенсея
			student->setSensei(sensei);
		else // если он не найден, пушим его
		{
			student = new Monk(first, sensei);
			dynasty->push_back(student);
		}

	}
	if (second != 0)
	{
		Monk* student = getMonk(dynasty, second);

		if (student != NULL) // если ученик уже в династии, значит, он монах, и достаточно изменить его сенсея
			student->setSensei(sensei);
		else // если он не найден, пушим его
		{
			student = new Monk(second, sensei);
			dynasty->push_back(student);
		}

	}
	if (third!= 0)
	{
		Monk* student = getMonk(dynasty, third); // получаю ссылку на монаха

		if (student != NULL) // если ученик уже в династии, значит, он монах, и достаточно изменить его сенсея
			student->setSensei(sensei);
		else // если он не найден, пушим его
		{
			student = new Monk(third, sensei);
			dynasty->push_back(student);
		}

	}


	
 

	
}

// принимает монаха и выводит всех его предков, вплоть до Святого Павла
void displayAllSenseis(Monk *monk)
{	
	Monk* sensei = monk->getSensei();
	if (sensei->getId() == 1) return; //дошли до Святого Павла
	cout << " " << sensei->getId();
	displayAllSenseis(sensei);
}
// первое задание
void firstTask(int monkId,vector <Monk*> *dynasty)
{
	Monk* monk = getMonk(dynasty, monkId);
	if (monk == NULL) cout << monkId << " - Не монах";
	else {
		cout << monkId << " - монах. Его учителя :";
		displayAllSenseis(monk);
	}
}
// второе задание
// возвращает id ближайшего общего сенсея
int commonSensei(Monk *firstSensei,Monk *secondSensei)
{
	int firstId = firstSensei->getId();
	int secondId = secondSensei->getId();
	// если у одного из сенсеев общий предок - Святой Павел, вернуть id общего павла
	if (firstId == 1 || secondId == 1) return 1;
	// если id равны, мы нашли общего предка
	if (firstId == secondId) return firstId;
	// иначе - копаем глубже
	commonSensei(firstSensei->getSensei(), secondSensei->getSensei());
	
}

void secondTask(int firstId, int secondId, vector <Monk*>* dynasty)
{
	// нахожу монахов в династии
	Monk* firstStudent = getMonk(dynasty, firstId);
	Monk* secondStudent = getMonk(dynasty, secondId);
	// если кто-то из них не монах - нет смысла искать дальше
	if (firstStudent == NULL || secondStudent == NULL) cout << "Кого-то из монахов не существует, а значит, я не могу найти общего предка!";
	else { // если оба монаха существуют, ищем общего предка 
		int commonSenseiId = commonSensei(firstStudent->getSensei(), secondStudent->getSensei());
		cout << firstId << " и " << secondId << " - оба монахи. Общий предок имеет номер " << commonSenseiId;
	}
}
int main()
{

	setlocale(LC_ALL, "rus");

	int monks; // сколько монахов будет описывать пользователь
	vector <Monk*> *dynasty = new vector <Monk*>; // "династия" всех монахов
	
	// ввод данных
	dataInput(&monks, "Введите, сколько монахов вы хотите описать : ");
	cout << "Введите исходные данные о монахе построчно: его номер и три номера его учеников(если у монаха нет ученика, пишите 0) : " << endl;
	for (int i = 0; i < monks; i++)
	{
		int id, // id учителя и номера учеников
			first,
			second,
			third;
		// просим ввод
		cin >> id >> first >> second >> third;
		pushToDynasty(id, first, second, third, dynasty);

	}

	cout << "Все номера сенсеев " << endl;
	for (int i = 0; i < dynasty->size(); i++)
		cout << (*dynasty)[i]->getId() << " ";

	int task;
	dataInput(&task, "Введите номер задания : ");
	switch (task)
	{
	case 1:
	{
		int monkId;
		dataInput(&monkId, "Вы выбрали задание 1! Введите номер монаха : ");
		firstTask(monkId,dynasty);
	}
	case 2: {
		int firstId, secondId;
		cout << "Вы выбрали задание 2! Введите номер первого и второхо монаха : ";
		cin >> firstId >> secondId;
		secondTask(firstId, secondId, dynasty);
	}
	default:
		break;
	}


	


	
}

