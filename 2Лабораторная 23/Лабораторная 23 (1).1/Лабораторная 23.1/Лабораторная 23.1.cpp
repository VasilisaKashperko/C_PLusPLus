//Стеком называется одномерная структура данных, включение и исключение элементов
//которого осуществляется с помощью указателя стека в соответствии с правилом
//"последним введен, первым выведен" (last - in, first - out LIFO). Стек Стек может быть реализован статически (на основе массива) и динамически (на основе списка).

//В соответствии со своим вариантом разработать программу с использованием односвязного списка по данным,
//представленным в таблице ниже. Программа должна содержать меню с пунктами : добавление элемента,
//удаление элемента, поиск элемента, вывод списка в консольное окно, запись списка в файл, считывание списка из файла.

//Создать список, содержащий элементы целого типа. Найти сумму отрицательных двухзначных элементов или выдать сообщение, что таких элементов нет. 

#include <iostream>
#include <fstream>
#include <windows.h>
#include <tchar.h>

using namespace std;

	struct Item {
		int number;
		Item* next;
	};

	void console(Item*& p);
	void adding(Item*&, int n);
	int del(Item*&, int n);
	void search(Item*&, int n);
	void write_in_file(Item*&);
	void read_from_file(Item*&);
	void sum(Item*&);

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Получить консоль
	CONSOLE_FONT_INFOEX fontInfo;
	GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo); // Получить текущий шрифт
	// Поменять какие-то параметры
	wcscpy_s(fontInfo.FaceName, L"Monotype Corsiva");// Имя
	fontInfo.dwFontSize.X = 10;// Размер (в логических единицах)
	SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo); // Установить новый
	setlocale(LC_CTYPE, "Rus");
	system("color 5F");

	Item* p = 0;//указатель на начало списка
	int choice, n;
	bool exit = false;

	while (exit != true)
	{
		cout << "Меню" << endl;
		cout << "\n1-Консоль\n2-Добавить элемент\n3-Удалить элемент\n4-Найти элемент\n5-Запись в файл\n6-Чтение из файла\n7-Сумма\n8-Выход\n\n";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			console(p); break;
		}
		case 2: {
			cout << "Добавить элемент:" << endl;
			cin >> n; //вводим значение, которое хотим удалить
			adding(p, n); break;
		}
		case 3: {
			cout << "Удалить элемент" << endl;
			cin >> n;
			del(p, n);
			console(p); break;
		}
		case 4: {
			cout << "Найти" << endl;
			cin >> n;
			search(p, n);
			break;
		}
		case 5: {
			write_in_file(p);
			console(p); break;
		}
		case 6: {
			read_from_file(p); break;
		}
		case 7: {
			sum(p); break;
		}
		case 8: {
			exit = true; break;
		}
		}
	}
	system("pause");
	return 0;
}

void console(Item*& p) {
	Item* head = p;//заголовок списка

	if (p == NULL)
	{
		cout << "Список пуст." << endl;
	}

	else {
		while (p != NULL) {//пока не конец списка
			cout << "*" << p->number << endl;//выводим элемент списка
			p = p->next;//переход к след элементу
		}
		cout << "NULL" << endl;//вывод, что список закончился
	}

	p = head;//в переменную посылаем 1 элемент
}

void adding(Item*& p, int n) {

	Item* newP = new Item;//создаём новый элемент типа структуры

	if (newP != NULL)//если новый элемент не равен концу списка
	{
		newP->number = n;//делаем новый элемент на 1 место
		newP->next = p;//следующий элемент, который был предыдущим
		p = newP;//новый элемент становится началом
	}

	else
		cout << "Не добавлено." << endl;
}

int del(Item*& p, int n) {
	Item* previous, * current, * temp;

	if (n == p->number)//если введнное значение совпало с элементом списка
	{
		temp = p;//посылаем в переменную это значение
		p = p->next;//в значение переменной посылаем значение след перемеенной
		delete temp;//удаляем элемент списка
		return n;//возвращаем значение
	}

	else {
		previous = p;//посылаем значение в переменную
		current = p->next;//посылаем в переменную след значение
		while (current != NULL && current->number != n)//пока следующее не равноконцу списка и пока значение не равно введённому значению
		{
			previous = current;//в предыдущее посылаем след
			current = current->next;
		}
		if (current != NULL)//еси след не равно концу
		{
			temp = current;
			previous->next = current->next;
			delete (temp);
		}
	}
}

void search(Item*& p, int n) {
	Item* head = p;
	int k = 0;
	while (p != NULL) {
		if (n == p->number)//если введённое значение совпало с элементом списка
			k++;
		p = p->next;//посылаем следующий элемент
	}
	p = head;
	if (k != 0)
	{
		cout << "Найден элемент " << n << ", который встречается " << k << "раз" << endl;
	}
	else {
		cout << "Этот элемент нигде не встречается." << endl;
	}
}

void write_in_file(Item*& p) {
	ofstream fout("File1.txt");
	while (p) {

		fout << p->number << endl;//запись в файл
		p = p->next;
	}
	fout.close();
}

void read_from_file(Item*& p) {
	ifstream fin;
	fin.open("File1.txt");
	while (fin.eof())


	{
		fin >> p->number;
		p = p->next;
	}
	fin.close();
}

void sum(Item*& p) {
	int sum = 0;
	if (p == NULL)
	{
		cout << "Список пуст" << endl;
	}
	else {
		while (p != NULL)
		{
			if (p->number < 0 && p->number<-9 && p->number>-100)
				sum = sum + (p->number);
			p = p->next;
		}
		cout << "Сумма чисел меньше 0: " << sum << endl;
	}
}
