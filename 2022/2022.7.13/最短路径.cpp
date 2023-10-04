/*
����(����ͼ)��
5 8
1 2 1
1 3 4
1 4 6
2 4 2
2 5 4
3 4 1
4 5 1
5 3 6
*/

//floyd:�����֮������·����DP��
//ʱ�临�Ӷȣ�O(n^3)
//�ռ临�Ӷȣ�O(n^2) 
int dist [400][400];
memset(dist, 0X3f, sizeof(dist));   //�����о����ʼ��Ϊ0x3f3f3f3f��ע�������������С��32λ��64λ�����ϵ�INT_MAX

for(int i = 1; i <= n; i++) {  //ÿ���㵽�Լ��ľ�����Ϊ 0 
	dist[i][i] = 0;
}

for(int i = 0; i <= m; i++) {  //���� m ���� 
	int u, v, w;
	scanf("%d%d%d", &u, &v, &w);
	dist[u][v] = w;
}

// ���� k�㣬���԰� i�㵽 j��ľ�������
void floyd(int n) {
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[k][j] + dist[k][j]);
			}
		}
	}
}


//--------------------------------------------------------------------------------------------


//Bellman-Ford :��Դ�����·��  
//����Ȩ��:ֻ��Ҫ�ٶ��ÿ�����ɳ�һ�飬�����λ��е㱻���£���˵�����ڸ�Ȩ����
//Դ�㵽Ŀ��㣬��ྭ n-1 ���ߣ�����ɳ� n - 1��
//ʱ�临�Ӷȣ�O(mn) 
//�ռ临�Ӷȣ�O(m) 

const int MAXM = 1000;
const int MAXN = 1000;
struct Edge {
	int from, to, w, next;
} edges[MAXM];
int head[MAXN], cnt = 0;

void add(int from, int to, int w) {
	edges[++cnt].w = w;
	edges[cnt].from = from;
	edges[cnt].to = to;
	edges[cnt].next = head[from];
	head[from] = cnt;
}

int dist[MAXN] //dist[]���洢ÿ���㵽������̾���
memset(dist, 0X3f, sizeof(dist));   //�����о����ʼ��Ϊ0x3f3f3f3f��ע�������������С��32λ��64λ�����ϵ�INT_MAX
dist[1] = 0;

void  Bellman-Ford(int n, int m) {   
	for(int j = 1; j < n; j++) {
		for(int i = 1; i <= m; i++) {
			dist[edges[i].to] = min(dist[edges[i].to], dist[edges[i].from] + edges[i].w);
		}
	}
}


//--------------------------------------------------------------------------------------------

//SPFA�������Ż�Bellman-Ford
//ʱ�临�Ӷȣ�O(m + nlogn)  ���ȶ��������ǣ�O(mn) 
//�ռ临�Ӷȣ�O(m) 
//SPFAҲ�����и�Ȩ�������ǿ�����һ�������¼ÿ��������ӵĴ�������һ��������ӳ���n��
//ʱ����˵�����ڸ�Ȩ����������Bellman-Ford�и�Ȩ����ԭ�����ƣ�

const int MAXM = 1000;
const int MAXN = 1000;
struct Edge {
	int from, to, w, next;
} edges[MAXM];
int head[MAXN], cnt = 0;

void add(int from, int to, int w) {
	edges[++cnt].w = w;
	edges[cnt].from = from;
	edges[cnt].to = to;
	edges[cnt].next = head[from];
	head[from] = cnt;
}

int dist[MAXN] //dist[]���洢ÿ���㵽������̾���
memset(dist, 0X3f, sizeof(dist));   //�����о����ʼ��Ϊ0x3f3f3f3f��ע�������������С��32λ��64λ�����ϵ�INT_MAX
dist[1] = 0;

void SPFA(int s) { //s��Դ�� 
	queue<int> Q;
	Q.push(s);
	while(!Q.empty()) {
		int p = Q.front();
		Q.pop();
		inqueue[p] = 0;
		for(int e = head[p]; e != 0; e = edges[e].next) {
			int to = edges[e].to;
			if(dist[to] > dist[p] + edges[e].w){
				dist[to] = dist[p] + edges[e].w;
				if(!inqueue[to]){
					inqueue[to] = 1;
					Q.push(to);
				}
			}
		}
	} 
} 


//------------------------------------------------------------------------------------------- 
//Dijkstra)(���Ż�): ��Դ�����·��(̰�Ĳ���)�������и���
//˼�룺����ȡ���붥�������û�б����ʹ��ĵ㣨̰�ģ����ɳ��������ܵ�������е㡣 
//ʱ�临�Ӷȣ�O(mlogm) 
//�ռ临�Ӷȣ�O(m) 



const int MAXM = 1000;
const int MAXN = 1000;
struct Edge {
	int from, to, w, next;
} edges[MAXM];
int head[MAXN], cnt = 0;

void add(int from, int to, int w) {
	edges[++cnt].w = w;
	edges[cnt].from = from;
	edges[cnt].to = to;
	edges[cnt].next = head[from];
	head[from] = cnt;
}

int dist[MAXN] //dist[]���洢ÿ���㵽������̾���
memset(dist, 0X3f, sizeof(dist));   //�����о����ʼ��Ϊ0x3f3f3f3f��ע�������������С��32λ��64λ�����ϵ�INT_MAX

typedef pair<int, int> Pair;
priority_queue<Pair, vector<Pair>, greater<Pair> > Q; 

void Dij(int s) {
	dist[s] = 0;
	Q.push(make_pair(0, s));
	while (!Q.empty())	{
		int p = Q.top().second;
		Q.pop();
		if (vis[p])	continue;
		vis[p] = 1;
		for (int e = head[p]; e != 0; e = edges[e].next) {
			int to = edges[e].to;
			dist[to] = min(dist[to], dist[p] + edges[e].w);
			if (!vis[to]) Q.push(make_pair(dist[to], to));
		}
	}
} 



