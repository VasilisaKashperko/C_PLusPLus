#include <iostream>
using namespace std; /*Найти в матрице строку, все элементы которой равны нулю.
					 Все элементы столбца с таким же номером уменьшить вдвое.*/

void nullstolb();
void nullstolb(int& n,int& m,int* arr[])
{
	int t = 0,k=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0)
				t++;
		}
		if (t == m)
			k = i;
		t = 0;
	}
	if (k != 0)
	{
		cout << "Строка с нулями: " << k + 1 << endl;
		cout << "Уменьшенные на 2 элементы " << k + 1 << " столбца:" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = k; j < k + 1; j++)
			{
				arr[i][j] = arr[i][j] / 2;
				cout << arr[i][j];
			}
			cout << endl;
		}
	}
	else cout << "Нет строк с нулями" << endl;
}
void main()
{
	system("color 5F");
	setlocale(LC_CTYPE, "rus");
	int m, n;
	cout << "Количество строк: ";
	cin >> n;
	cout << "Количество столбцов: ";
	cin >> m;
	int** arr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			cout << "Элемент матрицы: ";
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] <<"\t";
		}
		cout << endl;
	}
	nullstolb(n,m,arr);
	delete[]arr;
}