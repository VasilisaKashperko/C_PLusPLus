//Разработать программу с использованием перечислений и битовых полей для работы с данными из таблицы, приведенной ниже.
//Реализовать функции ввода с клавиатуры, вывода на экран, удаления, поиска элементов. Интерфейс пользователя осуществить в виде меню.

//Студенты.Ф.И.О., дата поступления, специальность, группа, факультет, средний балл.Выбор по среднему баллу.
//Дату поступления реализовать с помощью битового поля, факультет с помощью перечисления.

//Перечисления используются в тех случаях, когда данные можно представить в виде нумерованного списка.

//Элементом структуры может быть битовое поле, обеспечивающее доступ к отдельным битам памяти, 
//которые позволяют рационально использовать память с помощью хранения данных в минимально
//требуемом количестве битов.Элементы битового поля должны быть объявлены как тип int или unsigned.

#include <iostream>
#include <string>
using namespace std;
const int n = 100;


struct Date
{
	unsigned day : 5;
	unsigned month : 4;
	unsigned year : 5;
};

struct Student {
	string Last_name;
	string First_name;
	string Father_name;
	Date date_now;
	string spec;
	int group;
	int fac; // это поле для запоминания факультета
	double sr_ball;
};

enum Faculty {
	Poit = 1, designer, PMS, ISIT
};

void table_in(Student* A, int& t);
void find(Student* A, int t, double user_mark);

int main()
{
	setlocale(LC_CTYPE, "Rus");
	system("color 5F");
	int t = 0;
	Student A[n];
	bool exit = false;
	table_in(A, t);
	int k;//for menu
	while (exit != true)
	{
		cout << "Что вы хотите сделать?" << endl;
		cout << "Menu: " << endl;
		cout << "1-Show table" << endl;
		cout << "2-Delete the element" << endl;
		cout << "3-Find the average mark" << endl;
		cout << "4-Exit" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
		{
			cout << "Last Name\tName\tFather name\tDay\t\tSpec\tGroup\tBall" << endl;
			for (int i = 0; i < t; i++)
			{
				cout << A[i].Last_name << "\t\t";
				cout << A[i].First_name << "\t";
				cout << A[i].Father_name << "\t\t";
				cout << A[i].date_now.day << "." << A[i].date_now.month << "." << "20" << A[i].date_now.year << "\t";
				cout << A[i].spec << "\t";
				cout << A[i].group << "\t";
				switch (A[i].fac)
				{
				case Poit: cout << "POIT" << "\t"; break;
				case designer: cout << "DAIVI" << "\t"; break;
				case PMS: cout << "MOBILA" << "\t"; break;
				case ISIT: cout << "ISIT" << "\t"; break;
				}
				cout << A[i].sr_ball << endl;
			}
			break;
		}
		case 2:
		{
			string Last_name;
			cout << "Enter the Last name" << endl;
			cin >> Last_name;
			int ind;
			for (int i = 0; i < t; i++)
			{
				if (Last_name == A[i].Last_name)
				{
					ind = i;
					break;
				}
			}
			A[ind].Last_name = A[t - 1].Last_name;
			A[ind].First_name = A[t - 1].First_name;
			A[ind].Father_name = A[t - 1].Father_name;
			A[ind].date_now.day = A[t - 1].date_now.day;
			A[ind].date_now.month = A[t - 1].date_now.month;
			A[ind].date_now.year = A[t - 1].date_now.year;
			A[ind].spec = A[t - 1].spec;
			A[ind].group = A[t - 1].group;
			A[ind].sr_ball = A[t - 1].sr_ball;
			t--;

			break;
		}
		case 3: {
			cout << "Enter the average mark" << endl;
			double user_mark;
			cin >> user_mark;
			find(A, t, user_mark);
			break;
		}
		case 4: {
			exit = true;
			break;

		}
		}
	}


	system("pause");
	return 0;
}
void table_in(Student* A, int& t)
{
	int i = 0, act;
	do
	{
		cout << "Enter Last name" << endl;
		cin >> A[i].Last_name;
		cout << "Enter First name" << endl;
		cin >> A[i].First_name;
		cout << "Enter Father name" << endl;
		cin >> A[i].Father_name;

		int number;
		cout << "Enter day" << endl;
		cin >> number;
		A[i].date_now.day = number;
		cout << "Enter month" << endl;
		cin >> number;
		A[i].date_now.month = number;
		cout << "Enter year" << endl;
		cin >> number;
		A[i].date_now.year = number;
		cout << "Enter specialisation" << endl;
		cin >> A[i].spec;
		cout << "Enter the number of group" << endl;
		cin >> A[i].group;
		cout << "Enter the faculty" << endl;

		string fac;
		cin >> fac;
		if (fac == "Poit") {
			A[i].fac = Poit;
		}
		else if (fac == "Daivi")
		{
			A[i].fac = designer;
		}
		else if (fac == "Mobilki")
		{
			A[i].fac = PMS;
		}
		else if (fac == "Isit")
		{
			A[i].fac = ISIT;
		}
		cout << "Enter sr ball" << endl;
		cin >> A[i].sr_ball;
		i++;
		t = i;

		cout << "if you want to continue enter 1 else 0" << endl;
		cin >> act;
	}

	while (act == 1);

}
void find(Student* A, int t, double user_mark) {
	cout << "Last Name\tName\tFather name\tDay\t\tSpec\tGroup\tBall" << endl;
	for (int i = 0; i < t; i++)
	{

			cout << A[i].Last_name << "\t";
			cout << A[i].First_name << "\t";
			cout << A[i].Father_name << "\t";
			cout << A[i].date_now.day << "." << A[i].date_now.month << "." << "20" << A[i].date_now.year << "\t";
			cout << A[i].spec << "\t";
			cout << A[i].group << "\t";
			cout << A[i].fac << "\t";
			cout << A[i].sr_ball;


	}
}
