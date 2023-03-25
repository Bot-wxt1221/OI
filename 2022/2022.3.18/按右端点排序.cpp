#include <iostream>
#include <cstdio>
#define MAXN 1000
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
		int begin,end;
}a[MAXN];
bool cmp(node a,node b){
	return a.end<b.end;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	n=read();
	for(int i=1;i<=n;i++){
		a[i].begin=read();
		a[i].end=read();
	}
	sort(a+1,a+n+1,cmp);
	
	return 0;
}

