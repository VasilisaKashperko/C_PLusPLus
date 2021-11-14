#include <iostream> /*Дана квадратная матрица, элементы которой формируются случайным образом и находятся в пределах от -10 до 10
					Получить новую матрицу, переставляя ее блоки размера n×n в соответствии со схемой*/
#include <locale>
#include <ctime>

using namespace std;
void main()
{
	setlocale(LC_CTYPE, "rus");
	system("color 5F");
	int m;

	cout << "Кол-во строк и столбцов: ";							
	cin >> m;														
	
	int** arr= new int*[m];
	srand((unsigned)time(NULL));

	for (int i = 0; i < m; i++)
	{
		arr[i] = new int [m];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			
			arr[i][j]=-10+rand()%20;
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

	cout << endl;
	cout << char(3); cout << char(1); cout << char(3); cout << char(1); cout << char(3); cout << char(1); cout << char(3);
	cout << endl<<endl;

	cout << "Новая матрица: "<<endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			
			if (j == i || i==m-j-1)
				(cout << m << "\t");
			else cout << arr[i][j] << "\t";
			
		}
		cout << endl;
	}
}