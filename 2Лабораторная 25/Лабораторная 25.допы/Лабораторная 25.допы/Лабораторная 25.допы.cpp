////1. В приложении 2 приведен проект, в котором реализован проект с использованием двусвязного списка.
////На основе дан-ного проекта разработать функции, которые предлагается создать в данном приложении.
//
//#include <iostream>
//
//using namespace std;
//
//struct Element                   // Элемент списка 
//{
//	Element* Prev;                // указатель на предыдущий элемент 
//	Element* Next;                // указатель на следующий элемент 
//	void* Data;                  //  данные  
//	Element(Element* prev, void* data, Element* next)
//	{
//		Prev = prev;
//		Data = data;
//		Next = next;
//	}
//	Element* GetNext()            // получить следующий
//	{
//		return Next;
//	};
//	Element* GetPrev()            // получить предыдущий  
//	{
//		return Prev;
//	};
//};
////-----------------------------------------------------------
//struct Object                     // Блок управления списком 
//{
//	Element* Head;                 // указатель на начало списка
//	Object()
//	{
//		Head = NULL;
//	};
//	Element* GetFirst()            // получить первый элемент списка
//	{
//		return Head;
//	};
//	Element* GetLast();            // получить последний элемент списка
//	Element* Search(void* data);   // найти  первый элемент по данным 
//	bool Insert(void* data);       // добавить элемент в начало
//	bool InsertEnd(void* data);    // добавить в конец 
//	bool Delete(Element* e);       // удалить по адресу элемента 
//	bool Delete(void* data);       // удалить первый по данным
//	bool DeleteList();		    // очистить список 
//	void PrintList(void(*f)(void*));
//	void PrintList(void(*f)(void*), Element*);
//	int CountList();
//	bool DeleteDouble();
//};
//Object Create();                   // создать список
//
//
//
//struct Person
//{
//	char name[20];
//	int age;
//	Person* next;
//};
//
//void print(void* b)       //Функция используется при выводе 
//{
//	Person* a = (Person*)b;
//	cout << a->name << "  " << a->age << endl;
//}
//
//bool Object::Insert(void* data)           // Вставка в начало
//{
//	bool rc = 0;
//	if (Head == NULL)
//	{
//		Head = new Element(NULL, data, Head);
//		rc = true;
//	}
//	else
//	{
//		Head = (Head->Prev = new Element(NULL, data, Head));
//		rc = true;
//	}
//	return rc;
//}
////-----------------------------------------------------------
//Element* Object::Search(void* data)    // Найти заданный элемент
//{
//	Element* rc = Head;
//	while ((rc != NULL) && (rc->Data != data))
//		rc = rc->Next;
//	return rc;
//}
////-----------------------------------------------------------
//void Object::PrintList(void(*f)(void*))     // Вывод
//{
//	Element* e = Head;
//	while (e != NULL)
//	{
//		f(e->Data);
//		e = e->GetNext();
//	};
//}
////-----------------------------------------------------------
//void Object::PrintList(void(*f)(void*), Element* e)
//{
//	f(e->Data);
//}
////-----------------------------------------------------------
//bool  Object::Delete(Element* e)    // Удалить по ссылке
//{
//	bool rc = 0;
//	if (rc = (e != NULL))
//	{
//		if (e->Next != NULL)
//			e->Next->Prev = e->Prev;
//		if (e->Prev != NULL)
//			e->Prev->Next = e->Next;
//		else
//			Head = e->Next;
//		delete e;
//	}
//	return rc;
//}
////-----------------------------------------------------------
//bool Object::Delete(void* data)      // Удалить по значению
//{
//	return Delete(Search(data));
//};
////-----------------------------------------------------------
//Element* Object::GetLast()
//{
//	Element* e = Head, * rc = e;
//	while (e != NULL)
//	{
//		rc = e;
//		e = e->GetNext();
//	}
//	return rc;
//}
////-----------------------------------------------------------
//Object Create()
//{
//	return *(new Object());
//}
////-----------------------------------------------------------
//bool Object::DeleteList() {
//
//	Element* tmpl = Head;
//	while (tmpl != NULL) {
//		Element* nx = tmpl->GetNext();
//		delete tmpl;
//		tmpl = nx;
//	}
//	Head = NULL;
//	return true;
//}
////-----------------------------------------------------------
//int Object::CountList() {
//	int count = 0;
//
//	Element* tmpl = Head;
//	while (tmpl != NULL) {
//		++count;
//		tmpl = tmpl->GetNext();
//	}
//
//	return count;
//}
//
//int main(int argc, char* argv[])
//{
//	setlocale(LC_ALL, "Russian");
//	Person a1 = { "Петров", 20 };
//	Person a2 = { "Сидоров", 25 };
//	Person a3 = { "Гончаров", 47 };
//	bool rc;
//	Object L1 = Create();   // создание списка с именем L1
//	L1.Insert(&a1);
//	L1.Insert(&a2);
//	L1.Insert(&a3);
//	L1.PrintList(print);
//	Element* e = L1.Search(&a3);
//	Person* aa = (Person*)e->Data;
//	cout << "Найден элемент= " << aa->name << endl;
//	rc = L1.Delete(&a2);
//	if (rc == true) cout << "Удален элемент" << endl;
//	cout << "Размер списка - " << L1.CountList() << endl;
//	cout << "Список:" << endl;
//	L1.PrintList(print);
//
//	L1.DeleteList();
//	cout << "Очищен список\n";
//	L1.PrintList(print);
//	cout << "Размер списка - " << L1.CountList() << endl;
//	return 0;
//}

