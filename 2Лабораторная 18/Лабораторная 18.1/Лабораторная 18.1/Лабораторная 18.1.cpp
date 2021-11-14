#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Rus");
	system("color 5F");
	FILE* fa;
	FILE* fb;
	errno_t err, err_2;
	err = fopen_s(&fa, "fileA.txt", "r");
	if (err != NULL)
	{
		printf("Ошибка в открытии файла");
		return -1;
	}
	err_2 = fopen_s(&fb, "fileB.txt", "w");
	if (err_2 != NULL)
	{
		printf("Ошибка в открытии файла");
		return -1;
	}
	int n;
	fscanf_s(fa, "%d", &n);
	int* A = new int[n]; /* создаем массив из n элементов*/
	for (int i = 0; i < n; i++)
	{
		fscanf_s(fa, "%d", &A[i]); /* вводим в 1 файл элементы целого типа*/
	}
	fclose(fa);

	printf("Массив:");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i], " ");/* вывод массива в консоль*/
	}
	printf("\n");

	int* C = new int[n]; /* массив под количество повторяющихся более 2 раз элементов*/

	int* B = new int[n]; /* массив, в котором будут лежать повторяющиеся элементы массива А*/

	int b_len = 0; /* длина массива В изначально равна 0*/

	bool is_unique; /* бул-флафок логического типа*/


	for (int i = 0; i < n; i++)
	{
		B[i] = 0; /* заполняем массив нулями*/

		C[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		is_unique = true;

		for (int j = 0; j < n; j++)
		{
			if (A[i] == B[j]) /* если элемент массива А совпал с элементом массива В, т.е. если мы встретили в массиве А такой же элемент что и ранее */

			{
				C[j]++; /* накапливаем в массив С кол таких повторений*/

				is_unique = false; /* если нет повторяющихся элементов*/

				break;
			}
		}
		if (is_unique == true) /* если встретились повторяющиеся элементы*/

		{
			B[b_len] = A[i]; /* элементу массива В присваиваем значение повторяющихся элементов */

			C[b_len] = 1; /* в массив С такой же длины что и В записываем кол повторяющихся элементов */

			b_len++;/* переход на следующую ячейку массива В */

		}
	}

	printf("\n");
	cout<<"Запись чисел больше двух раз\n";
	printf("\n");
	for (int j = 0; j < n; j++)
	{
		printf("%d ", B[j]);
		if (C[j] > 2)
			fprintf(fb, "%d ", B[j]); /* вывод в файл В*/

	}

	fclose(fb);
	delete[] A;
	delete[] B;
	delete[] C;

	system("pause");
	return 0;
}
