#include <string>
using namespace std;

int delimitersInString(string st, char delimiter) // принимает строку и разделитель
{
	int count = 0; // количество разделителей
	for (int i = 0; i < st.size(); i++)
		if (st[i] == delimiter) count++;
	return count;
}

string* splitByDelimiter(string st, char delimiter) // принимаю строку и разделитель
{
	string* fields = new string[delimitersInString(st, delimiter) + 10]; // количество полей - данных об игрушке
	int substringLength = 0; // длинна подстроки, обнулется при нахождении разделителя
	int pos = 0; // индекс, с которого "вырезается" подстрока
	int fieldsIndex = 0; // индекс элемента поля - увеличивается при "вырезании" подстроки
	for (int i = 0; i < st.size(); i++)
	{
		if (st[i] != delimiter) substringLength++;
		else {
			fields[fieldsIndex] = st.substr(pos, substringLength); // нашёл разделитель
			fieldsIndex++;
			pos = i + 1; // начинаю другую строку
			substringLength = 0;
		}
	}
	return fields;
}