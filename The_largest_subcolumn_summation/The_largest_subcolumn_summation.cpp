// The_largest_subcolumn_summation.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include <climits>
//o(n^2)的复杂度似乎一般是能够接受的

int sum1(int a[], int n)
{
	int thisSum = 0, maxSum = 0;
	for (int i = 0; i < n; i++) {
		thisSum = 0; //o(n^2)
		for (int j = i; j < n; j++) {
			//thisSum = 0;
			//for (int k = i; k <= j; k++) 
				//thisSum += a[k];
			thisSum += a[j];
			if (thisSum > maxSum) {
				maxSum = thisSum;
			}
		}
	}
	return maxSum;
}

int sum2(int A[], int N)
{
	int ThisSum, MaxSum;
	int i;
	ThisSum = MaxSum = 0;
	for (i = 0; i < N; i++) {
		ThisSum += A[i];//向右累加
		if (ThisSum>MaxSum)
			MaxSum = ThisSum; // 发现更大和则更新当前结果
		else if (ThisSum < 0)  // 如果当前子列和为负数
			ThisSum = 0; // 则不可能使后面部分和增大，抛弃之
	}
	return MaxSum;
}

int main()
{
	int num;
	int order[100000];
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &order[i]);
	}
	//int res = sum1(order, num);
	int res = sum2(order, num);
	printf("%d", res);

    return 0;
}

