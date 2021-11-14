#include <iostream>; // Даны массивы A и B, состоящие из n элементов. Построить массив S, каждый элемент которого равен сумме соответствующих элементов массивов A и B.

void main(){
	using namespace std;
	system("color 5F");
	setlocale(LC_CTYPE, "Rus");

	const int max = 100;
	int a[max], b[max], s[max], raz;

	cout << "Введите число элементов массива: ";
	cin >> raz;
	cout << "Введите элементы массива A: ";

	for (int i = 1; i <= raz; i++) {
		cin >> *(a+i);
	}
	printf("%c", 3);
	printf("%c", 3);
	printf("%c\t", 3);
	cout << endl;
	cout << endl << "Введите элементы массива B: ";

	for (int i = 1; i <= raz; i++) {
		cin >> *(b+i);
		*(s + i) = *(a + i) + *(b + i);
	}
	printf("%c", 3);
	printf("%c", 3);
	printf("%c\t", 3);
	cout << endl;
	cout << endl << "Полученный массив S: ";

	for (int i = 1; i <= raz; i++) {
		cout << *(s + i) << " ";
	}

	system("pause");
}