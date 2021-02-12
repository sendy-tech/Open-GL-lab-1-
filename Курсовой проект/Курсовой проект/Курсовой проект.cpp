#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <ctime>
#include <regex>

using namespace std;
const int BUF = 50;

struct TRAIN
{
    char to[BUF];// название пункта назначения 
    int number_; // номер поезда
    float time_;// время отправления поезда
};

struct List
{
    TRAIN data;
    List* next;
};

void OutLine(TRAIN d)
{
    if (strlen(d.to) < 8)
    {
        cout << d.number_ << '\t' << '\t' << d.to << '\t' << '\t' << '\t' << '\t' << d.time_ << endl;
    }
    else
    {
        cout << d.number_ << '\t' << '\t' << d.to << '\t' << '\t' << '\t' << d.time_ << endl;
    }
}

void AddElem(List** begin, List** cur, TRAIN elem)
{
    List* p = new List;
    p->data = elem;
    if (*begin == NULL)
    {
        p->next = NULL;
        *begin = p;
    }
    else
    {
        p->next = (*cur)->next;
        (*cur)->next = p;
    }
    *cur = p;
}

void AddFirstElem(List** begin, TRAIN elem)
{
    List* p = new List;
    p->data = elem;
    p->next = *begin;
    *begin = p;
}

void ShowList(List* begin)
{
    List* p = begin;
    cout << "Поезд номер " << '\t'
        << "Пункт назначения " << '\t' << ' '
        << "Время отправления " << '\t' << endl;
    while (p != NULL)
    {
        OutLine(p->data);
        p = p->next;
    }
}

List* FindElem(List* begin, TRAIN elem)
{
    List* p = begin;
    while (p != NULL)
    {
        if (!strcmp(p->data.to, elem.to) && (p->data.number_ == elem.number_))
            break;
        p = p->next;
    }
    return p;
}

List* FindElemNum(List* begin, int k)
{
    List* p = begin;
    bool f = false;
    while (p != NULL)
    {
        if (p->data.number_ == k)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void FindTime(List* begin, float time)
{
    List* p = begin;
    bool f = false;
    while (p != NULL)
    {
        if (p->data.time_ > time)
        {
            f = true;
            cout << "Поезд номер " << '\t'
                << "Пункт назначения " << '\t' << ' '
                << "Время отправления " << '\t' << endl;
            OutLine(p->data);
        }
        p = p->next;
    }
    if (!f) cout << "Данные не найдены" << endl;
}

void inputData(TRAIN& r, List* begin)
{
    cin.ignore(cin.rdbuf()->in_avail());
    cout << "Введите название пункта назначения: ";
    bool f = false;
    bool g = false;
    cin.getline(r.to, 25);
    f = regex_search(r.to, regex("[A-Z][a-z]*"));
    while (!f)
    {
        cout << "Вы ввели недопустимое значение. Попробуйте ещё раз: ";
        cin.getline(r.to, 25);
        f = regex_search(r.to, regex("[A-Z][a-z]*"));
    }
    cout << "Введите номер поезда: ";
    while (!(cin >> r.number_) || (cin.peek() != '\n')
        || (r.number_ > 999) || (r.number_ < 0) ||
        FindElemNum(begin, r.number_) != NULL)
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Вы ввели недопустимое значение. Попробуйте ещё раз: ";
    }

    cout << "Введите время отправления поезда: ";
    while (!(cin >> r.time_) || (cin.peek() != '\n')
        || (r.time_ >= 24) || (r.time_ < 0) || (((r.time_ - (int)r.time_) - 0.6) > 0))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Вы ввели недопустимое значение. Попробуйте ещё раз: ";
    }
}

void init(TRAIN& r, int i)
{
    fstream infile;
    infile.open("table.txt", ios::in);
    for (int a = 0; a < i; a++)
    {
        infile >> r.to >> r.number_ >> r.time_;
    }

}

void DelElem(List** begin, List* ptrCur)
{
    List* p;
    if (ptrCur == *begin)
    {
        *begin = (*begin)->next;
    }
    else
    {
        p = *begin;
        while (p->next != ptrCur)
            p = p->next;
        p->next = ptrCur->next;
    }
    delete ptrCur;
}

