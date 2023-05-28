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
int a[3000005];
int ans[3000005];
int Stack[3000005];
int nStack[3000005];
int top=0;
int main(){
	freopen("nge.in","r",stdin);
	freopen("nge.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=n;i>=1;i--){
		while(top>0&&Stack[top-1]<=a[i]){
			top--;
		}
		if(top==0){
			nStack[top]=i;
			Stack[top++]=a[i];
			continue;
		}
		ans[i]=nStack[top-1];
		nStack[top]=i;
		Stack[top++]=a[i];
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
