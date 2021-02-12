#include <iostream>
using namespace std;
int counter1;
int counter2;

void InsertSort(int k, int mas[]) {
	int i, j, temp;
	for (i = 0; i < k; i++) {
		counter1++;
		//цикл проходов, i - номер прохода
		temp = mas[i];
		//поиск места элемента
		for (j = i - 1; j >= 0 && mas[j] > temp; j--)
		{
			counter2++;
			mas[j + 1] = mas[j];//сдвигаем элемент вправо, пока не дошли
			//место найдено, вставить элемент 
		}
		mas[j + 1] = temp;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите количество элементов: ";
	int n, r = -1; cin >> n; cout << endl;
	int* mas = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Введите элемент " << i + 1 << ": ";
		cin >> mas[i];
	}
	cout << "Исходный массив:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;
	while (r != 0) {
		cout << endl <<
			"1 - Добавить элемент" << endl <<
			"2 - Удалить элемент" << endl <<
			"3 - Поиск элемента по индексу" << endl <<
			"4 - Вывод отсортированного списка" << endl <<
			"0 - Выход\nВыберите действие: ";
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> r;
		while (cin.fail() || (r < 0) || (r > 4))
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
				int num;
				n++;
				int* new_mas = new int[n];
				for (int i = 0; i < n; i++)
				{
					new_mas[i] = mas[i];
				}
				cout << "Введите элемент ";
				cin >> num;
				new_mas[n - 1] = num;
				mas = new_mas;
				cout << "Массив:" << endl;
				for (int i = 0; i < n; i++)
				{
					cout << mas[i] << " ";
				}
				cout << endl;
				break;
			}
			case 2:
			{
				int num;
				n--;
				cout << "Введите номер элемента ";
				cin >> num;
				int* new_mas = new int[n];
				for (int i = 0; i < num-1; i++)
				{
					new_mas[i] = mas[i];
				}

				for (int i = num + 1; i < n+2; i++)
				{
					new_mas[i-2] = mas[i-1];
				}
				mas = new_mas;
				cout << "Массив:" << endl;
				for (int i = 0; i < n; i++)
				{
					cout << mas[i] << " ";
				}
				cout << endl;
				break;
			}
			case 3:
			{
				cout << "Введите номер элемента, который нужно найти: ";
				int k;
				cin >> k;
				cout << "Элемент k: " << mas[k - 1] << endl;
				break;
			}
			case 4:
			{
				counter1 = 0;
				counter2 = 0;
				InsertSort(n, mas);
				cout << "Отсортированный массив: " << endl;
				for (int i = 0; i < n; i++)
				{
					cout << mas[i] << " ";
				}
				cout << endl;
				cout << "Число сравнений: " << counter1 << endl;
				cout << "Число перестановок: " << counter2 << endl;
				break;
			}
		}
	}
}