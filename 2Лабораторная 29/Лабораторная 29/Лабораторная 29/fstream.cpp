#include "Header.h"
#include <iostream>
#include <iomanip>
using namespace std;
void AAA::Print()
{
	std::cout << x;
}
int AAA::GetPriority()
{
	return x;
}
namespace heap
{
	Heap Create(int maxsize, CMP(*f)(void*, void*))//�������� ���� � �������� ���� �������� � �-�� ��������� 2 ���������
	{
		return*(new Heap(maxsize, f));//������� ����� ���� � ���������� ��
	}
	int Heap::Left(int ix)//�������� ������ ������ ������� �������� ix
	{
		return (2 * ix + 1 >= Size) ? -1 : (2 * ix + 1);//���� ����� ������ ������� ������� �� ������� �������� ���������� ��������� � ����, �� ����� -1, ����� ����� ����������� ��������
	}
	int Heap::Right(int ix)//�������� ������ ������� ������� �������� ix
	{
		return (2 * ix + 2 >= Size) ? -1 : (2 * ix + 2);//���� ����� ������ ������� ������� �� ������� �������� ���������� ��������� � ����, �� ����� -1, ����� ����� ������������ ��������
	}
	int Heap::Parent(int ix)//��������� ������ ������������� �������� ix
	{
		return (ix + 1) / 2 - 1;//������� ������ ��� ��������
	}
	void Heap::Swap(int i, int j)//������������ 2 ���������
	{
		void* buf = Storage[i];//���������� i-�� ������� ������� � ������(Storage-������ ��������� ������ ����)
		Storage[i] = Storage[j];//�� ����� i-��� �������� ���������� j-��
		Storage[j] = buf;//�� ����� j-��� �������� ���������� ��, ��� ��������� � buf
	}
	void Heap::Heapify(int ix)//������������ ���� � �������(ix-����� �������� ��������)
	{
		int l = Left(ix), r = Right(ix), irl = ix;//irl = ix-���������� ��� �������� ������ ������ �� 3 ���������(����� ��� � ����)
		if (l > 0)
		{
			if (isGreat(Storage[l], Storage[ix]))
				irl = l;
			if (r > 0 && isGreat(Storage[r], Storage[irl]))
				irl = r;
			if (irl != ix)
			{
				Swap(ix, irl);
				Heapify(irl);
			}
		}
	}
	void Heap::Insert(void* x)//������� �������� � ����
	{
		int i;
		if (!isFull())
		{
			i = Size;
			Storage[i] = x;
			Size++;
			while (i > 0 && isLess(Storage[Parent(i)], Storage[i]))//���� �� ������ �� ������� � ���� ��� ��������������������
			{
				Swap(Parent(i), i);
				i = Parent(i);//����� �������� ������������ �������� ���������� ������� ��� ��������
			}
		}
	}
	void* Heap::ExtractMax()
	{
		void* rc = NULL;
		if (!isEmpty())
		{
			rc = Storage[0];//������������ ������� ����� ����� �������� �������
			Storage[0] = Storage[Size - 1];//�� ����� ��� �������� ���������� ��������� �������
			Size--;
			Heapify(0);//������������� ���� ������� � ����
		}
		Heapify(0);
		return rc;
	}
	void Heap::Scan(int i)//����� ����
	{
		int probel = 20;
		std::cout << "\n";
		if (Size == 0)
			std::cout << "The heap is empty";
		for (int u = 0, y = 0, level = 1; u < Size; u++)
		{
			cout << setw(probel + 10) << setfill(' ');
			((AAA*)Storage[u])->Print();
			if (u == y)//���� ����� �� ����� ����� ������(y-����� ������� ���� � ����� ������)
			{
				level++;
				cout << "\n";
				if (y == 0)//���� ����� ������� �������
					y = 2;//����� ���������� �������� � ���� 1-�� ������=2
				else y = pow(2, level) - 2;//����� ����������� ����� ���� �������� ��� ����  ������(level-����� ��� ������)
			}
			probel /= 2;
		}
		cout << '\n';
	}
	void Heap::Deleteheap()
	{
		if (!isEmpty())
		{
			Size = 0;
			this->~Heap();
		}
	}
	void* Heap::ExtractMin()
	{
		void* rc = NULL;
		if (Size > 0)
		{
			int j = Size / 2;//����� ��� ��������
			for (int i = Size / 2; i < Size; i++)//Size/2-�����1-�� �������� � ���� ����, Size-������ ����
			{
				if (Compare(Storage[i], Storage[j]) == LESS)//���� i-�� ����<���(Storage[i])
				{
					j = i;//���������� ����� ���������� ��� ��������
				}
			}
			rc = Storage[j];//��-� ��� ��������
			Swap(j, Size - 1);//������ ������� ���� ������� � ���������
			Size--;//��������� ������ ����
		}
		Heapify(0);
		return rc;//������� ��-� ���� ��� ��������
	}
	void* Heap::ExtractI(int i)//�������� i-��� ��������
	{
		void* rc = NULL;
		if (Size > 0 && i >= 0 && i < Size)
		{
			rc = Storage[i];
			Swap(i, Size - 1);//������������ ������� ��������� ������� � ����
			Size--;
		}
		Heapify(0);
		return rc;
	}
	void Heap::Union(Heap& h2)//����������� 2 ��� � 1
	{
		while (!h2.isEmpty())//���� �� �������� 2 ����
			Insert(h2.ExtractMax());//��������� ������� �� 2 ���� � ��������� � 1
	}
}
