#include <iostream> //В заданном предложении указать слово, в котором доля гласных (A, E, I, O, U — строчных или прописных) максимальна. 
#include <string>			

int main()
{
	using namespace std;
	setlocale(LC_CTYPE, "Rus");

	string str;
	int l, q = 0, j = 0, e = 0, num1 = 0, num2 = 0, num3 = 0;
	char arr_en[] = { 'a', 'e', 'i',  'o', 'u' };

	cout << "Введите строку: ";
	getline(cin, str);

	l = str.length();
	cout << endl;

	cout << "Максимально: ";
	for (int i = 0; i < l; i++)
	{
		if (str[i] != ' ')
			(q++);
		else																			
		{
			j = i;
			break;
		}
		q = 0;
	}
	for (int i = j; i < l; i++)
	{

		if (str[i] != ' ')
			(q++);
		else
		{
			e = i;
		}
		q = 0;
	}
	for (int i = 0; i < j; i++)
	{
		if (str[i] == arr_en[0] || str[i] == arr_en[1] || str[i] == arr_en[2] || str[i] == arr_en[3] || str[i] == arr_en[4])
			num1++;
	}
	for (int i = j; i < e; i++)
	{
		if (str[i] == arr_en[0] || str[i] == arr_en[1] || str[i] == arr_en[2] || str[i] == arr_en[3] || str[i] == arr_en[4])
			num2++;
	}
	for (int i = e; i < l; i++)
	{
		if (str[i] == arr_en[0] || str[i] == arr_en[1] || str[i] == arr_en[2] || str[i] == arr_en[3] || str[i] == arr_en[4])
			num3++;
	}
	if (num1 > num2 && num1 > num3)
	{
		for (int i = 0; i < j; i++)
			cout << str[i];
	}
	if (num2 > num1 && num2 > num3)
	{
		for (int i = j; i < e; i++)
			cout << str[i];
	}
	if (num3 > num1 && num3 > num2)
	{
		for (int i = e; i < l; i++)
			cout << str[i];
	}
	cout << endl;
}