#include <iostream>;
#include <windows.h>

using namespace std;

void main()
{
    setlocale(LC_CTYPE, "Russian");

	const int maxned = 52;
	int sum[maxned], a[maxned], ned, maxn=0, maxo=0;
	
	cout << "Введите количество недель: ";
	cin >> ned;
	sum[0] = 0;
	for (int k = 1; k <= ned; k++) { // вводим цикл на введенное количество недель
		cout << "Неделя " << k << endl;
		sum[k] = 0;
		for (int i = 1; i <= 7; i++) { // вводим количество осадков для каждого дня
			cout << "Введите количество осадков в " << i << " день: ";
			cin >> a[i];
			sum[k] = sum[k] + a[i]; // суммируем количество осадков на неделю
		}
		if (sum[k] > maxo) { // проверяем, больше ли всего осадков на данной неделе
			maxn = k;
			maxo = sum[k];
		}
		cout << endl;
	}
	cout << "Максимальные осадки на " << maxn << " неделе в количестве " << maxo << endl;
	system("pause");

    Beep(392.00, 500);
    Sleep(50);
    Beep(392.00, 500);
    Sleep(50);
    Beep(392.00, 500);
    Sleep(50);
    Beep(311.13, 650);
    Beep(466.16, 250);
    Beep(392.00, 500);

    Beep(311.13, 650);
    Beep(466.16, 250);
    Beep(392.00, 1000);
    Sleep(50);

    Beep(587.33, 500);
    Sleep(50);
    Beep(587.33, 500);
    Sleep(50);
    Beep(587.33, 500);
    Sleep(50);
    Beep(622.5, 600);
    Beep(466.16, 250);

    Beep(369.99, 500);
    Sleep(50);
    Beep(311.13, 500);
    Beep(466.16, 250);
    Beep(392.00, 1000);
}
