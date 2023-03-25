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
int b[1000005];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n,k;
	n=read();
	k=read();
	for(int i=1;i<=k-1;i++){
		b[i]=read();
		while(a.size()>0&&b[a.back()]>=b[i]){
			a.pop_back();
		}
		a.push_back(i);
	}
	for(int i=k;i<=n;i++){
		b[i]=read();
		while(a.size()>0&&b[a.back()]>=b[i]){
			a.pop_back();
		}
		a.push_back(i);
		printf("%d ",b[a.front()]);
		if(a.front()==1)
			a.pop_front();
	}
	return 0;
}
/*
Anything about this program:
Type:
	例题 
Description:
	给定一个长度为n的队列和一个整数 k,求数列bi=min{ai,ai+1,...,ai+k-1}(i=0,1,...,n-k) 
Example:
	1:
		In:
			5 3
			1 3 5 4 2
		Out:
			1 3 2
More:
	单调队列基础题
	From vjudge on  
*/

