//Бинарная куча (binary heap) представляет собой бинарное дерево,
//для которого выполняется основное свойство кучи: приоритет каждой вершины
//больше приоритетов её потомков. В простейшем случае приоритет можно считать равным значению.
//Реализация бинарной кучи возможна на основе массива и на основе списка.


#include <iostream> 
#include <iomanip>
using namespace std;

class BINARYHeap //class BiNARY Heap
{
		public:
				int* he;
				int HeapSize;
				BINARYHeap()
				{
					HeapSize = 0;				//размер кучи
					he = new int[100];			//массив под элементы
				}
				void add(int number);			//добавление элемента
				void show();					//вывод элементов
				void sort(int i);				//сортировка элементов
				void deleteMax();				//удаление максимального элемента
				void deleteMin();				//удаление минимального элемента
				void deleteById(int index);		//удаление элемента по айди
				void heapUnion(BINARYHeap& h2);		//объединение куч
				int sum();						//сумма всех узлов
				int right();					//кол-во узлов на правой ветке
				int evenElements();				//кол-во четных узлов
};


void BINARYHeap::add(int number)			//добавление элементов
{
	int parent, i;
	i = HeapSize;
	he[i] = number;
	parent = (i - 1) / 2;
	while (parent >= 0 && i > 0)
	{
		if (he[i] > he[parent])
		{
			int save = he[i];
			he[i] = he[parent];
			he[parent] = save;
		}
		i = parent;
		parent = (i - 1) / 2;
	}
	HeapSize++;
}

void BINARYHeap::show()					//вывод элементов
{
	int i = 0, k = 1;
	int probel = 20;
	while (i < HeapSize)
	{
		while (i < k && i < HeapSize)
		{
			cout << setw(probel + 10) << setfill(' ');
			cout << he[i] << " ";
			i++;
			probel /= 2;
		}
		cout << endl;
		k = k * 2 + 1;
	}
	cout << endl << endl << endl;
}

void BINARYHeap::sort(int i)				//сортировка элементов 
{
	int left, right;
	left = 2 * i + 1;
	right = 2 - i + 2;

	if (left < HeapSize)
	{
		if (he[i] < he[left])
		{
			int save = he[i];
			he[i] = he[left];
			he[left] = save;
			sort(left);
		}
		else return;
	}
	else return;
	if (right < HeapSize)
	{
		if (he[i] < he[right])
		{
			int save = he[i];
			he[i] = he[right];
			he[right] = save;
			sort(right);
		}
		else return;
	}
	else return;
}

void BINARYHeap::deleteMax()				//удаление максимального
{
	int number = he[0];
	he[0] = he[HeapSize - 1];
	HeapSize--;
	sort(0);
}

void BINARYHeap::deleteMin()				//удаление минимального
{
	int min = he[0];
	int index = 0;
	for (int i = 0; i < HeapSize; i++)
	{
		if (he[i] < min)
		{
			min = he[i];
			index = i;
		}
	}
	he[index] = he[HeapSize - 1];
	HeapSize--;
	sort(index);
}

void BINARYHeap::deleteById(int index)	//удаление по айди
{
	he[index] = he[HeapSize - 1];
	HeapSize--;
	sort(index);
}

void BINARYHeap::heapUnion(BINARYHeap& h2)		//объединение куч
{
	int count = 0;
	for (int i = 0; i < h2.HeapSize; i++)
	{
		add(h2.he[i]);
		count++;
	}
	while (h2.HeapSize != 0)
	{
		h2.HeapSize--;
	}
}

int BINARYHeap::sum()						//сумма всех узлов
{
	int sum = 0;
	for (int i = 0; i < HeapSize; i++)
	{
		sum += he[i];
	}
	return sum;
}

int BINARYHeap::right()					//кол-во узлов на правой ветке
{
	int count = 0;
	int i = 0;
	int k = pow(2, (int)log2(HeapSize)) - 1;
	while (he[k + i] != he[HeapSize])
	{
		i++;
		count++;
	}
	i = 0;
	k++;
	k /= 2;
	int q = count > k ? count - k : 0;
	while (i != (int)log2(HeapSize) - 1)
	{
		q += pow(2, i);
		i++;
	}
	return q;
}

int BINARYHeap::evenElements()			//кол-во четных узлов 
{
	int count = 0;
	for (int i = 0; i < HeapSize; i++)
	{
		if (he[i] % 2 == 0)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	system("color 5F");
	setlocale(LC_ALL, "rus");
	BINARYHeap h1;
	BINARYHeap h2;

	h2.add(10);			//добавление элементов во вторую кучу
	h2.add(5);


	h1.add(20);			//добавление элементов в основную кучу
	h1.add(30);
	h1.add(10);
	h1.add(40);
	h1.add(70);
	h1.add(50);
	h1.add(60);
	h1.add(80);
	h1.add(100);
	h1.add(90);
	h1.add(32);
	h1.add(54);

	cout << "Первичная куча " << endl;
	h1.show();
	cout << endl;

	cout << "Куча после удаления максимума " << endl;
	h1.deleteMax();
	h1.show();
	cout << endl;

	cout << "Куча после удаления минимума " << endl;
	h1.deleteMin();
	h1.show();
	cout << endl;

	cout << "Куча после удаления элемента по его айди " << endl;
	h1.deleteById(1);
	h1.show();
	cout << endl;

	cout << "Куча после объединения со второй кучей " << endl;
	h1.heapUnion(h2);
	h1.show();
	cout << endl;

	cout << "Сумма всех узлов " << h1.sum() << endl;
	cout << "Кол-во узлов на правой ветке " << h1.right() << endl;
	cout << "Кол-во четных элементов " << h1.evenElements() << endl;
}