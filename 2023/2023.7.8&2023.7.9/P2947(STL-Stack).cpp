/*
从后往前遍历奶牛，并用一个栈保存从低到高的奶牛，栈顶的奶牛最矮，栈底的最高。
具体操作是：遍历到奶牛 i 时，与栈顶的奶牛比较，如果不比i 高，就弹出栈顶，直到栈顶的
奶牛比 i 高，这就是 i 的仰望对象；然后把 i 放进栈顶，栈里的奶牛仍然保持从低到高。
复杂度：每个奶牛只进出栈一次，所以是 O(n)的。
*/

#include<bits/stdc++.h>
using namespace std;
int h[100001], ans[100001];
int main() {
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) scanf("%d",&h[i]);
	stack<int> st;
	for (int i = n; i >= 1; i--) {
		while (!st.empty() && h[st.top()] <= h[i])
			st.pop(); //栈顶奶牛没我高，弹出它，直到栈顶奶牛更高
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
