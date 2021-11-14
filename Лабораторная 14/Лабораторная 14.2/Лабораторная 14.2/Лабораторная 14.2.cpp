#include <iostream>; 
#include <windows.h>// Найти в матрице первую строку, все элементы которой положительны, и сумму этих элементов. Уменьшить все элементы матрицы на эту сумму.
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	const int M = 100;
	int N, S, ipol = 0, sumi = 0, i;
	static int A[M][M];
	do
	{
		cout << "Введите количество строк: "; // составляем матрицу
		cin >> N;
		if (N > M) cout << "Введите число меньше\n";
	} while (N > M);
	cout << endl;
	do
	{
		cout << "Введите количество столбцов: ";
		cin >> S;
		if (S > M) cout << "Введите число меньше\n";
	} while (N > M);
	for (int i = 0; i < N; i++)
	{
		cout << endl;
		for (int j = 0; j < S; j++)
		{
			A[i][j] = rand() % 12 - 2;
			cout << A[i][j] << " "; // заполнение матрицы случаными числами
		}
	}
	for (int i = 0; i < N; i++) // нахождение необходимой строки
	{
		cout << endl;
		for (int j = 0; j < S; j++)
		{
			if (A[i][j] <= 0) {
				j = S;
			};
			if ((A[i][j] > 0) && (j == S)) {
				ipol = i;
				i = N;
				j = S;
			};
		}
	}
	i = ipol;
	for (int j = 0; j < S; j++)
	{
		sumi = sumi + A[i][j]; // находим сумму элементов данной строки
	}
	cout << "Номер первой строки со всеми положительными элементами: " << ipol + 1 << endl << "Сумма элементов данной строки: " << sumi << endl;
	cout << "Матрица с вычтенной суммой элементов: " << endl;
	for (int i = 0; i < N; i++)
	{
		cout << endl;
		for (int j = 0; j < S; j++)
		{
			A[i][j] = A[i][j] - sumi;
			cout << A[i][j] << " "; // выводим готовую матрицу
		}
	}
	system("pause");
	system("pause");
	Beep(659.26, 200);
	Beep(659.26, 200);
	Sleep(200);
	Beep(659.26, 200);
	Sleep(100);
	Beep(523.26, 200);
	Beep(659.26, 200);
	Sleep(200);
	Beep(783.98, 200);
	Sleep(400);
	Beep(391.99, 200);
}