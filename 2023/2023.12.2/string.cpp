#include <iostream>
#include <cstdio>
#define int long long
inline int read();

signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	#endif
    int n=read(),k;
    k=read();
    int one=0;
    int zero=1;
    for(int i=1;i<k;i++){
        if(i%2==1){
            one++;
        }else{
            zero++;
        }
    }
    int ans=0;
    int tt;
    for(int i=k;i<=n;i++){
        if((k-1)%2==0){
            one+=(n-i+1);
            zero+=(i-k);
        }else{
            zero+=(n-i+1);
            one+=(i-k);
        }
        ans=std::max(ans,one*zero);
        if(ans==zero*one){
            tt=i;
        }
        if((k-1)%2==0){
            one-=(n-i+1);
            zero-=(i-k);
        }else{
            zero-=(n-i+1);
            one-=(i-k);
        }
    }
    printf("%lld\n",ans);
    for(int i=1;i<k;i++){
        printf("1 ");
    }
    for(int i=k;i<=n;i++){
        printf("%lld ",i==tt);
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

