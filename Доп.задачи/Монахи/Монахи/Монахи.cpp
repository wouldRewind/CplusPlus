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
	void setSensei(Monk* sensei) { this->sensei = sensei; };
};

// если находит монаха в династии монахов, возвраащет указатель на него
void getMonk(vector <Monk*> *dynasty,int id = 0)
{
	//(*dynasty)[i]->getId() - обращение к узателю на вектор через (*имя)[i]
}

void pushToDynasty(int id, int first, int second, int third, vector <Monk>* dynasty)
{

}



int main()
{
	setlocale(LC_ALL, "rus");

	int monks; // сколько монахов будет описывать пользователь
	vector <Monk*> *dynasty = new vector <Monk*>; // "династия" всех монахов

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

		// по условию считаю, что введенные номера не выходят за границы условия
		// создаю сенсея - ссылка на сенсея у него отсутствует
		Monk* sensei = new Monk(id);
		dynasty->push_back(sensei);

		// создаю его учеников


		// по условию у каждого монаха ровно 1 учитель, поэтому монаха с id в династию можно не добавлять

	}

	
}

