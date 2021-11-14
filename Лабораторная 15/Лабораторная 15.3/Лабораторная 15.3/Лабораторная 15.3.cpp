#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <locale>
using namespace std;

float dop1(float* a, float b, float e) {

	float x1, x;
	if ((cos(*a) + *a - 7) * (1 - sin(*a)) > 0)
		x1 = *a;
	else
		x1 = b;
	x = x1;
	while (abs(x1 - x) < e)
	{
		x = x1;
		x1 = x - ((cos(x) + x - 7) / (1 - sin(x)));
	}
	return -x1;
}

void main()
{
	system("color 5F");
	float (*dop)(float* a, float b, float n);
	dop = dop1;
	float a, b, n;
	setlocale(LC_CTYPE, "Rus");
	cout << "Считаем интеграл для функции <> в пределах от 1 до 6, n = 200" << endl;
	cout << "Введите a, b, n" << endl;
	cin >> a;
	cin >> b;
	cin >> n;
	cout << "Результат: " << dop(&a, b, n);
}
