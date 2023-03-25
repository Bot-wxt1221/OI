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
int main(){
	//	freopen(".in","r",stdin);
	//	freopen(".out","w",stdout);
	int n=read(),l=read(),r=read();
	for(int i=0;i<=n;i++){
		if(a.size()>0)
			dp[i]=dp[a.front()]+read();
		else
			dp[i]=read();
		if(i-l>=0){
			while(a.size()>0&&dp[a.back()]<=dp[i-l])	a.pop_back();
			a.push_back(i-l);
			if(a.front()==(i-r)){
				a.pop_front();
			}
		}	
	}
	int _max=-1000*200000-5;
	for(int i=n-r;i<=n-l;i++){
		_max=max(_max,dp[i]);
	}
	cout<<_max;
	return 0;
}
