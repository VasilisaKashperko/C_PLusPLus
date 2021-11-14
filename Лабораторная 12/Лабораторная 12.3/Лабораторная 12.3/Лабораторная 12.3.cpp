#include <iostream>; //	В заданной последовательности слов найти все слова, имеющие заданное окончание.

int main()
{
	using namespace std;
	system("color 5F");
	setlocale(LC_CTYPE, "Rus");

	const int max=100;
	char s[max], s1[max], A[max];

	cout << "Введите строку: " << endl;
	gets_s(s);

	cout << "Введите окончание: " << endl;
	gets_s(s1);

	int d = 0, b;

	for (int i = 0; i < 10; i++)
		A[i] = 0;

	int i = 0;
	char *p = s - 1;

	while (d++ < strlen(s))
	{
		p++;
		b = 0;
		i = 0;

		while (*p != ' ' && *p)
		{
			A[i] = *p;
			i++; // считаем символов всего в сумме
			p++;
			d++;
		}

		for (int j = i - 1, k = 0; j > 0, k < strlen (s1); j--, k++)

		if (s1[k] == A[j]) // считаем количества одинаковых символов
		{
			b++;
		}

		if (b >= strlen(s1))
		for (int j = 0; j < i; j++)
			cout << A[j]; 
		cout << " ";
	}
	cout << endl;
	return 0;
}