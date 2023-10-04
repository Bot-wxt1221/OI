#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
inline int read();
class node{
	public:
		int mo,i;
		node(int b,int a){
			mo=a;
			i=b;
		}
};
std::queue<node>a;
bool ans=0;
int tt;
int fir[55];
int nxt[205];
int v[205];
int w[205];
int _min[55];
int now;
int n;
int dp[55][20005];
bool vised[55][20005];
int minw=0;
void add(int x,int y,int z){
	now++;
	v[now]=y;
	w[now]=z;
	nxt[now]=fir[x];
	fir[x]=now;
	if(x==1){
		minw=std::min(minw,2*z);
	}
	return ;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	#endif
    int T=read();
	while(T--){
		minw=0x3f3f3f3f3f3f3f3fll;
		n=read();
		int m=read();
		tt=read();
		now=0;
		for(int i=1;i<=n;i++){
			fir[i]=-1;
			_min[i]=0x3f3f3f3f3f3f3f3fll;
		}
		for(int i=1;i<=m;i++){
			int x=read()+1,y,z;
			y=read()+1;
			z=read();
			add(x,y,z);
			add(y,x,z);
		}
		if(minw==0x3f3f3f3f3f3f3f3fll){
			printf("Impossible\n");
			return 0;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=minw;j++){
				dp[i][j]=0x3f3f3f3f3f3f3f3fll;
			}
		}
		dp[1][0]=0;
		a.push(node(1,0));
		while(a.size()>0){
			node fr=a.front();
			a.pop();
			vised[fr.i][fr.mo]=0;
			for(int i=fir[fr.i];i!=-1;i=nxt[i]){
				int ndis=(w[i]+fr.mo)%minw;
				if(dp[v[i]][ndis]>dp[fr.i][fr.mo]+w[i]){
					dp[v[i]][ndis]=dp[fr.i][fr.mo]+w[i];
					if(!vised[v[i]][ndis]){
						vised[v[i]][ndis]=1;
						a.push(node(v[i],ndis));
					}
				}
			}
		}
		if(dp[n][tt%minw]<=tt){
			printf("Possible\n");
		}else{
			printf("Impossible\n");
		}
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


