#include <iostream>
#include <cstdio>
#include <deque>
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
int a[200005];
int pos[2000005];
int qian[200005];
int main(){
	freopen("different.in","r",stdin);
	freopen("different.out","w",stdout);
	int n=read(),m;
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	pos[a[1]]=1;
	qian[1]=1;
	int i=2,l=1;
	while(i<=n&&l<=n){
		qian[i]=l;
		pos[a[i]]=i;
		i++;
		if(pos[a[i]]!=0){
			l=pos[a[i]]+1;
		}
	}
	for(int i=1;i<=m;i++){
		int a=read(),b=read();
		a++,b++;
		int _max=0;
		for(int j=a;j<=b;j++){
			if(qian[j]<=a){
				_max=max(_max,j-a+1);
			}else{
				_max=max(_max,qian[j]-a+1);
			}
		}
		printf("%d\n",_max);
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



