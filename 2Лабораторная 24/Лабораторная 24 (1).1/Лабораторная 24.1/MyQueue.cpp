#include "MyQueue.h"
#include <iostream>
using namespace std;

Queue *create() {//создание очереди
	Queue *queue;
	queue = new Queue;
	queue->begin = nullptr;//начало и конец очереди изначально равен 0
	queue->end = nullptr;
	queue->size = 0;
	return queue;
}
void adding(Queue* queue, int n) {//добавление элемента
	if (n >= 0) {//если элемент положительный, то он не записывается в очередь
		return;
	}
	list* temp;
	temp = new list;//создаем узел
	temp->next = nullptr;
	temp->n = n;//значение узла равен значению введенного элемента
	if (queue->end != nullptr)//если не было элементов
		queue->end->next = temp;//элемент становится последним
	else//если в очереди есть элементы
		queue->begin = temp;
	queue->end = temp;
	queue->size++;//увеличиваем размер
}
int show(Queue* queue) {//показываем значение 1 переменной
	if (queue->begin == nullptr)
		return 0;
	int m;
	m = queue->begin->n;
	return m;
}
int del(Queue* queue) {//извлекаем элементы
	if (queue->begin == nullptr)
		return 0;
	list* temp;
	temp = queue->begin;//в узел записываем 1 элемент очереди
	int k = temp->n;//записываем в переменную значение узла
	queue->begin = temp->next;//в голову записываем следующий элемент 
	delete temp;//удаляем узел
	if (queue->begin == nullptr)
		queue->end = nullptr;
	queue->size--;
	return k;
}
int empty(Queue* queue) {//проверка на пустоту очереди
	if (queue->begin == nullptr)
		return 1;
	return 0;
}
int clear(Queue* queue) {//очистка очереди
	if (queue->begin == nullptr)//очередь пуста
		return 0;
	list* temp, * l;
	temp = queue->begin;//в узел передаем 1 элемент очереди
	while (temp->next != nullptr)//пока следующий элемент существует
	{
		l = temp;//в переменную записываем узел и удаляем его
		temp = l->next;
		delete l;
	}
	queue->begin = nullptr;
	queue->end = nullptr;
	queue->size = 0;
	return 1;
}
void allqueue(Queue* queue) {//вывести всю очередь
	cout << endl;
	Queue* temp = create();//создаем узел
	int k;
	while (!empty(queue))
	{
		k = del(queue);
		printf("%d", k);
		adding(temp, k);//извлекаем и добавляем элемент в узел
	}
	while (!empty(temp))
	{
		k = del(temp);
		adding(queue, k);//извлекаем элемент и добавляем в существующую очередь
	}
}
int max(Queue* queue) {//вычисление максимума
	Queue* temp = create();//создаем узел
	int max, k;
	if (!empty(queue)) {//если очередь не пустая, то максимальный элемент 1
		max = queue->begin->n;
	}
	while (!empty(queue))//пока очередь непустая
	{
		k = del(queue);//извлекаем элемент
		if (k > max)
		{
			max = k;//если больше максимума, то становится максимумом
		}
		adding(temp, k);//добавляем в узел
	}
	while (!empty(temp))//пока узел непустой
	{
		k = del(temp);//извлекаем этот элемент
		adding(queue, k);//добавляем в существующую очередь
	}
	return max;
}
int min(Queue* queue) {//вычисление минимума
	Queue* temp = create();
	int min = 0, k;
	while (!empty(queue))
	{
		k = del(queue);
		if (k < min)
		{
			min = k;
		}
		adding(temp, k);
	}
	while (!empty(temp))
	{
		k = del(temp);
		adding(queue, k);
	}
	return min;
}
int length(Queue* queue)//определение длины очереди
{
	return queue->size;
}