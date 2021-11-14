#include <iostream>
#include <stdio.h>
#include <cmath>

int main()
{
	using namespace std;
	system ("color 5F");
	setlocale(LC_ALL, "Rus");

	float b, y, a, z;
	b = 2.5;
	a = 1.4E-3;
	int i, n;

	float m[3] = { 7.3, -2, 0.8 };
	float j[4] = { 0.3, 1, 0.7, 4 };

	float size = sizeof(m) / sizeof(m[0]);
	float size1 = sizeof(j) / sizeof(j[0]);

	for (i = 0; i < size; i++)
	{
		for (n = 0; n < size1; n++)
		{
			y = (m[i] * j[n]) / (tan(a) - exp(10 * m[i]));
			z = 2 * y * b + sqrt(a + b);
			cout << "Y =" << y << endl;
			cout << "Z =" << z << endl << endl;
		}
	}
		return 0;
}