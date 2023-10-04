#include <iostream>
#include <cstdio>
#include <stack>
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
int m;
int ans;
int aa[15000005];
int bb[15000005];
void dfs(int ,int );
int main(){
	freopen("throne.in","r",stdin);
	freopen("throne.out","w",stdout);
	int n=read();
	m=read();
	m++;
	for(int i=1;i<=n;i++){
		aa[i]=read();
		bb[i]=read();
	}
	dfs(1,1);
	printf("%d",ans-m);
	return 0;
}
void dfs(int now,int number){
	if(ans){
		return ;
	}
	if(now==m){
		ans=number;
		return ;
	}
	int temp=0,finda;
	bool find=0; 
	for(int i=now;i!=aa[now]+now;){
		i++;
		if(i+aa[i]>=m&&i<=m){
			find=1;
			finda=i;
		}
		
		i+=aa[i];
	}
	find=0;
	for(int i=now;i!=aa[now]+now;){
		i++;
		if(i+aa[i]>=m&&i<=m){
			find=1;
//			finda=i;
		}
		if(bb[finda]==0&&bb[i]==1){
			temp+=(aa[i]+1);
		}else if(bb[finda]==0&&bb[i]==0&&find==0){
			temp+=(aa[i]+1);
		}else if(bb[finda]==1&&bb[i]==1&&find==0){
			temp+=(aa[i]+1);
		}
		i+=aa[i];
	}
	dfs(finda,number+temp+1);
	return ;
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



