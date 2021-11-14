#pragma once
#define HASHDEL (void*) -1
struct Object
{
	void** data;//массив
	Object(int, int(*)(void*));//конструктор
	int size; //размер табл 
	int N;//тек кол-во элементов
	int(*getKey)(void*);//вычисление ключа
	bool insert(void*);
	int searchInd(int key);//поиск индекса по ключу
	void* search(int key);//поиск элемента по ключу
	void* deleteByKey(int key);//удаление по ключу
	bool deleteByValue(void*);//удаление по значению
	void scan(void(*f)(void*));//вывод на экран
};
static void* DEL = (void*)HASHDEL;//признак удаленного элемента
Object create(int size, int(*getkey)(void*));
#undef HASHDEL
