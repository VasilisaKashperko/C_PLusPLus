#include <iostream>

int main()
{
	setlocale(LC_CTYPE, "Rus");
	system("color B5");
	using namespace std;

	int t; float y, p, q; double x = 0.4E6;

	cout << "Введите число t" << endl;
	cin >> t;
	cout << "Введите число y" << endl;
	cin >> y;

	p = 2.6 * t + cos(y / (3 * x + y));
	q = sin(t) / cos(t);

	cout << "В результате рассчета по формуле p=" << p << endl;
	cout << "В результате рассчета по формуле q=" << q << endl;
}