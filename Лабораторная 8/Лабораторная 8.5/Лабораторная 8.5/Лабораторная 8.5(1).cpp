#include <iostream>;
using namespace std;
void main()
{
	system("color 5F");
	setlocale(LC_CTYPE, "Rus");
	float a = 1, b = 1, x = 0, e = 0.0001, x1;

	if (((pow(x,3) + x - 3) * 6*x) > 0) {
		x1 = a;
	}
	else {
		x1 = b;
	}

	while (abs(x1 - x) > e) {
		x = x1;
		x1 = x - ((pow(x, 3) + x - 3)) / (3*(pow(x, 2) + 1));
	}
	cout << "Вычисление корней уравнения методом касательных: " << x1 << endl;

	while (abs(a - b) > 2 * e) {
		x = (a + b) / 2;
		if ((pow(x, 3) + x - 3) * (6*x) <= 0) {
			b = x;
		}
		else {
			a = x;
		}
	}
	cout << "Вычисление корней уравнения методом дихотомии: " << x << endl;
	system("pause");
}