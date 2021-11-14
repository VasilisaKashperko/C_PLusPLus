#include "Header.h"
#include <iostream>
#include <iomanip>
using namespace std;
void AAA::Print()
{
	std::cout << x;
}
int AAA::GetPriority()
{
	return x;
}
namespace heap
{
	Heap Create(int maxsize, CMP(*f)(void*, void*))//создание кучи с заданным макс размером и ф-ей сравнения 2 элементов
	{
		return*(new Heap(maxsize, f));//создаем новую кучу и возвращаем ее
	}
	int Heap::Left(int ix)//полуение номера левого потомка элемента ix
	{
		return (2 * ix + 1 >= Size) ? -1 : (2 * ix + 1);//если номер левого потомка выходит за пределы текущего количества элементов в куче, то возвр -1, иначе возвр номерлевого элемента
	}
	int Heap::Right(int ix)//полуение номера правого потомка элемента ix
	{
		return (2 * ix + 2 >= Size) ? -1 : (2 * ix + 2);//если номер левого потомка выходит за пределы текущего количества элементов в куче, то возвр -1, иначе возвр номерправого элемента
	}
	int Heap::Parent(int ix)//получение номера родительского элемента ix
	{
		return (ix + 1) / 2 - 1;//возврат номера род элемента
	}
	void Heap::Swap(int i, int j)//перестановка 2 элементов
	{
		void* buf = Storage[i];//запоминаем i-ый элемент массива в буфере(Storage-массив элементов произв типа)
		Storage[i] = Storage[j];//на место i-ого элемента записываем j-ый
		Storage[j] = buf;//на место j-ого элемента записываем то, что сохранили в buf
	}
	void Heap::Heapify(int ix)//формирование кучи в массиве(ix-номер текущего элемента)
	{
		int l = Left(ix), r = Right(ix), irl = ix;//irl = ix-переменная для хранения номера наибол из 3 элементов(текущ лев и прав)
		if (l > 0)
		{
			if (isGreat(Storage[l], Storage[ix]))
				irl = l;
			if (r > 0 && isGreat(Storage[r], Storage[irl]))
				irl = r;
			if (irl != ix)
			{
				Swap(ix, irl);
				Heapify(irl);
			}
		}
	}
	void Heap::Insert(void* x)//вставка элемента в кучу
	{
		int i;
		if (!isFull())
		{
			i = Size;
			Storage[i] = x;
			Size++;
			while (i > 0 && isLess(Storage[Parent(i)], Storage[i]))//пока не дойдем до вершины и пока род элементБвставленного
			{
				Swap(Parent(i), i);
				i = Parent(i);//новой позицией вставленного элемента становится позиция род элемента
			}
		}
	}
	void* Heap::ExtractMax()
	{
		void* rc = NULL;
		if (!isEmpty())
		{
			rc = Storage[0];//возвращаеиый элемент равен нулев элементу массива
			Storage[0] = Storage[Size - 1];//на место нул элемента записываем последний элемент
			Size--;
			Heapify(0);//перестраиваем кучу начиная с кучи
		}
		Heapify(0);
		return rc;
	}
	void Heap::Scan(int i)//вывод кучи
	{
		int probel = 20;
		std::cout << "\n";
		if (Size == 0)
			std::cout << "The heap is empty";
		for (int u = 0, y = 0, level = 1; u < Size; u++)
		{
			cout << setw(probel + 10) << setfill(' ');
			((AAA*)Storage[u])->Print();
			if (u == y)//если дошли до конца текущ уровня(y-номер последн элем в текущ уровне)
			{
				level++;
				cout << "\n";
				if (y == 0)//если текущ уровень нулевой
					y = 2;//номер последнего элемента в след 1-ом уровне=2
				else y = pow(2, level) - 2;//иначе расчитываем номер посл элемента для след  уровня(level-номер тек уровня)
			}
			probel /= 2;
		}
		cout << '\n';
	}
	void Heap::Deleteheap()
	{
		if (!isEmpty())
		{
			Size = 0;
			this->~Heap();
		}
	}
	void* Heap::ExtractMin()
	{
		void* rc = NULL;
		if (Size > 0)
		{
			int j = Size / 2;//номер мин элемента
			for (int i = Size / 2; i < Size; i++)//Size/2-номер1-го элемента в посл слое, Size-размер кучи
			{
				if (Compare(Storage[i], Storage[j]) == LESS)//если i-ый элем<мин(Storage[i])
				{
					j = i;//запоминаем номер найденного мин элемента
				}
			}
			rc = Storage[j];//зн-е мин элемента
			Swap(j, Size - 1);//меняем местами посл элемент с найденным
			Size--;//уменьшаем размер кода
		}
		Heapify(0);
		return rc;//возвращ зн-е найд мин элемента
	}
	void* Heap::ExtractI(int i)//удаление i-ого элемента
	{
		void* rc = NULL;
		if (Size > 0 && i >= 0 && i < Size)
		{
			rc = Storage[i];
			Swap(i, Size - 1);//переставляем местами удаляемый элемент и посл
			Size--;
		}
		Heapify(0);
		return rc;
	}
	void Heap::Union(Heap& h2)//объединение 2 куч в 1
	{
		while (!h2.isEmpty())//пока не опустеет 2 куча
			Insert(h2.ExtractMax());//извлекаем элемент из 2 кучи и вставляем в 1
	}
}
