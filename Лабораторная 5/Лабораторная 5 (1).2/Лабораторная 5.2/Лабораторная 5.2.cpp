#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

void main()
{
	system("color 5F");
	setlocale(LC_CTYPE, "Russian");
	float y, b, j, m, a, z;
	b = 2.5;
	m = 3;
	a = 1.4E-3;
	j = b;
	while (j < 3.1)
	{
		y = (m * j) / (tan(a) - exp(10 * m));
		z = 2 * y * b + sqrt(a + b);
		cout << "Y =" << y << endl;
		cout << "Z =" << z << endl << endl;
		j = j + 0.1;
	}
}