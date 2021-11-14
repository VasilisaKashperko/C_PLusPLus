//#include <ctime>             
//#include <stdlib.h>
//#include <iostream>
//using namespace std;
//
//void* countSort(int in[], int out[], int size)					//���������� ���������
//{
//	int i, j, count;
//	for (i = 0; i < size; ++i)
//	{
//		for (count = 0, j = 0; j < size; ++j)
//			if (in[j] < in[i] || (in[j] == in[i] && i < j))
//				count++;
//		out[count] = in[i];
//	}
//	return out;
//}
//
////------------------------------
//void* bubbleSort(int a[], int n)								//���������� ���������
//{
//	int i, j, t;
//	for (i = 1; i < n; i++)
//		for (j = n - 1; j >= i; j--)
//			if (a[j - 1] > a[j])
//			{
//				t = a[j - 1];
//				a[j - 1] = a[j];
//				a[j] = t;
//			}
//	return a;
//}
////------------------------------
//int getHoarBorder(int A[], int sm, int em)						//���������� �����
//{
//	int i = sm - 1, j = em + 1;
//	int brd = A[sm];
//	int buf;
//	while (i < j)
//	{
//		while (A[--j] > brd);
//		while (A[++i] < brd);
//		if (i < j)
//		{
//			buf = A[j];
//			A[j] = A[i];
//			A[i] = buf;
//		};
//	}
//	return j;
//}
//int* sortHoar(int A[], int sm, int em)
//{
//	if (sm < em)
//	{
//		int hb = getHoarBorder(A, sm, em);
//		sortHoar(A, sm, hb);
//		sortHoar(A, hb + 1, em);
//	}
//	return A;
//};
//
////------------------------------
//int getRandKey(int reg = 0)     // ��������� ��������� ������
//{
//	if (reg > 0)
//		srand((unsigned)time(NULL));
//	int rmin = 0;
//	int rmax = 100000;
//	return (int)(((double)rand() / (double)RAND_MAX) * (rmax - rmin) + rmin);
//}
////------------------------------
//int main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	const int N = 50000;
//	int k[N], f[N], h[N], p[N];
//	int F[N];									//�������������� ������ ��� ���������� ���������
//	clock_t  t1, t2;							//���������� ��� �������� ������
//	getRandKey(1);								//��������� ������� k
//	for (int i = 0; i < N; i++)
//		k[i] = getRandKey(0);
//	getRandKey(1);								//��������� ������� f
//	for (int i = 0; i < N; i++)
//		f[i] = getRandKey(0);
//	getRandKey(1);								//��������� ������� h
//	for (int i = 0; i < N; i++)
//		h[i] = getRandKey(0);
//	for (int n = 10000; n <= N; n += 10000)
//	{
//		cout << "n = " << n << endl;
//		cout << "���������� ��������� ";
//		memcpy(p, k, n * sizeof(int));
//		t1 = clock();							//����� �� ����������
//		bubbleSort(k, n);
//		t2 = clock();							//����� ����� ����������
//		cout << "������ " << t2 - t1 << " ������ �������" << endl;	//������� �����
//
//		cout << "���������� ��������� ";
//		memcpy(p, f, n * sizeof(int));
//		t1 = clock();							//����� �� ����������
//		countSort(f, F, n);
//		t2 = clock();							//����� ����� ����������
//		cout << "������ " << t2 - t1 << " ������ �������" << endl;	//������� �����
//
//		cout << "���������� ������� ����� ";
//		memcpy(p, h, n * sizeof(int));
//		t1 = clock();							//����� �� ����������
//		sortHoar(h, 0, n - 1);
//		t2 = clock();							//����� ����� ����������
//		cout << "������ " << t2 - t1 << " ������ �������" << endl << endl;	//������� �����
//	}
//	return 0;
//}

//2//////////////////////////////////////////////////////////////////////////////////////////////

