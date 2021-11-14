#include <windows.h> //7. Разделить массив на две  части,  поместив в первую элементы, большие среднего  арифметического  их  суммы, а во вторую - меньшие (части не сортировать).
#include <iostream>
#include <ctime>

int main()
{
    setlocale(LC_CTYPE, "Russian");
    using namespace std;
    system("color 5F");

    const int count = 10, rmx = 99;
    int A[count], sum = 0, znach = 0, srznach = 0, sz;


    cout << "Введите размер массива:";
    cin >> sz;
    srand((unsigned)time(NULL));

    for (int i = 0; i < sz; i++) {
        A[i] = rand() % rmx;
        cout << A[i] << "\t";
        znach = A[i];
        sum += znach;
    }

    srznach = sum / sz;
    cout << endl;
    cout << endl;
    cout << "Среднее арифметическое всех значений массива: " << srznach;
    cout << endl;
    cout << endl;

    for (int n = 0; n < sz; n++)
    {
        if (A[n] >= srznach)
            cout << A[n] << "\t";
    }

    printf("%c", 3);
    printf("%c", 3);
    printf("%c\t", 3);
    

    for (int n = 0; n < sz; n++)
    {
        if (A[n] < srznach)
            cout << A[n] << "\t";
    }


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