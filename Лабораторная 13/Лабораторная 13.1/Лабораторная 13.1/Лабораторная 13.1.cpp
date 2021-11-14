#include <iostream>; //Дана матрица A(N, M). Найти количество элементов этой матрицы, больших среднего арифметического всех её элементов.
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	system("color 5F");

	const int M = 100;
	int N, sum = 0, d = 0, k = 0;
	static int A[M][M];

	do
	{
		cout << "Введите размер матрицы, меньше 100: "; // составляем матрицу
		cin >> N;
		if (N > M) cout << "Слишком большой размер! Введите число меньше\n";
	} while (N > M);

	for (int i = 0; i < N; i++)
	{
		cout << endl;
		for (int j = 0; j < N; j++)
		{
			A[i][j] = rand() % 100;
			cout << A[i][j] << " ";
			sum = sum + A[i][j]; // суммируем все элементы
			d++; // кол-во всех элементов
		}
	}

	sum = sum / d; // среднее арифметическое

	for (int i = 0; i < N; i++)
	{
		cout << endl;
		for (int j = 0; j < N; j++)
		{
			if (A[i][j] > sum) {
				k++;
			}

		}
	}

	cout << endl;

	cout << "Среднее арифметическое всех элементов: " << sum << endl;
	cout << "Количество элементов массива, больше среднего арифметического: " << k << endl;

	return 0;
}
