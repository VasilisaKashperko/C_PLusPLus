//В соответствии со своим вариантом разработать программу с использованием односвязного списка по данным, представленным в таблице ниже. 
//Программа должна содержать меню с пунктами : добавление элемента, удаление элемента, поиск элемента, вывод списка в консольное окно, запись списка в файл, считывание списка из файла.

//Создать список, содержащий элементы целого типа. Найти сумму отрицательных двухзначных элементов или выдать сообщение, что таких элементов нет.

//Список представляет собой линейную последовательность переменных, каждая из которых связана указателями со своими соседями.
//Списки бывают односвязные (каждый элемент имеет указатель на следующий); двусвязные (каждый элемент имеет указатель на следующий и на предыдущий);
//двусвязные циклические (первый и последний элементы ссылаются друг на друга).

#include <iostream>
#include <fstream>
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
	system("color 5F");
	Item* p = 0;//указатель на начало списка
	int molom, n;
	bool exit = false;
	while (exit != true)
	{
		cout << "Menu" << endl;
		cout << "1-Console\n2-add the element\n3-delete the element\n4-find the element\n5-write in file\n6-read from file\n7-sum\n8-exit\n";
		cin >> molom;

		switch (molom)
		{
		case 1:
		{
			console(p); break;
		}
		case 2: {
			cout << "Add the element:" << endl;
			cin >> n;//вводим значение, которое хотим удалить
			adding(p, n); break;
		}
		case 3: {
			cout << "Delete the element" << endl;
			cin >> n;
			del(p, n);
			console(p); break;
		}
		case 4: {
			cout << "Find" << endl;
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
		cout << "List is empty" << endl;
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
		cout << "Not adding" << endl;
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
		if (current != NULL)//если след не равно концу
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
		cout << "Find the element " << n << "which meets " << k << "times" << endl;
	}
	else {
		cout << "This element doesn't meets" << endl;
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
		cout << "List is empty" << endl;
	}
	else {
		while (p != NULL)
		{
			if (p->number < 0 && p->number<-9 && p->number>-100)
				sum = sum + (p->number);
			p = p->next;
		}
		cout << "The sum of numbers<0: " << sum << endl;
	}
}