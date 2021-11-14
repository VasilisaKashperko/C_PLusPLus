#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Rus");
    system("color B5");
    

    int a, b, n, z;
    n = 0;
    z = 0;

    cout << "Введите натуральное число a - \n";
    cin >> a;
    cout << "Введите натуральное число b - \n";
    cin >> b;

    if (a < b)
        n = a;
    else
        n = b;

    for (int i = 1; i <= n; i++) //делитель не может быть больше, чем само натуральное число
    {
        if (a % i == 0 && b % i == 0)
            z = i;
    }
    cout << "Наибольший общий делитель = " << z;
    cout << endl;
    
}