// sjjgzc.cpp: 定义控制台应用程序的入口点。
// K&R style

#include "stdafx.h"
#include <iostream>



int main()
{
	int num = 0;
	char letter = 0;
	scanf("%d %c", &num,&letter);	//数量
	
	int num1 = (num - 1) / 2;
	int i = 0;
	while ((i * i + 2 * i) <= num1) {
		i++;
	}
	int layer = i - 1; //一个梯形有多高
	for (int i = layer; i > 0; i--) {
		for (int j = 0; j < layer - i; j++) {
			putchar(' ');
		}
		for (int j = 0; j < 2*i+1; j++) {
			putchar(letter);
		}
		putchar('\n');
	}
	for (int i = 0; i < layer; i++) {
		putchar(' ');
	}
	putchar(letter);
	putchar('\n');
	for (int i = 1; i <= layer; i++) {
		for (int j = 0; j < layer - i; j++) {
			putchar(' ');
		}
		for (int j = 0; j < 2*i+1; j++) {
			putchar(letter);
		}
		putchar('\n');
	}
	int last = num - 1 - 2 * (layer*layer + 2 * layer);
	printf("%d", last);
    return 0;
}

