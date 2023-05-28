#include <iostream>
#include <cstdio>
#include <algorithm>
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
int a[10005];
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m,ans=0;
	n=read();
	m=read();
	int more=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	sort(a+1,a+n+1);
	
	cout<<ans;
	return 0;
}

