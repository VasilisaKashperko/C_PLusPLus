#include <stdarg.h>
#include <iostream>	 /* Написать функцию с переменным числом параметров для перевода
						чисел из десятичной системы счисления в двоичную
							С помощью этой функции перевести различные числа из десятичной
								системы счисления в двоичную. */
using namespace std;
char bit(int cnt,...)
{
	va_list vl;
	va_start(vl, cnt);
	int n = va_arg(vl, int);					
	int i, mass[99];
	for (i = 0; i < 99; i++)
	{
		mass[i] = 0;
	}

	i = 0;
	while (n != 0)
	{
		if (n % 2 == 0)
		{
			mass[i] = 0;
		}
		else
		{
			mass[i] = 1;
		}
		n = n >> 1;
		i++;
	}
	cout << "В двоичной системе: ";
	i = i - 1;
	for (; i >= 0; i--)
		cout << mass[i];
	va_end(vl);
	return(0);
}
void main()
{
	setlocale(LC_CTYPE, "rus");
	cout << bit(1, 34) << endl;
	cout << bit(1, 85) << endl;
	cout << bit(1,2020);
}