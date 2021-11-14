//Разработать программу с использованием структуры в виде объединения, для работы с данными из таблицы, приведенной ниже.
//Реализовать функции ввода с клавиатуры, вывода на экран и поиска.

//Государство. Наименование, столица, численность населения, площадь, фамилия президента.Выбор государства по названию.

//Объединение – это поименованная совокупность данных разных типов, размещаемых в одной и той же области памяти,
//размер которой достаточен для хранения наибольшего элемента. Объединение подобно структуре,
//однако в каждый момент времени может использоваться только один из элементов объединения.

#include <iostream>
#include <string>
using namespace std;
const int n = 100;
union country {
	int population;
	int square;
};
struct Goverment {
	string name;
	string capital;
	string president;
	country un;
};
void table_in(Goverment* inf, int& t);
void show_table(Goverment* inf, int t);
void find_name(Goverment* inf, int t, string user_name);
int main()
{
	setlocale(LC_CTYPE, "Rus");
	system("color 5F");
	Goverment inf[n];
	int t = 0, lol;
	bool exit = false;
	table_in(inf, t);
	while (exit != true)
	{
		cout << "Menu" << endl;
		cout << "1-show the table\n2-Find the name\n3-Exit" << endl;
		cin >> lol;
		switch (lol)
		{
		case 1: {
			show_table(inf, t);

			break;
		}
		case 2: {
			cout << "Enter the user name" << endl;
			string user_name;
			cin >> user_name;
			find_name(inf, t, user_name);
			break;
		}
		case 3: {
			exit = true;
			break;
		}
		}

	}
	system("pause");
	return 0;
}
void table_in(Goverment* inf, int& t)
{
	int i = 0, act;
	do

	{
		cout << "Enter the name" << endl;
		cin >> inf[i].name;
		cout << "Enter the capital" << endl;
		cin >> inf[i].capital;
		cout << "Enter the population" << endl;
		cin >> inf[i].un.population;
		cout << "Enter the president" << endl;
		cin >> inf[i].president;
		cout << "Enter the square" << endl;
		cin >> inf[i].un.square;
		i++;
		t = i;
		cout << "if you want to continue enter 1 else 0" << endl;
		cin >> act;

	} while (act == 1);
}
void show_table(Goverment* inf, int t) {
	cout << "Name\t\tCapital\t\tPopulation\tPresident\t\tSquare" << endl;
	for (int i = 0; i < t; i++)
	{
		cout << inf[i].name << "\t\t";
		cout << inf[i].capital << "\t\t";
		cout << inf[i].un.population << "\t\t";
		cout << inf[i].president << "\t\t";
		cout << inf[i].un.square << endl;

	}
}
void find_name(Goverment* inf, int t, string user_name) {
	cout << "Name\t\tCapital\t\tPopulation\tPresident\t\tSquare" << endl;
	for (int i = 0; i < t; i++)
	{
		if (user_name == inf[i].name)
		{
			cout << inf[i].name << "\t\t";
			cout << inf[i].capital << "\t\t";
			cout << inf[i].un.population << "\t";
			cout << inf[i].president << "\t\t";
			cout << inf[i].un.square << endl;
		}
	}
}
