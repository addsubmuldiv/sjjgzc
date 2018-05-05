#include <iostream>
#define MAXN 40000
using namespace std;

typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MAXN];	//下标就是它的值,S[i]是它的父节点,根节点保存的是元素数

SetName Find(SetType S, ElementType X) 
{
	if (S[X] < 0)
		return X;
	else
		return S[X] = Find(S, S[X]);  //尾递归压缩路径
}

SetName Union(SetType S, SetName Root1, SetName Root2)
{
	if (S[Root1] < S[Root2]) {	//根节点是负数
		S[Root1] += S[Root2];	//根节点存储的数字表示这个集合的元素个数
		S[Root2] = Root1;
	}
	else {
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	}
}
	
void Initialization(SetType S, int N)	//初始化集合
{
	for (int i = 0; i < N; i++) {
		S[i] = -1;
	}
}

void Input_connection(SetType S)
{
	ElementType u, v;
	scanf("%d %d", &u, &v);
	SetName Root1, Root2;
	Root1 = Find(S, u - 1);		//因为输入时从1开始编号的，所以要减1
	Root2 = Find(S, v - 1);
	if (Root1 != Root2) {	//只有当两个元素不是同一个集合的时候才把他们合起来
		Union(S, Root1, Root2);
	}
}

void Check_connection(SetType S)
{
	ElementType u, v;
	scanf("%d %d", &u, &v);
	SetName Root1, Root2;
	Root1 = Find(S, u - 1);
	Root2 = Find(S, v - 1);
	if (Root1 != Root2)
		printf("no\n");
	else
		printf("yes\n");
}

void Check_network(SetType S, int N)
{
	int counter = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] < 0)
			counter++;
	}
	if (counter == 1)
		printf("The network is connected.\n");
	else
		printf("There are %d components.\n", counter);
}


int main(void)
{
	SetType S;
	int N;
	scanf("%d", &N);	//后面要读取字符的话，可以在scanf中把前面的换行一块读了
	char in;
	Initialization(S, N);
	do {
		scanf(" %c", &in);
		switch (in) {
		case 'C':	Check_connection(S); break;
		case 'I':	Input_connection(S); break;
		case 'S':	Check_network(S, N); break;
		}
	} while (in != 'S');
	return 0;
}