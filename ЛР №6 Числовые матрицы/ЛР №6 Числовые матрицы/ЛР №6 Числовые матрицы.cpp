#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");
    const int N = 8;
    int A[N][N];
    int k, sum;
    cout << "Введите матрицу:" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "Искомые номера для k-ых строки (столбца): ";
    for (int i = 0; i < N; i++)
    {
        k = 0;
        for (int j = 0; j < N; j++)
        {
            if (A[i][j] == A[j][i])
                k++;
        }
        if (k == N)
            cout << i + 1 << " ";
    }
    cout << endl;

    cout << "Искомые суммы элементов:" << endl;
    for (int i = 0; i < N; i++)
    {
        k = 0;
        for (int j = 0; j < N; j++)
        {
            if (A[i][j] < 0)
                k++;
        }
        if (k > 0)
        {
            sum = 0;
            for (int j = 0; j < N; j++)
            {
                sum += A[i][j];
            }
            cout << "Строка " << i + 1 << ": " << sum << endl;
        }
    }
}