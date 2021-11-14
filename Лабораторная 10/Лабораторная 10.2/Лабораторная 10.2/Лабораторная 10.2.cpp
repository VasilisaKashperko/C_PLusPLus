#include <iostream> // Установить 1 в числе А n битов вправо от позиции p.
#include <windows.h>
void main()
{
	using namespace std;
	setlocale(LC_CTYPE, "Russian");
	system("color 5F");

	int A, i = 0, mask = 0, p, n;
	char tmp[33];
	
	cout << "Введите количество битов: ";
	cin >> n;

	cout << "Введите позицию: ";
	cin >> p;

	cout << "Введите число A: ";
	cin >> A;

	_itoa_s(A, tmp, 2);
	cout << "A: " << tmp<<endl;

	for (i = (p - n) - 1; i < (p - n) - 1 + n; i++)
	{
		mask += pow(2, i); // Маска для A
	}						

	_itoa_s(mask, tmp, 2);
	cout << "Маска для A: " << tmp << endl;

	_itoa_s(A | mask, tmp, 2);
	cout << "Итог: " << tmp << endl;

	_itoa_s(A | mask, tmp, 10);
	cout << "Итог: " << tmp << endl;

    Beep(247, 500);
    Beep(417, 500);
    Beep(417, 500);
    Beep(370, 500);
    Beep(417, 500);
    Beep(329, 500);
    Beep(247, 500);
    Beep(247, 500);
    Beep(247, 500);
    Beep(417, 500);
    Beep(417, 500);
    Beep(370, 500);
    Beep(417, 500);
    Beep(497, 500);
    Sleep(500);
    Beep(497, 500);
    Beep(277, 500);
    Beep(277, 500);
    Beep(440, 500);
    Beep(440, 500);
    Beep(417, 500);
    Beep(370, 500);
    Beep(329, 500);
    Beep(247, 500);
    Beep(417, 500);
    Beep(417, 500);
    Beep(370, 500);
    Beep(417, 500);
    Beep(329, 500);
}
