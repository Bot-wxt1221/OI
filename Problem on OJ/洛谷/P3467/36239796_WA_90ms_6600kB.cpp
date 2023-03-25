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
bool a[1000000005];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read();
	int ans=0;
	for(int i=1;i<=n;i++){
		int aa=read();
		aa=read();
		if(!a[aa]){
			a[aa]=1;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
