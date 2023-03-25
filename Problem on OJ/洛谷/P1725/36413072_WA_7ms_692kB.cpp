#include <iostream>
#include <cstdio>
#include <deque>
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
int main(){
	//	freopen(".in","r",stdin);
	//	freopen(".out","w",stdout);
	int n=read(),l=read(),r=read();
	int _max=-0x3f3f3f3f;
	for(int i=0;i<=n;i++){
		aa[i]=read();
	}
	use[l]=0;
	for(int i=l;i<=n;i++){	
	if(use[i]){
		while(a.size()>0&&dp[a.back()]<=dp[i-l])	a.pop_back();
		a.push_back(i-l);
		while(a.size()>0&&a.front()+r<i){
			a.pop_front();
		}
		
			for(int j=i+l;j<=i+r;j++){
				use[j]=1;
			}
		}
	}
	for(int i=n-r+1;i<=n;i++){
		if(use[i])
			_max=max(_max,dp[i]);
	}
	cout<<_max;
	return 0;
}
