// Лабораторная 18.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Создать текстовый файл F1 не менее, чем из 5 строк, и записать в него информацию. Скопировать в файл F2 только те строки из F1, которые начинаются с цифры.

#include <iostream>
#include <stdio.h>
const int n = 34;
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Rus");
	FILE* F1;
	FILE* F2;
	errno_t err, err2;
	char mass[n];
	err = fopen_s(&F1, "F1.txt", "w");
	if (err != NULL)
	{
		printf("Ошибка при открытии файла!");
		return -1;
	}
	for (int i = 0; i < 6; i++)
	{
		printf("String  %d : \n", i + 1);
		gets_s(mass);
		fputs(mass, F1);
		fputs("\n", F1);
	}
	fclose(F1);
	err = fopen_s(&F1, "F1.txt", "r");
	err2 = fopen_s(&F2, "F2.txt", "w");
	if (err2 != NULL)
	{
		printf("Ошибка при открытии файла!");
		return -1;
	}
	while (fgets(mass, 34, F1) != NULL) /* пока строки не закончатся в входном файле*/
	{
		if (mass[0] == '1' || mass[0] == '2' || mass[0] == '3' || mass[0] == '4' || mass[0] == '5' || mass[0] == '6' || mass[0] == '7' || mass[0] == '8' || mass[0] == '9')
		{

			fputs(mass, F2); /* вывод в выходной файл*/
		}
	}
	fclose(F1);
	fclose(F2);
	system("pause");
	return 0;
}

