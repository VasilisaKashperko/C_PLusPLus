/* Написать программу, которая удаляет в строке все буквы b в тексте,
написанном латинскими буквами.
*/

#include <iostream>
#include <string>;

int main()
{
	using namespace std;
	system("color 5F");
	setlocale(LC_CTYPE, "Rus");
	
		string str; //char s[256]; char *ps;
		char a;
		int c = 0;

		cout << "Придумайте предложение: " << endl;
		cin >> str; //gets_s(s);

		cout << "Введите символ, который вам больше не нужен в предложении: ";
		cin >> a;

		for (int i = 0; i < str.length(); i++) { //count = 0, ps = s; *ps != str.length();ps++

			if (str[i] == a) { //(*ps == a)
				str.erase(i, 1);
				i--;
			}
		}

		cout << str << endl;
		return 0;
	}