//1. Нарисовать круг по центру консольного окна, закрашенный введенным символом.
#include <iomanip> /*iomanip реализует инструменты для работы с форматированием вывода,
например базу, используемую при форматировании значений чисел.*/
#include <iostream>
using namespace std; // пространство имен
int main()
{
	system("color 5F");
	setlocale(LC_CTYPE, "Rus"); // функция позволяет выводить символы кириллицы

	char p; p = ' ';
	int c;
	cout << "Введите, пожалуйста, любой символ:\n";
	cin >> c;
	cout << "\n";

	

	cout << setw(53) << setfill(p) << p; //setw(int n) – установить ширину поля вывода в n символов;setfill(int n) – символ-заполнитель;
	printf("   %c \n", c); // печатать. Спецификация преобразования %c – символ;
	cout << setw(53) << setfill(p) << p;
	printf("   %c \n", c);
	cout << setw(53) << setfill(p) << p;
	printf("   %c \n", c);
	cout << setw(49) << setfill(p) << p;
	printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", c, c, c, c, c, c, c, c, c, c, c, c, c, c);
	cout << setw(53) << setfill(p) << p; //setw(int n) – установить ширину поля вывода в n символов;setfill(int n) – символ-заполнитель;
	printf("   %c \n", c); // печатать. Спецификация преобразования %c – символ;
	cout << setw(53) << setfill(p) << p;
	printf("   %c \n", c);
	cout << setw(53) << setfill(p) << p;
	printf("   %c \n", c);

	cout << "\n";
	cout << endl;
	cout << "\n";

	cout << setw(55) << setfill(p) << p; //setw(int n) – установить ширину поля вывода в n символов;setfill(int n) – символ-заполнитель; 
	printf("    %c%c%c%c%c \n", c, c, c, c, c); // печатать. Спецификация преобразования %c – символ; 
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
	printf("    %c%c%c%c%c \n", c, c, c, c, c);
	return(0);
}