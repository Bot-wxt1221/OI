#include <iostream>
#include <cstdio>
using namespace std;
inline int read(); 
int main(){
	int n=read();
	cout<<n;
	return 0;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:f;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);//x*8+x*2+(x-48)
		c=getchar();
	}
	return f*x;
}
