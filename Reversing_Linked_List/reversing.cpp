#include<iostream>
#include<algorithm>
using namespace std;
int list[100010];
int node[100010][2];
int main()
{
	/*这个做法严重违背姥姥的初衷，甚至绕开了她设下的陷阱，屌炸！*/
	int st, num, r;
	cin >> st >> num >> r;
	int address, data, next, i;
	for (i = 0; i<num; i++)
	{
		cin >> address >> data >> next;
		node[address][0] = data;
		node[address][1] = next;
	}
	int m = 0, n = st;
	while (n != -1)	//list这个数组把原始的链表的下一个元素地址连续按链表顺序保存下来
	{
		list[m++] = n;	//一开始就是顺着给定的链表走的，所以完美绕开了无用节点……
		n = node[n][1];
	}
	i = 0;
	while (i + r <= m)
	{
		reverse(list + i, list + i + r);	//把下地址每k个反过来排序
		i = i + r;
	}
	for (i = 0; i < m - 1; i++)
	{
		printf("%05d %d %05d\n", list[i], node[list[i]][0], list[i + 1]);//按着反过来的顺序输出就解决了
	}
	printf("%05d %d -1\n", list[i], node[list[i]][0]);
}