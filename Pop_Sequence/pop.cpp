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
����Ҫ�жϵ����У���������жϵ�λ�õ����ֱ�ջ��Ԫ�ش�(һ��ʼջ����0)����ô������ջֱ��һ�������ջ������һ����
�Ǿ�˵�����ԣ�
���һ������ô������ջ�������ж���һ��λ�õ����֡�
��������ÿ��λ�õ����ֶ��ж����ˣ��Ǿ�˵����һ�������ǿ��Եġ�
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