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
int a[1000005];
int qian[1000005];
int tree[1000005];
int lowbit(int m){
	return (m)&(-m);
}
void bu(int r,int l){
	for(int i=r;i<=l;i++){
		tree[i]=qian[i]-qian[i-lowbit(i)];
	}
	return ;
}
int qia(int a){
	int ans=0;
	while(a>0){
		ans+=tree[a];
		a-=lowbit(a);
	}
	return ans;
} 
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read(),m;
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		qian[i]=qian[i-1]+a[i];
	}
	bu(1,n);
	for(int i=1;i<=m;i++){
		int a=read();
		if(a==2){//find
			int x=read(),y;
			y=read();
			printf("%d\n",qia(y)-qia(x-1));
		}else if(a==1){//and 
			int a=read();
			int b=read();
			while(a<=n){
				tree[a]+=b;
				a+=lowbit(a);
			}
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


