#include <windows.h> //4.	Найти в массиве наибольшее число подряд идущих одинаковых элементов.
#include <iostream>
#include <ctime>

int main()
{
    setlocale(LC_CTYPE, "Russian");
    using namespace std;
    system("color 5F");

    const int count = 99;
    long A[count];
    int sz, rmx = 99, col = 0;


    cout << "Введите размер массива:";
    cin >> sz;
    srand((unsigned)time(NULL));

    for (int i = 0; i < sz; i++) {
        A[i] = rand() % rmx;
        cout << A[i] << "\t";
    }

    cout << endl;
    cout << endl;

    printf("%c", 3);
    printf("%c", 3);
    printf("%c\t", 3);

    cout << endl;
    cout << endl;

    for (int n = 0; n < sz; n++) {
        if (A[n] == A[n-1]) {
            col += 1;
        }
    }

    cout << "Количество одинаковых элементов идущих подряд= " << col;

    cout << endl;
    cout << endl;

    Beep(392.00, 500);
    Sleep(50);
    Beep(392.00, 500);
    Sleep(50);
    Beep(392.00, 500);
    Sleep(50);
    Beep(311.13, 650);
    Beep(466.16, 250);
    Beep(392.00, 500);

    Beep(311.13, 650);
    Beep(466.16, 250);
    Beep(392.00, 1000);
    Sleep(50);

    Beep(587.33, 500);
    Sleep(50);
    Beep(587.33, 500);
    Sleep(50);
    Beep(587.33, 500);
    Sleep(50);
    Beep(622.5, 600);
    Beep(466.16, 250);

    Beep(369.99, 500);
    Sleep(50);
    Beep(311.13, 500);
    Beep(466.16, 250);
    Beep(392.00, 1000);
}