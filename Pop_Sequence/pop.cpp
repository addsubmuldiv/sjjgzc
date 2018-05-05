#include<stack>
#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;
int M, N, K;
int check_stack(vector<int> &v) {
	stack<int> sta;
	sta.push(0);    //dummy element, as sential
	int cap = M + 1;    //stack capacity
	int idx = 0;        //index of vector v
	int num = 1;        //to push to stack
	while (idx != N) {
		while (v[idx]>sta.top() && sta.size()<cap&&idx <= N)
			sta.push(num++);
		if (v[idx] == sta.top()) {
			sta.pop();
			idx++;
		}
		else //sta.size>=cap; idx>N
			return 0;   //false
	}
	return 1;   //true
}
/*
对于要判断的序列，如果正在判断的位置的数字比栈顶元素大(一开始栈顶放0)，那么持续入栈直到一样大，如果栈满还不一样，
那就说明不对；
如果一样，那么把它出栈，继续判断下一个位置的数字。
如果到最后每个位置的数字都判断完了，那就说明这一组数据是可以的。
*/
int main() {
	//int M,N,K;
	cin >> M >> N >> K;
	vector<int> vec(N, 0);   //N pop number
	for (int i = 0; i != K; ++i) {
		//input to vec
		copy_n(istream_iterator<int>(cin), N, vec.begin());
		cout << (check_stack(vec) ? "YES" : "NO") << endl;
	}
}