 #include <iostream>
#include <cstdio>
using namespace std;
int a[1005][2];//a[i][0] 表示n位偶数 a[i][1] 表示n位奇数 
int read(){
	int x=0,f=1;char c=getchar();
	while('0'>c||'9'<c)	c=='-'?f=-1:1,c=getchar();
	while('0'<=c&&c<='9')	x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
int main(){
	freopen("problem.in","r",stdin);
	freopen("problem.out","w",stdout);
	int n=read();
	a[1][0]=9,a[1][1]=1;
	for(int i=2;i<=n-1;i++){
		a[i][0]=a[i-1][0]*9+a[i-1][1];
		a[i][0]=a[i][0]%12345;
		a[i][1]=a[i-1][1]*9+a[i-1][0];
		a[i][1]=a[i][1]%12345;
	}
	cout<<(a[n-1][0]*8+a[n-1][1])%12345;
	return 0;
}

