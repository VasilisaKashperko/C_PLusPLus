#include <iostream>
using namespace std;	/*Проверить, есть ли в матрице хотя бы одна строка, 
						содержащая положительный элемент, и найти ее номер. 
						Знаки элементов предыдущей строки изменить на противоположные.*/
void polelement();
void polelement(int& n,int& m,int* arr[])
{
	int t = 0,k=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] > 0)
				t=i;
		}
	}
	if (t > 0)
	{
		cout << "Строка с пол. числом: " << t << endl;
		cout << "Числа " << t - 1 << " строки с противоположными знаками:" << endl;
		for (int i = t-1; i < t; i++)
		{
			for (int j = 0; j < m; j++)
			{
				arr[i][j] = arr[i][j] *(-1);
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
	}
	else cout << "Нет строк с пол. числами/пол. число в первой строке" << endl;;
}
void main()
{
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
			arr[i][j]=-8+rand()%10;
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
	polelement(n,m,arr);
	delete[]arr;
}