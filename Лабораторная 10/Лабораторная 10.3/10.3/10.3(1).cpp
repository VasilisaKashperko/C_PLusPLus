#include <iostream> // Извлечь 5 битов числа A, начиная с третьего и вставить их в число B, начиная со 2.

void main()
{
	using namespace std;
	setlocale(LC_CTYPE, "Russian");
	system("color 5F");

	char tmp[33];
	int A, B, maskA = 248; // маска А - размер выделенной части в числе А (4 бита А с 3 позиции - 1111000) 
	int maskB = ~maskA >> 1;  

	cout << "Первое число А: ";
	cin >> A; 

	cout << "Второе число В: ";
	cin >> B;

	_itoa_s(A, tmp, 2);
	cout << "A = " << tmp << endl;

	_itoa_s(B, tmp, 2);
	cout << "B = " << tmp << endl;

	_itoa_s(maskA, tmp, 2);
	cout << "Маска для А: " << tmp << endl;

	_itoa_s((A & maskA) >> 3, tmp, 2);  // сдвигаем маску А на число, с которого ведем отсчет А
	cout << "Выделенные биты А: " << tmp << endl;
	
	_itoa_s(maskB, tmp, 2);
	cout << "Маска для В: " << tmp << endl;

	_itoa_s((B & maskB), tmp, 2);
	cout << "Очищены биты в B: " << tmp << endl;
	_itoa_s(((B & maskB) | ((A & maskA) >> 1)), tmp, 2); // сдвигаем маску А вправо на разницу между позицией А и позицией В

	cout << "Результат B = " << tmp << endl;

	system("pause");
}