// Каждый элемент списка студентов содержит фамилию, имя, отчество, год рождения,
//курс, номер группы, оценки по пяти предметам. Упорядочить студентов по курсу, 
//причем студенты одного курса должны располагаться в алфавитном поряд-ке. 
//Найти средний балл каждой группы по каждому предмету. Определить самого старшего 
//студента и самого младшего студентов. Для каждой группы найти лучшего с точки зрения успеваемости студента.

//#include <iostream>
//#include <fstream>
//#include <string>
//#include <windows.h>
//#include <vector>
//
//using namespace std;
//
//struct Address
//{
//	string name;
//	int groupId;
//	int math;
//	int chemistry;
//	int it;
//	int biology;
//	int pi;
//	int berthyear;
//	Address* next;
//	Address* prev;
//};
//void insert(Address* e, Address** phead, Address** plast)
//{
//	Address* p = *plast;
//	if (*plast == NULL)
//	{
//		e->next = NULL;
//		e->prev = NULL;
//		*plast = e;
//		*phead = e;
//		return;
//	}
//	else
//	{
//		p->next = e;
//		e->next = NULL;
//		e->prev = p;
//		*plast = e;
//	}
//}
//Address* setElement()
//{
//	Address* temp = new  Address();
//	if (!temp)
//	{
//		cerr << "Ошибка выделения памяти памяти";
//		return NULL;
//	}
//	cout << "Введите имя: ";
//	getline(cin, temp->name);
//	getline(cin, temp->name);
//	cout << "Введите оценки: \n";
//	cout << "биология ";
//	cin >> temp->biology;
//	cout << "математика ";
//	cin >> temp->math;
//	cout << "химия ";
//	cin >> temp->chemistry;
//	cout << "информатика ";
//	cin >> temp->it;
//	cout << "физкультура ";
//	cin >> temp->pi;
//	cout << "Введите год рождения";
//	cin >> temp->berthyear;
//	cout << "Введите группу";
//	cin >> temp->groupId;
//	temp->next = NULL;
//	temp->prev = NULL;
//	return temp;
//}
//void outputList(Address** phead, Address** plast)
//{
//	Address* t = *phead;
//	while (t)
//	{
//		cout << t->name << endl << " Оценки: биология " << t->biology << " математика " << t->math << " физкульт " << t->pi << " информатика " << t->it << " химия " << t->chemistry << endl << "Год рождения " << t->berthyear << "\nГруппа" << t->groupId << endl;
//		t = t->next;
//	}
//	cout << "" << endl;
//}
//void delet(string name, Address** phead, Address** plast)
//{
//	struct Address* t = *phead;
//	while (t)
//	{
//		if (name == t->name)  break;
//		t = t->next;
//	}
//	if (!t)
//		cerr << "Имя не найдено" << endl;
//	else
//	{
//		if (*phead == t)
//		{
//			*phead = t->next;
//			if (*phead)
//				(*phead)->prev = NULL;
//			else
//				*plast = NULL;
//		}
//		else
//		{
//			t->prev->next = t->next;
//			if (t != *plast)
//				t->next->prev = t->prev;
//			else
//				*plast = t->prev;
//		}
//		delete t;
//		cout << "Элемент удален" << endl;
//	}
//}
//void sortList(Address** phead, Address** plast) {
//	Address* pheadP = NULL;
//	Address* plastP = NULL;
//
//	struct Address* tp = *phead;
//	while (tp)
//	{
//		Address* tpNext = tp->next;
//		insert(tp, &pheadP, &plastP);
//		tp = tpNext;
//	}
//
//	struct Address* t = *phead;
//	while (t)
//	{
//		struct Address* sec = t;
//		while (sec) {
//			if (sec->name < t->name) {
//				Address tmpl = *t;
//				t->name = sec->name;
//				t->berthyear = sec->berthyear;
//				t->groupId = sec->groupId;
//				t->biology = sec->biology;
//				t->math = sec->math;
//				t->pi = sec->pi;
//				t->it = sec->it;
//				t->chemistry = sec->chemistry;
//
//				sec->name = tmpl.name;
//				sec->berthyear = tmpl.berthyear;
//				sec->groupId = tmpl.groupId;
//				sec->biology = tmpl.biology;
//				sec->math = tmpl.math;
//				sec->pi = tmpl.pi;
//				sec->it = tmpl.it;
//				sec->chemistry = tmpl.chemistry;
//			}
//			sec = sec->next;
//		}
//		t = t->next;
//	}
//	cout << "Отсортированный список: \n";
//	outputList(&pheadP, &plastP);
//}
//void averMarks(Address** phead, Address** plast) {
//
//	struct Address* t = *phead;
//	vector<int> groups;
//	while (t)
//	{
//		int counter = 0;
//		for (size_t i = 0; i < groups.size(); i++)
//		{
//			if (groups[i] != t->groupId) counter++;
//		}
//		if (counter == groups.size()) groups.push_back(t->groupId);
//		t = t->next;
//	}
//
//	for (size_t i = 0; i < groups.size(); i++)
//	{
//		int colOfStudents = 0;
//		t = *phead;
//		int mathVal = 0;
//		int chemistryVal = 0;
//		int biologyVal = 0;
//		int piVal = 0;
//		int itVal = 0;
//		while (t)
//		{
//			if (groups[i] == t->groupId) {
//				colOfStudents++;
//				mathVal += t->math;
//				chemistryVal += t->chemistry;
//				biologyVal += t->biology;
//				piVal += t->pi;
//				itVal += t->it;
//			}
//			t = t->next;
//		}
//		cout << "Средние баллы группы N" << groups[i] << ": \n";
//		cout << "биология " << biologyVal / (float)colOfStudents << " математика " << mathVal / (float)colOfStudents << " физкульт " << piVal / (float)colOfStudents << " информатика " << itVal / (float)colOfStudents << " химия " << chemistryVal / (float)colOfStudents << endl;
//	}
//}
//
//void stat(Address** phead, Address** plast) {
//
//	struct Address* t = *phead;
//	vector<int> groups;
//	while (t)
//	{
//		int counter = 0;
//		for (size_t i = 0; i < groups.size(); i++)
//		{
//			if (groups[i] != t->groupId) counter++;
//		}
//		if (counter == groups.size()) groups.push_back(t->groupId);
//		t = t->next;
//	}
//
//	for (size_t i = 0; i < groups.size(); i++)
//	{
//		int bestScore = 0;
//		Address bestStudent;
//		t = *phead;
//
//		while (t)
//		{
//			if (groups[i] != t->groupId) {
//				t = t->next;
//				continue;
//			}
//
//			int rscore = 0;
//			rscore += t->math;
//			rscore += t->chemistry;
//			rscore += t->biology;
//			rscore += t->pi;
//			rscore += t->it;
//
//			if (rscore > bestScore) {
//				bestScore = rscore;
//				bestStudent = *t;
//			}
//			t = t->next;
//		}
//
//		cout << "Лучший студент группы N" << groups[i] << " это " << bestStudent.name << endl;
//	}
//
//	t = *phead;
//	int maxYear = t->next->berthyear;
//	int minYear = 0;
//	Address oldest;
//	Address yangest;
//	while (t)
//	{
//		if (t->berthyear < maxYear) {
//			maxYear = t->berthyear;
//			oldest = *t;
//		}
//		if (t->berthyear > minYear) {
//			minYear = t->berthyear;
//			yangest = *t;
//		}
//		t = t->next;
//	}
//	cout << "Самый младший студент - " << yangest.name << " " << yangest.berthyear << " год\n";
//	cout << "Самый старший студент - " << oldest.name << " " << oldest.berthyear << " год\n";
//}
//
//int main(void)
//{
//	int m, a;
//	Address* head = NULL;
//	Address* last = NULL;
//	setlocale(LC_CTYPE, "Rus");
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	while (true)
//	{
//		cout << endl;
//		cout << "1. Ввод" << endl;
//		cout << "2. Удаление" << endl;
//		cout << "3. Вывод на экран" << endl;
//		cout << "4. Упорядочить" << endl;
//		cout << "5. Ср. баллы" << endl;
//		cout << "6. Статистика студентов" << endl;
//		cout << "8. Выход" << endl;
//		cout << endl;
//		cin >> a;
//		switch (a)
//		{
//		case 1:  insert(setElement(), &head, &last);
//			break;
//		case 2: {	  string dname;
//			cout << "Введите имя: ";
//			getline(cin, dname);
//			cin.ignore(cin.rdbuf()->in_avail());
//			cin.sync();
//			delet(dname, &head, &last);
//		}
//			  break;
//		case 3:  outputList(&head, &last);
//			break;
//		case 4:
//			sortList(&head, &last);
//			break;
//		case 5:
//			averMarks(&head, &last);
//			break;
//		case 6:
//			stat(&head, &last);
//			break;
//		case 8:  exit(0);
//		default: exit(1);
//		}
//	}
//	system("pause");
//	return 0;
//}


