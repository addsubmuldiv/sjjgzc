#include <iostream>
#define MINDATA -10001
using namespace std;


struct Heap {
	int *data;
	int size;
	int capacity;
	Heap(int capacity);
	~Heap();
};

using MinHeap = Heap*;

Heap::Heap(int capacity) 
{
	data = new int[capacity+1];
	capacity = capacity;
	size = 0;
	data[0] = MINDATA;

}

Heap::~Heap()
{
	delete[] data;
}

void Insert(MinHeap h, int x)
{
	int i;
	i = ++h->size;
	for (; h->data[i / 2] > x; i /= 2) {
		h->data[i] = h->data[i / 2];
	}
	h->data[i] = x;
}



int main(void)
{
	int N, M;
	scanf("%d", &N);
	scanf("%d", &M);
	Heap h(1000);
	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		Insert(&h, tmp);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &tmp);
		printf("%d", h.data[tmp]);
		while (tmp > 1) {
			tmp /= 2;
			printf(" %d", h.data[tmp]);
		}
		putchar('\n');
	}
	h.~Heap();
	return 0;
}