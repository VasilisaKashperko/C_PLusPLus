#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

struct Node
{
	int numberOfWords;
	char word;
	string str;
	Node* next;
	Node* prev;

	Node()
	{
		this->numberOfWords = 0;
		this->word = '\0';
		this->str = "";
		this->next = this->prev = NULL;
	}
};


struct HashTable
{
	int currentSize;
	int size;
	Node* table;

	HashTable(int size)
	{
		this->size = size;
		this->currentSize = 0;
		this->table = new Node[size];
	}

	void Insert();
	int HashFunction(int hashKey);
	void PrintTable();
	void SearchNodes();
	void FillPercent();
};

int HashTable::HashFunction(int hashKey)
{
	double m = 5;
	double A = (sqrt(m) - 1) / 2;
	double z = A * hashKey;
	z -= (int)z;

	return (int)(this->size * z);
}
//--------------------------------------------------------------------
void HashTable::Insert()
{
	int countOfWords = 0;
	int counter = 0;
	string str;
	do
	{
		cout << "Введите численность населения" << endl;
		cin >> countOfWords;
		if (countOfWords > this->size)
			cout << "Количество букв превышает размер таблицы! Попробуйте еще раз." << endl;

	} while (countOfWords > this->size);
	cout << endl;

	cout << "Введите название города: ", cin >> str;

	if (this->currentSize < this->size)
	{
		while (counter != countOfWords)
		{

			Node* newElem = new Node;
			Node* temp;
			newElem->str = str;
			cout << "Введите имена жильцов: ", cin >> newElem->word;
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] == newElem->word)
					newElem->numberOfWords++;
			}
			int position = HashFunction(newElem->numberOfWords);
			temp = this->table[position].next;

			if (!temp)
			{
				this->table[position].next = newElem;
				this->table[position].next->prev = &this->table[position];
				this->currentSize++;
				counter++;
			}
			else
				while (true)
				{
					if (!temp->next)
					{
						temp->next = newElem;
						temp->next->prev = temp;

						this->currentSize++;
						counter++;
						break;
					}
					else
						temp = temp->next;
				}
		}
	}
	else
		cout << "Хэш-таблица заполнена." << endl;

}
//--------------------------------------------------------------------
void HashTable::PrintTable()
{
	Node* temp;

	cout << "\n-----------------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < this->size; i++)
	{
		temp = this->table[i].next;

		cout << " Цепочка №" << i << ":\n";
		if (!this->table[i].next)
		{
			cout << "пусто\n\n";
			continue;
		}

		while (temp)
		{
			cout << "|Жилец: " << temp->word << "\t\tГород: " << temp->str << "|\n";
			temp = temp->next;
		}
		cout << endl;

	}
	cout << "\n-----------------------------------------------------------------------------------------------------------\n";
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void HashTable::SearchNodes()
{
	char tempWord;
	bool flag = false;
	cout << "Введите жильца, которого хотите найти: ", cin >> tempWord;
	Node* temp;
	int i = 0;
	temp = this->table[i].next;
	for (i; i < this->size; i++)
	{
		while (temp)
		{
			if (temp->word == tempWord)
			{
				cout << "Жилец присутствует в таблице" << endl;
				cout << "|Жилец: " << temp->word << "\t\tГород: " << temp->str << "|\n";
				flag = true;
				break;
			}
			temp = temp->next;
		}

		temp = this->table[i].next;
	}

	if (!flag)
		cout << "Жилец не найден" << endl;

}
//--------------------------------------------------------------------
void HashTable::FillPercent()
{
	cout << "\nНа данный момент таблица заполнена на " << int(float(this->currentSize) / float(this->size) * 100) << "%.\n";
}

void main()
{
	setlocale(LC_ALL, "Russian");
	int size;
	cout << "Введите размер хэш-таблицы: "; cin >> size; cout << endl;

	HashTable* HT_1 = new HashTable(size);


	int choice = -1;
	while (choice)
	{
		cout << "\n------------------------------";
		cout << "\nМеню для работы с Хэш-таблицей" << endl;
		cout << "1 - добавление элемента" << endl;
		cout << "2 - вывод хэш-таблицы" << endl;
		cout << "3 - поиск элемента(-ов)" << endl;
		cout << "4 - процент заполнения" << endl;
		cout << "0 - выход" << endl;
		cout << "------------------------------\n\n";
		cout << "Ваш выбор: "; cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
		{
			HT_1->Insert();
			break;
		}
		case 2:
		{
			HT_1->PrintTable();
			break;
		}
		case 3:
		{
			HT_1->SearchNodes();
			break;
		}
		case 4:
		{
			HT_1->FillPercent();
			break;
		}
		case 0:
		{
			exit(0);
		}
		default:
		{
			cout << "\nТакого пункта не существует. Выберете снова.\n";
			break;
		}
		}

	}
}