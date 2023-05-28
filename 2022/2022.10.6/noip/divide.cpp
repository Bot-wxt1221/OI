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
int s[1000005];
signed main(){
	freopen("divide.in","r",stdin);
	freopen("divide.out","w",stdout);
int t=read();
while(t--){
	int n=read(),k,p;
	k=read();
	p=read();
	int _min=10000000000ll;
	for(int i=1;i<=k;i++){
		s[i]=read();
		_min=min(_min,s[i]);
	}
	if(s[p]==_min){
		printf("%d\n",n/s[p]);
		continue;
	}else{
		int temp=n/_min;
		int temp2=0;
		bool next=1;
		while(next){
			next=0;
			int ntemp2=temp2+1;
			if(n<ntemp2*s[p]){
				break;
			}
			int ntemp=(n-ntemp2*s[p])/_min;
			if(temp2+temp<=ntemp+ntemp2){
				temp=ntemp;
				temp2=ntemp2;
				next=1;
			}
		}
		printf("%d\n",temp2);
	}
}
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



