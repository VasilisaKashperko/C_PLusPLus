#include <iostream>
using namespace std;

struct node {
    int elem;
    node *sled;
};

class Spisok {
    private:
        node *phead, *Res;
    public:
        Spisok() {
            phead = new(node); Res = NULL;
        }
        ~Spisok() { delete phead; }
        void POSTROENIE();
        void VYVOD();
        node *POISK(int);
        void InsAfter(int);
        void InsBefore(int);
        void Delete();
        void DelAfter();
        void OCHISTKA();
};

void main()
{
    setlocale(LC_ALL, "Rus");
    Spisok A;
    int el, el1;
    node *Res_Zn;

    A.POSTROENIE();
    A.VYVOD();
    cout << "\nВведите элемент звена, после которого";
    cout << "осуществляется вставка: ";
    cin >> el;
    cout << "\nВведите элемент вставляемого звена: ";
    cin >> el1;

    if (A.POISK(el) != NULL)
    {
        A.InsAfter(el1); A.VYVOD();
    }
    
    else
        cout << "\nВведите элемент звена, перед которого";
        cout << "осуществляется вставка: ";
        cin >> el;
        cout << "Введите элемент вставляемого звена:";
        cin >> el1;

        if (A.POISK(el) != NULL)
        {
            A.InsBefore(el1); A.VYVOD();
        }

        else cout << "Звена с заданным элементов в кольце нет!";
            cout << "\nВведите элемент звена, ";
            cout << "после которого нужно удалять.";
            cin >> el;

            if (A.POISK(el) != NULL) {
                A.DelAfter(); A.VYVOD();
            }
            else cout << "Звена с заданным элементом в кольце нет!";
            A.OCHISTKA();

            cout << "\n";
            system("PAUSE");
}

void Spisok::POSTROENIE() 
// Построение кольцевого списка с удаленным заглавным звеном.
// phead - указатель на заглавное звено.
{
    node *t;
    int el;
    t = phead; (*t).sled = NULL;
    cout << "Вводите элементы кольца: ";
    cin >> el;
    while (el != 0) {
        (*t).sled = new (node);
        t = (*t).sled; (*t).elem = el;
        cin >> el;
    }
    (*t).sled = (*phead).sled;
}