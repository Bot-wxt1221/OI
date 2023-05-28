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
int stack[5005];
int top=1;
int qu[5005];
int main(){
	freopen("dispatch.in","r",stdin);
	freopen("dispatch.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		qu[i]=read();
	}
	int to=1;
	for(int i=1;i<=n;i++){
		stack[top++]=i;
		if(qu[to]==i){
			to++;
			top--;
		}
	}
	while(top>1){
		if(stack[top-1]==qu[to]){
			to++;
			top--;
		}else{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}

