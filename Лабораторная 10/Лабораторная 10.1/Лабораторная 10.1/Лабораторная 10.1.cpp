#include <iostream> 
#include <windows.h> 
using namespace std;

void main()
{
	setlocale(LC_CTYPE, "Russian");
	system ("color 5F");

	int A, i; char tmp[33];
	cout << "Введите число ";
	cin >> A;
	_itoa_s(A, tmp, 2);

	cout << "Число в двоичном виде = " << tmp << endl;
	if ((A & 3) == 0)
		cout << "Число кратно 4" << endl;
	else
		cout << "Число не кратно 4" << endl;

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
