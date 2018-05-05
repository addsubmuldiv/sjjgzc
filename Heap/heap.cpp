#include <iostream>
#define ElementType int
#define MAXDATA 1000	//哨兵，大于堆中任何一个元素
using namespace std;

typedef struct HNode *Heap;

struct HNode {
	ElementType *Data;  //存储元素的数组
	int Size;	//堆中当前元素数
	int Capacity;	//堆的最大容量
};

typedef Heap MaxHeap;	//最大堆
typedef Heap MinHeap;	//最小堆

MaxHeap CreateHeap(int MaxSize)
{
	MaxHeap H = (MaxHeap)malloc(sizeof(struct HNode));
	H->Data = (ElementType *)malloc((MaxSize + 1) * sizeof(ElementType)); //堆从1开始存
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Data[0] = MAXDATA;	// 0 下标出放置哨兵
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
		printf("最大堆已满");
		return false;
	}
	i = ++H->Size; //i指向插入后堆中的最后一个元素的位置
	for (; H->Data[i / 2] < X; i /= 2) {
		H->Data[i] = H->Data[i / 2];	//最大堆，所以比X小的就往下移
	}
	H->Data[i] = X;
	return true;
}




int main(void)
{

}