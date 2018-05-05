#include <iostream>
#define ElementType int
#define MAXDATA 1000	//�ڱ������ڶ����κ�һ��Ԫ��
using namespace std;

typedef struct HNode *Heap;

struct HNode {
	ElementType *Data;  //�洢Ԫ�ص�����
	int Size;	//���е�ǰԪ����
	int Capacity;	//�ѵ��������
};

typedef Heap MaxHeap;	//����
typedef Heap MinHeap;	//��С��

MaxHeap CreateHeap(int MaxSize)
{
	MaxHeap H = (MaxHeap)malloc(sizeof(struct HNode));
	H->Data = (ElementType *)malloc((MaxSize + 1) * sizeof(ElementType)); //�Ѵ�1��ʼ��
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Data[0] = MAXDATA;	// 0 �±�������ڱ�
	return H;
}

bool IsFull(Heap H)
{
	return H->Size == H->Capacity;
}

bool Insert(MaxHeap H, ElementType X)
{
	int i;

	if (IsFull(H)) {
		printf("��������");
		return false;
	}
	i = ++H->Size; //iָ��������е����һ��Ԫ�ص�λ��
	for (; H->Data[i / 2] < X; i /= 2) {
		H->Data[i] = H->Data[i / 2];	//���ѣ����Ա�XС�ľ�������
	}
	H->Data[i] = X;
	return true;
}




int main(void)
{

}