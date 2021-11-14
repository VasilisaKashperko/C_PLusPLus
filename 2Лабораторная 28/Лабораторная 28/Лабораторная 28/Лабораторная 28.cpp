/*
//Дерево - это структура, имеющая следующие свойства: 
//–  существует единственный элемент(узел, вершина), на который не ссылается никакой другой и который называется корнем;
//– начиная с корня и следуя по определенной цепочке указателей, можно осуществить доступ к любому элементу структуры;
//– на каждый элемент, кроме корня, имеется единственная ссылка.

//Бинарное дерево поиска – это упорядоченное дерево, каждая вершина которого имеет не более двух поддеревьев : 
//в левом поддереве содержатся ключи, имеющие значения, меньшие, чем значение данного узла, 
//в правом поддереве содержатся клю - чи, имеющие значения, большие, чем значение данного узла.

#include <iostream>
using namespace std;


//Кол-во отступов высчитывается по кол-ву рекурсивного вхождения при выводе в фукцию print

int tabs = 0; //Для создания отступов

int kolich = 0;

//Структура ветки

struct Branch
{
    int Data; //Поле данных

    Branch* LeftBranch; //УКАЗАТЕЛИ на соседние веточки
    Branch* RightBranch;
};

//Функция внесения данных
void Add(int aData, Branch*& aBranch)
{
    //Если ветки не существует
    if (!aBranch)
    { //создадим ее и зададим в нее данные
        aBranch = new Branch;
        aBranch->Data = aData;
        aBranch->LeftBranch = 0;
        aBranch->RightBranch = 0;
        return;
    }
    else //Иначе сверим вносимое
        if (aBranch->Data > aData)
        { //Если оно меньше того, что в этой ветке - добавим влево
            Add(aData, aBranch->LeftBranch);
        }
        else
        { //Иначе в ветку справа
            Add(aData, aBranch->RightBranch);
        };
}

//Функция вывода дерева
void print(Branch* aBranch)
{
    if (!aBranch) return; //Если ветки не существует - выходим. Выводить нечего
    tabs += 5; //Иначе увеличим счетчик рекурсивно вызванных процедур
    //Который будет считать нам отступы для красивого вывода
    print(aBranch->LeftBranch); //Выведем ветку и ее подветки слева
    for (int i = 0; i < tabs; i++) cout << " "; //Потом отступы
    cout << aBranch->Data << endl; //Данные этой ветки
    print(aBranch->RightBranch);//И ветки, что справа
    tabs -= 5; //После уменьшим кол-во отступов
    return;
}

void pr_obh(Branch*& aBranch)
{
    if (NULL == aBranch) return; //Если дерева нет, выходим
    cout << aBranch->Data << endl; //Посетили узел
    pr_obh(aBranch->LeftBranch); //Обошли левое поддерево
    pr_obh(aBranch->RightBranch); //Обошли правое поддерево
}

int kol_ch(Branch*& aBranch)
{
    if (NULL == aBranch) return 0; //Если дерева нет, выходим
    if (aBranch->Data % 2 == 0)
    {
        kolich++;
    }
    kol_ch(aBranch->LeftBranch); //Обошли левое поддерево
    kol_ch(aBranch->RightBranch); //Обошли правое поддерево
    return kolich;
}

int summ_k(Branch*& aBranch, int k) {
    int sum = 0;
    if ((aBranch != NULL) && (k > 0)) {
        sum += summ_k(aBranch->LeftBranch, k - 1);
        sum += aBranch->Data;
        sum += summ_k(aBranch->RightBranch, k - 1);
    }
    return sum;
}

void add_elem(int aData, Branch*& aBranch)
{
    if (!aBranch)
    {
        aBranch = new Branch;
        aBranch->Data = aData;
        aBranch->LeftBranch = 0;
        aBranch->RightBranch = 0;
        return;
    }
    else
    {
        if (aData < aBranch->Data) {
            add_elem(aData, aBranch->LeftBranch);
        }
        else if (aData > aBranch->Data) {
            add_elem(aData, aBranch->RightBranch);
        }
    }
}

void is_Empty(Branch*& aBranch)
{
    if (!aBranch)
    {
        cout << "Дерево пустое...";
    }
    else
    {
        cout << "Дерево не пустое...";
    }
}

void FreeTree(Branch* aBranch)
{
    if (!aBranch) return;
    FreeTree(aBranch->LeftBranch);
    FreeTree(aBranch->RightBranch);
    delete aBranch;
    return;
}

Branch* del_elem(Branch*& aBranch, int aData) {
    if (aBranch == NULL)
        return aBranch;

    if (aData == aBranch->Data) {
        Branch* tmp;
        if (aBranch->RightBranch == NULL)
            tmp = aBranch->LeftBranch;
        else {
            Branch* ptr = aBranch->RightBranch;
            if (ptr->LeftBranch == NULL) {
                ptr->LeftBranch = aBranch->LeftBranch;
                tmp = ptr;
            }
            else {
                Branch* pmin = ptr->LeftBranch;
                while (pmin->LeftBranch != NULL) {
                    ptr = pmin;
                    pmin = ptr->LeftBranch;
                }
                ptr->LeftBranch = pmin->RightBranch;
                pmin->LeftBranch = aBranch->LeftBranch;
                pmin->RightBranch = aBranch->RightBranch;
                tmp = pmin;
            }
        }
        delete aBranch;
        return tmp;
    }
    else if (aData < aBranch->Data)
        aBranch->LeftBranch = del_elem(aBranch->LeftBranch, aData);
    else
        aBranch->RightBranch = del_elem(aBranch->RightBranch, aData);
    return aBranch;
}

int main()
{
    system("color 5F");
    setlocale(LC_ALL, "rus");
    Branch* Root = 0;
    int vel, element, k;
    cout << "Введите кол-во элементов для будущего дерева: ";
    cin >> vel;
    cout << endl;
    cout << "Проверим дерево на пустоту до его заполнения: " << endl;
    is_Empty(Root);
    cout << endl;
    for (int i = 0; i < vel; i++)
    {
        Add(rand() % 100, Root);
    }
    cout << "Проверим дерево на пустоту после его заполнения: " << endl;
    is_Empty(Root);
    cout << endl;
    cout << "Вывод бинарного дерева: " << endl;
    print(Root);
    cout << endl;
    cout << "Прямой обход бинарного дерева: " << endl;
    pr_obh(Root);
    cout << endl;
    cout << "Добавим новый элемент в бинарное дерево:" << endl;
    cout << "Введите новый элемент: ";
    cin >> element;
    add_elem(element, Root);
    cout << "Вывод бинарного дерева: " << endl;
    print(Root);
    cout << endl;
    cout << "Удалим элемент из бинарного дерева:" << endl;
    cout << "Введите нэлемент: ";
    cin >> element;
    del_elem(Root, element);
    cout << "Вывод бинарного дерева: " << endl;
    print(Root);
    cout << endl;
    cout << "Посчитаем кол-во четных элементов в дереве: ";
    cout << kol_ch(Root) << endl;
    cout << "Посчитаем сумму элементов в дереве на уровне ";
    cin >> k;
    cout << summ_k(Root, k) << endl;
    FreeTree(Root);
    cout << "Вся динамическая память очищена..." << endl;
    return 0;
}
*/

