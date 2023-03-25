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
int a[500005];
int ra[500005];
int main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	int n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        ra[n-i+1]=a[i];
    }
    int ans1=0,ans2=0;
    for(int i=1;i<=n;i++){
        int b=read();
        if(b!=a[i]){
            ans1++;
        }
        if(b!=ra[i]){
            ans2++;
        }
    }
    printf("%d",min(ans1,ans2+1));
	return 0;
}
