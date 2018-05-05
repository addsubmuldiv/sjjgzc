#include <iostream>
#define MaxVertexNum 100

using namespace std;

typedef int Vertex;
typedef int WeightType;
typedef char DataType;

typedef struct ENode *PtrToENode;	//边节点貌似只在输入时用一下,权重在邻接表中是放在邻接点上的
struct ENode {
	Vertex V1, V2;
	WeightType Weight;
};

typedef PtrToENode Edge;

typedef struct AdjVNode *PtrToAdjVNode;

struct AdjVNode {	//邻接点，也就是链表上挂的
	Vertex AdjV;	//顶点下标
	WeightType Weight;	//边的权重
	PtrToAdjVNode Next;	//指向下一个邻接点的指针
};

typedef struct VNode {	//邻接表头结点
	PtrToAdjVNode FirstEdge;	//指向第一个邻接点的指针
	DataType Data;		//每个顶点中存的数据
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
	/*----------------有向图到此结束，如果是无向图则还要把节点插到终点的链表上--------------*/
	//如下
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V1;
    NewNode->Weight = E->Weight;
    /* 将V1插入V2的表头 */
    NewNode->Next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph()
{
	LGraph Graph;
	int Nv;
	//printf("输入顶点个数");
	scanf("%d", &Nv);
	Graph = CreateGraph(Nv);
	//printf("输入边个数");
	scanf("%d", &(Graph->Ne));
	if (Graph->Ne != 0) {
		Edge E = (Edge)malloc(sizeof(ENode));
		for (int i = 0; i < Graph->Ne; i++) {
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);//边的起点、终点、权重
			InsertEdge(Graph, E);
		}
	}
	//输入顶点的数据
	for (int i = 0; i < Graph->Nv; i++) {
		scanf(" %c", &(Graph->G[i].Data));
	}
}


int main(void)
{

}