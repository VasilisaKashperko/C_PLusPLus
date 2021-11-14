#include <iostream>; // Дан массив A из n элементов и B из m элементов. Содержится ли наибольший элемент массива A в массиве B?

void main(){

    using namespace std;
    system("color 5F");
    setlocale(LC_CTYPE, "Rus");

	const int max = 100;
	int a[max], b[max], m, n, amax=0,k=0;

	cout << "Введите число элементов массива А: ";
	cin >> n;

	a[0] = -99999;

	for (int i = 1; i <= n; i++) {
		cout << "Введите " << i << " элемент массива А: ";
		cin >> a[i];
		if (a[i] > amax) { amax = a[i]; };
	}

	cout << endl;
	cout << "Максимальный элемент массива А: " << amax << endl;

    printf("%c", 3);
    printf("%c", 3);
    printf("%c\t", 3);
    cout << endl;

	cout << "Введите число элементов массива В: ";
	cin >> m;

	for (int i = 1; i <= m; i++) {
		cout << "Введите " << i << " элемент массива А: ";
		cin >> b[i];
		if (b[i] == amax) { k=1; };
	}

	if (k == 1) { 
    cout << "В массиве В есть максимальный элемент массива А" << endl;
    }

	else {
    cout << "В массиве В нет максимального элемента массива А" << endl;
    }

	system("pause");
}