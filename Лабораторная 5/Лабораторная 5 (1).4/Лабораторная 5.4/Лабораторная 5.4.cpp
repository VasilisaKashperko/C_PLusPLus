#include <iostream> //7. Составить алгоритм решения ребуса КОТ+КОТ=ТОК (различные буквы означают различные цифры, старшая - не 0).

int main()
{
    using namespace std;
    system("color 5F");
    setlocale(LC_CTYPE, "Rus");

    int z,c,i;
   
    for (int k = 1; k < 10; k++)
    {
        for (int o = 1; o < 10; o++)
        {
            for (int t = 1; t < 10; t++)
            {
                z = 100 * k + 10 * o + t;
                c = z + z;
                i = 100 * t + 10 * o + k;
                if (c == i)
                    cout << "КОТ + КОТ = ТОК\n" << z, i;
                if (c != i)
                    cout << "Такого решения нет\n" << z,i;
            }
        }
    }
  
}
