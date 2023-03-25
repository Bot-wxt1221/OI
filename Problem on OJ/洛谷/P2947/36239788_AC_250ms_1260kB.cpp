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
int a[100005];
int top=0;
int Stack[100005];
int nStack[100005];
int ans[100005];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=n;i>=1;i--){
		while(top>0&&Stack[top-1]<=a[i]){
			top--;
		}
//		cout<<nStack[top-1]<<endl;
		ans[i]=nStack[top-1];
		nStack[top]=i;
		Stack[top++]=a[i];
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