#include <iostream>
#include <map>
#include <string>
#include <windows.h>
struct  T_subscriber_node;

typedef std::string                                 T_str;
typedef T_subscriber_node* T_subscriber_tree;
typedef std::map            <T_str, int     >   T_count_of_tariff; //typedef - новый тд

struct    T_subscriber
{
    T_str   phone_num_;
    T_str   name_;
    T_str   tariff_;

    T_str   phone_num_title_;
    T_str   name_title_;
    T_str   tariff_title_;
    T_subscriber()
        :
        phone_num_title_("номер телефона\t: "),
        name_title_("имя\t\t: "),
        tariff_title_("тариф\t\t: ")
    {}
    bool    operator<   (T_subscriber  const& subscriber)            const
    {
        return  phone_num_ < subscriber.phone_num_;
    }
    void    input()
    {
        std::cout << std::endl
            << "Введите данные абонента:"
            << std::endl;

        input_phone();

        std::cout << '\t' << name_title_;
        std::cin >> name_;

        std::cout << '\t' << tariff_title_;
        std::cin >> tariff_;
    }
    void    input_phone()
    {
        std::cout << '\t' << phone_num_title_;
        std::cin >> phone_num_;
    }
    void    print()                                                     const
    {
        std::cout << phone_num_title_ << phone_num_ << std::endl
            << name_title_ << name_ << std::endl
            << tariff_title_ << tariff_ << std::endl;
    }
};
struct  T_subscriber_node
{
    T_subscriber        subscriber_;
    T_subscriber_tree   left_;
    T_subscriber_tree   right_;
    T_subscriber_node(T_subscriber     const& subscriber)
        :
        subscriber_(subscriber),
        left_(),
        right_()
    {}
};
class   T_subscribers
{
    T_subscriber_tree   subscriber_tree_;
public:
    T_subscribers()
        :
        subscriber_tree_()
    {}
    void    add_subscriber()
    {
        T_subscriber    subscriber;
        subscriber.input();

        auto    bool_res = successfully_insert_subscriber_in_tree
        (
            subscriber,
            subscriber_tree_
        );

        std::cout << (
            bool_res
            ? "Абонент успешно добавлен в базу."
            : "Абонент с таким номером телефона уже существует."
            )

            << std::endl;
    }
    void    print_all_subscribers()                                     const
    {
        if (!subscriber_tree_)
        {
            std::cout << "База абонентов пуста."
                << std::endl;
        }
        else
        {
            std::cout << "Все абоненты базы:"
                << std::endl;

            int     counter = 0;

            print_tree
            (
                subscriber_tree_,
                counter
            );
        }//else
    }
    void    find_subscriber_by_phone_num()                              const
    {
        T_subscriber    subscriber_with_phone_num;
        std::cout << "Введите для поиска ";
        subscriber_with_phone_num.input_phone();

        auto    phone_num_tree = get_tree_with_phone_num
        (
            subscriber_tree_,
            subscriber_with_phone_num
        );

        if (!phone_num_tree)
        {
            std::cout << "Абонента с таким номером телефона не существует."
                << std::endl;
        }
        else
        {
            std::cout << "Абонент с этим номером телефона найден:"
                << std::endl;
            phone_num_tree->subscriber_.print();
        }
    }
    void    find_most_popular_tariff()                                  const
    {
        T_count_of_tariff   count_of_tariff;
        int                 popular_tariff_count{};
        T_str               popular_tariff;

        find_popular_tariff_in_tree
        (
            count_of_tariff,
            popular_tariff_count,
            popular_tariff,
            subscriber_tree_
        );

        if (!popular_tariff_count)
        {
            std::cout << "Тариф не найден."
                << std::endl;
        }
        else
        {
            std::cout << "Самый популярный тариф у абонентов "
                << popular_tariff
                << "."
                << std::endl;
        }
    }
private:
    bool    successfully_insert_subscriber_in_tree
    (
        T_subscriber    const& subscriber,
        T_subscriber_tree& subscriber_tree
    )
    {
        if (!subscriber_tree)
        {
            subscriber_tree = new     T_subscriber_node(subscriber);
            return  true;
        }
        else if (
            subscriber < subscriber_tree->subscriber_
            )
        {
            return  successfully_insert_subscriber_in_tree
            (
                subscriber,
                subscriber_tree->left_
            );
        }
        else if (
            subscriber_tree->subscriber_ < subscriber
            )
        {
            return  successfully_insert_subscriber_in_tree
            (
                subscriber,
                subscriber_tree->right_
            );
        }
        else
        {
            return  false;
        }
    }
    void    print_tree
    (
        T_subscriber_tree   subscriber_tree,
        int                 counter
    )                                                               const
    {
        if (subscriber_tree)
        {
            print_tree
            (
                subscriber_tree->left_,
                counter
            );

            std::cout << std::endl
                << "Абонент № "
                << ++counter
                << std::endl;

            subscriber_tree->subscriber_.print();

            print_tree
            (
                subscriber_tree->right_,
                counter
            );
        }//if
    }
    T_subscriber_tree   get_tree_with_phone_num
    (
        T_subscriber_tree               subscriber_tree,
        T_subscriber        const& subscriber_with_phone_num
    )                                                               const
    {
        if (!subscriber_tree)
        {
            return  subscriber_tree;
        }
        else
        {
            if (
                subscriber_with_phone_num
                < subscriber_tree->subscriber_
                )
            {
                return  get_tree_with_phone_num
                (
                    subscriber_tree->left_,
                    subscriber_with_phone_num
                );
            }
            else if (
                subscriber_tree->subscriber_
                < subscriber_with_phone_num
                )
            {
                return  get_tree_with_phone_num
                (
                    subscriber_tree->right_,
                    subscriber_with_phone_num
                );
            }
            else
            {
                return  subscriber_tree;
            }
        }//else
    }
    void    find_popular_tariff_in_tree
    (
        T_count_of_tariff& count_of_tariff,
        int& popular_tariff_count,
        T_str& popular_tariff,
        T_subscriber_tree       subscriber_tree
    )                                                               const
    {
        if (subscriber_tree)
        {
            auto& tariff_cur = subscriber_tree->subscriber_.tariff_;
            auto        count_cur = ++count_of_tariff[tariff_cur];

            if (count_cur > popular_tariff_count)
            {
                popular_tariff_count = count_cur;
                popular_tariff = tariff_cur;
            }

            find_popular_tariff_in_tree
            (
                count_of_tariff,
                popular_tariff_count,
                popular_tariff,
                subscriber_tree->left_
            );

            find_popular_tariff_in_tree
            (
                count_of_tariff,
                popular_tariff_count,
                popular_tariff,
                subscriber_tree->right_
            );
        }//if
    }
};
enum    class   T_action
{
    ADD_SUBSCRIBER = 1,
    PRINT_ALL_SUBSCRIBERS,
    FIND_SUBSCRIBER_BY_PHONE_NUM,
    FIND_MOST_POPULAR_TARIFF,
    EXIT
};
void    print_menu()
{
    std::cout << std::endl
        << "Выберите действие:"
        << std::endl;

    std::cout
        << '\t' << int(T_action::ADD_SUBSCRIBER)
        << '\t' << "добавить абонента" << std::endl

        << '\t' << int(T_action::PRINT_ALL_SUBSCRIBERS)
        << '\t' << "напечатать данные всех абонентов" << std::endl

        << '\t' << int(T_action::FIND_SUBSCRIBER_BY_PHONE_NUM)
        << '\t' << "найти абонента по номеру телефона" << std::endl

        << '\t' << int(T_action::FIND_MOST_POPULAR_TARIFF)
        << '\t' << "напечатать самый популярный тариф" << std::endl

        << '\t' << int(T_action::EXIT)
        << '\t' << "выйти из программы" << std::endl;
}
T_action    input_and_get_action()
{
    std::cout << "Введите номер действия: ";
    int    int_action;
    std::cin >> int_action;
    return  T_action(int_action);
}
int     main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    T_subscribers   subscribers;

    for (;;)
    {
        print_menu();
        auto    action = input_and_get_action();

        if (action == T_action::EXIT)
        {
            break;
        }

        switch (action)
        {
        case   T_action::ADD_SUBSCRIBER:
            subscribers.add_subscriber();
            break;

        case   T_action::PRINT_ALL_SUBSCRIBERS:
            subscribers.print_all_subscribers();
            break;

        case   T_action::FIND_SUBSCRIBER_BY_PHONE_NUM:
            subscribers.find_subscriber_by_phone_num();
            break;

        case   T_action::FIND_MOST_POPULAR_TARIFF:
            subscribers.find_most_popular_tariff();
            break;

        default:
            ;
        }
    }//for

    system("pause");
}
