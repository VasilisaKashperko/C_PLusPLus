#include <iostream> 
#include <iomanip>
using namespace std;

class Heap
{
public:
	int* h;
	int HeapSize;
	Heap()
	{
		HeapSize = 0;				//размер кучи
		h = new int[100];			//массив под элементы
	}
	void add(int number);			//добавление элемента
	void show();					//вывод элементов
	void sort(int i);				//сортировка элементов
	void deleteMax();				//удаление максимального элемента
	void deleteMin();				//удаление минимального элемента
	void deleteById(int index);		//удаление элемента по айди
	void heapUnion(Heap& h2);		//объединение куч
	int sum();						//сумма всех узлов
	int right();					//кол-во узлов на правой ветке
	int evenElements();				//кол-во четных узлов
};


void Heap::add(int number)			//добавление элементов
{
	int parent, i;
	i = HeapSize;
	h[i] = number;
	parent = (i - 1) / 2;
	while (parent >= 0 && i > 0)
	{
		if (h[i] > h[parent])
		{
			int save = h[i];
			h[i] = h[parent];
			h[parent] = save;
		}
		i = parent;
		parent = (i - 1) / 2;
	}
	HeapSize++;
}

void Heap::show()					//вывод элементов
{
	int i = 0, k = 1;
	int probel = 20;
	while (i < HeapSize)
	{
		while (i < k && i < HeapSize)
		{
			cout << setw(probel + 10) << setfill(' ');
			cout << h[i] << " ";
			i++;
			probel /= 2;
		}
		cout << endl;
		k = k * 2 + 1;
	}
	cout << endl << endl << endl;
}

void Heap::sort(int i)				//сортировка элементов 
{
	int left, right;
	left = 2 * i + 1;
	right = 2 - i + 2;

	if (left < HeapSize)
	{
		if (h[i] < h[left])
		{
			int save = h[i];
			h[i] = h[left];
			h[left] = save;
			sort(left);
		}
		else return;
	}
	else return;
	if (right < HeapSize)
	{
		if (h[i] < h[right])
		{
			int save = h[i];
			h[i] = h[right];
			h[right] = save;
			sort(right);
		}
		else return;
	}
	else return;
}

void Heap::deleteMax()				//удаление максимального
{
	int number = h[0];
	h[0] = h[HeapSize - 1];
	HeapSize--;
	sort(0);
}

void Heap::deleteMin()				//удаление минимального
{
	int min = h[0];
	int index = 0;
	for (int i = 0; i < HeapSize; i++)
	{
		if (h[i] < min)
		{
			min = h[i];
			index = i;
		}
	}
	h[index] = h[HeapSize - 1];
	HeapSize--;
	sort(index);
}

void Heap::deleteById(int index)	//удаление по айди
{
	h[index] = h[HeapSize - 1];
	HeapSize--;
	sort(index);
}

void Heap::heapUnion(Heap& h2)		//объединение куч
{
	int count = 0;
	for (int i = 0; i < h2.HeapSize; i++)
	{
		add(h2.h[i]);
		count++;
	}
	while (h2.HeapSize != 0)
	{
		h2.HeapSize--;
	}
}

int Heap::sum()						//сумма всех узлов
{
	int sum = 0;
	for (int i = 0; i < HeapSize; i++)
	{
		sum += h[i];
	}
	return sum;
}

int Heap::right()					//кол-во узлов на правой ветке
{
	int count = 0;
	int i = 0;
	int k = pow(2, (int)log2(HeapSize)) - 1;
	while (h[k + i] != h[HeapSize])
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

int Heap::evenElements()			//кол-во четных узлов 
{
	int count = 0;
	for (int i = 0; i < HeapSize; i++)
	{
		if (h[i] % 2 == 0)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	setlocale(LC_ALL, "rus");
	Heap h1;
	Heap h2;

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