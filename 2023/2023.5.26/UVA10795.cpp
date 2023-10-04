#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int start[66],end[66];
int f(int *p,int i,int to){
    if(i==0){
        return 0;
    }
    if(p[i]==to){
        return f(p,i-1,to);
    }
    return f(p,i-1,6-p[i]-to)+((1LL)<<(i-1));
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=0;
    int ii=0;
    while(scanf("%lld",&n)!=EOF&&n!=0){
        ii++;
        for(int i=1;i<=n;i++){
            start[i]=read();
        }
        for(int i=1;i<=n;i++){
            end[i]=read();
        }
        int now=n;
        while(now>=1&&start[now]==end[now]){
            now--;
        }
        int ans=0;
        if(now>=1){
            long long got=6-start[now]-end[now];
            ans+=(f(start,now-1,got)+1+f(end,now-1,got));
        }
        printf("Case %lld: %lld\n",ii,ans);
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


