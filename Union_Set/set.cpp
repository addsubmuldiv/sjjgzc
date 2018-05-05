#include <iostream>
#define MAXN 40000
using namespace std;

typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MAXN];	//�±��������ֵ,S[i]�����ĸ��ڵ�,���ڵ㱣�����Ԫ����

SetName Find(SetType S, ElementType X) 
{
	if (S[X] < 0)
		return X;
	else
		return S[X] = Find(S, S[X]);  //β�ݹ�ѹ��·��
}

SetName Union(SetType S, SetName Root1, SetName Root2)
{
	if (S[Root1] < S[Root2]) {	//���ڵ��Ǹ���
		S[Root1] += S[Root2];	//���ڵ�洢�����ֱ�ʾ������ϵ�Ԫ�ظ���
		S[Root2] = Root1;
	}
	else {
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	}
}
	
void Initialization(SetType S, int N)	//��ʼ������
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
	Root1 = Find(S, u - 1);		//��Ϊ����ʱ��1��ʼ��ŵģ�����Ҫ��1
	Root2 = Find(S, v - 1);
	if (Root1 != Root2) {	//ֻ�е�����Ԫ�ز���ͬһ�����ϵ�ʱ��Ű����Ǻ�����
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
	scanf("%d", &N);	//����Ҫ��ȡ�ַ��Ļ���������scanf�а�ǰ��Ļ���һ�����
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