#include <iostream>
#define MaxVertexNum 100

using namespace std;

typedef int Vertex;
typedef int WeightType;
typedef char DataType;

typedef struct ENode *PtrToENode;	//�߽ڵ�ò��ֻ������ʱ��һ��,Ȩ�����ڽӱ����Ƿ����ڽӵ��ϵ�
struct ENode {
	Vertex V1, V2;
	WeightType Weight;
};

typedef PtrToENode Edge;

typedef struct AdjVNode *PtrToAdjVNode;

struct AdjVNode {	//�ڽӵ㣬Ҳ���������Ϲҵ�
	Vertex AdjV;	//�����±�
	WeightType Weight;	//�ߵ�Ȩ��
	PtrToAdjVNode Next;	//ָ����һ���ڽӵ��ָ��
};

typedef struct VNode {	//�ڽӱ�ͷ���
	PtrToAdjVNode FirstEdge;	//ָ���һ���ڽӵ��ָ��
	DataType Data;		//ÿ�������д������
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;
	int Ne;
	AdjList G;
};

typedef PtrToGNode LGraph;

LGraph CreateGraph(int VertexNum)
{
	Vertex V;
	LGraph Graph;
	
	Graph = (LGraph)malloc(sizeof(GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (V = 0; V < Graph->Nv; V++) {
		Graph->G[V].FirstEdge = NULL;
	}
	return Graph;
}

void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode;
	NewNode = (PtrToAdjVNode)malloc(sizeof(AdjVNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;

	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;
	/*----------------����ͼ���˽��������������ͼ��Ҫ�ѽڵ�嵽�յ��������--------------*/
	//����
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V1;
    NewNode->Weight = E->Weight;
    /* ��V1����V2�ı�ͷ */
    NewNode->Next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph()
{
	LGraph Graph;
	int Nv;
	//printf("���붥�����");
	scanf("%d", &Nv);
	Graph = CreateGraph(Nv);
	//printf("����߸���");
	scanf("%d", &(Graph->Ne));
	if (Graph->Ne != 0) {
		Edge E = (Edge)malloc(sizeof(ENode));
		for (int i = 0; i < Graph->Ne; i++) {
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);//�ߵ���㡢�յ㡢Ȩ��
			InsertEdge(Graph, E);
		}
	}
	//���붥�������
	for (int i = 0; i < Graph->Nv; i++) {
		scanf(" %c", &(Graph->G[i].Data));
	}
}


int main(void)
{

}