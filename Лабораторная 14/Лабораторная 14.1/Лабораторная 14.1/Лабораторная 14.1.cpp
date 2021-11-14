#include <iostream>;
#include <windows.h>/* В одномерном массиве, состоящем из n вещественных элементов,
вычислить произведение положительных элементов массива и сумму элементов массива,
расположенных до минимального элемента */
using namespace std;
void main()
{
	const int max = 100;
	int a[max], raz, pro = 1, imin = -1, min = 101, sum = 0;
	setlocale(LC_CTYPE, "Russian");

	cout << "Введите число элементов массива: ";
	cin >> raz;
	cout << endl;

	for (int i = 0; i < raz; i++)
	{
		a[i] = rand() % 20 - 10;
		cout << a[i] << " ";
		if (a[i] > 0) { pro = pro*a[i];};
		if (a[i] < min) {
			min = a[i];
			imin = i;
		}
	}

	for (int i = 0; i < imin; i++)
	{
		sum = sum + a[i];
	}
	cout << "Произведение положительных: " << pro << endl << "Сумма элементов, стоящих перед минимальным: " << sum << endl;
	
	system("pause");
	Beep(659.26, 200);
	Beep(659.26, 200);
	Sleep(200);
	Beep(659.26, 200);
	Sleep(100);
	Beep(523.26, 200);
	Beep(659.26, 200);
	Sleep(200);
	Beep(783.98, 200);
	Sleep(400);
	Beep(391.99, 200);
}
