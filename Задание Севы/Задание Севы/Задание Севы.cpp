// Задание Севы.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Person {
private:
    string birthday;
    string zodiac;
    string username;
public:
    Person(string username,string zodiac,string birthday)
    {
        // инициализирую поля класса
        this->birthday = birthday;
        this->username = username;
        this->zodiac = zodiac;
    }
    int getMonth() { return stoi(this->birthday.substr(3, 2));}
    string getUsername() { return this->username; }
};


// просит число пользователей, их данные. Возвращает массив пользователей.
vector <Person> personsList()
{
    vector <Person> persons; // массив объектов всех людей
    string personsCount; // число людей задаёт пользователь
    cout << "Введите количество людей : ";
    getline(cin, personsCount);
    // заполнение
    for (int i = 0; i < stoi(personsCount); i++)
    {
        string username, birthday, zodiac;
        cout << "Введите имя и фамилию пользователя : ";
        getline(cin, username);
        cout << "Введите дату рождения : ";
        getline(cin, birthday);
        cout << "Введите знак зодиака : ";
        getline(cin, zodiac);
        // создаю пользователя и пушу в массив
        Person person(username, zodiac, birthday);
        persons.push_back(person);

        cout << "-----------------" << endl;
        cout << "-----------------" << endl;
    }
    return persons;
}

// выводит пользователей, родившихся в кокретный месяц
// принимает массив пользователь и число месяца
void displayUsers(vector <Person> humans, int month)
{
    setlocale(LC_ALL,"rus");
    cout << "Вывожу список людей, родившихся в " << month << "-ом месяце : " << endl;
    for (int i = 0; i < humans.size(); i++)  
        if (humans[i].getMonth() == month) 
            cout << humans[i].getUsername() << endl;
    
}


int main()
{
    std::system("chcp 1251");
    //vector <Person> humans = personsList();

    int month = 6;
    displayUsers(personsList(), 6); // отображает пользователей, родившихся в 6-ом месяце
   
}


