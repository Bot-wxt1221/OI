#include<iostream>
#include<cstring>
using namespace std;
struct node{
	int a,b,w;
}e[210];
int dis[110];
int n,m,cnt=0;

void add(int a,int b,int w){
	e[cnt].a=a;
	e[cnt].b=b;
	e[cnt++].w=w;
}

bool bellman_ford(int u){//求源点u到其它顶点的最短路径长度，判负环 
	memset(dis,0x3f,sizeof(dis));
	dis[u]=0;
	for(int i=1;i<n;i++){//执行n-1次
		bool flag=false;
		for(int j=0;j<m;j++)//边数m或cnt
			if(dis[e[j].b]>dis[e[j].a]+e[j].w){
				dis[e[j].b]=dis[e[j].a]+e[j].w;
				flag=true;
			}
		if(!flag)
			return false;
	}
	for(int j=0;j<m;j++)//再执行1次，还能松弛说明有环
		if(dis[e[j].b]>dis[e[j].a]+e[j].w)
			return true;
	return false;
}

void print(){//输出源点到其它节点的最短距离 
	cout<<"最短距离："<<endl; 
	for(int i=1;i<=n;i++)
		cout<<dis[i]<<" ";
	cout<<endl;
}

int main(){
	int a,b,w;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b>>w;
		add(a,b,w);
	}
	if(bellman_ford(1))//判断负环
		cout<<"有负环！"<<endl;
	else
		print();	
	return 0;
}
/*测试数据1 
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
/*测试数据2，有负环 
4 4
1 2 3
2 3 -4
3 4 2
4 2 1
*/
