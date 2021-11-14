//Личная библиотека. Автор книги, название, издательство,
//раздел библиотеки (специальная литература, хобби,
//домашнее хозяйство, беллетристика и т. д.), происхождение
//(покупка, кража, подарок) и наличие книги в данный момент. Выбор книг по автору.

#include <iostream>
using namespace std;
void input(int size);
void output();
void find(char lastname[]);

typedef struct books
{
	char author[20];
	char name[20];
	char made[20];
	char separate[25];
	char spec[20];
	char find[20];
} stud;

int number; FILE* f; errno_t err;

int main()
{
	system("color 0B");
	setlocale(LC_CTYPE, "russian");
	int choice; char surname[20];
	do
	{
		cout << "1. Ввод данных с клавиатуры и запись в файл\n";
		cout << "2. Вывод данных из файла\n";
		cout << "3. Поиск по фамилии\n";
		cout << "0. Выход из программы\n\n";
		cout << "Введите номер операции: ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите количество книг, данные о которых хотите ввести: ";
			cin >> number;
			input(number);
			cout << endl; break;
		case 2: output(); break;
		case 3: {  cout << "Введите автора книги: ";
			cin >> surname;
			find(surname); break;
		}
		case 0: exit(0);  break;
		}
	} while (choice != 0);
}

void input(int size)
{
	stud buf = { ' ', ' ' };
	if (!fopen_s(&f, "C:\\Users\\Vasilisa\\Desktop\\lab20.txt", "ab"))
	{
		for (int p = 0; p < size; p++)
		{
			cout << "Автор книги: "; 	cin >> buf.author;
			cout << "Название: "; 	cin >> buf.name;
			cout << "Издательство: "; 	cin >> buf.made;
			cout << "Раздел библиотеки (специальная литература, хобби, домашнее хозяйство, беллетристика и т.д.): "; 	cin >> buf.separate;
			cout << "Происхождение (покупка, кража, подарок): "; 	cin >> buf.spec;
			cout << "Наличие книги в данный момент: "; 	cin >> buf.find;
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
	stud buf;
	if (!fopen_s(&f, "C:\\Users\\Vasilisa\\Desktop\\lab20.txt", "rb"))
	{
		cout << "\nАвтор книги       Название     Издательство     Раздел библиотеки     Происхождение     Наличие книги    \n";
		fread(&buf, sizeof(buf), 1, f);
		while (!feof(f))
		{
			cout << buf.author << "\t   " << buf.name << "\t  " << buf.made << "\t \t       " << buf.separate << "\t \t  " << buf.spec << "\t   " << buf.find << "\t   " << "\t   " << endl;
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

void find(char lastname[20])
{
	bool flag = false;  stud buf;
	if (!fopen_s(&f, "C:\\Users\\Vasilisa\\Desktop\\lab20.txt", "rb"))
	{
		while (!feof(f))
		{
			fread(&buf, sizeof(buf), 1, f);
			if (strcmp(lastname, buf.author) == 0)   // сравнение строк
			{
				cout << "\nАвтор книги       Название     Издательство     Раздел библиотеки     Происхождение     Наличие книги    \n";
				cout << buf.author << "\t \t  \t   \t     " << buf.name << "\t  " << buf.made << "\t \t       " << buf.separate << "\t \t  " << buf.spec << "\t   " << buf.find << "\t   " << endl;
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