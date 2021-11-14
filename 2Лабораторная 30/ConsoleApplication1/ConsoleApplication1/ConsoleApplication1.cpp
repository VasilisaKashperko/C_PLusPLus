#include "Header.h"
#include <iostream>
#include <ctime> 
#include <iomanip>

using namespace std;
int HashFunction(int key, int size, int p)    //мультипликат хэш
{
	double key2 = 5 * ((0.6180339887499 * key) - int((0.6180339887499 * key)));
	return (p + key) % size;
}
//-------------------------------
int Next_hash(int hash, int size, int p)//модульная хэш
{
	return (hash + 5 * p + 3 * p * p) % size;
}
//-------------------------------
Object create(int size, int(*getkey)(void*))
{
	return *(new Object(size, getkey));
}
//-------------------------------
Object::Object(int size, int(*getkey)(void*))
{
	N = 0;
	this->size = size;
	this->getKey = getkey;
	this->data = new void* [size];
	for (int i = 0; i < size; ++i)
		data[i] = NULL;
}
//-------------------------------
bool Object::insert(void* d)
{
	int kollizia = 0;
	bool b = false;
	if (N != size)
		for (int i = 0, t = getKey(d), j = HashFunction(t, size, 0); i != size && !b; j = Next_hash(j, size, ++i))
		{
			if (data[j] == NULL || data[j] == DEL)
			{
				data[j] = d;
				N++;
				b = true;
			}
			kollizia++;
		}
	std::cout << "kollizii " << kollizia;
	std::cout << "\n";
	return b;
}
//-------------------------------
int Object::searchInd(int key)
{
	int t = -1;
	bool b = false;
	if (N != 0)
		for (int i = 0, j = HashFunction(key, size, 0); data[j] != NULL && i != size && !b; j = HashFunction(key, size, ++i))
			if (data[j] != DEL)
				if (getKey(data[j]) == key)
				{
					t = j; b = true;
				}
	return t;
}
//-------------------------------
void* Object::search(int key)
{
	int t = searchInd(key);
	return(t >= 0) ? (data[t]) : (NULL);
}
//-------------------------------
void* Object::deleteByKey(int key)

{
	int i = searchInd(key);
	void* t = data[i];
	if (t != NULL)
	{
		data[i] = DEL;
		N--;
	}
	return t;
}
//-------------------------------
bool Object::deleteByValue(void* d)
{
	return(deleteByKey(getKey(d)) != NULL);
}
//-------------------------------
void Object::scan(void(*f)(void*))
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << " Элемент" << i;
		if ((this->data)[i] == NULL)
			std::cout << "  пусто" << std::endl;
		else
			if ((this->data)[i] == DEL)
				std::cout << "  удален" << std::endl;
			else
				f((this->data)[i]);
	}
}

struct AAA
{
	int key;
	char* mas;
	AAA(int k, char* z)
	{
		key = k;  mas = z;
	} AAA() {}
};
//-------------------------------
int key(void* d)
{
	AAA* f = (AAA*)d;   return f->key;
}
//-------------------------------
void AAA_print(void* d)
{
	cout << " ключ " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}
//-------------------------------
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	int size, choice, k;
	cout << "Введите размер хеш-таблицы" << endl; 	cin >> size;
	Object H = create(size, key);
	for (;;)
	{
		cout << "1 - вывод хеш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;   cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1: H.scan(AAA_print);  break;
		case 2: { AAA* a = new AAA;
			char* str = new char[20];
			cout << "введите ключ" << endl;	cin >> k;
			a->key = k;
			cout << "введите строку" << endl; cin >> str;
			a->mas = str;
			if (H.N == H.size)
				cout << "Таблица заполнена" << endl;
			else
				H.insert(a);
		} break;
		case 3: {  cout << "введите ключ для удаления" << endl;
			cin >> k;
			H.deleteByKey(k);
		}  break;
		case 4: {  cout << "введите ключ для поиска" << endl;
			cin >> k;
			int start_time = clock();
			if (H.search(k) == NULL)
				cout << "Элемент не найден" << endl;
			else
				AAA_print(H.search(k));
			unsigned long long int end_time = clock();
			cout << "Время выполнения куска программы: " << end_time - start_time <<
				" миллисекунд\n";
			cout << endl;
		}  break;
		}
	}
	system("pause");
	return 0;

}
