// poj 2449代码
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1005, M = 100005;
struct edge{          //记录边
int to, w;
//vector edge[i]:起点是i;它有很多边,其中一个边的to是边的终点,w是边长
    edge(int a,int b){ to = a, w = b;} //赋值
};
vector <edge>G[M], G2[M];  //G:原图; G2:反图
struct node {      //用于dijkstra。记录点，以及点到起点的路径
    int id, dis;   //id:点；dis：点id到起点的路径长度
    node(int a, int b){ id = a, dis = b;} //赋值
    bool operator < (const node &u) const { return dis > u.dis; }
};
int  dist[N];   //dist[i]: 从s到点i的最短路长度
bool done[N];   //done[i]=ture: 表示到i的最短路已经找到
void dijkstra(int s) {    //标准的dijkstra: 求s到其他所有点的最短路
    for(int i =0;i<N;i++) {dist[i]=INF; done[i]=false;}  //初始化
    dist[s] = 0;          //起点s到自己的距离是0
    priority_queue<node> q;
    q.push(node(s, dist[s]));    //从起点开始处理队列
    while (!q.empty()) {
        node u = q.top();        //pop出距起点s最近的点u
        q.pop();
        if (done[u.id])  continue; //丢弃已经找到最短路的点            
        done[u.id] = true;       //标记：点u到s的最短路已经找到
        for (int i = 0; i< G2[u.id].size(); i++) {  //检查点u的所有邻居
            edge y = G2[u.id][i];
            if (done[y.to])   continue; //丢弃已经找到最短路的邻居                
            if (dist[y.to] > u.dis + y.w) {
                dist[y.to] = u.dis + y.w;
                q.push(node(y.to, dist[y.to]));  //扩展新的邻居，放进优先队列
            }
        }
    }
}
struct point {      //用于 astar
    int v, g, h;    //评估函数 f = g + h, g是从s到i的长度，h是从i到t的长度
    point(int a, int b, int c) { v=a, g=b, h=c; }
    bool operator < (const point & b) const { return g + h > b.g + b.h;}
};
int times[N];     //times[i]: 点i被访问的次数
int astar(int s, int t, int k){
    memset(times, 0, sizeof(times));
    priority_queue<point> q;
    q.push(point(s, 0, 0));
    while (!q.empty()) {
        point p = q.top();   //从优先队列中弹出f = g + h最小的
        q.pop();
        times[p.v]++;
        if (times[p.v] == k && p.v == t)  //从队列中第k次弹出t，就是答案
            return p.g + p.h;
        for (int i = 0; i< G[p.v].size(); i++) {
            edge y = G[p.v][i];
            q.push(point(y.to, p.g + y.w, dist[y.to]));
        }
    }
    return -1;
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while (m--) {
        int a, b, w;             //读边：起点、终点、边长
        scanf("%d%d%d", &a, &b, &w);  //本题是有向图
         G[a].push_back(edge(b,w));  //原图
        G2[b].push_back(edge(a,w));  //反图
    }
    int s, t, k;
    scanf("%d%d%d", &s, &t, &k);
    if (s == t)  k++;         //一个小陷阱
    dijkstra(t);              //在反图G2上，求终点t到其他点的最短路
    printf("%d\n", astar(s, t, k));  //在原图G上，求第k短路
    return 0;
}

