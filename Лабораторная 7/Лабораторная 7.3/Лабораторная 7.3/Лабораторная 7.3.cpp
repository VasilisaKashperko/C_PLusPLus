#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	system("color CF");

	float h;
	int ymn = 0, n = 5;
	float d = 12.5E-4, a[5] = { 0.8, 4, -7, 2, 0.91 };

	int size = sizeof(a) / sizeof(a[0]);
	
	for (int r = 1; r <= n; r++)
	{
		ymn += pow(a[r], 2);
	}
		h = d + ymn;

		cout << "Значение h = " << h << endl<<endl;
	cout << "Решение задания окончено!\n" << endl;
}