void sortList(List* begin)
{
    if (!begin)
    {
        cout << "Список пуст." << endl;
        return;
    }
    List* ptrN = begin;

    while (ptrN->next != NULL)
    {
        List* ptr = begin;
        while (ptr->next != NULL)
        {
            if (ptr->data.time_ > ptr->next->data.time_)
            {
                TRAIN data = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = data;
            }
            ptr = ptr->next;
        }
        ptrN = ptrN->next;
    }
}

int main()
{
    setlocale(LC_ALL, "");
    List* head = NULL;
    List* cur = NULL;
    int n = -1;
    int i = 1;
    TRAIN r;
    fstream infile;
    infile.open("table.txt", ios::in);;
    while (!infile.eof())
    {
        string v;
        getline(infile, v);
        bool f = regex_search(v, regex("[A-Z][a-z]* +\\d{1,3} +\\b([01]?[0-9]|2[0-3]).[0-5]+\\d{1,2}"));
        init(r, i);
        i++;
        if ((f) && (FindElemNum(head, r.number_) == NULL))
        {
            AddElem(&head, &cur, r);
        }
        else
        {
            break;
        }
    }

    if (!infile.is_open())
    {
        cerr << "Ошибка при открытии файла\n";
        return EXIT_FAILURE;
    }

    while (n != 0) {
        cout << endl <<
            "1 - Добавить в конец" << endl <<
            "2 - Добавить в начало" << endl <<
            "3 - Вывод списка" << endl <<
            "4 - Поиск по № поезда" << endl <<
            "5 - Поиск времени отправления" << endl <<
            "6 - Удаление" << endl <<
            "7 - Сохранить в файл" << endl <<
            "8 - Сортировать по времени отправления" << endl <<
            "9 - Редактировать время отправления" << endl <<
            "0 - Выход\nВыберите действие: ";
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cin >> n;
        while (cin.fail() || (n < 0) || (n > 9))
        {
            cin.clear();
            cin.sync();
            cout << "Ошибка ввода, выберите действие: ";
            cin >> n;
        }
        switch (n)
        {
        case 1:
        {
            inputData(r, head);
            AddElem(&head, &cur, r);
            break;
        }
        case 2:
        {
            inputData(r, head);
            AddFirstElem(&head, r);
            break;
        }
        case 3:
        {
            if (head) ShowList(head);
            break;
        }
        case 4:
        {
            int num;
            cout << "Введите номер поезда: ";
            cin >> num;
            List* p = FindElemNum(head, num);
            if (p == NULL)
            {
                cout << "Данные не найдены" << endl;
                break;
            }
            cout << "Поезд номер " << '\t'
                << "Пункт назначения " << '\t' << ' '
                << "Время отправления " << '\t' << endl;
            OutLine(p->data);
            break;

        }
        case 5:
        {
            float time;
            cout << "Введите время отправления поезда поезда: ";
            cin >> time;
            FindTime(head, time);
            break;
        }
        case 6:
        {
            if (!head) { cout << "Нет данных" << endl; break; }
            int num;
            cout << "Введите номер поезда: ";
            cin >> num;
            List* p = FindElemNum(head, num);
            if (p == NULL)
                cout << "Запись не найдена" << endl;
            else {
                DelElem(&head, p);
                cout << "Запись удалена" << endl;
            }
            break;
        }
        case 7:
        {
            List* p = head;
            fstream infile;
            infile.open("table.txt", ios::out);
            while (p != NULL)
            {
                r = p->data;
                infile << r.to << ' ' << r.number_ << ' ' << r.time_ << endl;
                p = p->next;
            }
            cout << "Файл перезаписан" << endl;
            infile.close();
            break;
        }
        case 8:
        {
            sortList(head);
            break;
        }
        case 9:
        {
            if (!head) { cout << "Нет данных" << endl; break; }
            int num;
            cout << "Введите номер поезда, время которого нужно изменить: ";
            cin >> num;
            List* p = FindElemNum(head, num);
            if (p == NULL)
                cout << "Запись не найдена" << endl;
            else {
                cout << "Поезд номер " << '\t'
                    << "Пункт назначения " << '\t' << ' '
                    << "Время отправления " << '\t' << endl;
                OutLine(p->data);
                cout << "Введите новое время отправления: ";
                float time;
                while (!(cin >> time) || (cin.peek() != '\n')
                    || (time >= 24) || (time < 0) || (((time - (int)time) - 0.6) > 0))
                {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "Вы ввели недопустимое значение. Попробуйте ещё раз: ";
                }
                p->data.time_ = time;
            }
            break;
        }
        }
    }
    return EXIT_SUCCESS;
}