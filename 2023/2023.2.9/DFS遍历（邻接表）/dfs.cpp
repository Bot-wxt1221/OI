#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXM = 2005;
struct Edge {
	int to, w, next;
} edges[MAXM];
int head[MAXM], cnt = 1; // cntΪ��ǰ�ߵı��
bool vis[1001];
int n,m;
void dfs(int u);
inline void add(int from, int to, int w);

int main(void) {
	freopen("graph.in","r",stdin);
	freopen("graph_bfs.out","w",stdout);
	memset(vis,false,sizeof(vis));
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >>z;
		add(x, y, z);
		add(y, x, z);
	}	
	dfs(1);	
	
	return 0;
} 

void dfs(int u) {
	cout << u << " ";
	vis[u] = true;
	for(int t = head[u]; t; t = edges[t].next) {
    		int k = edges[t].to;
    		if(vis[k] == false) {
    			dfs(k); 					
    		}
    	}  
				
	return;
}

inline void add(int from, int to, int w) {
	edges[++cnt].w = w; //����һ�����Ϊcnt+1�ıߣ���ȨΪw
	edges[cnt].to = to; //�ñߵ��յ�Ϊto
	edges[cnt].next = head[from]; //����һ���ߣ�����Ϊ��ǰ���ĵ�һ����
	head[from] = cnt; //�ñ߳�Ϊ��ǰ����µĵ�һ����
} 
