﻿#include <iostream>; // 6. Получить квадратную матрицу порядка n.
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");

	const int M = 100;
	int N;
	static int A[M][M];

	do
	{
		cout << "Введите размер матрицы: "; // составляем матрицу
		cin >> N;
		if (N > M) cout << "Слишком большой размер! Введите число меньше\n";
	} while (N > M);

	if (N % 2 == 1) // Для квадратных матриц нечётного порядка
	{
		for (int i = 0; i<(N / 2) + 1; i++)
		{
			int k = 0;
			for (int j = i; j<(N / 2) + 1; j++) // Симметричное заполнение до середины
			{
				*(*(A + i) + j) = ++k; // Верхний левый угол
				*(*(A + (N - i - 1)) + (N - j - 1)) = k; // Правый нижний угол
			}
			for (int j = (N / 2) + 1; j<N - i; j++) // Симметричное заполнение после середины
			{
				*(*(A + i) + j) = --k;
				*(*(A + (N - i - 1)) + (N - j - 1)) = k;
			}
		}

	}

	else // Для квадратных матриц чётного порядка
	{
		for (int i = 0; i<(N / 2) + 1; i++)
		{
			int k = 0;
			for (int j = i; j<(N / 2); j++)
			{
				*(*(A + i) + j) = ++k; // Левый верхний угол
				*(*(A + i) + (N - j - 1)) = k; // Правый верхний угол
				*(*(A + (N - i - 1)) + (N - j - 1)) = k; // Правый нижний угол
				*(*(A + (N - i - 1)) + j) = k; // Левый нижний угол
			}
		}
	}

	for (int i = 0; i<N; i++)
	{
		cout << endl;
		for (int j = 0; j<N; j++)
		{
			cout << *(*(A + i) + j) << " ";
		}
	}
	system("pause");
}
