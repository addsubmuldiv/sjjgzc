// polynomial.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <ctime>
#include <cmath>
#define MAXN 10
#define MAXK 1e7
#define MAXM 100
using namespace std;

clock_t start, stop;
double duration;

double f1(int n, double a[], double x)
{
	double p = a[0];
	for (int i = 1; i <= n; i++) {
		p += (a[i] * pow(x, i));
	}
	return p;
}

double f2(int n, double a[], double x)
{
	double p = a[n];
	for (int i = n; i > 0; i--) {
		p = a[i - 1] + x * p;
	}
	return p;
}

void laolao()
{
	double a[MAXN];
	for (int i = 0; i < MAXN; i++) a[i] = double(i);
	start = clock();
	for(int i=0;i<MAXK;i++) 
		f1(MAXN - 1, a, 1.1);
	stop = clock();
	duration = ((double)(stop - start) / CLK_TCK /MAXK);
	printf("ticks1 = %lf\n", (double)(stop - start));
	printf("duration1 = %6.2e\n", duration);
	
	start = clock();
	for(int i=0;i<MAXK;i++) 
		f2(MAXN - 1, a, 1.1);
	stop = clock();
	duration = ((double)(stop - start) / CLK_TCK /MAXK);
	printf("ticks1 = %lf\n", (double)(stop - start));
	printf("duration1 = %6.2e\n", duration);
}

double* init()
{
	double a[MAXM];
	for (int i = 0; i < MAXM; i++) {
		a[i] = 1.0 / (i + 1);
	}
	return a;
}

void calculate(clock_t start, clock_t stop)
{
	duration = ((double)(stop - start) / CLK_TCK /MAXK);
	printf("ticks1 = %lf\n", (double)(stop - start));
	printf("duration1 = %6.2e\n", duration);

}


int main()
{
	double *a = init();
	start = clock();
	for (int i = 0; i < MAXK; i++)
		f1(MAXM - 1, a, 1.1);
	stop = clock();
	calculate(start, stop);
	start = clock();
	for (int i = 0; i < MAXK; i++)
		f2(MAXM - 1, a, 1.1);
	stop = clock();
	calculate(start, stop);

    return 0;
}

