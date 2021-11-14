#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	system("color 02");

	float z;
	int sum = 1, ymn = 0;
	int m = 5, k = 1;
	float x[5] = { -2, 6, 1.1, 2.7, 4 };

	int size = sizeof(x) / sizeof(x[0]);

	for (int i = 1; i <= size; i++)
	{
		while (k <= m)
		{
			ymn += pow(x[i] - 2, 2);
			k += 1;
		}
		z = 8 * pow(x[i], 3) + ymn;
		cout << "Вариант №" << i << endl;
		cout << "Значение z = " << z << endl<<endl;
	}
	cout << "Решение задания окончено!\n" << endl;
}