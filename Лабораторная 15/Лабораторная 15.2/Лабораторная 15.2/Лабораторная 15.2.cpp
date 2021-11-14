#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <locale>
using namespace std;

//В строке есть два символа (). Получить все символы между первым и вторым символом (. 
char* osn2(const char* s) {
	setlocale(LC_ALL, "Russian");
	int k = strlen(s);
	int p = 0, p1 = 0;
	for (int i = 0; i < k; i++) {
		if (s[i] == ')') {
			p = i;
		}
		if (s[i] == '(')
			p1 = i;
	}
	char* s1 = new char[p - p1];
	for (int i = p1 + 1; i < +p; i++) {
		s1[i - p1 - 1] = s[i];
		if (i == p) {
			s1[i] = '\0';
		}
	}
	return s1;
}

void main()
{
	system("color 5F");
	setlocale(LC_ALL, "Russian");
	char str[256];
	cin >> str;
	cout << osn2(str);
}


//#include <iostream>; // В строке есть два символа (). Получить все символы между первым и вторым символом (). 
//using namespace std;
//int main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	char str[256];
//	int c = 0;
//	cout << "Введите строку с двумя *" << endl;
//	cin >> str;
//	for (int i = 0; i < strlen(str); i++) {
//		if (c == 0) {
//			if (str[i] == '*') c++;
//		}
//		else
//		if (str[i] == '*') break;
//		else cout << str[i];
//	}
//	cout << endl;
//	system("pause");
//}