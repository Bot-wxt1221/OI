#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
inline int read();
int dp[1605][1605];
signed main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen("IQ.in","r",stdin);
	freopen("IQ.out","w",stdout);
	#endif
    int n=read();
    int sum=0;
    for(int i=1;i<=n;i++){
        int temp=read();
        sum+=temp;
        for(int j=1600;j>=0;j--){
            for(int m=1600;m>=0;m--){
                if(j-temp>=0)
                    dp[j][m]|=dp[j-temp][m];
                if(m-temp>=0)
                    dp[j][m]|=dp[j][m-temp];
            }
        }
        dp[0][temp]=dp[temp][0]=1;
    }
    double _max=0;
    for(int i=1;i<=1600;i++){
        for(int j=1;j<=1600;j++){
            int m=sum-i-j;
            if(dp[i][j]==0){
                continue;
            }
            if(m<0){
                continue;
            }
            if(i+j<=m||i+m<=j||j+m<=i){
                continue;
            }
            double p=(i+j+m)/2.0;
            _max=std::max(_max,sqrt(p*(p-i)*(p-j)*(p-m)));
        }
    }
    if(_max==0){
        printf("-1");
        return 0;
    }
    printf("%lld",(int)(_max*100));
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


