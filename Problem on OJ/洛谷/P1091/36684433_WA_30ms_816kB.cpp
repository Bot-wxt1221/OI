#include <iostream>
#include <cstdio>
#include <queue>
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
int a[105];
int l[105];
int r[105];
deque<int>b;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		while(b.size()>0&&a[b.back()]>=a[i])	b.pop_back();
		if(b.size()>0)
			l[i]=l[b.back()]+1;
		else
			l[i]=1;
		b.push_back(i);
	}
	b=deque<int>();
	for(int i=n;i>=1;i--){
		while(b.size()>0&&a[b.back()]>=a[i])	b.pop_back();
		if(b.size()>0)
			r[i]=r[b.back()]+1;
		else
			r[i]=1;
		b.push_back(i);
	}
	int _max=0;
	for(int i=1;i<=n;i++){
		_max=max(_max,r[i]+l[i]-1);
	}
	printf("%d",n-_max);
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

