//В двусвязных списках каждый элемент имеет указатели на следующий и на предыдущий элементы.

//addLBegin – функция добавления в начало списка всех элементов некоторого списка L.

#include <iostream>
#include <fstream>
using namespace std;
const unsigned int NAME_SIZE = 30;//размер имени
const unsigned int CITY_SIZE = 20;//размер города

struct Address
{
	char name[NAME_SIZE];
	char city[CITY_SIZE];
	Address* next;
	Address* prev;
};
int menu(void)
{
	char s[80];  int c;
	cout << endl;
	cout << "1. Ввод имени" << endl;
	cout << "2. Удаление имени" << endl;
	cout << "3. Вывод на экран" << endl;
	cout << "4. Поиск" << endl;
	cout << "5. Запись в файл" << endl;
	cout << "6. Считывание из файла" << endl;
	cout << "7. Моя функция" << endl;
	cout << "8. Выход" << endl;
	cout << endl;
	do
	{
		cout << "Ваш выбор: ";
		cin.sync();//отбрасывает все непрочитанные символы
		gets_s(s);
		cout << endl;
		c = atoi(s);//преобразует строку в тип инт
	} while (c < 0 || c > 8);
	return c;
}
void insert(Address* e, Address** phead, Address** plast) //Добавление в конец списка
{
	Address* p = *plast;//текущий элемент
	if (*plast == NULL)//если нет элементов в списке
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else//если уже есть элементы
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
Address* setElement()      // Создание элемента и ввод его значений с клавиатуры 
{
	Address* temp = new  Address();//создание нового списка
	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}
	cout << "Введите имя: ";
	cin.getline(temp->name, NAME_SIZE - 1, '\n');//ввод имени и уменьшение размера массива
	cin.ignore(cin.rdbuf()->in_avail());//извлечение из буферного потока и пропуск 1 символа
	cin.clear();//очищение буфера
	cout << "Введите город: ";
	cin.getline(temp->city, CITY_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
void outputList(Address** phead, Address** plast)      //Вывод списка на экран
{
	Address* t = *phead;//в переменную посылаем голову списка
	while (t)
	{
		cout << t->name << ' ' << t->city << endl;//вывод элементов
		t = t->next;
	}
	cout << "" << endl;
}
void find(char name[NAME_SIZE], Address** phead)    // Поиск имени в списке
{
	Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;//сравнение введенного слова с словом из списка
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
		cout << t->name << ' ' << t->city << endl;
}
void delet(char name[NAME_SIZE], Address** phead, Address** plast)  // Удаление имени 
{
	struct Address* t = *phead;	//забрасываем в переменную голову списка
	while (t)
	{
		if (!strcmp(name, t->name))  break;//сравнение введенного слова с словом из списка
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;//вывод сообщения об ошибке
	else
	{
		if (*phead == t)//если голова совпала с элементом
		{
			*phead = t->next;//в голову посылаем следующий элемент
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else//если элемент не является головой
		{
			t->prev->next = t->next;//в элементе, предыдущем от текущего, присвоить указателю на следующий элемент значение указателя на новый элемент
			if (t != *plast)
				t->next->prev = t->prev;//в элементе, следующем от текущего, присвоить указателю на предыдущий элемент значение указателя на предыдущий элемент
			else
				*plast = t->prev;
		}
		delete t;//удаление текущего элемента
		cout << "Элемент удален" << endl;
	}
}
void writeToFile(Address** phead)//Запись в файл
{
	struct Address* t = *phead;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist.txt", "wb");//открытые файла
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	cout << "Сохранение в файл" << endl;
	while (t)
	{
		fwrite(t, sizeof(struct Address), 1, fp);//запись
		t = t->next;
	}
	fclose(fp);
}
void readFromFile(Address** phead, Address** plast)//Считывание из файла
{
	struct Address* t;//текущий элемент
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist.txt", "rb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	while (*phead)
	{
		*plast = (*phead)->next;//в хвост забрасываем элемент следующий после головы
		delete* phead;//удаление головы
		*phead = *plast;//в голову зарасываем новый хвост
	}
	*phead = *plast = NULL;
	cout << "Загрузка из файла" << endl;
	while (!feof(fp))//пока файл не закончился
	{
		t = new Address();
		if (!t)
		{
			cerr << "Ошибка выделения памяти" << endl;
			return;
		}
		if (1 != fread(t, sizeof(struct Address), 1, fp)) break;//чтение из файла
		insert(t, phead, plast);//добавление в конец списка
	}
	fclose(fp);
}
void allLBegin(Address** phead, Address** pLlast) {
	Address* p = *pLlast;//закидываем в р последний элемента 2 списка
	while (p != nullptr) {//пока не закончится 2 список
		Address* temp = new Address();//создаем узел
		strcpy_s(temp->city, p->city);//копируем последние значения из 2 списка в узел
		strcpy_s(temp->name, p->name);
		temp->prev = NULL;//предыдущее значение узла равно 0
		temp->next = (*phead);//голову списка посылыем в следующий элемент после узла
		*phead = temp;//головой становится узел
		p = p->prev;//в р посылаем предыдущий элемент
	}
}
int main(void)
{
	system("color 5F");
	Address* Lhead = NULL;
	Address* Llast = NULL;
	Address* head = NULL;
	Address* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	while (true)
	{
		switch (menu())
		{
		case 1:
		{
			cout << "List 1" << endl;
			insert(setElement(), &head, &last);
			cout << "List L" << endl;
			insert(setElement(), &Lhead, &Llast);
			break;
		}
		case 2: {	  char dname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.getline(dname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			delet(dname, &head, &last);
			break;
		}
		case 3: {
			cout << "List 1" << endl;
			outputList(&head, &last);
			cout << "List L" << endl;
			outputList(&Lhead, &Llast);
			break;
		}
		case 4: {	  char fname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.getline(fname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			find(fname, &head);
			break;
		}
		case 5:
		{
			writeToFile(&head); break;
		}
		case 6:
		{
			readFromFile(&head, &last); break;
		}
		case 7:
		{
			allLBegin(&head, &Llast);
			break;
		}

		case 8: {
			exit(0);
		default: exit(1);
			break; }
		}
	}
	return 0;
	system("pause");

}
