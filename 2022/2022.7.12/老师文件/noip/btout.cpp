#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char a[1005];
char b[1005];
int posa[1005];
int posb[1005];
int righ[1005];
int lef[1005];
int dp[1005];
char dfs(int l,int r,int l1,int r1);
void calc(char );
void out(char );
int main(){
	freopen("btout.in","r",stdin);
	freopen("btout.out","w",stdout);
	scanf("%s",a);
	scanf("%s",b);
	int siz=strlen(a);
	for(int i=0;i<siz;i++){
		posa[a[i]]=i;
		posb[b[i]]=i;
	}
	dfs(0,siz-1,0,siz-1);
	calc(a[0]);
	out(a[0]);
	return 0;
}
char dfs(int l,int r,int l1,int r1){
	if(l>=r){
		return a[l];
	}
	int pos=posb[a[l]];
	if(pos==l1){
		righ[a[l]]=dfs(l+1,r,l1+1,r1);
	}else if(pos==r1){
		lef[a[l]]=dfs(l+1,r,l1,r1-1);
	}else{
		int pos2=posa[b[pos-1]];
		righ[a[l]]=dfs(l+1,pos2,l1,pos-1);
		lef[a[l]]=dfs(pos2+1,r,pos+1,r1);
	}
	return a[l];
}
void calc(char a){
	if(righ[a]!=0){
		calc(righ[a]);
		dp[a]+=dp[righ[a]];
	}
	if(lef[a]!=0){
		calc(lef[a]);
		dp[a]+=dp[lef[a]];
	}
	if(righ[a]==0&&lef[a]==0){
		dp[a]=1;
	}
	return ;
}
void out(char a){
	for(int i=1;i<=dp[a];i++){
		printf("%c",a);
	}
	printf("\n");
	if(righ[a]!=0){
		out(righ[a]);
	}
	if(lef[a]!=0){
		out(lef[a]);
	}
}
