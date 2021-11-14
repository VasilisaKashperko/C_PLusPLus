#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	system("color 5F");

	float k = 6;
	float f, g, sum = 0;
	int i = 1;
	float a[4] = { 2.3, 7, -2, -4.9 };

	int size = sizeof(a) / sizeof(a[0]);

	for (i; i <= size; i++) {
		sum += a[i];
	}
	while (k <= 7)
	{
			f = k;
			g = f / (sum / i);
			cout << "\nЗначение f = " << f << endl;
			cout << "Значение g = " << g << endl;
			k = k + 0.2;
		}
	cout << "Решение задания окончено!\n" << endl;
}
