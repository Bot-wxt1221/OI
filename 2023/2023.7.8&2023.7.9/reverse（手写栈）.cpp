#include<bits/stdc++.h>
const int N = 100100;
struct mystack {
	char a[N];                            //存放栈元素，字符型
	int t = 0;                            //栈顶位置
	void push(char x) {
		a[++t] = x;    //送入栈
	}
	char top()       {
		return a[t];    //返回栈顶元素
	}
	void pop()       {
		t--;            //弹出栈顶
	}
	int empty()      {
		return t==0?1:0;   //返回1表示空
	}
} st;

int main() {
	int n;
	scanf("%d",&n);
	getchar();
	while(n--) {
		while(true) {
			char ch = getchar();            //一次读入一个字符
			if(ch==' '||ch=='\n'||ch==EOF) {
				while(!st.empty()) {
					printf("%c",st.top());    //输出并清除栈顶
					st.pop();
				}
				if(ch=='\n'||ch==EOF)  break;
				printf(" ");
			} else    st.push(ch);            //入栈
		}
		printf("\n");
	}
	return 0;
}

