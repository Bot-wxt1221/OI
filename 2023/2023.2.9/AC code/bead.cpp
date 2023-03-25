#include <iostream>
#include <cstdio>
#include <bitset>
#define int long long
inline int read();
std::bitset<105>a[105];
std::bitset<105>b[105];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("bead.in","r",stdin);
	freopen("bead.out","w",stdout);
	#endif
    int n,m;
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        a[i][i]=1;
        b[i][i]=1;
    }
    for(int i=1;i<=m;i++){
        int x=read();
        int y=read();
        a[x][y]=1;//x比y大
        b[y][x]=1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(a[i][k]){//i比k大，说明i比所有比k大的大
                a[i]|=a[k];
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(b[i][k]){//i比k小，说明i比所有比k小的小
                b[i]|=b[k];
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(b[i].count()>(n+1)/2||a[i].count()>(n+1)/2){
            ans++;//比他小或大的的数大于等于(n+1)/2
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


