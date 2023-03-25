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
		while(top!=0&&stack[top-1]<=aa[i]){
			if(aa[i]==stack[top-1]){
				x++;
			}
			ans++;
			top--;
		}
		if(top!=0){
			ans++;
		}
		for(int ia=1;ia<=x;ia++){
			stack[top++]=aa[i];
		}
	}
	cout<<ans;
	return 0;
}
