#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 100;

struct mystack {
	int a[maxn]; //存放栈元素，int 型
	int t = 0; //栈顶位置
	void push(int x) {
		a[++t] = x;    //送入栈
	}
	int top() {
		return a[t];    //返回栈顶元素
	}
	void pop() {
		t--;    //弹出栈顶
	}
	int empty() {
		return t == 0 ? 1 : 0;   //返回 1 表示空
	}
} st;
int h[maxn], ans[maxn];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) scanf("%d",&h[i]);
	for (int i = n; i >= 1; i--) {
		while (!st.empty() && h[st.top()] <= h[i])
			st.pop(); //栈顶奶牛没 i 高，弹出它，直到栈顶奶牛更高
		if (st.empty()) //栈空，没有仰望对象
			ans[i] = 0;
		else //栈顶奶牛更高，是仰望对象
			ans[i] = st.top();
		st.push(i);
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n",ans[i]);
	return 0;
}

/*
输入：
6
3
2
6
1
1
2

输出：
3
3
0
6
6
0
*/
