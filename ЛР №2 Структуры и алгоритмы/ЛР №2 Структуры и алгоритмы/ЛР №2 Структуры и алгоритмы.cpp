#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

struct list {
    int field; // поле данных
    struct list* next; // указатель на следующий элемент
    struct list* prev; // указатель на предыдущий элемент
};

struct list* init(int a)  // а- значение первого узла
{
    struct list* lst;
    // выделение памяти под корень списка
    lst = (struct list*)malloc(sizeof(struct list));
    lst->field = a;
    lst->next = lst; // указатель на следующий узел
    lst->prev = lst; // указатель на предыдущий узел
    return(lst);
}

struct list * addelem(list *lst, int number)
{
  struct list *temp, *p;
  temp = (struct list*)malloc(sizeof(list));
  p = lst->next; // сохранение указателя на следующий узел
  lst->next = temp; // предыдущий узел указывает на создаваемый
  temp->field = number; // сохранение поля данных добавляемого узла
  temp->next = p; // созданный узел указывает на следующий узел
  temp->prev = lst; // созданный узел указывает на предыдущий узел
  p->prev = temp;
  return(temp);
}

struct list* deletelem(list* lst)
{
    struct list* prev, * next;
    prev = lst->prev; // узел, предшествующий lst
    next = lst->next; // узел, следующий за lst
    prev->next = lst->next; // переставляем указатель
    next->prev = lst->prev; // переставляем указатель
    free(lst); // освобождаем память удаляемого элемента
    return(prev);
}

void listprint(list* lst)
{
    struct list* p;
    p = lst;
    do {
        cout<< p->field << ' '; // вывод значения элемента p
        p = p->next; // переход к следующему узлу
    } while (p != lst); // условие окончания обхода
}

list* FindElem(list* begin, int k)
{
    list* p = begin;
    bool f = false;
    while (p->next != begin)
    {
        if (p->field== k)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

list* reverse(list* lst)
{
    list* beg;
    list* end;
    end = lst;
    end = end->prev;
    beg = init(end->field);
    do
    {
       end = end->prev;
       addelem(beg->prev, end->field);
    } while (end != lst);
    return beg;
}

list* subtraction(list* orig, list* lst)
{
    list* beg = orig, * end = lst;
    do
    {
        beg->field = (beg->field) - (end->field); // вывод значения элемента p
        beg = beg->next; // переход к следующему узлу
        end = end->next; // переход к следующему узлу
    } while (end != lst);
    return (beg);
}


int main() 
{
    setlocale(LC_ALL, "rus");
    list* head;
    int r = -1, n, first, elem;
    cout << "Введите количество элементов: ";
    cin >> n;
    cout << "Введите элемент 1: ";
    cin >> first;
    head = init(first);
    for (int i = 1; i < n; i++)
    {
        cout << "Введите элемент " << i + 1 << ": ";
        cin >> elem;
        addelem(head->prev, elem);
    }
    cout << "Исходная последовательность: " << endl;
    listprint(head);
    while (r != 0) {
        cout << endl <<
            "1 - Добавить элемент" << endl <<
            "2 - Удалить элемент" << endl <<
            "3 - Вывод полученных списков" << endl <<
            "0 - Выход\nВыберите действие: ";
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cin >> r;
        while (cin.fail() || (r < 0) || (r > 3))
        {
            cin.clear();
            cin.sync();
            cout << "Ошибка ввода, выберите действие: ";
            cin >> r;
        }
        switch (r)
        {
            case 1:
            {
                cout << "Введите элемент: ";
                cin >> elem;
                addelem(head->prev, elem);
                cout << "Последовательность: " << endl;
                listprint(head);
                cout << endl;
                break;
            }
            case 2:
            {
                cout << "Последовательность: " << endl;
                listprint(head);
                cout << endl;
                cout << "Введите элемент: ";
                cin >> elem;
                if (FindElem(head, elem) == NULL)
                {
                    cout << "Элемент не найден" << endl;
                    break;
                }
                if (FindElem(head, elem) == head)
                {
                    head = head->next;
                    deletelem(head->prev);
                    listprint(head);
                    break;
                }
                deletelem(FindElem(head, elem));
                listprint(head);
                cout << endl;
                break;
            }
            case 3:
            {
                list* p = head;
                cout << "Отраженная последовательность: " << endl;
                listprint(reverse(p));
                cout << endl;
                cout << "Поэлементная разница между исходной и отраженной: " << endl;
                listprint(subtraction(p, reverse(p)));
                cout << endl;
                break;
            }
        }
    }
}
