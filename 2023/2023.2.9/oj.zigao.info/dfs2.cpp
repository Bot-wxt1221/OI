#include <iostream>
#include <cstdio>
#include <stack>
inline int read();
int map[105][105];
int out[10005];
int out2[10005];
int nn;
int n;
bool vised[10005];
int now;
void dfs(int step,int now){
    nn++;
    vised[now]=1;
    out[now]=nn;
    for(int i=1;i<=n;i++){
        if(vised[i]||map[now][i]==0){
            continue ;
        }
        dfs(step+1,i);
    }
    out2[now]=++nn;
    // vised[now]=0;
    return ;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("dfs.in","r",stdin);
	freopen("dfs.out","w",stdout);
	#endif
    n=read();
    for(int i=1;i<=n;i++){
        int id=read();
        int k=read();
        for(int i=1;i<=k;i++){
            map[id][read()]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(vised[i]){
            continue;
        }
        dfs(1,i);
    }
    for(int i=1;i<=n;i++){
        printf("%d %d %d\n",i,out[i],out2[i]);
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


