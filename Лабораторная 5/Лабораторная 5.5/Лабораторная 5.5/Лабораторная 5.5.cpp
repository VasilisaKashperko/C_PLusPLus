#include <iostream>;

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Rus");
	system("color 5F");

	int n, nr = 1;
	int p, r, v, l, g;

	int kolm=0, kold = 0, r1 = 0, v1 = 0;
	int r2 = 1000, a2 = 1000;

	int letvsm=0, letvsd = 0 ;
	float letsredm, letsredd;

	int x = 0, y = 0;

	cout << "Введите количество детей - ";
	cin >> n;
	cout << endl;

	while (n >= 1)
	{
		cout << "Введите пол " << nr << "-го ребенка (0 - мальчик, 1 - девочка) - ";
		cin >> p;
		cout << "Введите год рождения ребенка - ";
		cin >> g;
		l = 2020 - g;
		cout << "Введите рост ребенка - ";
		cin >> r;
		cout << "Введите вес ребенка - ";
		cin >> v;
		cout << endl;

		if (p == 0) {
			kolm = kolm + 1; letvsm = letvsm + l;
		}
		else
		{
			kold = kold +1; letvsd= letvsd + l;
		}


		if (p == 0 && r > r1)
			r1 = r; {


			if (v > v1)
			{
				v1 = v;
				x = 1;
			}
			else
				x = 0; }


		if (p == 1 && r < r2) {
			r2 = r;
			if (l < a2) {
				a2 = l;
				y = 1;
			}
			else { y = 0; };
		};

		n = n - 1;
		nr = nr + 1;
	}
	cout << "Количество мальчиков в классе - " << kolm << endl;
	cout << "Количество девочек в классе - " << kold << endl;

	letsredm = letvsm / kolm;
	letsredd = letvsd / kold;

	cout << "Средний возраст мальчиков - " << letsredm << endl;
	cout << "Средний возраст девочек - " << letsredd << endl;

	if (x == 1)
		cout << "Самый высокий мальчик весит больше всех" << endl;
	else
		cout << "Самый высокий мальчик НЕ весит больше всех" << endl;

	if (y == 1) {
		cout << "Самая низкая девочка - младшая в классе" << endl;
	}
	else {
		cout << "Самая низкая девочка НЕ младшая в классе" << endl;
	}

	return 0;

}
