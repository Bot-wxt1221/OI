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
int Stack[250005];
int top=0;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read();
	int ans=0;
	for(int i=1;i<=n;i++){
		int a=read();
		a=read();
		while(top>0&&Stack[top-1]>=a){
			if(Stack[top-1]==a){
				ans++;
			}
			top--;
		}
		Stack[top++]=a;
	}
	cout<<n-ans;
	return 0;
}
