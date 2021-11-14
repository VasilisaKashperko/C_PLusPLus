#pragma once
struct AAA {
	int x;
	void Print();
	int GetPriority();
};
namespace heap {
	enum CMP { LESS = -1, EQUAL = 0, GREAT = 1 };
	struct Heap {
		int Size;
		int MaxSize;
		void** Storage;
		CMP(*Compare)(void*, void*);//��������� 2 ���������
		Heap(int maxsize, CMP(*f)(void*, void*))//����������� ���� ��������� ������� � � �������� �������� ��������� ���������
		{
			Size = 0;
			Storage = new void* [MaxSize = maxsize];
			Compare = f;
		};
		Heap(int maxsize, CMP(*f)(void*, void*), void* x[])//����������� ���� ��������� ������� � �������� �-�� ��������� ��������� � ���������� �������� �������� �
		{
			Size = 0;
			Storage = x;
			MaxSize = maxsize;
			Compare = f;
		};
		int Left(int ix);//������� ����� ������ �������� �� �������� ix
		int Right(int ix);//������� ����� ������� �������� �� �������� ix
		int Parent(int ix);//������� ����� ������������� �������� �� �������� ix
		bool isFull()//�������� ������ �� ����
		{
			return(Size >= MaxSize);//������� ���������� ��������� �������� ������� � ������������
		};
		bool isEmpty()//�������� ���� �� �������
		{
			return(Size <= 0);//��������� ��������� �������� ������� � 0
		};
		bool isLess(void* x1, void* x2)//��������� x1<x2
		{
			return Compare(x1, x2) == LESS;//������� ��������� ���������� ������� � ��������� ������������ LESS
		};
		bool isGreat(void* x1, void* x2)//��������� x1>x2
		{
			return Compare(x1, x2) == GREAT;//������� ��������� ���������� ������� � ��������� ������������ GREAT
		};
		bool isEqual(void* x1, void* x2)//��������� x1=x2
		{
			return Compare(x1, x2) == EQUAL;//������� ��������� ���������� ������� � ��������� ������������ EQUAL
		};
		void Swap(int i, int j);//������������ 2 ��������� � �������� i � j
		void Heapify(int ix);//������������ ���� �� �������
		void Insert(void* x);//������� �������� x � ����
		void* ExtractMax();//���������� ���� ��������(������� ����)
		void Deleteheap();//������� ����
		void Scan(int i);//����� ���� ������� � ��������� ��������
		void* ExtractMin();//�������� ��� �������� 
		void* ExtractI(int i);//�������� i-��� ��������
		void Union(Heap&);//����������� 2 ��� � 1 (����� � �������� ��������� ���� � ����� ��-�� �� ���)
	};
	Heap Create(int maxsize, CMP(*f)(void*, void*));//�������� ���� � �������� �������� � �-�� ���������

