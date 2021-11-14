#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	system("color 5F");

	float b = -0.12, x = 1.3E-4, z, y; int n = 40, k;


	cout << "Хотите ли вы посчитать форулу? (1 - да, 2 - нет)";
	cin >> k;

	switch (k)
	{
	case 1:
		z = 1 / (x - 1) + sin(x) - sqrt(n);
		y = (exp(-b) + 1) / 2 * z;
		cout << "Число z =\n" << z;
		cout << "Число y =\n" << y; break;
	case 2: puts("Ну ладно"); break;

	default: puts("Некорректный вариант"); break;
	}
}