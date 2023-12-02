#include <iostream>
#include <cstdio>
inline int read();
int n;
int ans;
int pos[50];
void dfs(int now,int last,int more){
	if(more==0){
		if(pos[1]==n){
			return ;
		}
		ans++;
		printf("%d",n,pos[1]);
		for(int i=2;i<now;i++){
			printf("+%d",pos[i]);
		}
		printf("\n");
		return ;
	}
    for(int i=last;i<=more;i++){
		pos[now]=i;
        dfs(now+1,i,more-i);
    }
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("decompose.in","r",stdin);
	freopen("decompose.out","w",stdout);
	#endif
    while(scanf("%d",&n)!=EOF){
		ans=0;
        dfs(1,1,n);
// 		printf("total=%d\n",ans);
    }
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

