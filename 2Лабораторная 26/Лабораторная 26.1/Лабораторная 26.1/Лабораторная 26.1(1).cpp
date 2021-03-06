//Разработать программу, реализующую рекурсивную функцию подсчета количества всех положительных делителей натурального числа n.  

//Рекурсивная функция  это функция c такой организацией работы, при которой она вызывает сама себя.
//Рекурсия должна иметь внутри себя условие завершения.Рекурсивная функция(программа) может быть 
//линейной(функция содержит един - ственный вызов самой себя), смешанной(две или более функций вызывают друг друга попеременно),
//ветвящейся(когда ре - курсивный вызов содержится в теле функции более одного раза, либо производится в цикле), 
//вложенной(имеется вызов функции внутри обращения к самой функции).


#include <iostream>
using namespace std;
int kol(int n, int x) {
	if (n < 0)
		return 0;
	if (x != 0)
	{
		if (n % x == 0)
		{
			return kol(n, x - 1) + 1;
		}
		else {
			return kol(n, x - 1);
		}
	}
	return 0;
}
int main()
{
	int n;
	cout << "Enter n" << endl;
	cin >> n;
	cout << kol(n, n) << endl;
	system("pause");
	return 0;
}
