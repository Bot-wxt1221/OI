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
short stack[100];
int top=0;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int a=read();
	while(a>0){
		stack[top++]=a%8;
		a/=8;
	}
	while(top>0){
		cout<<stack[--top];
	}
	return 0;
}

