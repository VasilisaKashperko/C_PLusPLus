#include <iostream> //7. Составить алгоритм решения ребуса КТО+КОТ=ТОК (различные буквы означают различные цифры, старшая - не 0).

int main()
{
    using namespace std;
    system("color 5F");
    setlocale(LC_CTYPE, "Rus");

    int z, c, i;

        for (int k = 1; k < 10; k++)
        {
            for (int o = 1; o < 10; o++)
            {
                for (int t = 1; t < 10; t++)
                {
                    z = 100 * k + 10 * t + o;
                    c = 100 * k + 10 * o + t;
                    i = 100 * t + 10 * o + k;
                   
                    if (z + c == i) {
                        

                            cout << z << "+";
                        cout << c << "=";
                        cout << i << endl;
                    }
                    
                }
            }
        }
}
   