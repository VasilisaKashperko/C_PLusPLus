// Ввести с клавиатуры строку символов, состоящую из цифр и скобок, и записать ее в файл. 
// Прочитать из файла данные, посчитать и вывести количество скобок различного вида.

#include<iostream>
#include<fstream>

const int n = 256;
const char file1[n] = "File1.txt";
const char file2[n] = "File2.txt";
using namespace std;
void input_file(const char* file_read, char* str);
void output_file(const char* file_write, char* str);

int main()
{
	char str[n];
	cin >> str;
	output_file(file1, str);
	char str2[n];
	input_file(file1, str2);
	char ans[n];
	int A[n], k = 0;
	for (int i = 0; i < n; i++)
	{
		A[i] = 0;
	}

	for (int i = 0; i < strlen(str2); i++)
	{
		switch (str2[i])
		{
		case '}':A[0]++; break;
		case '{':A[1]++; break;
		case ')':A[2]++; break;
		case '(':A[3]++; break;
		case '[':A[4]++; break;
		case ']':A[5]++; break;
		case '<':A[6]++; break;
		case '>':A[7]++; break;
		}
	}
	sprintf_s(ans, "} %d\n{ %d\n) %d\n( %d\n[ %d\n] %d\n< %d\n< %d\n", A[0], A[1], A[2], A[3], A[4], A[5], A[6], A[7]);
	output_file(file2, ans);


	return 0;
}
void output_file(const char* file_write, char* str)
{
	ofstream fout(file_write);
	fout << str;
}
void input_file(const char* file_read, char* str)
{
	ifstream fin(file_read);
	fin >> str;
}
