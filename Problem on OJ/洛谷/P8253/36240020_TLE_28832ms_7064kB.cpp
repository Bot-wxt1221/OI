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
long long a[40][200005];
int main(){
//	freopen("sort.in","r",stdin);
//	freopen("sort.out","w",stdout);
	int m,n;
	m=read();
	n=read();
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=read();
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			long long _max=0,_min=-1U;
			for(int M=1;M<=m;M++){
				_max=max(_max,a[M][i]+a[M][j]);
				_min=min(_min,a[M][i]+a[M][j]);
			}
			ans+=_max;
			ans+=_min;
		}
	}
	cout<<ans;
	return 0;
}
