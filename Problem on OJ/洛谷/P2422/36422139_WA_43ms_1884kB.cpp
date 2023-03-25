#include <iostream>
#include <cstdio>
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
int a[100005];
int lMaxi[100005];
int rMaxi[100005];
int qian[100005];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		qian[i]=qian[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]<a[i-1]){
			lMaxi[i]=lMaxi[i-1];
		}else{
			lMaxi[i]=i;
		}
	}
	for(int i=n;i>=1;i--){
		if(a[i]<a[i+1]){
			rMaxi[i]=rMaxi[i+1];
		}else{
			rMaxi[i]=i;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,(qian[rMaxi[i]]-qian[lMaxi[i]-1])*a[i]);
	}
	cout<<ans;
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
