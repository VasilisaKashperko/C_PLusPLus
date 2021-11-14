#include <iostream>; /* Дана целочисленная прямоугольная матрица. 
Определить количество строк, не содержащих ни одного нулевого элемента 
и максимальное из чисел, встречающихся в заданной матрице более одного раза. */
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	system("color 5F");
	const int M = 100;
	int N, S, k = 0;
	static int A[M][M];
	do
	{
		cout << "Введите количество строк: "; // составляем матрицу
		cin >> N;
		if (N > M) cout << "Слишком большой размер! Введите число меньше\n";
	} while (N > M);
	cout << endl;
	do
	{
		cout << "Введите количество столбцов: ";
		cin >> S;
		if (S > M) cout << "Слишком большой размер! Введите число меньше\n";
	} while (N > M);
	for (int i = 0; i < N; i++)
	{
		cout << endl;
		for (int j = 0; j < S; j++)
		{
			A[i][j] = rand() % 10;
			cout << A[i][j] << " "; // заполняем матрицу случаными числами
		}
	}
	for (int i = 0; i < N; i++) // ищем число 0
	{
		cout << endl;
		for (int j = 0; j < S; j++)
		{
			if (A[i][j] == 0) {
				k = k + 1;
				j = S;
			};
		}
	}
	cout << "Число строк с элементом 0 - " << k << endl;
	system("pause");
}