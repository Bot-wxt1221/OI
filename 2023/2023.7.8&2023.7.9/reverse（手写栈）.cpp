#include<bits/stdc++.h>
const int N = 100100;
struct mystack {
	char a[N];                            //���ջԪ�أ��ַ���
	int t = 0;                            //ջ��λ��
	void push(char x) {
		a[++t] = x;    //����ջ
	}
	char top()       {
		return a[t];    //����ջ��Ԫ��
	}
	void pop()       {
		t--;            //����ջ��
	}
	int empty()      {
		return t==0?1:0;   //����1��ʾ��
	}
} st;

int main() {
	int n;
	scanf("%d",&n);
	getchar();
	while(n--) {
		while(true) {
			char ch = getchar();            //һ�ζ���һ���ַ�
			if(ch==' '||ch=='\n'||ch==EOF) {
				while(!st.empty()) {
					printf("%c",st.top());    //��������ջ��
					st.pop();
				}
				if(ch=='\n'||ch==EOF)  break;
				printf(" ");
			} else    st.push(ch);            //��ջ
		}
		printf("\n");
	}
	return 0;
}

