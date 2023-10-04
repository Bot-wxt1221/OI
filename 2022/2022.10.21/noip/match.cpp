#include <iostream>
#include <cstdio>
#include <cstring>
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
char can[257][257];
int dp[105][105];
char a[105];
int main(){
    can['('][')']=1;
    can['['][']']=1;
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
    scanf("%s",a+1);
    int siz=strlen(a+1);
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=siz;i++){
        dp[i][i]=1;
    }
    for(int L=2;L<=siz;L++){
        for(int i=1;(i+L-1)<=siz;i++){
            int j=(i+L-1);
            if(can[a[i]][a[j]]){
                if(L==2){
                    dp[i][j]=0;
                }
                dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
            }
            for(int k=i;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
        }
    }
    printf("%d",dp[1][siz]);
	return 0;
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

