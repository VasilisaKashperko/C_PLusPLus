#include <iostream>;
#include <windows.h>;
using namespace std;
void massiv();
void matrix();

int main(void)
{
	setlocale(LC_CTYPE, "Russian");
	system("color 5F");
	int c;
	do
	{
		cout << "Выберите, с чем вы хотите работать:" << endl;
		cout << "1) одномерный массив" << endl;
		cout << "2) матрица" << endl;
		cout << "3) я не хочу работать :(" << endl;
		cin >> c;
		switch (c)
		{
		case 1: massiv(); break;
		case 2: matrix(); break;
		case 3: break;
		}
	} while (c != 3);
}

void massiv()
{
	const int max = 100;
	int a[max], raz, pro = 1, imin = -1, min = 101, sum = 0;
	setlocale(LC_CTYPE, "Russian");

	cout << "Введите число элементов массива: ";
	cin >> raz;
	cout << endl;

	for (int i = 0; i < raz; i++)
	{
		a[i] = rand() % 20 - 10;
		cout << a[i] << " ";
		if (a[i] > 0) { pro = pro * a[i]; };
		if (a[i] < min) {
			min = a[i];
			imin = i;
		}
	}

	for (int i = 0; i < imin; i++)
	{
		sum = sum + a[i];
	}
	cout << "Произведение положительных: " << pro << endl << "Сумма элементов, стоящих перед минимальным: " << sum << endl;
	system("pause");
}
void matrix()
{
	setlocale(LC_CTYPE, "Russian");
	const int M = 100;
	int N, S, ipol = 0, sumi = 0, i;
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
			A[i][j] = rand() % 12 - 2;
			cout << A[i][j] << " "; // заполняем матрицу случаными числами
		}
	}
	for (int i = 0; i < N; i++) // находим необходимую нам строку
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