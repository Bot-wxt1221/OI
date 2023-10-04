#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int read(){
	int x=0,op=1;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		op=((temp=='-')?-1:1);
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return x*op;
}
int a[15000005];
int b[15000005],n,m;
int bef=0;
void dfs(int now){
	if(now==m){
		bef++;
		return ;
	}
	bef++;
	int sonn=a[now];
	int nowto=now+1;
	int nowson=0;
	for(;nowto<=now+a[now];){
		if(b[nowto]==0){
			nowto+=a[nowto]+1;
			continue;
		}
		if(nowto<=m&&nowto+a[nowto]>=m){
			dfs(nowto);
			return ;
		}
		bef+=a[nowto]+1;
		nowto+=a[nowto]+1;
	}
	nowto=now+1;
	for(;nowto<=now+a[now];){
		if(b[nowto]==1){
			nowto+=a[nowto]+1;
			continue;
		}
		if(nowto<=m&&nowto+a[nowto]>=m){
			dfs(nowto);
			return ;
		}
		bef+=a[nowto]+1;
		nowto+=a[nowto]+1;
	}
	return ;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("throne.in","r",stdin);
	freopen("throne.out","w",stdout);
	#endif
	n=read();
	m=read()+1;
	for(int i=1;i<=n;i++){
		a[i]=read();
		b[i]=read();
	}
	dfs(1);
	printf("%d",bef-m);
	return 0;
}

