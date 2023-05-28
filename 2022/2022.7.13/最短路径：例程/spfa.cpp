#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=505,maxe=100001;
int n,m,cnt;
int head[maxn],dis[maxn],sum[maxn];
bool vis[maxn];//����Ƿ��ڶ����� 
struct node{
	int to,next,w;
}e[maxe];

void add(int u,int v,int w){
	e[cnt].to=v;
	e[cnt].next=head[u];
	e[cnt].w=w;	
	head[u]=cnt++;
}

bool spfa(int u){
	queue<int>q;
	memset(vis,0,sizeof(vis));//����Ƿ��ڶ�����
	memset(sum,0,sizeof(sum));//ͳ����ӵĴ���
	memset(dis,0x3f,sizeof(dis));
	vis[u]=1;
	dis[u]=0;
	sum[u]++;
	q.push(u);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(int i=head[x];~i;i=e[i].next){
			int v=e[i].to;
			if(dis[v]>dis[x]+e[i].w){
				dis[v]=dis[x]+e[i].w;
				if(!vis[v]){
					if(++sum[v]>=n)
						return true;
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return false;
}

void print(){//���Դ�㵽�����ڵ����̾��� 
	cout<<"��̾��룺"<<endl; 
	for(int i=1;i<=n;i++)
		cout<<dis[i]<<" ";
	cout<<endl;
}

int main(){
	cnt=0;
	cin>>n>>m;
	memset(head,-1,sizeof(head));
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
	}
	if(spfa(1))
		cout<<"�и�����"<<endl;
	else
		print();
	return 0;
}
/*��������1 
5 8
1 2 2
1 3 5
2 3 2
2 4 6
3 4 7
3 5 1
4 3 2
4 5 4
*/
/*��������2���и��� 
4 4
1 2 3
2 3 -4
3 4 2
4 2 1
*/
