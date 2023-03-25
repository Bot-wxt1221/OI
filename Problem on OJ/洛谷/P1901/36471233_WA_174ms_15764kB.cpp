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
int lMax[100005];
int rMax[100005];
int St[1000005];
int top=0;
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
		while(top>0&&h[St[top-1]]<h[i])	top--;
		if(top==0)	lMax[i]=0;
		else lMax[i]=St[top-1];
		St[top++]=i;
	}
	top=0;
	for(int i=n;i>=1;i--){
		while(top>0&&h[St[top-1]]<h[i])	top--;
		if(top==0)	rMax[i]=0;
		else rMax[i]=St[top-1];
		St[top++]=i;
	}
	for(int i=1;i<=n;i++){
		if(h[lMax[i]]>h[i]){
			ans[lMax[i]]+=v[i];
		}
		if(h[rMax[i]]>h[i]){
			ans[rMax[i]]+=v[i];
		}
	}
	int ans2=0;
	for(int i=1;i<=n;i++){
//		cout<<lMax[i]<<' '<<rMax[i]<<endl;
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
