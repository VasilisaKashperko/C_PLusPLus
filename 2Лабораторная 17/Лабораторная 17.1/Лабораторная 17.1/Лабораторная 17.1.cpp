/* В соответствии со своим вариантом отделить корни
двух уравнений и вычислить их методом дихотомии для
исходных данных из таблицы, приведенной ниже. 
Точность вычислений принять равной e = 0,001 для всех вариантов.*/

#include <iostream>
using namespace std;

double f1(double x)
{
	return pow(x, 3) + 2*x - 1; /* уравнение 1*/
}
double f2(double x)
{
	return exp(x) - 2; /* уравнение 2*/
}
double fun(double(*f)(double), double a, double b) /* функция для решения метода дихотомии*/
{
	double x = 1, e = pow(10, -3);
	while (abs(a - b) > 2 * e)
	{
		x = (a + b) / 2;
		if (f(x) * f(a) <= 0)
		{
			b = x;
		}
		else a = x;
	}
	return x;
}
void main()
{
	system("color 5F");
	setlocale(LC_CTYPE, "Rus");
	double c;
	c = fun(f1, 0, 1); /* при отделении корней а=0, в=1*/
	cout << "Корень 1 функции= " << c << endl;
	c = fun(f2, -2, 0); /* при отделении корней а=-2, в=0*/

	cout << "Корень 2 функции= " << c << endl;
	system("pause");
}
