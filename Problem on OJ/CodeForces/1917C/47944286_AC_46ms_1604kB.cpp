#include <iostream>
#include <cstdio>
inline int read();
int a[2005];
int v[100005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int t=read();
    while(t--){
        int n=read(),k,d;
        k=read();
        d=read();
        for(int i=1;i<=n;i++){
            a[i]=read();
        }
        for(int i=1;i<=k;i++){
            v[i]=read();
        }
        int _max=0;
        for(int i=1;i<=std::min(d, 2 * n);i++){
            int ans=0;
            for(int j=1;j<=n;j++){
                if(a[j]==j){
                    ans++;
                }
            }
            _max=std::max(_max,ans+(d-i)/2);
            for(int j=1;j<=v[(i-1)%k+1];j++){
                a[j]++;
            }
        }
        printf("%d\n",_max);
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


