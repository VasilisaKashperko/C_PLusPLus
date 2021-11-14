#include <windows.h>
#include <iostream>
#include <ctime>

int main()
{
    setlocale(LC_CTYPE, "Russian");
    using namespace std;
    system("color 5F");

    const int count = 99, rmx=99;
    int A[count];
    int sz;

    cout << "Введите размер массива:";
    cin >> sz;

    srand((unsigned)time(NULL));

    for (int i = 0; i < sz; i++) {
        A[i] = rand() % rmx;
        cout << A[i] << "\t";
    }
    cout << endl;

    int min = 0, max = 0;

    cout << endl;

    cout << endl;

    cout << endl;

    cout << endl;

    cout << endl;


    for (int i = 0; i < sz; i++) {
        if (i<=4 || i>=6) {
            cout << A[i]<<"\t";
        }
        else
        {
            cout << "Элемент удален" << "\t";
        }
    }


    cout << endl;

    cout << endl;

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    for (int n = 0; n < sz; n++) {
        if (A[n] < A[min])
            min = n;
        if (A[n] > A[max])
            max = n;
    }

    int chasha = A[max];
    A[max] = A[min];
    A[min] = chasha;

    for (int m = 0; m < sz; m++) {
        cout << A[m] << "\t";
    }

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