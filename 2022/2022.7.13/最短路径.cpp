/*
输入(有向图)：
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

//floyd:任意点之间的最短路径（DP）
//时间复杂度：O(n^3)
//空间复杂度：O(n^2) 
int dist [400][400];
memset(dist, 0X3f, sizeof(dist));   //把所有距离初始化为0x3f3f3f3f，注意这个数的两倍小于32位和64位机器上的INT_MAX

for(int i = 1; i <= n; i++) {  //每个点到自己的距离设为 0 
	dist[i][i] = 0;
}

for(int i = 0; i <= m; i++) {  //读入 m 条边 
	int u, v, w;
	scanf("%d%d%d", &u, &v, &w);
	dist[u][v] = w;
}

// 经由 k点，尝试把 i点到 j点的距离缩短
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


//Bellman-Ford :单源点最短路径  
//处理负权环:只需要再多对每条边松弛一遍，如果这次还有点被更新，就说明存在负权环。
//源点到目标点，最多经 n-1 条边，最多松弛 n - 1次
//时间复杂度：O(mn) 
//空间复杂度：O(m) 

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

int dist[MAXN] //dist[]来存储每个点到起点的最短距离
memset(dist, 0X3f, sizeof(dist));   //把所有距离初始化为0x3f3f3f3f，注意这个数的两倍小于32位和64位机器上的INT_MAX
dist[1] = 0;

void  Bellman-Ford(int n, int m) {   
	for(int j = 1; j < n; j++) {
		for(int i = 1; i <= m; i++) {
			dist[edges[i].to] = min(dist[edges[i].to], dist[edges[i].from] + edges[i].w);
		}
	}
}


//--------------------------------------------------------------------------------------------

//SPFA：队列优化Bellman-Ford
//时间复杂度：O(m + nlogn)  不稳定，最坏情况是：O(mn) 
//空间复杂度：O(m) 
//SPFA也可以判负权环，我们可以用一个数组记录每个顶点进队的次数，当一个顶点进队超过n次
//时，就说明存在负权环。（这与Bellman-Ford判负权环的原理类似）

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

int dist[MAXN] //dist[]来存储每个点到起点的最短距离
memset(dist, 0X3f, sizeof(dist));   //把所有距离初始化为0x3f3f3f3f，注意这个数的两倍小于32位和64位机器上的INT_MAX
dist[1] = 0;

void SPFA(int s) { //s是源点 
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
//Dijkstra)(堆优化): 单源点最短路径(贪心策略)，不能有负环
//思想：不断取出离顶点最近而没有被访问过的点（贪心），松弛它和它能到达的所有点。 
//时间复杂度：O(mlogm) 
//空间复杂度：O(m) 



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

int dist[MAXN] //dist[]来存储每个点到起点的最短距离
memset(dist, 0X3f, sizeof(dist));   //把所有距离初始化为0x3f3f3f3f，注意这个数的两倍小于32位和64位机器上的INT_MAX

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



