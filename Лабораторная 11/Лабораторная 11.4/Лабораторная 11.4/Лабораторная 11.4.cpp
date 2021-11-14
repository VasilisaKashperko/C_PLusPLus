#include <iostream>; // Задан одномерный числовой массив A из n элементов и число k. Найти номера всех элементов массива, которые равны, больше и меньше k.

void main()
{
	using namespace std;
	system("color 5F");
	setlocale(LC_CTYPE, "Rus");

	const int max = 100;
	int a[max], raz, k;

	cout << "Введите число элементов массива: ";
	cin >> raz;

	cout << "Введите k: ";
	cin >> k;

	for (int i = 1; i <= raz; i++) {
		cout << "Введите " << i << " элемент: ";
		cin >> a[i];
	}

	for (int i = 1; i <= raz; i++) {
		if (a[i] < k) { cout << "Элемент под номером " << i << " меньше k" << endl; };
		if (a[i] == k) { cout << "Элемент под номером " << i << " равен k" << endl; };
		if (a[i] > k) { cout << "Элемент под номером " << i << " больше k" << endl; };
	}

	system("pause");
}
