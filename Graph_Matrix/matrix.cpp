#include <iostream>
#define MaxVertexNum 100  //��󶥵�����
#define INFINITY 65535
using namespace std;

typedef int Vertex;
typedef int WeightType;
typedef char DataType;
typedef struct ENode *PtrToENode;

struct ENode {	//�߽ṹ
	Vertex V1, V2;	//�ߵĶ˵�
	WeightType Weight;	//�ߵ�Ȩ��
};

typedef PtrToENode Edge;


typedef struct GNode {	//ͼ�ṹ
	int Nv;		//������
	int Ne;		//����
	WeightType G[MaxVertexNum][MaxVertexNum];	//�ߣ��ڽӾ���
	DataType Data[MaxVertexNum];   //����
} *PtrToGNode;

typedef PtrToGNode MGraph;

MGraph CreateGraph(int VertexNum)
{	/*�½�һ���ж��㵫û�бߵ�ͼ����ʼ�ڽӾ���ȫ����Ϊ����*/
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (int i = 0; i < Graph->Nv; i++) {
		for (int j = 0; j < Graph->Nv; j++) {
			Graph->G[i][j] = INFINITY;
		}
	}

	return Graph;
}

void Insert(MGraph Graph, Edge E)	//�����,��Ϊ�Ǿ���,���Բ�����,����Ҫ�Գ�
{
	Graph->G[E->V1][E->V2] = E->Weight;
	Graph->G[E->V2][E->V1] = E->Weight;
}


MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	//printf("���붥����:");
	scanf("%d", &Nv);
	Graph = CreateGraph(Nv);

	//printf("�������:");
	scanf("%d", &Graph->Ne);
	if (Graph->Ne != 0) {
		E = new ENode;
		for (i = 0; i < Graph->Ne; i++) {
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			Insert(Graph, E);
		}
	}
	
	//���붥���ϵ�����
	for (V = 0; V < Graph->Nv; V++) {
		scanf(" %c", &Graph->Data[V]);
	}

	return Graph;
}


int main(void)
{

}