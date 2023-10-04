#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
int fir[105];
int nxt[10005];
int dis[10005];
int v[10005];
bool vised[10005];
int now;
std::queue<int>a;
void add(int a,int b){
    now++;
    v[now]=b;
    nxt[now]=fir[a];
    fir[a]=now;
	return ;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("bfs.in","r",stdin);
	freopen("bfs.out","w",stdout);
	#endif
    int n=read();
	for(int i=1;i<=n;i++){
		fir[i]=-1;
	}
    for(int i=1;i<=n;i++){
		dis[i]=0x3f3f3f3f;
        int id=read();
        int k=read();
        for(int i=1;i<=k;i++){
			add(id,read());
        }
    }
	a.push(1);
	vised[1]=1;
	dis[1]=0;
	while(a.size()>0){
		int temp=a.front();
		a.pop();
		for(int i=fir[temp];i!=-1;i=nxt[i]){
			if(vised[v[i]]){
				continue;
			}
			vised[v[i]]=1;
			dis[v[i]]=dis[temp]+1;
			a.push(v[i]);
		}
	}
	for(int i=1;i<=n;i++){
		if(dis[i]==0x3f3f3f3f){
			dis[i]=-1;
		}
		printf("%d %d\n",i,dis[i]);
	}
	return 0;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/


