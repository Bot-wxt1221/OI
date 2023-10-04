#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
int dp[2005][2005];
char temp1[2005];
char temp2[2005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("activity.in","r",stdin);
	freopen("activity.out","w",stdout);
	#endif
    scanf("%s",temp1+1);
    scanf("%s",temp2+1);
    int st1=strlen(temp1+1);
    int st2=strlen(temp2+1);
    int _max=0;
    for(int i=3;i<=st1;i++){
        for(int j=3;j<=st2;j++){
            dp[i][j]=std::max(dp[i-1][j],dp[i][j-1]);
            if(temp2[j]==temp1[i]&&temp2[j-1]==temp1[i-1]&&temp2[j-2]==temp1[i-2]){
                dp[i][j]=std::max(dp[i-3][j-3]+3,dp[i][j]);
                if(j>=4&&i>=4&&temp2[j-3]==temp1[i-3]){
                    dp[i][j]=std::max(dp[i-4][j-4]+4,dp[i][j]);
                    if(i>=5&&j>=5&&temp2[j-4]==temp1[i-4]){
                        dp[i][j]=std::max(dp[i-5][j-5]+5,dp[i][j]);
                    }
                }
            }
            _max=std::max(_max,dp[i][j]);
            
        }
    }
    printf("%d",_max);
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


