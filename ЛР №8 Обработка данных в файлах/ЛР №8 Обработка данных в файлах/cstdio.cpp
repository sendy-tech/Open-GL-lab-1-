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
        printf("He ������� ������� ����.\n");
        exit(1);
    }
    cout << "�����, ����� ������� ������ ��� 4 �����." << endl;
    while (!feof(F))
    {
        //������ ���������� �������� �� ������ F � ���������� a
        fgets(a, 100, F);
        char* pch = strtok(a, " ");
        while (pch != NULL)
            // ���� ���� �������
        {
            if (strlen(pch) <= 4)
            {
                n++; //���������� ���������� ����
            }
            pch = strtok(NULL, " ");
        }
    }
    //�������� ������
    fclose(F);
    //����� �� ����� ���������� ����
    cout << "���������� ���� " << n - 1 << endl;
    system("Pause");
    return 0;
}