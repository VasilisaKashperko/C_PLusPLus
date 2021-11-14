#include <iostream>; /* Задан массив A из n элементов.
Найти количество элементов этого массива,
больших среднего арифмети-ческого всех его элементов. */
using namespace std;
void main()
{
	const int max = 100;
	int a[max], raz, sum = 0, k = 0;
	float sr;

	setlocale(LC_CTYPE, "Russian");
	system("color 5F");

	cout << "Введите число элементов массива: ";
	cin >> raz;
	cout << endl;
	for (int i = 0; i < raz; i++)
	{
		a[i] = rand() % 200 - 100; // задаем массив
		cout << a[i] << " ";
		sum = sum + a[i];
	}
	sr = (float)sum / (float)raz; // ищем среднее арифметическое 
	for (int i = 0; i < raz; i++) // находим количество тех, которые больше среднего арифметического
	{
		if (a[i] > sr) { k = k + 1; };
	}
	cout << "Среднее арифмитическое: " << sr << endl << "Количество элементов больше среднего арифмитического: " << k << endl;
	system("pause");
}