//#include <iostream>
//using namespace std;
//void bubbleSort(int a[], int n);					//���������� ������� �������� 
//
//void main()
//{
//	setlocale(LC_ALL, "Rus");
//	int sizeA, i, max, k = 0;
//	int A[100];										//������ �
//
//	cout << "���������� ��������� ������� � = ";	//���� ������� �
//	cin >> sizeA;
//	cout << "������� ������ �:" << endl;
//	for (i = 0; i < sizeA; i++)
//	{
//		cout << i + 1 << " ������� = ";
//		cin >> A[i];
//	}
//
//	cout << "��������� ������ A:" << endl;			//����� ������� �
//	for (i = 0; i < sizeA; i++)
//	{
//		cout << A[i] << " ";
//	}
//	cout << endl;
//
//	max = A[0];
//	for (int i = 0; i < sizeA; i++)					//������� ����� ������������� ��������
//	{
//		if (A[i] > max)
//		{
//			k = i;
//			max = A[i];
//		}
//	}
//
//	bubbleSort(A, sizeA);							//��������� ������
//	for (int i = 0; i < sizeA; i++)
//		cout << A[i] << '\t';
//	cout << endl;
//	cout << "������������ ������� " << A[sizeA - 1] << " � ��� ����� " << k + 1 << endl;
//	cout << "����������� ������� " << A[0] << endl;
//}
//
//
//void bubbleSort(int a[], int n)									//���������� ������� ��������
//{
//	int i, j, t;
//	for (i = 1; i < n; i++)
//		for (j = n - 1; j >= i; j--)
//			if (a[j - 1] > a[j])
//			{
//				t = a[j - 1];
//				a[j - 1] = a[j];
//				a[j] = t;
//			}
//}


//3//////////////////////////////////////////////////////////////////////////////////////////////////


//#include <iostream>
//using namespace std;
//
//void main()
//{
//	setlocale(LC_ALL, "Rus");
//	int sizeA, i;
//	int A[100];										//������ �
//
//	sizeA = 10;
//	cout << "������� ������ �:" << endl;			//���� ������� �
//	for (i = 0; i < sizeA; i++)
//	{
//		cout << i + 1 << " ������� = ";
//		cin >> A[i];
//	}
//
//	cout << "��������� ������ A:" << endl;			//����� ������� �
//	for (i = 0; i < sizeA; i++)
//	{
//		cout << A[i] << " ";
//	}
//	cout << endl;
//
//	int j, t;
//	for (i = 0; i < 4; i++)							//���������� ������ 4-�� ��������� �� �����������
//		for (j = 0; j < 4; j++)
//			if (A[j] > A[i])
//			{
//				t = A[i];
//				A[i] = A[j];
//				A[j] = t;
//			}
//
//	for (i = 6; i < sizeA; i++)						//���������� ��������� 4-�� ��������� �� ��������
//		for (j = 6; j < sizeA; j++)
//			if (A[j] < A[i])
//			{
//				t = A[i];
//				A[i] = A[j];
//				A[j] = t;
//			}
//
//	cout << "��������������� ������ A:" << endl;			//����� ���������������� ������� �
//	for (i = 0; i < sizeA; i++)
//	{
//		cout << A[i] << " ";
//	}
//	cout << endl;
//}



//4////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <ctime>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	int sizeA, i;
	int A[100];										//������ �
	int B[100];										//�������������� ������
	int count = 0;									//������� ��������������� �������

	sizeA = 15;
	srand((unsigned)time(NULL));
	for (i = 0; i < sizeA; i++)						//�������� ������� ������� �
	{
		A[i] = -5 + rand() % 10;
	}

	cout << "��������� ������ A:" << endl;			//����� ������� �
	for (i = 0; i < sizeA; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	int j, t;
	for (i = 0; i < sizeA; i++)							//���������� ������� �� �����������
		for (j = 0; j < sizeA; j++)
			if (A[j] > A[i])
			{
				t = A[i];
				A[i] = A[j];
				A[j] = t;
			}

	cout << "��������������� ������ A:" << endl;	//����� ���������������� ������� �
	for (i = 0; i < sizeA; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	for (i = 0; i < sizeA; i++)							//���������� �� ������������� ��������� 
			if (A[i] != A[i + 1])
			{
				B[count] = A[i];
				count++;
			}

	cout << "�������������� ������ A:" << endl;			//����� ������� � � ���������� �������������� ����������
	for (i = 0; i < count; i++)
	{
		cout << B[i] << " ";
	}
	cout << endl;
}

