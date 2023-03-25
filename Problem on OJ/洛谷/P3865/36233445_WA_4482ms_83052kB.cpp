#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int dp[100005][210];
int a[100005];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		dp[i][0]=a[i];
	}
	for(int j=1;j<=log2(n);j++){
		for(int i=1;(int(1<<(j-1))+i)<n;i++){
			dp[i][j]=max(dp[i][j-1],dp[(1<<(j-1))+i][j-1]);
		}
	}
	for(int i=1;i<=m;i++){
		int a,b;
		a=read();b=read();
		cout<<max(dp[a][int(log2(b-a+1))],dp[b-(1<<int(log2(b-a+1)))+1][int(log2(b-a+1))])<<endl;
	}
	return 0;
}