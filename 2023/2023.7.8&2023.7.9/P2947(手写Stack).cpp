#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 100;

struct mystack {
	int a[maxn]; //���ջԪ�أ�int ��
	int t = 0; //ջ��λ��
	void push(int x) {
		a[++t] = x;    //����ջ
	}
	int top() {
		return a[t];    //����ջ��Ԫ��
	}
	void pop() {
		t--;    //����ջ��
	}
	int empty() {
		return t == 0 ? 1 : 0;   //���� 1 ��ʾ��
	}
} st;
int h[maxn], ans[maxn];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) scanf("%d",&h[i]);
	for (int i = n; i >= 1; i--) {
		while (!st.empty() && h[st.top()] <= h[i])
			st.pop(); //ջ����ţû i �ߣ���������ֱ��ջ����ţ����
		if (st.empty()) //ջ�գ�û����������
			ans[i] = 0;
		else //ջ����ţ���ߣ�����������
			ans[i] = st.top();
		st.push(i);
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n",ans[i]);
	return 0;
}

/*
���룺
6
3
2
6
1
1
2

�����
3
3
0
6
6
0
*/
