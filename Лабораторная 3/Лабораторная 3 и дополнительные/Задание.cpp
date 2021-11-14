//1. Ќарисовать круг по центру консольного окна, закрашенный введенным символом.
	/*		#include <iomanip> /*iomanip реализует инструменты дл€ работы с форматированием вывода,
например базу, используемую при форматировании значений чисел.*/
	/*				#include <iostream>
using namespace std; // пространство имен
int main() 
{
	system("color 5F");
	setlocale(LC_CTYPE, "Rus"); // функци€ позвол€ет выводить символы кириллицы
	char p; p = ' ';
	char c;
	cout << "¬ведите, пожалуйста, любой символ:\n";
	cin >> c;
	cout << setw(55) << setfill(p) << p; //setw(int n) Ц установить ширину пол€ вывода в n символов;setfill(int n) Ц символ-заполнитель; 
	printf("    %c%c%c%c%c \n", c, c, c,c,c); // печатать. —пецификаци€ преобразовани€ %c Ц символ; 
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