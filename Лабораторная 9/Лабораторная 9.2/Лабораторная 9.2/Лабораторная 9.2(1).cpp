#include <windows.h> //Удалить все элементы с заданным значением, если они имеются в массиве. Добавить перед каждым четным элементом массива элемент со значением 1. 
#include <iostream>
#include <ctime>

int main()
{
    setlocale(LC_CTYPE, "Russian");
    using namespace std;
    system("color 5F");

    const int count = 10, rmx = 99;
    int A[count], element = 0, m = 0, sz;

    cout << "Введите размер массива:";
    cin >> sz;
    cout << "Введите элемент, который вы хотите исключить из массива: ";
    cin >> element;

    srand((unsigned)time(NULL));

    for (int i = 0; i < sz; i++) {
        A[i] = rand() % rmx;
        cout << A[i] << "\t";
    }
    cout << endl;
    cout << endl;

    for (int n = 0; n < sz; n++)
    {
        if (A[n] != element)
            cout << A[n] << "\t";
        else
            m ++;
    }

    cout << "Столько элементов было удалено: " << m;

    cout << endl;
    cout << endl;

    for (int m = 0; m < sz; m++) {
        if (A[m] % 2 == 0) {
            cout << "1" << "\t";
            cout << A[m] << "\t";
        }
        else
            cout << A[m] << "\t";
    }

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