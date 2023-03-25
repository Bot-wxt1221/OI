#include <iostream>
#include <cstdio>
#define int long long
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
int h[100005];
int w[100005];
int stack[100005];
int top=0;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	while(n!=0){
		n=read();
		if(n==0){
			return 0;
		}
		int ans=0,a;
		top++;
		for(int i=1;i<=n+1;i++){
			if(i<=n)
				h[i]=read();
			if(stack[top]<h[i]){
				stack[++top]=h[i];
				w[top]=1;
				continue;
			}
			a=0;
			while(stack[top]>h[i]&&top>0){
				a+=w[top];
				ans=max(ans,stack[top]*a);
				top--;
			}
			stack[++top]=h[i];
			w[top]=a+1;
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
input:
7
2 1 4 5 1 3 3
output:
8
*/