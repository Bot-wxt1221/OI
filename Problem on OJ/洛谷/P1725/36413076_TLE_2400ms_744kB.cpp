#include <iostream>
#include <cstdio>
#include <deque>
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
deque<int>a;
int dp[200005];
int aa[200005];
bool use[200005];
signed main(){
		freopen("1.in","r",stdin);
	//	freopen(".out","w",stdout);
	int n=read(),l=read(),r=read();
	int _max=-0x3f3f3f3f;
	for(int i=0;i<=n;i++){
		aa[i]=read();
	}
	for(int i=l;i<=r;i++)
		use[i]=1;
	for(int i=l;i<=n;i++){	
		while(a.size()>0&&dp[a.back()]<=dp[i-l])	a.pop_back();
		a.push_back(i-l);
		while(a.size()>0&&a.front()+r<i){
			a.pop_front();
		}
		if(use[i]) use[i+l]=1;
		dp[i]=aa[i]+dp[a.front()];
		if(i+r>n&&use[i])	_max=max(_max,dp[i]);
	}
	cout<<_max;
	return 0;
}