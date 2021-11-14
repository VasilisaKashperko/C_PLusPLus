#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <locale>
using namespace std;

float dop2(float* a, float b, float n) {
	float h, x, s1, s2, i, s;
	h = (b - *a) / (2 * n), x = *a + 2 * h, s1 = 0, s2 = 0, i = 1;
	while (i < n)
	{
		s2 = s2 + pow(cos(x), 3);
		x = x + h;
		s1 = s1 + pow(cos(x), 3);
		x = x + h;
		i = i + 1;
	}
	s = (h / 3) * (pow(cos(*a), 3) + 4 * cos(x + h) + 4 * s1 + 2 * s2 + pow(cos(b), 3));
	return s;
}

void main()
{
	system("color 5F");
	float (*dop)(float* a, float b, float n);
	dop = dop2;
	setlocale(LC_CTYPE, "Russian");
	float a, b, n;
	cout << "Считаем интеграл для функции <> в пределах от 1 до 6, n = 200" << endl;
	cout << "Введите a, b, n" << endl;
	cin >> a;
	cin >> b;
	cin >> n;
	cout << "Результат: " << dop(&a, b, n);
}
