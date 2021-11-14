//1. Дана величина a строкового типа из четного количества символов.
//Получить и напечатать величину b, состоящую из символов первой половины величины a,
//записанных в обратном порядке, после которых идут символы второй половины ве-личины a,
//также записанные в обратном порядке (например, при а = “привет” b должно быть равно «ипртев»).
#include <iostream>
using namespace std;

struct Stack
{
	char data;     //информационный элемент
	Stack* head;   //вершина стека 
	Stack* next;   //указатель на следующий элемент
};

void push(char x, Stack* myStk)   //Добавление элемента х в стек 
{
	Stack* e = new Stack;    //выделение памяти для нового элемента
	e->data = x;             //запись элемента x в поле v 
	e->next = myStk->head;   //перенос вершины на следующий элемент 
	myStk->head = e;         //сдвиг вершины на позицию вперед
}

int pop(Stack* myStk)   //Извлечение (удаление) элемента из стека
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1;               //если стек пуст - возврат -1 
	}
	else
	{
		Stack* e = myStk->head;   //е - переменная для хранения адреса элемента
		char a = myStk->head->data;   //запись числа из поля data в переменную a 
		myStk->head = myStk->head->next; //перенос вершины
		delete e;                        //удаление временной переменной
		return a;                        //возврат значения удаляемого элемента
	}
}

void show(Stack* myStk)    //Вывод стека
{
	Stack* e = myStk->head;    //объявляется указатель на вершину стека
	char a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->data;          //запись значения в переменную a 
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}

int main() //беоп??ясме
{
	system("chcp 1251>nul");
	system("color 5F");
	setlocale(LC_ALL, "Rus");
	char str[20];
	int dl;
	Stack* myStk = new Stack; //выделение памяти для стека
	myStk->head = NULL;       //инициализация первого элемента 
	while (strlen(str) % 2 != 0) {
		cout << "Строка с четным количеством символов" << endl;
		cin >> str;
	}
	dl = strlen(str);
	for (int i = (dl / 2); i < dl; i++) {
		push(str[i], myStk);
	}
	for (int i = 0; i < (dl / 2); i++) {
		push(str[i], myStk);
	}
	show(myStk);
}