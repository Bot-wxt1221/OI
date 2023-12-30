// LUOGU_RID: 140910482
#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
inline int read();
int x[200005];
int y[200005];
long double calcdis(int x1,int x2,int y1,int y2){
    return sqrt(((long long)(x1-x2))*(x1-x2)+((long long)(y1-y2))*(y1-y2));
}
long double sumdis[200005];
long double hdis[200005];
long double yy[2000005];
long double dp[2000005];
std::deque<int>qu;
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read();
    int k=read();
    int sx=read();
    int sy=read();
    for(int i=1;i<=n;i++){
        x[i]=read();
        y[i]=read();
        hdis[i]=calcdis(sx,x[i],sy,y[i]);
        sumdis[i]=sumdis[i-1];
        if(i!=1)
            sumdis[i]+=calcdis(x[i-1],x[i],y[i-1],y[i]);
    }
    for(int i=1;i<=n;i++){
        yy[i]=hdis[i+1]-sumdis[i+1];
    }
    yy[0]=hdis[1];
    //dp[i]=min(dp[j]-sumdis(1,j)+hdis(j+1)+hdis(i)+sumdis(1,i))  (i-j<=k)
    //dp[0]=0
    qu.push_back(0);
    for(int i=1;i<=n;i++){
        while(qu.size()>0&&i-qu.front()>k){
            qu.pop_front();
        }
        dp[i]=dp[qu.front()]+yy[qu.front()]+hdis[i]+sumdis[i];
        // printf("%Lf\n",dp[i]);
        while(qu.size()>0&&yy[qu.back()]+dp[qu.back()]>=yy[i]+dp[i]){
            qu.pop_back();
        }
        qu.push_back(i);
    }
    printf("%.20Lf",dp[n]);
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


