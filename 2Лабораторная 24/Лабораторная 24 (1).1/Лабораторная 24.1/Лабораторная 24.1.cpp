// Создать проект из нескольких файлов, демонстрирующий работу с очередью. В соответствии со своим вариантом выполнить зада-ние из таблицы, представленной ниже. 
//Разработать меню и реализовать все операции с очередью через функции.

/*Создать очередь для массива целых (положительных и отрицательных) 
чисел и функции для ввода, вывода и уда-ления элементов очереди. 
При вводе чисел в очередь помещать только отрицательные элементы. 
Найти минималь-ный и максимальный элемент очереди. 
Вывести все элементы очереди и посчитать их количество.*/

//Очередь - одномерная структура данных, для которых загрузка или извлечение элементов осуществляется 
//с помощью указателей начала извлечения (head) и конца (tail) очереди в соответствии с правилом 
//FIFO ("first-in, first-out" - "первым введен, первым выведен"), т. е. включение производится с одного, а исключение – с другого конца.

#include <iostream>
#include "MyQueue.h"
using namespace std;
int main() {
	system("color 5F");
	Queue* queue = create();
	int lol, a, t;
	bool exit = false;
	cout << "menu" << endl;
	while (exit != true)
	{
		cout << "1-Add the element\n2-Take the element from queue\n3-Print the queue\n4-Clear the queue\n5-My task\n6-Exit\n";
		cin >> lol;
		switch (lol) {
		case 1: {
			cout << "Enter the element" << endl;
			cin >> a;
			adding(queue, a);
			break;
		}
		case 2: {
			cout << "The element which was taken is " << del(queue) << endl;
			break;
		}
		case 3: {
			cout << "Print the all queue:" << endl;
			allqueue(queue);
			break;
			cout << endl;
			break;
		}
		case 4: {t = clear(queue);
			if (t == 1)
				cout << "The queue is clear";
			else if (t == 0)
				cout << "It can't be cleaned";
			break;
		}
		case 5: {
			cout << "max " << max(queue) << "\n";
			cout << "min " << min(queue) << "\n";
			cout << "length " << length(queue) << "\n";
			break;
		}
		case 6: { exit = true; break; }
		}
	}
	system("pause");
	return 0;
}
