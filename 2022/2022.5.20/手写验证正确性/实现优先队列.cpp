#include <iostream>
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
int a[10005];
int n;
inline void down(int b){
	while(a[b]<a[b/2]){
		swap(a[b],a[b/2]);
		b=b/2;
	}
	return ;
}
inline void del(){
	int b=1;
	swap(a[b],a[n]);
	a[n]=0;
	n--;
	while((a[b]>a[b*2]||a[b]>a[b*2+1])&&b*2<=n){
		if(a[b]>a[b*2+1]&&a[b*2+1]<a[b*2]&&b*2+1<=n){
			swap(a[b],a[b*2+1]);
			b=b*2+1;
		}else if(a[b]>a[b*2]){
			swap(a[b],a[b*2]);
			b=b*2;
		}
		if(b*2+1>n){
			break;
		}
	}
	return ;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	int m=n;
	for(int i=1;i<=m;i++){
		a[i]=read();
		down(i);
	}
	for(int i=1;i<=m;i++){
		cout<<a[1]<<' ';
		del();
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

