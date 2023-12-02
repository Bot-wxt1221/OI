#include <iostream>
#include <cstdio>
#include <cmath>
inline int read();
int a[150005];
int q[150005][2005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read(),m;
    m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    int temp=sqrt(n);
    for(int p=1;p<=temp;p++){
        for(int i=1;i<=n;i++){
            q[i%p][p]+=a[i];
        }
    }
    for(int i=1;i<=m;i++){
        char cmd;
        std::cin>>cmd;
        int x,y;
        x=read();
        y=read();
        if(cmd=='A'){
            if(x<temp){
                printf("%d\n",q[y][x]);
            }else{
                int ans=0;
                for(int j=y;j<=n;j+=x){
                    ans+=a[j];
                }
                printf("%d\n",ans);
            }
        }else{
            for(int j=1;j<=temp;j++){
                q[x%j][j]+=y-a[x];
            }
            a[x]=y;
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

