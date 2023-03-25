#include <iostream>
#include <cstdio>
#define int long long
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
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int m,s,t,mnow;
	m=read();
	s=read();
	t=read();
	mnow=m;
	int s1=0,s2=0;
	for(int i=1;i<=t;i++){
		s1+=17;
		if(mnow>=10){
			mnow-=10;
			s2+=60;
		}else{
			mnow+=4;
		}
		if(s2>s1){
			s1=s2;
		}
		if(s1>s){
			printf("Yes\n%d",i);
			return 0;
		}
	}
	printf("No\n%d",s1);
	return 0;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/


