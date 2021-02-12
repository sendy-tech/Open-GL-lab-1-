#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#define b 2000

using namespace std;

string Tab[b];
int adress = 0;
int h(char[7]);
void input(char[7]);
void add();
void find();
void del();
void create_table();
void output_in_file();

int h(char key[7])
{
	int h = 0, sum = 0;
	for (int i = 0; i < 6; i++)
		sum += (int)((((int)key[i]) / (3 * (i + 1)))) * (int)key[i];
	sum *= sum * 2;
	sum = sum % 1000000;
	h = (int)(sum / 100);
	do
	{
		h = h % b;
	} while (h > b - 1);
	return h;
}

void input(char key[7])
{
	bool correct = true;
	char smth[256];
	do
	{
		cin >> smth;
		if (smth[6] != NULL)
		{
			correct = false;
			cout << "Введенные данные некорректны. Введите еще раз: " << endl;
			continue;
		}
		else
		{
			for (int i = 0; i < 7; i++)
				key[i] = smth[i];
		}
		for (int i = 0; i < 6; i++)
		{
			if ((i > 0) && (i < 4))
			{
				if (((int)key[i] < 48) || ((int)key[i] > 57))
				{
					correct = false;
					cout << "Введенные данные некорректны. Введите еще раз: " << endl;
					break;
				}
			}
			else
			{
				if (((int)key[i] < 65) || ((int)key[i] > 90))
				{
					correct = false;
					cout << "Введенные данные некорректны. Введите еще раз: " << endl;
					break;
				}
			}
			if (i == 5)
				correct = true;
		}
	} while (correct == false);
}

void add()
{
	char key[7] = { NULL };
	bool correct = true;
	do
	{
		if (correct == true)
			cout << "Введите ключ формата БцццББ ";
		input(key);
		adress = h(key);
		correct = true;
		while ((Tab[adress] != "") && (correct == true))
		{
			if (Tab[adress] == key)
				correct = false;
			else
				adress += 2;
		}
		if (correct == false)
			cout << "Такое значение уже есть в таблице. Повторите ввод" << endl;
		continue;
	} while (correct == false);
	adress = h(key);
	do
	{
		if ((Tab[adress] == "") || (Tab[adress] == "deleted"))
		{
			Tab[adress] = key;
			break;
		}
		else
			adress += 2;
	} while (adress < b - 1);
	if (adress >= b)
		cout << "Невозможно добавить данные в таблицу" << endl;
	else
	{
		cout << "Данные добавлены в таблицу" << endl << endl << ". " << endl;
		for (int i = 0; i < 11; i++)
		{
			if (adress - (5 - i) < 0)
				continue;
			if (i == 5)
				cout << endl << adress << " " << Tab[adress] << endl << endl;
			else
				cout << adress - (5 - i) << " " << Tab[adress - (5 - i)] << endl;
		}
		cout << ". " << endl << endl;
	}
	output_in_file();
}

void find()
{
	char key[7] = { NULL };
	bool correct = true;
	int try_count = 0;
	cout << "Введите ключ формата БцццББ ";
	input(key);
	adress = h(key);
	bool flag = false;
	do
	{
		if (Tab[adress] == key)
		{
			flag = true;
			break;
		}
		else
		{
			if (Tab[adress] == "")
				break;
			else
				adress += 2;
		}
	} while (adress < b - 1);
	if (flag == false)
		cout << "Элемент не найден" << endl;
	else
	{
		cout << "Элемент найден" << endl << endl << ". " << endl;
		for (int i = 0; i < 11; i++)
		{
			if (adress - (5 - i) < 0)
				continue;
			if (i == 5)
				cout << endl << adress << " " << Tab[adress] << endl << endl;
			else
				cout << adress - (5 - i) << " " << Tab[adress - (5 - i)] << endl;
		}
		cout << ". " << endl << endl;
	}
}

void del()
{
	char key[7] = { NULL };
	bool correct = true;
	int try_count = 0;
	cout << "Введите ключ формата БцццББ ";
	input(key);
	adress = h(key);
	bool flag = true;
	do
	{
		if (Tab[adress] == key)
		{
			Tab[adress] = "deleted";
			break;
		}
		else
		{
			if (Tab[adress] == "")
			{
				flag = false;
				break;
			}
			else
				adress += 2;
		}
	} while (adress < b - 1);
	if (adress >= b)
		flag = false;
	if (flag == false)
		cout << "Элемент не найден" << endl;
	else
	{
		cout << "Элемент удален!" << endl << endl << ". " << endl;
		for (int i = 0; i < 11; i++)
		{
			if (adress - (5 - i) < 0)
				continue;
			if (i == 5)
				cout << endl << adress << " " << Tab[adress] << endl << endl;
			else
				cout << adress - (5 - i) << " " << Tab[adress - (5 - i)] << endl;
		}
		cout << ". " << endl << endl;
	}
	output_in_file();
}

void create_table()
{
	char key[7] = { NULL };
	int adress = 0;
	bool correct = true;
	srand((unsigned)time(0));
	for (int i = 0; i < b - 100; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if ((j > 0) && (j < 4))
				key[j] = (char)(rand() % 10 + 48);
			else
				key[j] = (char)(rand() % 26 + 65);
		}
		adress = h(key);
		if ((Tab[adress] == "") || (Tab[adress] == "deleted"))
			Tab[adress] = key;
		else
			continue;
	}
	output_in_file();
}

void output_in_file()
{
	ofstream ofs("Table.txt");
	for (int i = 0; i < b; i++)
	{
		ofs << i << " " << Tab[i] << endl;
	}
	ofs.close();
}

int main()
{
	for (int i = 0; i < b; i++)
	{
		Tab[i] = "";
	}
	setlocale(LC_ALL, "rus");
	int r = -1;
	while (r != 0) {
		cout << endl <<
			"1 - Заполнение хеш-таблицы случайными значениями" << endl <<
			"2 - Добавить элемент" << endl <<
			"3 - Просмотр хэш-таблицы" << endl <<
			"4 - Поиск элемента" << endl <<
			"5 - Удаление элемента" << endl <<
			"0 - Выход\nВыберите действие: ";
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> r;
		while (cin.fail() || (r < 0) || (r > 5))
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
				create_table();
				break;
			}
			case 2:
			{
				add();
				break;
			}
			case 3:
			{
				fstream infile;
				infile.open("Table.txt", ios::in);;
				while (!infile.eof())
				{
					string v;
					getline(infile, v);
					cout << v << endl;
				}

				break;
			}
			case 4:
			{
				find();
				break;
			}
			case 5:
			{
				del();
				break;
			}
		}
	}
	return 0;
}