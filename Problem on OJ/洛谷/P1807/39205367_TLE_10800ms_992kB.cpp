#include <iostream>
#include <queue>
#include <cstdio>
// using namespace std;
inline int read();
int dp[100005];
int w[100005];
int fir[100005];
bool vised[100005];
int que[100006];
int l,r;
int in[100006];
int nxt[100005];
int v[100006];
int now;
void add(int x,int y,int z){
	now++;
	v[now]=y;
	w[now]=z;
	in[x]++;
	nxt[now]=fir[x];
	fir[x]=now;
	return ;
}
int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read();
	int m=read();
	for(int i=1;i<=n;i++){
		fir[i]=-1;
		dp[i]=-0x3f3f3f3f;
	}
	for(int i=1;i<=m;i++){
		int u=read();
		int v=read();
		int w=read();
		add(u,v,w);
	}
	que[++r]=1;
	dp[1]=0;
	while(l!=r){
		l++;
		if(l=100006){
			l=0;
		}
		int temp=que[l];
		vised[temp]=0;
		for(int i=fir[temp];i!=-1;i=nxt[i]){
			if(dp[v[i]]<dp[temp]+w[i]){
				dp[v[i]]=dp[temp]+w[i];
				if(vised[v[i]]==0){
					vised[v[i]]=1;
					r++;
					if(r==100006){
						r=0;
					}
					que[r]=v[i];
				}
			}
		}
	}
	if(dp[n]==-0x3f3f3f3f)
		printf("-1");
	else
		printf("%d",dp[n]);
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


