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
        i = i + 2;
            if (c % 2 == 0)
            i = i + 3;
                if (i == 1)
                cout << "Есть одно четное число A\n";
    if (i == 3)
    cout << "Есть два четных числа A и B\n";
        if (i == 4)
        cout << "Есть два четных числа A и C\n";
            if (i == 5)
            cout << "Есть два четных числа B и C\n";
                if (i == 0)
                cout << "Среди заданных чисел четных нет!\n";
                return (0);
}