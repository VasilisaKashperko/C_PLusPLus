// Сравнение файлов.
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	register int i;
	unsigned char buf1[1024], buf2[1024];
		cout << "Применение: сравнение файлов test " << "и test1 \n";
	ifstream f1("test.txt", ios::in | ios::binary);
	if (!f1) {
		cout << "He удается открыть первый файл.\n";
		return 1;
	}
	ifstream f2("test1.txt", ios::in | ios::binary);
	if (!f2) {
		cout << "He удается открыть второй файл.\n";
		return 1;
	}
	cout << "Сравнение файлов ...\n";
	do {
		f1.read((char*)buf1, sizeof buf1);
		f2.read((char*)buf2, sizeof buf2);
		if (f1.gcount() != f2.gcount()) {
			cout << "Файлы имеют разные размеры.\n";
			f1.close();
			f2.close();
			return 0;
		}
		// Сравнение содержимого буферов.
		for (i = 0; i < f1.gcount(); i++)
			if (buf1[i] != buf2[i]) {
				cout << "Файлы различны.\n";
				f1.close();
				f2.close();
				return 0;
			}
	} while (!f1.eof() && !f2.eof());
	cout << "Файлы одинаковы.\n";
	f1.close();
	f2.close();
	return 0;
}
