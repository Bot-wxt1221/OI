// poj 2449����
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1005, M = 100005;
struct edge{          //��¼��
int to, w;
//vector edge[i]:�����i;���кܶ��,����һ���ߵ�to�Ǳߵ��յ�,w�Ǳ߳�
    edge(int a,int b){ to = a, w = b;} //��ֵ
};
vector <edge>G[M], G2[M];  //G:ԭͼ; G2:��ͼ
struct node {      //����dijkstra����¼�㣬�Լ��㵽����·��
    int id, dis;   //id:�㣻dis����id������·������
    node(int a, int b){ id = a, dis = b;} //��ֵ
    bool operator < (const node &u) const { return dis > u.dis; }
};
int  dist[N];   //dist[i]: ��s����i�����·����
bool done[N];   //done[i]=ture: ��ʾ��i�����·�Ѿ��ҵ�
void dijkstra(int s) {    //��׼��dijkstra: ��s���������е�����·
    for(int i =0;i<N;i++) {dist[i]=INF; done[i]=false;}  //��ʼ��
    dist[s] = 0;          //���s���Լ��ľ�����0
    priority_queue<node> q;
    q.push(node(s, dist[s]));    //����㿪ʼ�������
    while (!q.empty()) {
        node u = q.top();        //pop�������s����ĵ�u
        q.pop();
        if (done[u.id])  continue; //�����Ѿ��ҵ����·�ĵ�            
        done[u.id] = true;       //��ǣ���u��s�����·�Ѿ��ҵ�
        for (int i = 0; i< G2[u.id].size(); i++) {  //����u�������ھ�
            edge y = G2[u.id][i];
            if (done[y.to])   continue; //�����Ѿ��ҵ����·���ھ�                
            if (dist[y.to] > u.dis + y.w) {
                dist[y.to] = u.dis + y.w;
                q.push(node(y.to, dist[y.to]));  //��չ�µ��ھӣ��Ž����ȶ���
            }
        }
    }
}
struct point {      //���� astar
    int v, g, h;    //�������� f = g + h, g�Ǵ�s��i�ĳ��ȣ�h�Ǵ�i��t�ĳ���
    point(int a, int b, int c) { v=a, g=b, h=c; }
    bool operator < (const point & b) const { return g + h > b.g + b.h;}
};
int times[N];     //times[i]: ��i�����ʵĴ���
int astar(int s, int t, int k){
    memset(times, 0, sizeof(times));
    priority_queue<point> q;
    q.push(point(s, 0, 0));
    while (!q.empty()) {
        point p = q.top();   //�����ȶ����е���f = g + h��С��
        q.pop();
        times[p.v]++;
        if (times[p.v] == k && p.v == t)  //�Ӷ����е�k�ε���t�����Ǵ�
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
        int a, b, w;             //���ߣ���㡢�յ㡢�߳�
        scanf("%d%d%d", &a, &b, &w);  //����������ͼ
         G[a].push_back(edge(b,w));  //ԭͼ
        G2[b].push_back(edge(a,w));  //��ͼ
    }
    int s, t, k;
    scanf("%d%d%d", &s, &t, &k);
    if (s == t)  k++;         //һ��С����
    dijkstra(t);              //�ڷ�ͼG2�ϣ����յ�t������������·
    printf("%d\n", astar(s, t, k));  //��ԭͼG�ϣ����k��·
    return 0;
}

