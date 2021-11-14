#pragma once
struct AAA {
	int x;
	void Print();
	int GetPriority();
};
namespace heap {
	enum CMP { LESS = -1, EQUAL = 0, GREAT = 1 };
	struct Heap {
		int Size;
		int MaxSize;
		void** Storage;
		CMP(*Compare)(void*, void*);//сравнение 2 элементов
		Heap(int maxsize, CMP(*f)(void*, void*))//конструктор кучи заданного размера и с заданной функцией сравнения элементов
		{
			Size = 0;
			Storage = new void* [MaxSize = maxsize];
			Compare = f;
		};
		Heap(int maxsize, CMP(*f)(void*, void*), void* x[])//конструктор кучи заданного размера с заданной ф-ей сравнения элементов и содержащие заданные элементы х
		{
			Size = 0;
			Storage = x;
			MaxSize = maxsize;
			Compare = f;
		};
		int Left(int ix);//возвращ номер левого элемента от текущего ix
		int Right(int ix);//возвращ номер правого элемента от текущего ix
		int Parent(int ix);//возвращ номер родительского элемента от текущего ix
		bool isFull()//проверка полная ли куча
		{
			return(Size >= MaxSize);//возврат результата сравнения текущего размера с максимальным
		};
		bool isEmpty()//проверка кучи на пустоту
		{
			return(Size <= 0);//результат сравнения текущего размера с 0
		};
		bool isLess(void* x1, void* x2)//сравнение x1<x2
		{
			return Compare(x1, x2) == LESS;//возврат сравнения результата функции с элементом перечисления LESS
		};
		bool isGreat(void* x1, void* x2)//сравнение x1>x2
		{
			return Compare(x1, x2) == GREAT;//возврат сравнения результата функции с элементом перечисления GREAT
		};
		bool isEqual(void* x1, void* x2)//сравнение x1=x2
		{
			return Compare(x1, x2) == EQUAL;//возврат сравнения результата функции с элементом перечисления EQUAL
		};
		void Swap(int i, int j);//перестановка 2 элементов с номерами i и j
		void Heapify(int ix);//формирование кучи из массива
		void Insert(void* x);//вставка элемента x в кучу
		void* ExtractMax();//извлечение макс элемента(вершины кучи)
		void Deleteheap();//очистка кучи
		void Scan(int i);//вывод кучи начиная с заданного элемента
		void* ExtractMin();//удаление мин элемента 
		void* ExtractI(int i);//удаление i-ого элемента
		void Union(Heap&);//объединение 2 куч в 1 (берет в качестве аргумента кучу и берет ук-ль на нее)
	};
	Heap Create(int maxsize, CMP(*f)(void*, void*));//создание кучи с заданным размером и ф-ей сравнения

