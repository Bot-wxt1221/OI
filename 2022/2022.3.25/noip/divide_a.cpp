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
int main(){
	freopen("divide_a.in","r",stdin);
	freopen("divide_a.out","w",stdout);
	int n,m,more=m,ans=1;
	n=read();
	m=read();
	more=m;
	for(int i=1;i<=n;i++){
		int temp=read();
		if(more>=temp){
			more-=temp;
		}else{
			more=m-temp;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

