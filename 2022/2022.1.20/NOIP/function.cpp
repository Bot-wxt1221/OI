#include <iostream>
#include <cstdio>
using namespace std;
long long wdp[31][31][31];
int read(){
	int x=0,f=1;char c=getchar();
	while('0'>c||'9'<c)	c=='-'?f=-1:1,c=getchar();
	while('0'<=c&&c<='9')	x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
long long w(int a,int b,int c);
int main(){
//	freopen("function.in","r",stdin);
//	freopen("function.out","w",stdout);
	while(1){
		int a=read(),b=read(),c=read();
		if(a==-1&&b==-1&&c==-1){
			break;
		}
		printf("w(%d,%d,%d)=%d",a,b,c,w(min(a,20),min(b,20),min(c,20)));
	}
	return 0;
}
long long w(int a,int b,int c){
	if(a<=0||b<=0||c<=0){
		return 1;
	}
	if(a>20||b>20||c>20){
		return wdp[a][b][c]=w(20,20,20);
	}
	if(wdp[a][b][c]){
		return wdp[a][b][c];
	}
	if(a<b&&b<c){
		return wdp[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	}
	return wdp[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}
