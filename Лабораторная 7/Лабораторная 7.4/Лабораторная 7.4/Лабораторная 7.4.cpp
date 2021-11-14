//7. Найти в последовательности n целых чисел и вывести порядковый номер первого отрицательного элемента.

#include <iostream>;
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	system("color 05");

	int n, n1, k = 1,s=0;

	cout << "Введите количество чисел в ряду - ";
	cin >> n;
	while (n >= 1)
	{
		cout << "Введите n" << k << " " << endl;
		cin >> n1;
			if (n1 < 0) 
			{ cout << "Номер первого отрицательного - " << k;
		s = 1;
		system ("pause");
			};
		k = k + 1;
		n = n - 1;
	}

	if (s != 1) 
	{ 
		cout << "Нет отрицательных чисел ";
	}

	system ("pause");
}