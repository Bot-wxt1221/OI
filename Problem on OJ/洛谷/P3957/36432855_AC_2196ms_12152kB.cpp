#include <iostream>
#include <cstdio>
#include <deque>
#include <cstring>
#define int long long
using namespace std;
int read(){
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
class node{
	public:
		int x,s;
}a[500005];
int dp[500005];
deque<int>b;
int n,d,k;
bool check(int g);
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();d=read();k=read();
	int total=0;
	for(int i=1;i<=n;i++){
		a[i].x=read();
		a[i].s=read();
	}
	int l=0,r=10000000000,mid=(l+r)/2,ans;
	while(l<=r){
		if(check(mid)){
			r=mid-1;
		}else{
			l=mid+1;
		}
		mid=(l+r)/2;
	}
	if(r==10000000000){
		cout<<-1;
		return 0;
	}
	cout<<r+1;
	return 0;
}
bool check(int g){
	int lpos=max(1LL,d-g);
	int rpos=d+g;
	b=deque<int>();
//	b.push_back(1);
	memset(dp,0,sizeof(dp));
	int j=0;
	for(int i=1;i<=n;i++){
		for(;j<i&&a[i].x-a[j].x>=lpos;j++){
				while(b.size()>0&&dp[b.back()]<dp[j])	b.pop_back();
				b.push_back(j);
		}
		while(b.size()>0&&(a[i].x-a[b.front()].x)>rpos)	b.pop_front();
		if(b.size()>0)
			dp[i]=dp[b.front()]+a[i].s;
		else{
			dp[i]=-0x3f3f3f3f3f3f;
		}
		if(dp[i]>=k){
			return 1;
		}
	}
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
