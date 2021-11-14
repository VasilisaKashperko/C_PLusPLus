#include <iostream>;
using namespace std;

void main()
{
	int A, i = 0, mask = 0, p, n; // Установить 0 в числе А n битов влево от позиции p.
	char tmp[33];

	setlocale(LC_CTYPE, "Russian");

	cout << "Введите n: ";
	cin >> n;
	cout << "Введите p: ";
	cin >> p;
	cout << "Введите число A: ";
	cin >> A;

	_itoa_s(A, tmp, 2);
	cout << "A: " << tmp;

	for (i = p - 1; i < p - 1 + n; i++)
	{
		mask += pow(2, i);
	} // Маска для A

	_itoa_s(~mask, tmp, 2);
	cout << "Маска для A: " << tmp << endl;

	_itoa_s(A & ~mask, tmp, 2);
	cout << "Итог: " << tmp << endl;

	system("pause");
}