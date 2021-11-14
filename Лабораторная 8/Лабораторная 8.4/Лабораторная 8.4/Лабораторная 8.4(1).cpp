#include <iostream>;
using namespace std;
void main()
{
	system("color 5F");
	setlocale(LC_CTYPE, "Rus");
	float a = 1, b = 3, x = 0, e = 0.0001, x1;

	if ((exp(x) -3 - (1/x)) * (exp(x) + (1/pow(x,2)))>0) {
		x1 = a;
	}
	else { 
		x1 = b;
	}

	while (abs(x1 - x) > e) {
		x = x1;
		x1 = x - (exp(x) - 3 - (1 / x)) / (exp(x) + (2 / pow(x, 3)));
	}
	cout << "Вычисление корней уравнения методом касательных: " << x1 << endl;

	while (abs(a - b) > 2 * e) {
		x = (a + b) / 2;
		if ((exp(a) - 3 - (1 / a)) * ((exp(b) - 3 - (1 / b))) <= 0) {
			b = x;
		}
		else {
			a = x;
		}
	}
	cout << "Вычисление корней уравнения методом дихотомии: " << x<< endl;
	system("pause");
}