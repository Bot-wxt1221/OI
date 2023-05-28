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
char weekday[7][11]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	for(int i=0;i<7;i++){
		cout<<weekday[i]<<' ';
	}
	return 0;
}

