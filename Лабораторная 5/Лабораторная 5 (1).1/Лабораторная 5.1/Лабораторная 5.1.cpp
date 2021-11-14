#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
	system("color 5F");
	setlocale(LC_CTYPE, "Russian");
	double y, b, m, a, z;
	b = 2.5;
	m = 3;
	a = 1.4E-3;

	int j[3] = { 0.7, -2, 2.9 };
	int size = sizeof(j) / sizeof(j[0]); /*Находим длину массива.
										 Применяем оператор sizeof.
										 Длина массива равна совокупной длине его элементов.
										 Поэтому с помощью выражения sizeof(numbers) находим длину всего массива в байтах,
										 а с помощью выражения sizeof(numbers[0]) - длину одного элемента в байтах.
										 Разделив два значения, можно получить количество элементов в массиве. */

	for (int i = 0; i < size; i++)
	{
		y = (m * j[i]) / (tan(a) - exp(10*m));
		z = 2*y*b + sqrt(a+b);
		cout << "\nВариант" << i << endl;
		cout << "\nY =" << y << endl;
		cout << "Z =" << z << endl<<endl;
	}
	return 0;
}