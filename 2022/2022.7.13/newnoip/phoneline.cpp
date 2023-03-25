#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#define int long long
using namespace std;
int read(){
	int f=0,x=1;
	char a=getchar();
	while('0'>a||a>'9'){
		(a=='-')?(x=-1):1;
		a=getchar();
	}
	while('0'<=a&&a<='9'){
		f=(f<<3)+(f<<1)+(a^48);
		a=getchar();
	}
	return f*x;
}
int now=0;
int first[1005];
int nxt[2000005];
int v[2000005];
int w[2000005];
bool vised[1005];
int dis[1005][1005];
void add(int a,int b,int c){
	++now;
	v[now]=b;
	w[now]=c;
	nxt[now]=first[a];
	first[a]=now;
	return ;
}
queue<int>spfa;
signed main(){
	freopen("phoneline.in","r",stdin);
	freopen("phoneline.out","w",stdout);
	int n=read(),p,k;
	p=read();
	k=read();
	for(int i=1;i<=n;i++){
		first[i]=-1;
	}
	for(int i=1;i<=p;i++){
		int a=read();
		int b=read();
		int c=read();
		add(a,b,c);
		add(b,a,c);
	}
	spfa.push(1);
	memset(dis,0x3f,sizeof(dis));
	int inf=dis[0][0];
	dis[1][0]=0;
	while(spfa.size()>0){
		int temp=spfa.front();
//		while(vised[temp]&&spfa.size()>0){
//			spfa.pop();
//			temp=spfa.front();
//			cout<<temp<<endl;
//		}
//		if(spfa.size()==0){
//			break;
//		}
		
		spfa.pop();
		vised[temp]=0;
		for(int i=first[temp];i!=-1;i=nxt[i]){
//			if(vised[v[i]]){
//				continue;
//			}
			bool change=0;
			if(max(dis[temp][0],w[i])<dis[v[i]][0]){
				dis[v[i]][0]=max(dis[temp][0],w[i]);
				change=1;
			}
			for(int j=1;j<=k;j++){
				if(max(dis[temp][j],w[i])<dis[v[i]][j]){
					dis[v[i]][j]=max(dis[temp][j],w[i]);
					change=1;
				}
				if(dis[temp][j-1]<dis[v[i]][j]){
					dis[v[i]][j]=dis[temp][j-1];
					change=1;
				}
			}
			if(change&&!vised[v[i]]){
				spfa.push(v[i]);
				vised[v[i]]=1;
			}
		}
	}
	if(dis[n][k]>=inf){
		printf("-1");
	}else{
		printf("%d",dis[n][k]);
	}
	return 0;
}

