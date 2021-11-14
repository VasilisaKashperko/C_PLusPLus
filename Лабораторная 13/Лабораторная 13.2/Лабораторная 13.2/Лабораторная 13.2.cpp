#include <iostream> 
#include <ctime> 
#include <cstdlib> 
#include <iomanip>  //В заданной матрице A(N, M) поменять местами столбцы с номерами P и Q.

using namespace std;

int main()
{
    setlocale(0, "rus"); 

    system("color 5F");

    srand((unsigned)time(0));
    const int N = 5; // размеры
    const int M = 5;
    int matrix[N][M]; // матрица
    int i, j;

    int p, q;

    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            matrix[i][j] = rand() % 10; // заполняем матрицу случайными числами от 0 до 10

    for (i = 0; i < N; i++) // выводим исходную матрицу
        for (j = 0; j < M; j++)
        {
            if (j % M == 0) // после 5 чисел переход на новую строку
                cout << endl;
            cout << setw(3) << matrix[i][j]; // ширина поля 3
        }
    cout << endl;

    cout << "Введите номера столбцов" << endl; // незабываем что отсчёт идёт с 0
    cin >> p >> q;                             // то есть столбцы от 0 до 4
    cout << endl;

    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
        {
            int temp = matrix[i][p]; // временному элементу присваиваем со элемент П
            matrix[i][p] = matrix[i][q]; 
            matrix[i][q] = temp;       
        }

    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
        {
            if (j % M == 0)
                cout << endl;
            cout << setw(3) << matrix[i][j]; // выводим изменённую матрицу
        }
    cout << endl;

    system("Pause");

}