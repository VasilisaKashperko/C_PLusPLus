//1. Найти в последовательности n целых чисел и вывести значение суммы четных элементов.
#include <iostream>;
using namespace std;

void main()
{
	int n, n1, k = 1, sum = 0, d;

	setlocale(LC_CTYPE, "Russian");
	system("color 5F");

	cout << "Введите количество чисел в ряду - ";
	cin >> n;

	while (n >= 1)
	{
		cout << "Введите n" << k << " ";
		cin >> n1;
		d = n1 % 2;
		if (d == 0)
		{ sum = sum + n1; 
		}

		n = n - 1;
		k = k + 1;
	}

	cout << "Сумма четных элементов равна "<< sum;
	system("pause");
}
