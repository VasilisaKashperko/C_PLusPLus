/* Написать функцию days с переменным числом параметров, 
которая находит количество дней, прошедших между двумя 
датами (параметрами функции являются даты в формате «дд.мм.гг». */

//#include <iostream>
//#include <ctime>
//
//int days(int y, int m, int d) { /* В английском варианте, так легче - 0001-01-01 */
//    if (m < 3)
//        y--, m += 12;
//    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
//}
//
//int main()
//{
//    using namespace std;
//    system("color 5F");
//    setlocale(LC_CTYPE, "Rus");
//
//    int day = days(2012, 1, 10) - days(2012, 1, 8);
//    cout <<"Между двумя датами "<< day <<" дней"<< endl;
//}

#include <iostream>
int sum(int n, ...); // задаем прототип функции
using namespace std;

int sum(int n, ...)
{
	int* p = &n;
	int x, y;
	cout << "Начало промежутка: ";
	cin >> x;
	cout << "Конец промежутка: ";
	cin>> y;
	int tmp[100];
	for (int i = 0; i <= n; i++, p++) {
		if (*p > x && *p < y) {
			tmp[i] = *p;
			cout << tmp[i] << " ";
		}
		else {
			cout << "";
		}
	}
	return 0;
}
void main()
{
	system("color 5F");
	setlocale(LC_CTYPE, "rus");
	cout << endl << sum(17, 13, 11, 7, 5, 1, 2, 3, 0) << endl;
	cout << endl << sum(2, 34, 503, 601) << endl;
}