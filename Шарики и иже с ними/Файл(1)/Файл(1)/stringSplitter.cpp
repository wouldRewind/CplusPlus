#include <string>
using namespace std;

int delimitersInString(string st, char delimiter) // ��������� ������ � �����������
{
	int count = 0; // ���������� ������������
	for (int i = 0; i < st.size(); i++)
		if (st[i] == delimiter) count++;
	return count;
}

string* splitByDelimiter(string st, char delimiter) // �������� ������ � �����������
{
	string* fields = new string[delimitersInString(st, delimiter) + 10]; // ���������� ����� - ������ �� �������
	int substringLength = 0; // ������ ���������, ��������� ��� ���������� �����������
	int pos = 0; // ������, � �������� "����������" ���������
	int fieldsIndex = 0; // ������ �������� ���� - ������������� ��� "���������" ���������
	for (int i = 0; i < st.size(); i++)
	{
		if (st[i] != delimiter) substringLength++;
		else {
			fields[fieldsIndex] = st.substr(pos, substringLength); // ����� �����������
			fieldsIndex++;
			pos = i + 1; // ������� ������ ������
			substringLength = 0;
		}
	}
	return fields;
}