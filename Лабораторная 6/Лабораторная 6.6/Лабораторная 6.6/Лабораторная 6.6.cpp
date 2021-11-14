
#include <iostream>;
using namespace std;
void main()
{
	int f = 100, f1, f2, f3, ki;
	double k, a;
	while (f <= 999) {
		f1 = f / 100;
		f2 = f % 100 / 10;
		f3 = f % 10;
		k = sqrt(f);
		ki = sqrt(f);
		a = k - ki;
	}
	if (f1 < f2 && f2 < f3 && a == 0)
	{
		cout << f << endl;
	}
	f = f + 1;
	system("pause");
}
	