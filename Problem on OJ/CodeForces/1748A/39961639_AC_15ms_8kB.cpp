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
int main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	int T=read();
    for(int i=1;i<=T;i++){
        printf("%d\n",(read()+1)/2);
    }
	return 0;
}
