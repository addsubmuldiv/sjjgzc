#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N = 0;
bool *visited = NULL;
int **matrix = NULL;
vector<int> res;

void DFS(int Start)
{
	visited[Start] = true;
	res.push_back(Start);
	for (int i = 0; i < N; i++) {
		if (matrix[Start][i] == 1 && !visited[i]) {
			DFS(i);
		}
	}
}

void Output()
{
	printf("{ ");
	for (int x : res) {
		printf("%d ", x);
	}
	printf("}\n");
}


void ListComponent_DFS()
{
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			res.clear();
			DFS(i);
			Output();
		}
	}
}


void BFS(int Start)
{
	visited[Start] = true;
	res.push_back(Start);
	queue<int> Q;
	Q.push(Start);
	int V;
	while (!Q.empty()) {
		V = Q.front();
		Q.pop();
		for (int i = 0; i < N; i++) {
			if (matrix[V][i] == 1 && !visited[i]) {
				Q.push(i);
				res.push_back(i);
				visited[i] = true;
			}
		}
	}

}


void ListComponent_BFS()
{
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			res.clear();
			BFS(i);
			Output();
		}
	}
}


int main(void)
{
	int E;
	scanf("%d", &N);
	visited = new bool[N];
	matrix = new int*[N];
	for (int i = 0; i < N; i++) {
		matrix[i] = new int[N];
		visited[i] = false;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			matrix[i][j] = 0;
		}
	}
	scanf("%d", &E);
	int V, W;
	for (int i = 0; i < E; i++) {
		scanf("%d %d", &V, &W);
		matrix[V][W] = 1;
		matrix[W][V] = 1;
	}
	ListComponent_DFS();
	for (int i = 0; i < N; i++) {
		visited[i] = false;
	}
	res.clear();
	ListComponent_BFS();
	system("pause");
	return 0;
}