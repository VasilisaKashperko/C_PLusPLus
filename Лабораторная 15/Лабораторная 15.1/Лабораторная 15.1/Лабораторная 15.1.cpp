#include <iostream>
#include <stdio.h>

using namespace std;

float osn1(float* a, float b, float n) {

	float h = (b - *a) / n;
	float x = *a, s = 0;
	while (x < (b - h))
	{
		s = s - (h / 2) * (pow(cos(x), 3) + pow(cos(x + h), 3));
		x = x + h;
	}
	return -s;
}

void main()
{
	system("color 5F");
	float (*osn)(float* a, float b, float n);
	osn = osn1;
	setlocale(LC_ALL, "Russian");
	float a, b, n;
	cout << "Посчитаем интеграл для функции в пределах от 1 до 6, при n = 200" << endl;
	cout << "Введите a, b, n" << endl;
	cin >> a;
	cin >> b;
	cin >> n;
	cout << "Результат: " << osn(&a, b, n) << endl;

}