//N человек  располагаются  по кругу.  Начав отсчет от первого, удаляют каждого k-го, 
//смыкая круг после удаления. Определить порядок удаления людей из круга. Использовать линейный список.

#include <iostream>
#include <fstream>
using namespace std;

struct Address
{
	int id;
	Address* next;
	Address* prev;
};
void insert(Address* e, Address** phead, Address** plast)
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
Address* setElement()
{
	static int user_id = 0;
	Address* temp = new  Address();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}
	temp->id = user_id++;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
void outputList(Address** phead, Address** plast)
{
	Address* t = *phead;
	while (t)
	{
		cout << t->id << endl;
		t = t->next;
	}
	cout << "" << endl;
}
bool delet(int id, Address** phead, Address** plast)
{
	struct Address* t = *phead;
	while (t)
	{
		if (id == t->id) break;
		t = t->next;
	}
	if (!t)
		return 0;
	else
	{
		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		delete t;
		cout << "Элемент удален" << endl;
		return 1;
	}
}
int main(void)
{
	int m, a;
	Address* head = NULL;
	Address* last = NULL;

	int length = 20;
	for (size_t i = 0; i < length; insert(setElement(), &head, &last), i++) {}
	outputList(&head, &last);
	int id = 0;
	int k = 8;

	setlocale(LC_CTYPE, "Rus");
	while (true)
	{
		cout << endl;
		cout << "1. Удалить к-го и определить порядок" << endl;
		cout << "0. Выход" << endl;
		cout << endl;
		cin >> a;
		switch (a)
		{
		case 1:
			if (delet(id, &head, &last)) {
				cout << "Удален элемент с айди = " << id << endl;
				id += k;
				--length;
			}
			else {
				cout << "Удален элемент с айди = " << id << endl;
				id += 1;
			}
			outputList(&head, &last);
			if (id > length) id -= length;
			break;
		case 0:  exit(0);
		default: exit(1);
		}
	}
	system("pause");
	return 0;
}