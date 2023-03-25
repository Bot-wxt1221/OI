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
char a[20000];
char tree[40000];
int fir[20000];
int sec[20000];
void dfs(int l,int r,int now);
void dfs2(int now);//out
signed main(){
// 	freopen("fbi.in","r",stdin);
// 	freopen("fbi.out","w",stdout);
	int n;
	n=read();
	for(int i=1;i<=(1LL<<n);i++){
		cin>>a[i];
		if(a[i]=='1'){
			fir[i]=fir[i-1]+1;
			sec[i]=sec[i-1];
		}else{
			sec[i]=sec[i-1]+1;
			fir[i]=fir[i-1];
		}
	}
	dfs(1,(1ll<<n),1);
	dfs2(1);
	return 0;
}
void dfs(int l,int r,int now){
	int one=fir[r]-fir[l-1],two=sec[r]-sec[l-1];
	if(two==0){
		tree[now]='I';
	}else if(one==0){
		tree[now]='B';
	} else{
		tree[now]='F';
	}
	if(l==r){
		return ;
	}
	dfs(l,(l+r)/2,now*2);
	dfs((l+r)/2+1,r,now*2+1);
	return ;
}
void dfs2(int now){
	if(tree[now]=='\0'){
		return ;
	}
	dfs2(now*2);
	dfs2(now*2+1);
	printf("%c",tree[now]);
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


