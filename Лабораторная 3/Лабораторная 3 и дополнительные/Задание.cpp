//1. ���������� ���� �� ������ ����������� ����, ����������� ��������� ��������.
	/*		#include <iomanip> /*iomanip ��������� ����������� ��� ������ � ��������������� ������,
�������� ����, ������������ ��� �������������� �������� �����.*/
	/*				#include <iostream>
using namespace std; // ������������ ����
int main() 
{
	system("color 5F");
	setlocale(LC_CTYPE, "Rus"); // ������� ��������� �������� ������� ���������
	char p; p = ' ';
	char c;
	cout << "�������, ����������, ����� ������:\n";
	cin >> c;
	cout << setw(55) << setfill(p) << p; //setw(int n) � ���������� ������ ���� ������ � n ��������;setfill(int n) � ������-�����������; 
	printf("    %c%c%c%c%c \n", c, c, c,c,c); // ��������. ������������ �������������� %c � ������; 
	cout << setw(53) << setfill(p) << p;
	printf("   %c%c%c%c%c%c%c%c%c%c%c \n", c, c, c, c, c, c, c, c, c, c, c);
	cout << setw(52) << setfill(p) << p;
	printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  \n", c, c, c, c, c, c, c, c, c, c, c, c, c, c, c);
	cout << setw(52) << setfill(p) << p;
	printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c);
	cout << setw(52) << setfill(p) << p;
	printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  \n", c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c);
	cout << setw(52) << setfill(p) << p;
	printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", c, c, c, c, c, c, c, c, c, c, c, c, c, c, c);
	cout << setw(53) << setfill(p) << p;
	printf("   %c%c%c%c%c%c%c%c%c%c%c \n", c, c, c, c, c, c, c, c, c, c, c);
	cout << setw(55) << setfill(p) << p;
	printf("    %c%c%c%c%c \n", c, c, c,c,c);
	return(0);
} */