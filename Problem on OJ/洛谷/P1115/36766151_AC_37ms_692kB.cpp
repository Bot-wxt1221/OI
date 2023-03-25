#include <iostream>
#include <cstdio>
#include <cstring>
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
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n,ans,_min=0,total=0;
	ans=1000*200000+5;
	ans=-ans;
	n=read();
	for(int i=1;i<=n;i++){
		int temp=read();
		total+=temp;
		ans=max(ans,total-_min);
		_min=min(_min,total);
	}
	printf("%d",ans);
	return 0;
}

