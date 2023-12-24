#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
inline int read();
char s[30][100005];
int sz[30];
char temp[100005];
int seq[30];
int n;
int ans=0;
bool cho[30];
void dfs(int now){
	if(now==n+1){
		int cc=0; 
		for(int i=1;i<=n;i++){
			if(cho[i]==1){
				for(int j=1;j<=sz[i];j++){
					temp[++cc]=s[i][j];
				}
			}
		}
		if(cc==0){
			return ;
		}
		for(int i=1;i<=cc;i++){
			if(temp[i]!=temp[cc-i+1]){
				return ;
			}
		}
//		for(int i=1;i<=cc;i++){
//			printf("%c",temp[i]); 
//		}
//		putchar('\n');
		ans++;
		int mod=1e9+7;
		ans%=mod; 
		return ;
	}
	dfs(now+1);
	cho[now]=1;
	dfs(now+1);
	cho[now]=0;
	return ;
}
signed main(){
//	#ifdef ONLINE_JUDGE
//	#else
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
//	#endif
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1); 
		sz[i]=strlen(s[i]+1);
	} 
	dfs(1);
	printf("%lld",ans);
	return 0;
}
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



