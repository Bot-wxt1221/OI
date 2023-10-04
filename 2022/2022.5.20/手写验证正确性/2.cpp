#include <iostream>
#include <cstdio>
#include <queue>
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
priority_queue<int>a;
int main(){
	freopen("sort.in","r",stdin);
	freopen("2.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		a.push(-read());
	}
	for(int i=1;i<=n;i++){
		cout<<-a.top()<<' ';
		a.pop();
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

