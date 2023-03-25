#include <iostream>
#include <cstdio>
#include <deque>
#include <cstring>
#include <windows.h>
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
	int l=0,r=10000000000,mid=(l+r+1)/2,ans;
	while(l<r){
		cout<<l<<' '<<r<<endl;
		Sleep(50);
		if(check(mid)){
			r=mid;
		}else{
			l=mid+1;
		}
		mid=(l+1+r)/2;
	}
	if(r==10000000000){
		cout<<-1;
		return 0;
	}
	cout<<r;
	return 0;
}
bool check(int g){
	b=deque<int>();
	b.push_back(1);
	memset(dp,0,sizeof(dp));
	dp[1]=a[1].s;
	int j=1;
	for(int i=max(d-g,1LL)+1;i<=n;i++){
		while(b.size()>0&&(a[i].x-a[b.front()].x)>(d+g))	b.pop_front();
		for(;j<=i;j++){
			if(i-d-g<=j&&j<=i-max(1LL,d-g)){
				while(b.size()>0&&dp[b.back()]<dp[j])	b.pop_back();
				b.push_back(j);
			}else{
				break;
			}
		}
		if(b.size()>0) 
			dp[i]=dp[b.front()]+a[i].s;
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
