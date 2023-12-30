#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
int pow(int x,int y){
    if(y==0){
        return 1;
    }
    if(y%2==0){
        int temp=pow(x,y/2);
        return (temp*temp)%998244353ll;
    }
    return (pow(x,y-1)*x)%998244353ll;
}
inline int read();
char tt[1005][1005];
int low[1005][1005];
int dfn[1005][1005];
int cnt;
int h,w;
int to[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int aa=0;
int bb=0;
void dfs(int xx,int yy,bool root=0){
    low[xx][yy]=dfn[xx][yy]=++cnt;
    int c=0;
    for(int i=0;i<4;i++){
        int tx=xx+to[i][0];
        int ty=yy+to[i][1];
        if(tx<=0||ty<=0||tx>h||ty>w||tt[tx][ty]=='.'){
            continue;
        }
        if(dfn[tx][ty]==0){
            dfs(tx,ty);
            low[xx][yy]=std::min(low[xx][yy],low[tx][ty]);
            if(low[tx][ty]>=dfn[xx][yy]){
                c++;
            }
        }else{
            low[xx][yy]=std::min(low[xx][yy],dfn[tx][ty]);
        }
    }
    c+=!root;
    bb++;
    aa+=c-1;
    aa%=mod;
    aa+=mod;
    aa%=mod;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    h=read();
    w=read();
    for(int i=1;i<=h;i++){
        scanf("%s",tt[i]+1);
    }
    int cl=0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cnt=0;
            if(dfn[i][j]!=0||tt[i][j]=='.'){
                continue;
            }
            dfs(i,j,1);
            cl++;
        }
    }
    aa+=(cl*bb)%mod;
    aa%=mod;
    aa+=mod;
    aa%=mod;
    bb%=mod;
    printf("%lld",(aa*pow(bb,mod-2))%mod);
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

