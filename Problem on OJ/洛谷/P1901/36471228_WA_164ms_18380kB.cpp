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
int h[1000005];
int v[1000005];
int ans[1000005];
int lMax[1000005];
int rMax[1000005];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	n=read();
	for(int i=1;i<=n;i++){
		h[i]=read();
		v[i]=read();
	}
	for(int i=1;i<=n;i++){
		if(h[i-1]>=h[i]){
			lMax[i]=i-1;
		}else{
			lMax[i]=lMax[i-1];
		}
	}
	for(int i=n;i>=1;i--){
		if(h[i+1]>=h[i]){
			rMax[i]=i+1;
		}else{
			rMax[i]=rMax[i+1];
		}
	}
	for(int i=1;i<=n;i++){
		if(h[lMax[i]]>=h[i]){
			ans[lMax[i]]+=v[i];
		}
		if(h[rMax[i]]>=h[i]){
			ans[rMax[i]]+=v[i];
		}
	}
	int ans2=0;
	for(int i=1;i<=n;i++){
		ans2=max(ans2,ans[i]);
	}
	cout<<ans2;
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
