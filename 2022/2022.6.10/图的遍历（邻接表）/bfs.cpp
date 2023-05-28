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
int n, m;
void bfs(int u);
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
	bfs(1);	
		
	return 0;
} 

void bfs(int u) {
	int q[1001];
	int front = 0, tail = 0;
	q[front] = u;
	tail++;
    vis[u] = true;
    while(front < tail) {
    	int p = q[front++];
    	cout << p << " ";    	
    	for(int t = head[p]; t; t = edges[t].next) {
    		int k = edges[t].to;
    		if(vis[k] == false) {
    				q[tail++] = k;
    				vis[k] = true;       					
    		}
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

