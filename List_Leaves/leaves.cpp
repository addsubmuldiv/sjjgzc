#include <iostream>
#include <set>
#include <queue>
#include <string>
using namespace std;


int main(void)
{
	int N;
	scanf("%d", &N);
	char **tree = new char *[N];
	for (int i = 0; i < N; i++) {
		tree[i] = new char[2];
	}
	for (int i = 0; i < N; i++) {
		scanf(" %c", &tree[i][0]);
		scanf(" %c", &tree[i][1]);
		if (tree[i][0] != '-') {
			tree[i][0] = tree[i][0] - '0';
		}
		if (tree[i][1] != '-') {
			tree[i][1] = tree[i][1] - '0';
		}
	}
	set<int> c;
	
	for (int i = 0; i < N; i++) {
		c.insert(i);
	}

	for (int i = 0; i < N; i++) {
		if (tree[i][0] != '-') {
			c.erase(tree[i][0]);
		}
		if (tree[i][1] != '-') {
			c.erase(tree[i][1]);
		}
	}
	int root;
	if (!c.empty()) {
		set<int>::iterator iter = c.begin();
		root = *iter;
	}
	
	queue<int> q;
	q.push(root);
	string res = "";
	int node;
	while (!q.empty()) {
		node = q.front();
		q.pop();
		if (tree[node][0] == '-'&&tree[node][1] == '-') {
			res = res + to_string(node) + " ";
		}
		if (tree[node][0] != '-') {
			q.push(tree[node][0]);
		}
		if (tree[node][1] != '-') {
			q.push(tree[node][1]);
		}
	}
	printf("%s",res.substr(0, res.length() - 1).c_str());
	delete[] tree;
	system("pause");
	return 0;
}