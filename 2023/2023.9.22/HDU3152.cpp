#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
int map[16005];
int fir[16005];
int nxt[64005];
int v[64005];
bool get[64005];
int now;
class node{
	public:
		int num,data;
		node(int xx,int yy){
			num=xx;
			data=yy;
			return ;
		}
};
bool operator < (node a,node b){
	return a.data>b.data;
}
int dp[16005];
std::priority_queue<node>de;
int getpos(int x,int y){
	return (x-1)*125+y;
}
void add(int x,int y){
	v[++now]=y;
	nxt[now]=fir[x];
	fir[x]=now;
	return ;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n,TT=0;
	while(scanf("%d",&n)!=EOF&&n!=0){
		now=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				map[getpos(i,j)]=read();
				fir[getpos(i,j)]=-1;
				dp[getpos(i,j)]=0x3f3f3f3f;
				get[getpos(i,j)]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=1){
					add(getpos(i,j),getpos(i-1,j));
				}
				if(j!=1){
					add(getpos(i,j),getpos(i,j-1));
				}
				if(i!=n){
					add(getpos(i,j),getpos(i+1,j));
				}
				if(j!=n){
					add(getpos(i,j),getpos(i,j+1));
				}
			}
		}
		dp[getpos(1,1)]=map[getpos(1,1)];
		de.push(node(getpos(1,1),dp[getpos(1,1)]));
		while(de.size()>0){
			node te=de.top();
			de.pop();
			while(get[te.num]&&de.size()>0){
				te=de.top();
				de.pop();
			}
			if(get[te.num]){
				break;
			}
			get[te.num]=1;
			for(int i=fir[te.num];i!=-1;i=nxt[i]){
				if(dp[v[i]]>dp[te.num]+map[v[i]]){
					dp[v[i]]=dp[te.num]+map[v[i]];
					de.push(node(v[i],dp[v[i]]));
				}
			}
		}
		printf("Problem %d: %d\n",++TT,dp[getpos(n,n)]);
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


