#include <iostream>
#include <cstdio>
inline int read();
int n,m;
int pre[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char map[105][105];
bool vised[105][105];
void dfs(int x,int y){
    vised[x][y]=1;
    for(int i=0;i<4;i++){
        int nx=x+pre[i][0];
        int ny=y+pre[i][1];
        if(nx<=0||ny<=0||nx>n||ny>m||vised[nx][ny]||map[nx][ny]!='1'){
            continue;
        }
        dfs(nx,ny);
    }
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	#endif
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        scanf("%s",&map[i][1]);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(vised[i][j]||map[i][j]!='1'){
                continue;
            }
            dfs(i,j);
            ans++;
            // printf("%d %d\n",i,j);
        }
    }
    printf("%d",ans);
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


