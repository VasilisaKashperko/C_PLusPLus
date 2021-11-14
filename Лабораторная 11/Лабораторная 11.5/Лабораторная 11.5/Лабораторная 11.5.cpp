#include <iostream>; // Вводится последовательность из n натуральных чисел. Необходимо определить наименьшее натуральное число, отсутствующее в последовательности.

int main()
{
	using namespace std;
	system("color 5F");
	setlocale(LC_CTYPE, "Rus");

	const int max = 100;
	int a[max], raz, ch=1, k=-1;

	cout << "Введите число элементов массива: ";
	cin >> raz;

	cout << "Вводите элементы массива A: ";

	for (int i = 1; i <= raz; i++) {
		cin >> *(a+i);
	}

	for (int i = 1; i <= raz; i++) {
		if (*(a + i) > k) { k = *(a + i); }
	}

	for (int s = 1; s <= k; s++) {
		for (int i = 1; i <= k; i++) {
			if (*(a + i) == s) { ch = ch + 1; };
		}
	}

	cout << "Наименьшее натуральное число, не входящее в массив: " << ch << endl;

	system("pause");
}