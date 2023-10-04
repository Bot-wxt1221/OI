#include<bits/stdc++.h>
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3fLL;      //这样定义的好处是: INF <= INF+x
const int N = 3e5+2;

struct edge {
	int from, to;   //边：起点，终点，权值。起点from并没有用到，e[i]的i就是from
	long long w;    //边：权值
	edge(int a, int b, long long c) {
		from = a; to = b; w = c;
	}
};

vector<edge> e[N];   		          //存储图
struct node {
	int id;
	long long n_dis;          //id：结点；n_dis：这个结点到起点的距离
	node(int b, long long c) {
		id = b;
		n_dis = c;
	}
	bool operator < (const node & a) const {
		return n_dis > a.n_dis;
	}
};

int n,m;
int pre[N];                          //记录前驱结点

void print_path(int s, int t) {       //打印从s到t的最短路
	if(s==t) {
		printf("%d ", s);    //打印起点
		return;
	}
	print_path(s, pre[t]);            //先打印前一个点
	printf("%d ", t);                 //后打印当前点。最后打印的是终点t
}

long long  dis[N];                    //记录所有结点到起点的距离
bool done[N];                         //done[i]=true表示到结点i的最短路径已经找到

void dijkstra() {
	int s = 1;                        //起点s = 1
	for (int i=1; i<=n; i++) {
		dis[i]=INF;    //初始化
		done[i]=false;
	}
	dis[s]=0;                         //起点到自己的距离是0
	priority_queue <node> Q;          //优先队列，存结点信息
	Q.push(node(s, dis[s]));          //起点进队列
	while (!Q.empty())   {
		node u = Q.top();             //pop出距起点s距离最小的结点u
		Q.pop();
		if(done[u.id]) continue;      //丢弃已经找到最短路径的结点。即集合A中的结点
		done[u.id]= true;
		for (int i=0; i<e[u.id].size(); i++) {  //检查结点u的所有邻居
			edge y = e[u.id][i];       //u.id的第i个邻居是y.to
			if(done[y.to]) continue;   //丢弃已经找到最短路径的邻居结点
			if (dis[y.to] > y.w + u.n_dis) {
				dis[y.to] = y.w + u.n_dis;
				Q.push(node(y.to, dis[y.to]));    //扩展新邻居，放到优先队列中
				pre[y.to]=u.id;        //如果有需要，记录路径
			}
		}
	}
	// print_path(s,n);                //如果有需要，打印路径: 起点1，终点n
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++)   e[i].clear();
	while (m--) {
		int u, v, w;
		scanf("%d%d%lld",&u,&v,&w);
		e[u].push_back(edge(u,v,w));
		// e[v].push_back(edge(v,u,w));     //本题是单向边
	}
	dijkstra();
	for(int i =1; i <= n; i++) {
		if(dis[i] >= INF)  cout << "-1 ";
		else   printf("%lld ", dis[i]);
	}
	return 0;
}

