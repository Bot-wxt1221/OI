#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
using namespace std;
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
int d;
int inf;
int x[500005];
int s[500005];
int n;
deque<int>b;
int dp[500005];
int check(int g){
	memset(dp,-0x3f,sizeof(dp));
	b=deque<int>();
	int nowin=0;
	int ans=0;
	dp[0]=0;
	for(int i=1;i<=n;i++){
		while(nowin<=n&&x[i]-x[nowin]>=max(1ll,d-g)){
			if(dp[i]==-inf){
				nowin++;
				continue;
			}
			while(b.size()>0&&dp[nowin]>=dp[b.front()]){
				b.pop_front();
			}
			b.push_front(nowin);
			nowin++;
		}
		while(b.size()>0&&x[i]-x[b.back()]>d+g){
			b.pop_back();
		}
		if(b.size()>0){
			dp[i]=max(dp[b.back()]+s[i],dp[i]);
		}else{
			dp[i]=-inf;
		}
		ans=max(ans,dp[i]);
	}
	return ans;
}
signed main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	memset(&inf,0x3f,sizeof(inf));
	int k;
	n=read();
	d=read();
	k=read();
	int ra=0;
	for(int i=1;i<=n;i++){
		x[i]=read();
		s[i]=read();
		ra=max(ra,x[i]);
	}
	long long l=0,r=ra+10;
	while(r-l>=10){
		long long mid=(l+r)/2;
		if(check(mid)>k){ 
			r=mid+1;
		}else{
			l=mid-1;
		}
	}
	for(long long i=l;i<=r;i++){
		if(check(i)>=k){
			printf("%lld",i);
			return 0;
		}
	}
	printf("-1");
	return 0;
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



