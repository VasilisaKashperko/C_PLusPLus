#include <iostream> //Определить, есть ли среди заданных целых чисел A, B, C два чётных.
using namespace std;

int main()
{
    system("color 5F");
    setlocale(LC_CTYPE, "Rus");
    int a, b, c, i;
    i = 0;
    cout << "Введите число A:\n";
    cin >> a;
    cout << "Введите число B:\n";
    cin >> b;
    cout << "Введите число C:\n";
    cin >> c;
    if (a % 2 == 0)
        i = i + 1;
    if (b % 2 == 0)
        i = i + 1;
    if (c % 2 == 0)
        i = i + 1;
    if (i >= 2)
        cout << "Есть два четных числа\n";
    else 
        cout << "Четных чисел нет\n";
    return (0);
}
