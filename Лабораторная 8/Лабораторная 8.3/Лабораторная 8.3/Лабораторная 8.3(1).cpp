#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	system("color 5F");

	float n = 200, a = 5, b = 11;
	float h, x, s, z;

	float s1 = 0, s2 = 0, i = 1;

	h = (b - a) / n;
	x = a;
	s = 0;

	while (x <= (b - h)) {
		s = s + h * (exp(x) +2 + exp(x + h) +2 )/ 2;
		x = x + h;
	}
	cout << "Интеграл, посчитанный методом трапеций, равен: " << s;

	h = (b - a) / (2 * n);
	x = a + 2 * h;

	while (i < n) {
		s2 = s2 + exp(x) - (1 / x);
		x = x + h;
		s1 = s1 + exp(x) - (1 / x);
		x = x + h;
		i = i + 1;
	}
	z = h * (exp(a) +2 + 4 * (exp(a + h) + 2) + 4 * s1 + 2 * s2 + exp(b) + 2) / 3;
	cout << "\nИнтеграл, посчитанный методом парабол, равен: " << z << endl;

	return (0);
}