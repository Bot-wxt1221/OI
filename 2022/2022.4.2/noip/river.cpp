#include <iostream>
#include <algorithm>
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
int a[1005];
int main(){
	freopen("river.in","r",stdin);
	freopen("river.out","w",stdout);
	int T;
	T=read();
	for(int t=1;t<=T;t++){
		int n,_min=105,ans=0,_max=0;
		n=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		sort(a+1,a+n+1);
		while(n>3){
			ans+=min(a[1]*2+a[n]+a[n-1],a[2]*2+a[1]+a[n]);
			n-=2;
		}
		if(n==1){
			ans+=a[1];
		}else if(n==2){
			ans+=a[2];
		}else if(n==3){
			ans+=a[1]+a[2]+a[3];
		}
		cout<<ans<<endl;
	}
	return 0;
}

