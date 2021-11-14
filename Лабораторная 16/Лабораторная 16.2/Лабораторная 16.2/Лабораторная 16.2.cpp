#include <stdarg.h>  /*Написать функцию kvadr с переменным числом параметров,
int kvadr(int cnt, ...)   которая определяет количество чисел,
являющихся точными квадратами (2, 4, 9, 16,…) типа int.*/

#include <iostream> 

int kvadr(int cnt, ...)

{
    va_list vl; //создает сама функцию
    va_start(vl, cnt);
    int kvadr = 0;
    for(int i=0;i<cnt;i++)
    {
        int n = va_arg(vl, int);                                         
        if (n > 0) 
        {
            if (sqrt(n) - ceil(sqrt(n))==0) 
            {
                kvadr++;
            }
        }
    }
    va_end(vl);
    return kvadr;
}

int main()
{
    std::cout << kvadr(3, 0, 1, 2)<<std::endl;
    std::cout << kvadr(7, 4, 6, 8, 16, 32, 64, 128)<<std::endl;
    std::cout << kvadr(11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    return 0;
}
