#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();

int x[805];
int y[805];

signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("mini.in","r",stdin);
	freopen("mini.out","w",stdout);
	#endif
    int T=read();
    int ii=0;
    while(T--){
        ii++;
        int n=read();
        for(int i=1;i<=n;i++){
            x[i]=read();
        }
        for(int i=1;i<=n;i++){
            y[i]=-read();
        }
        std::sort(x+1,x+n+1);
        std::sort(y+1,y+n+1);
        int ans=0;
        for(int i=1;i<=n;i++){
            ans-=x[i]*y[i];
        }
        std::cout<<"Case #"<<ii<<": "<<ans<<std::endl;
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


