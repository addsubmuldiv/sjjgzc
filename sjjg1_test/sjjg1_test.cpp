// sjjg1_test.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <ctime>

clock_t start, stop;
double duration;


void printN1(int N)
{
	for (int i = 1; i <= N; i++) {
		printf("%d", i);
	}
}

void printN2(int N) {
	if (N >= 1) {
		printN2(N - 1);
		printf("%d", N);
	}
}


int main()
{
	start = clock();
	printN1(100000);
	stop = clock();
	duration = ((double)(stop - start)) / CLK_TCK;
	printf("\n%lf s", duration);
    return 0;
}

