#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
inline int read();
int read2[1000005];
int a[1000005];
int to[1000005][33];
signed main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen("reply.in","r",stdin);
	freopen("reply.out","w",stdout);
	#endif
    int m=0;
    while((a[++m]=read())!=EOF){
        if(a[m]<=1000000)
            read2[a[m]]++;
    }
    m--;
    int n;
    for(int i=m;i>=1;i-=2){
        if(a[i]<=1000000)
            read2[a[i]]--;
        if(a[i-1]<=1000000)
            read2[a[i-1]]--;
        if(a[i]<=1000000&&read2[a[i]]==0){
            n=i;
            break;
        }
    }
    int lg=log2(n);
    for(int i=1;i<=n;i++){
        to[i][0]=a[i];
    }
    for(int i=1;i<=32;i++){
        for(int j=1;j<=n;j++){
            to[j][i]=to[to[j][i-1]][i-1];
        }
    }
    for(int aa=n+1;aa<=m;aa+=2){
        int &m=a[aa];
        int &x=a[aa+1];
        for(int i=32;i>=0;i--){
            if(m>=(1ll<<i)){
                m-=(1ll<<i);
                x=to[x][i];
            }
        }
        printf("%d ",x);
    }
	return 0;
}
inline int read(){
	int x=0,f=1;char c=getchar();
    if(c==EOF){
            return EOF;
        }
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
        if(c==EOF){
            return EOF;
        }
		c=getchar();
	}
    if(c==EOF){
            return EOF;
        }
	while(c>='0'&&c<='9'){
        if(c==EOF){
            return EOF;
        }
		x=(x<<3)+(x<<1)+(c^48);
        
		c=getchar();
	}
    if(c==EOF){
            return EOF;
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

