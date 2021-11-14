#include <iostream>
#include <stdio.h>

using namespace std;

float dop3(float* a, float b, float n) {
	float h, x, s;
	h = (b - *a) / n, x = *a, s = 0;
	while (x < (b - h)) {
		s = s + h * (1 + pow(x, 3) + pow(x + h, 3)) / 2;
		x = x + h;
	}
	return s;
}

void main()
{
	system("color 5F");
	float (*dop)(float* a, float b, float n);
	dop = dop3;
	setlocale(LC_CTYPE, "Russian");
	float a, b, n;
	cout << "Посчитаем интеграл для функции <> в пределах от 1 до 6, при n = 200" << endl;
	cout << "Введите a, b, n" << endl;
	cin >> a;
	cin >> b;
	cin >> n;
	cout << "Результат:\n" << dop(&a, b, n)*10000000000000;
}
