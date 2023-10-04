#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
int a[20005];
int b[20005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n,m;
    while(scanf("%d%d",&n,&m)&&n!=0&&m!=0){
        for(int i=1;i<=n;i++){
            a[i]=read();
        }
        for(int i=1;i<=m;i++){
            b[i]=read();
        }
        std::sort(a+1,a+n+1);
        std::sort(b+1,b+m+1);
        int i,j;
        int ans=0;
        for(i=1,j=1;i<=n&&j<=m;i++){
            while(j<=m&&b[j]<a[i]){
                j++;
            }
            ans+=b[j];
            j++;
        }
        if(i==n+1&&j<=m+1){
            printf("%d\n",ans);
        }else{
            printf("Loowater is doomed!\n");
        }
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


