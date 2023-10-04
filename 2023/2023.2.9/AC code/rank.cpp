#include <iostream>
#include <cstdio>
#include <bitset>
#define int long long
inline int read();
std::bitset<1005>a[1005];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("rank.in","r",stdin);
	freopen("rank.out","w",stdout);
	#endif
    int n,m;
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        a[i][i]=1;
    }
    for(int i=1;i<=m;i++){
        int x=read();
        a[x][read()]=1;//x比y大
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(a[i][k]){//i比k大，说明i比所有比k大的大
                a[i]|=a[k];
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=a[i].count();//统计所知道的关系数
    }
    printf("%d",(n)*(n+1)/2-ans);//计算没有直接关系的
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


