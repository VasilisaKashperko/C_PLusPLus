#include <iostream>  //Преобразовать строку таким образом, чтобы в ее начале были записаны слова, 
#include <string>	//содержащие только цифры, потом слова, содержащие только буквы, а затем слова, которые содержат и буквы и цифры.

int main(){	
	using namespace std;
	string str;
	setlocale(LC_CTYPE, "Rus");

	int l, q = 0, j = 0, e = 0, num1 = 0, num2 = 0, num3 = 0;
	char arr_num[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };

	cout << "Введите строку, ок?: ";
	getline(cin, str);

	l = str.length();
	cout << endl;

	cout << "Новая строка: ";
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
		if (str[i] == arr_num[0] || str[i] == arr_num[1] || str[i] == arr_num[2] || str[i] == arr_num[3] || str[i] == arr_num[4] || str[i] == arr_num[5] || str[i] == arr_num[6] || str[i] == arr_num[7] || str[i] == arr_num[8] || str[i] == arr_num[9])
		{
			num1++;
		}
	}

	for (int i = j; i < e; i++)
	{
		if (str[i] == arr_num[0] || str[i] == arr_num[1] || str[i] == arr_num[2] || str[i] == arr_num[3] || str[i] == arr_num[4] || str[i] == arr_num[5] || str[i] == arr_num[6] || str[i] == arr_num[7] || str[i] == arr_num[8] || str[i] == arr_num[9])
		{
			num2++;
		}
	}

	for (int i = e; i < l; i++)
	{
		if (str[i] == arr_num[0] || str[i] == arr_num[1] || str[i] == arr_num[2] || str[i] == arr_num[3] || str[i] == arr_num[4] || str[i] == arr_num[5] || str[i] == arr_num[6] || str[i] == arr_num[7] || str[i] == arr_num[8] || str[i] == arr_num[9])
		{
			num3++;
		}
	}

	if (num1 > num2 && num1>num3 && num3>num2)
	{
		for (int i = 0; i < l; i++)
			cout << str[i];
	}

	if (num2 > num1 && num2 > num3 && num3 > num1)
	{
		for (int i = j; i < e; i++)
			cout << str[i];
		cout << " ";
		for (int i = 0; i < j; i++)
			cout << str[i];
		for (int i = e; i < l; i++)
			cout << str[i];
	}

	if (num3 > num1 && num3 > num2 && num2>num1)
	{
		for (int i = e; i < l; i++)
			cout << str[i];
		cout << " ";
		for (int i = 0; i < j; i++)
			cout << str[i];
		for (int i = j; i < e; i++)
			cout << str[i];
	}

	if (num1 > num2 && num1 > num3 && num2 > num3)
	{
		for (int i = 0; i < j; i++)
			cout << str[i];
		for (int i = e; i < l; i++)
			cout << str[i];
		for (int i = j; i < e; i++)
			cout << str[i];
	}

	cout << endl;
}