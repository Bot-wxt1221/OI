#include <iostream>
#include <cstdio>
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
int b[100005];
int c[100005];
int a[100005];
bool jisuan[100005];
int main(){
	freopen("butterfly.in","r",stdin);
	freopen("butterfly.out","w",stdout);
	int n=read();
	int k=read();
	for(int i=1;i<=n;i++){
		b[i]=read();
	}
	for(int i=1;i<=n;i++){
		c[i]=read();
		if((b[i]+c[i])%k==0){
			jisuan[i]=1;
		}
		a[i]=min(b[i],c[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int _min=a[i];
		int have=0;
		for(int j=i;j<=n;j++){
			_min=min(_min,a[j]);
			have+=jisuan[j];
			ans=max(ans,have*_min);
		}
	}
	printf("%d",ans);
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


