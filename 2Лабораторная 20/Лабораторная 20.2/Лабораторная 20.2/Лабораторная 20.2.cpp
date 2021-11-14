#include <iostream>
using namespace std;
void input(int size);
void output();
void find(char lastName[]);

typedef struct Exams //Ключевое слово typedef позволяет программисту создать псевдоним для любого типа данных и использовать его вместо фактического имени типа
{
	char surname[16];
	char name[16];
	char secondname[16];
	char count[3];
	float mark;
} STUD;
int number, markplus = 0, markminus = 0; float per = 0; FILE *f; errno_t err;

int main()
{
	system("color 06");
	setlocale(LC_ALL, "Russian");
	int choice; char surname[16];
	do
	{
		cout << "1. Ввод данных с клавиатуры и запись в файл\n";
		cout << "2. Вывод данных из файла\n";
		cout << "3. Поиск по фамилии\n";
		cout << "4. Процент учащихся со средним баллом >=4.0\n";
		cout << "0. Выход из программы\n\n";
		cout << "Введите номер операции: ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите количество студентов, данные о которых хотите ввести: ";
			cin >> number;
			input(number);
			cout << endl; break;
		case 2: output(); break;
		case 3: {  cout << "Введите фамилию: ";
			cin >> surname;
			find(surname); break;
		}
		case 4: { per = ((float)markplus / (float)markminus) * 100;
			cout << "На данный момент процент учащихся со средним баллов >= 4 - " << per << "%." << endl;
			break;
		}
		case 0: exit(0);  break;
		}
	} while (choice != 0);
}

void input(int size)
{
	STUD buf = { ' ', ' ' };
	if (!fopen_s(&f, "C:\\Users\\Vasilisa\\Desktop\\lab202.txt", "ab"))
	{
		for (int p = 0; p < size; p++)
		{
			cout << "Фамилия: "; 	cin >> buf.surname;
			cout << "Имя: "; 	cin >> buf.name;
			cout << "Отчество: "; 	cin >> buf.secondname;
			cout << "Количество экзаменов: "; 	cin >> buf.count;
			cout << "Средний балл: "; 	cin >> buf.mark;
			cout << endl;
			if (buf.mark >= 4) { markplus++; }
			else { markminus++; };
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
	if (!fopen_s(&f, "C:\\Users\\Vasilisa\\Desktop\\lab202.txt", "rb"))
	{
		cout << "\nФамилия    Имя    Отчество    Количество экзаменов    Средний балл\n";
		fread(&buf, sizeof(buf), 1, f);
		while (!feof(f))
		{
			cout << buf.surname << "\t    " << buf.name << "\t  " << buf.secondname << "\t    " << buf.count << "\t \t       " << buf.mark << endl;
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

void find(char lastName[16])
{
	bool flag = false;  STUD buf;
	if (!fopen_s(&f, "C:\\Users\\Vasilisa\\Desktop\\lab202.txt", "rb"))
	{
		while (!feof(f))
		{
			fread(&buf, sizeof(buf), 1, f);
			if (strcmp(lastName, buf.surname) == 0)   //сравнение строк
			{
				cout << "\nФамилия    Имя    Отчество    Количество экзаменов    Средний балл\n";
				cout << buf.surname << "\t    " << buf.name << "\t  " << buf.secondname << "\t    " << buf.count << "\t \t   " << buf.mark << endl;
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