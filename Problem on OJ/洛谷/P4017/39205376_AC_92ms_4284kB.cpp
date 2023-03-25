#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
inline int read();
int fir[5005];
int in[5005];
int out[5005];
int v[500005];
int nxt[500005];
int dp[5005];
int now;
queue<int>a;
void add(int x,int y){
    now++;
    v[now]=y;
	in[y]++;
	out[x]++;
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
    int n=read(),m;
    m=read();
    for(int i=1;i<=n;i++){
		dp[i]=0;
        fir[i]=-1;
    }
    for(int i=1;i<=m;i++){
		int a=read(),b;
		b=read();
		add(a,b);
    }
	for(int i=1;i<=n;i++){
		if(in[i]==0){
			dp[i]=1;
			a.push(i);
		}
	}
	int _max=0;
	while(a.size()>0){
		int temp=a.front();
		a.pop();
		for(int i=fir[temp];i!=-1;i=nxt[i]){
			in[v[i]]--;
			dp[v[i]]+=dp[temp];
			dp[v[i]]%=80112002;
			if(in[v[i]]==0){
				a.push(v[i]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(out[i]==0){
			_max+=(dp[i]);
			_max%=80112002;
		}
	}
	printf("%d",_max);
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


