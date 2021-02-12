#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <clocale>
#include <cstdio>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int n = 0;
    char a[100];
    FILE* F = fopen("C:\\lab8_text.txt", "r");
    if (F == NULL)
    {
        printf("He удается открыть файл.\n");
        exit(1);
    }
    cout << "Слова, длина которых меньше чем 4 буквы." << endl;
    while (!feof(F))
    {
        //чтение очередного значения из потока F в переменную a
        fgets(a, 100, F);
        char* pch = strtok(a, " ");
        while (pch != NULL)
            // пока есть лексемы
        {
            if (strlen(pch) <= 4)
            {
                n++; //увеличение количества слов
            }
            pch = strtok(NULL, " ");
        }
    }
    //закрытие потока
    fclose(F);
    //вывод на экран количества слов
    cout << "Количество слов " << n - 1 << endl;
    system("Pause");
    return 0;
}