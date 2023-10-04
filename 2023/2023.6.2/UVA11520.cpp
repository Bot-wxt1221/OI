#include <iostream>
#include <cstdio>
inline int read();
char map[15][15];
int to;
bool dfs(int nowx,int nowy){
    if(nowx==to&&nowy==to+1){
        return 1;
    }
    if(nowy==to+1){
        return  dfs(nowx+1,1);
    }
    if(map[nowx][nowy]!='.'){
        return dfs(nowx,nowy+1);
    }
    for(char g='A';g<='Z';g++){
        if(map[nowx-1][nowy]==g||map[nowx][nowy-1]==g||map[nowx][nowy+1]==g||map[nowx+1][nowy]==g){
            continue;
        }
        map[nowx][nowy]=g;
        if(dfs(nowx,nowy+1)){
            return 1;
        }
    }
    return 0;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int T=read();
    for(int TT=1;TT<=T;TT++){
        int n=read();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                std::cin>>map[i][j];
            }
        }
        to=n;
        dfs(1,1);
        printf("Case %d:\n",TT);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                printf("%c",map[i][j]);
            }
            printf("\n");
        }
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


