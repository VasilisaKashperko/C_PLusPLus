#include <iostream>; // Установить 0 в числе А n битов вправо от позиции p.
using namespace std;

void main()
{
	int A, i = 0, mask = 0, p, n;
	char tmp[33];

	setlocale(LC_CTYPE, "Russian");
	system("color 5F");

	cout << "Введите количество битов: ";
	cin >> n;
	cout << "Введите позицию: ";
	cin >> p;
	cout << "Введите число A: ";
	cin >> A;

	_itoa_s(A, tmp, 2);
	cout << "A: " << tmp << endl;

	for (i = (p - n) - 1; i < (p - n) - 1 + n; i++)
	{
		mask += pow(2, i);
	} // Маска для A

	_itoa_s(~mask, tmp, 2);
	cout << "Маска для A: " << tmp << endl;

	_itoa_s(A & ~mask, tmp, 2);
	cout << "Итог: " << tmp << endl;

	system("pause");
}