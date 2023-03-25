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
int n;
bool prime[100];
inline void initprime(){
	for(int i=2;i<=100;i++){
		if(prime[i]==0){
			continue;
		}
		for(int ans=i*2;ans<=100;ans+=i){
			prime[ans]=0;
		}
	}
	return ;
}
int vised[25];
int ans[25];
void dfs(int);
int main(){
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	for(int i=2;i<=100;i++){
		prime[i]=1;
	}
	initprime();
	for(int N=1;scanf("%d",&n)!=EOF;N++){
		printf("Case %d:\n",N);
		vised[1]=1;
		ans[1]=1;
		dfs(2);
		ans[1]=0;
		vised[1]=0;
		printf("\n");
	}
	return 0;
}
void dfs(int step){
	if(step==n+1){
		if(prime[ans[1]+ans[n]]){
			for(int i=1;i<=n;i++){
				printf("%d ",ans[i]);
			}
			printf("\n");
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if((step!=1&&0==prime[i+ans[step-1]])){
			continue;
		}
		if(vised[i]){
			continue;
		}
		vised[i]=1;
		ans[step]=i;
		dfs(step+1);
		vised[i]=0;
		ans[step]=0;
	}
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


