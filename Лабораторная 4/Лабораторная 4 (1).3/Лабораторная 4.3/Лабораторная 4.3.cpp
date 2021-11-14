#include <iostream> //Разработать консольную программу-калькулятор для целых числе с операциями %, /, +, -, *.

	int main()
{
	using namespace std;
	system("color 5F");
	setlocale(LC_CTYPE, "Rus");


	int a, b, i;
	char c;                  


	for (int i = 1; i <= 5; i++)
	{
		cout << "Вы можете воспользоваться этой консолью в качетсве калькулятора для двух целых чисел.\n";
		cin >> a;
		cin >> c;
		cin >> b;

		switch (c)
		{
		case '%': cout << a % b << endl; break;
		case '/': cout << a / b << endl; break;
		case '+': cout << a + b << endl; break;
		case '-': cout << a - b << endl; break;
		case '*': cout << a * b << endl; break;
		default: cout << "Введите корректный знак операции!\n"; break;
		}

	}
return (0);
}