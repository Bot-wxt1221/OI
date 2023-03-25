//����ͼ�ĸ��---tarjan_cut�㷨
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int n, m; //n���㣬 m����

//�ڽӱ��ͼ
struct Edge{
	int to, next;
} e[MAXN << 1];
int head[MAXN], cnt = 0;

void add(int u, int v) {
	e[++cnt].to = v;
	e[cnt].next = head[u];
	head[u] = cnt; 
} 
 
//tarjan_cut�㷨
int num = 0;  //ʱ���������
int dfn[MAXN], low[MAXN]; //ʱ�����׷�ݵ�
int root; //���ڵ� 
void tarjan_cut(int u, int fa) { //���� 
	dfn[u] = low[u] = ++num;
	int count = 0; //���� root �ڵ㣬ͳ���亢�ӵ�����
	for(int i = head[u]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa) continue;
		if(!dfn[v]) {//u���ڽӵ�vδ���ʹ� 
			tarjan_cut(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] >= dfn[u]) { //����ͨ����u-v֮���·���ص���������� 
				count++;
				if(u != root || count > 1) {//���Ǹ��ڵ�����Ǹ��ڵ㵫�亢�Ӵ���1�� 
					cout << u << endl;
				}
			}
		}
		else { //u���ڽӵ�v�ѷ��ʹ��������Ǹ��ף���v��u��������� 
			low[u] = min(low[u], dfn[v]);
		}
	} 
	return;
} 

int main() {
	memset(head, 0, sizeof(head));
	memset(dfn, 0 ,sizeof(dfn));
	memset(low, 0, sizeof(low));
	cin >> n >> m;
	int u, v;
	while(m--) {
		cin >> u >> v;
		add(u, v);
		add(v, u);
	}
	for(int i = 1; i <= n; i++) {
		if(!dfn[i]) {
			root = i;
			tarjan_cut(i, 0);
		}
	}
	return 0;
}

/*
���룺
7 7
1 2
2 3
3 5
5 7
5 6
6 4
4 1
�����
5
*/ 


/*
���룺
10 13
1 2
1 3
1 4
2 3
2 5
3 5
4 6
5 7
5 6
5 8
8 9
8 10
9 10
�����
8
5
*/ 

