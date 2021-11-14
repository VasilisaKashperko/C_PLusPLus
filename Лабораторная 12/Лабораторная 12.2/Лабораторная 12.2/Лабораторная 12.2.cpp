/* Преобразовать строку : после каждой буквы a добавить символ !
*/

#include <iostream>
#include <string>;

 void main()
{
	using namespace std;
	system("color 5F");
	setlocale(LC_CTYPE, "Rus");

	string str;
	char a;
	int c = 0;
	char b = '!';

	cout << "Придумайте предложение: " << endl;
	cin >> str;

	cout << "Введите символ, после которого будет стоять восклицательный знак: ";
	cin >> a;

	
	for (int i = 0; i < str.length(); i++) {
		cout << str[i];
		if (str[i] == a) {
			cout << b;
		}
	}
	cout << endl;
}