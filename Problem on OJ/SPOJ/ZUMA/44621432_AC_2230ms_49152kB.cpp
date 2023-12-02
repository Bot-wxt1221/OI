#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
int aa[105];
int a[105];
int dp[105][105][105][10];
int all[105][105];
int vis[105];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read(),k;
    k=read();
    int ans=0;
    for(int i=1;i<=n;i++){
        aa[i]=read();
        vis[aa[i]]++;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(vis[aa[i]]==1){
            ans+=k-1;
        }else{
            a[++cnt]=aa[i];
        }
    }
    n=cnt;
    memset(dp,0x3f,sizeof(dp));
    memset(all,0x3f,sizeof(all));
    for(int i=1;i<=n;i++){
        dp[i][i][a[i]][1]=0;
        all[i][i]=k-1;
    }
    for(int siz=1;siz<=n;siz++){
        for(int i=1;i+siz-1<=n;i++){
            for(int color=1;color<=100;color++){
                int j=i+siz-1;
                for(int kk=k;kk>=1;kk--){
                    for(int kkk=i;kkk<j;kkk++){
                        dp[i][j][color][kk]=std::min(dp[i][j][color][kk],dp[i][kkk][color][kk]+all[kkk+1][j]);
                        dp[i][j][color][kk]=std::min(dp[i][j][color][kk],dp[kkk+1][j][color][kk]+all[i][kkk]);
                        for(int gg=1;gg<kk;gg++){
                            dp[i][j][color][kk]=std::min(dp[i][j][color][kk],dp[i][kkk][color][gg]+dp[kkk+1][j][color][kk-gg]);
                        }
                    }
                    dp[i][j][color][kk]=std::min(dp[i][j][color][kk],dp[i][j][color][kk+1]);
                    all[i][j]=std::min(all[i][j],dp[i][j][color][kk]+k-kk);
                }
            }
        }
    }
    printf("%d",all[1][n]+ans);
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

