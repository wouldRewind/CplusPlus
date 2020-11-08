// ООП.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class Person {

public:
	int age;
	void setAge(int age)
	{
		this->age = age;
	}
	Person(int age)
	{
		this->age = age;
	}
	Person()
	{

	}

};


int main()
{
	Person person;
	
}
