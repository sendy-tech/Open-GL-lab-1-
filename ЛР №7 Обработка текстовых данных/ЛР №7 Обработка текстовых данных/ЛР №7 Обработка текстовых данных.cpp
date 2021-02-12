#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

void Func(char src[6], char target[15])
{
	int len = strlen(src);
	strcpy(target, src); // копируем исходную строку в результат (string)
	target[len / 2] = '\0'; // половину обрезаем (str)
	strcat(target, src); // присоединяем к результату исходную строку(strstring)
	char* pch = src + (len / 2); // это указатель на вторую половину исходной строки(ing)
	strcat(target, pch); // присоединяем эту половинку (strstringing)
}

int main() {
	char src[] = "strin", target[15];
	Func(src, target);
	puts(target);
	system("pause");
	return 0;
}