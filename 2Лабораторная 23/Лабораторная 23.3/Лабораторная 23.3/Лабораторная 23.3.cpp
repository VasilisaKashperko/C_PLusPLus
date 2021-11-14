//2. Создать стек с целочисленным информационным полем.
//Заполнить его длинами строк, считанных из файла.
//Распечатать на экране содержимое стека. Указать номер и длину последней самой короткой строки файла.

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

struct Stack
{
	int ind;
	Stack* next;
};

void length(Stack** el, int n)
{
	Stack* i = new Stack;
	i->ind = n;
	i->next = *el;
	*el = i;
}

void out(Stack* el)
{
	Stack* i = el;
	if (el == nullptr)
	{
		cout << "Список пуст";
		return;
	}
	while (i != nullptr)
	{
		cout << i->ind << endl;
		i = i->next;
	}
}

int main()
{
	system("color 5F");
	int min = 256, j = 0;
	setlocale(LC_CTYPE, "Russian");
	Stack* el = nullptr;
	ifstream file1("1.txt");
	char str[255];
	int n;
	while (!file1.eof())
	{
		file1.getline(str, 255);
		n = strlen(str);
		length(&el, n);
		if (n < min)
		{
			min = n;
			j++;
		}
	}
	file1.close();
	out(el);
	cout << endl;
	cout << "Длина самой маленькой строки:" << min << endl;
	cout << "Её номер:" << j << endl;
	return 0;
}