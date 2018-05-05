#include <iostream>
#define MaxVertexNum 100  //最大顶点数量
#define INFINITY 65535
using namespace std;

typedef int Vertex;
typedef int WeightType;
typedef char DataType;
typedef struct ENode *PtrToENode;

struct ENode {	//边结构
	Vertex V1, V2;	//边的端点
	WeightType Weight;	//边的权重
};

typedef PtrToENode Edge;


typedef struct GNode {	//图结构
	int Nv;		//顶点数
	int Ne;		//边数
	WeightType G[MaxVertexNum][MaxVertexNum];	//边，邻接矩阵
	DataType Data[MaxVertexNum];   //顶点
} *PtrToGNode;

typedef PtrToGNode MGraph;

MGraph CreateGraph(int VertexNum)
{	/*新建一个有顶点但没有边的图，初始邻接矩阵全部设为无穷*/
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

void Insert(MGraph Graph, Edge E)	//插入边,因为是矩阵,所以插两个,矩阵要对称
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

	//printf("输入顶点数:");
	scanf("%d", &Nv);
	Graph = CreateGraph(Nv);

	//printf("输入边数:");
	scanf("%d", &Graph->Ne);
	if (Graph->Ne != 0) {
		E = new ENode;
		for (i = 0; i < Graph->Ne; i++) {
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			Insert(Graph, E);
		}
	}
	
	//输入顶点上的数据
	for (V = 0; V < Graph->Nv; V++) {
		scanf(" %c", &Graph->Data[V]);
	}

	return Graph;
}


int main(void)
{

}