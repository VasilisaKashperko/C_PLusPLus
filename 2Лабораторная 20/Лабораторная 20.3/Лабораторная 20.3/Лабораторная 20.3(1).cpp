#include <iostream>
using namespace std;
void input(int size);
void output();
void finds(char lastName[]);
void findh(int h, int m);
typedef struct Train
{
	char city[16];
	char num[16];
	int dateh;
	int datem;
} STUD;
int number, adateh = 0, adatem = 0; FILE *f; errno_t err;

int main()
{	
	system("color 02");
	setlocale(LC_ALL, "Russian");
	int choice; char city[16];
	do
	{
		cout << "\n1. Ввод данных с клавиатуры и запись в файл\n";
		cout << "2. Вывод данных из файла\n";
		cout << "3. Поиск по пункту назначения\n";
		cout << "4. Поиск позже определенного времени отправления\n";
		cout << "0. Выход из программы\n\n";
		cout << "Введите номер операции: ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите количество рейсов, информацию о которых вы хотите ввести: ";
			cin >> number;
			input(number);
			cout << endl; break;
		case 2: output(); break;
		case 3: {  cout << "Введите пункт назначения: ";
			cin >> city;
			finds(city); break;
		}
		case 4: { cout << "Введите время отправления (часы, 0-23)";
			cin >> adateh;
			cout << "Введите время отправления (минуты, 0-59)";
			cin >> adatem;
			findh(adateh, adatem);
			break;
		}
		case 0: exit(0);  break;
		}
	} while (choice != 0);
}

void input(int size)
{
	STUD buf = { ' ', ' ' };
	if (!fopen_s(&f, "C:\\Users\\Vasilisa\\Desktop\\lab203.txt", "ab"))
	{
		for (int p = 0; p < size; p++)
		{
			cout << "Пункт назначения: "; 	cin >> buf.city;
			cout << "Номер рейса: "; 	cin >> buf.num;
			cout << "Время отправления (часы): "; 	cin >> buf.dateh;
			cout << "Время отправления (минуты): "; 	cin >> buf.datem;
			cout << endl;
			fwrite(&buf, sizeof(buf), 1, f);
		}
		fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
}

void output()
{
	STUD buf;
	if (!fopen_s(&f, "C:\\Users\\Vasilisa\\Desktop\\lab203.txt", "rb"))
	{
		cout << "\nПункт назначения    Номер рейса    Время отправления\n";
		fread(&buf, sizeof(buf), 1, f);
		while (!feof(f))
		{
			cout << buf.city << "\t \t \t   " << buf.num << "\t  \t  " << buf.dateh << ":" << buf.datem << endl;
			fread(&buf, sizeof(buf), 1, f);
		}
		cout << endl;
		fclose(f);
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}

void finds(char lastName[16])
{
	bool flag = false;  STUD buf;
	if (!fopen_s(&f, "C:\\Users\\Vasilisa\\Desktop\\lab203.txt", "rb"))
	{
		while (!feof(f))
		{
			fread(&buf, sizeof(buf), 1, f);
			if (strcmp(lastName, buf.city) == 0)  
			{
				cout << "\nПункт назначения    Номер рейса    Время отправления\n";
				cout << buf.city << "\t \t \t  " << buf.num << "\t  \t  " << buf.dateh << ":" << buf.datem << endl;
				flag = true; break;
			}
		}
		fclose(f);
		if (!flag) cout << "Ничего не найдено\n";
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}

void findh(int h, int m) //функция, которая находит времечко
{
	bool flag = false;  STUD buf;
	if (!fopen_s(&f, "C:\\Users\\Vasilisa\\Desktop\\lab203.txt", "rb"))
	{
		while (!feof(f))
		{
			fread(&buf, sizeof(buf), 1, f);
			if ((buf.dateh > h) || (h == buf.dateh && buf.datem > m))
			{
				cout << "\nПункт назначения    Номер рейса    Время отправления\n";
				cout << buf.city << "\t \t  \t  " << buf.num << "\t  \t  " << buf.dateh << ":" << buf.datem << endl;
				flag = true; break;
			}
		}
		fclose(f);
		if (!flag) cout << "Ничего не найдено\n";
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}