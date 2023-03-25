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
int stack[500005];
int top=0;
int aa[500005];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read(),ans=0;
	for(int i=1;i<=n;i++){
		aa[i]=read();
	}
	for(int i=1;i<=n;i++){
		int x=1;
		int r=top;
		while(r!=1&&stack[r-1]<=aa[i]){
			ans++;
			r--;
		}
		ans+=(top-r);
		while(top>0&&stack[top-1]<aa[i]){
			top--;
		}
		stack[top++]=aa[i];
	}
	cout<<ans;
	return 0;
}
