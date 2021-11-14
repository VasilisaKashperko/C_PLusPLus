#include <iostream> /*Для заданной матрицы размером 6 на 6 найти такие значения к, что k-я строка матрицы совпадает с k-м столбцом.
Найти сумму элементов в тех строках, которые содержат хотя бы один отрицательный элемент.*/
#include <locale>

using namespace std;
void main()
{
	setlocale(LC_CTYPE, "rus");
	system("color 5F");

	const int m = 6;
	int arr[m][m],sum=0;
	cout << "Матрица: " << endl;	

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			
			arr[i][j]=-2+rand()%20;
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			
			if (j == i)
				(cout <<"arr["<<i <<","<<j <<"] = " << arr[i][j] << endl);
			if (arr[i][j] < 0)
			{
				for (int k = i; k < i+1; k++)
				{
					for (int j = 0; j < m; j++)
					{
						sum += arr[k][j];
					}
				}
			}
		}

		if (sum != 0)
		{
			cout << "Сумма строки с отрицательным числом = " << sum << endl;
			sum = 0;
		}

		cout << endl;
	}
}