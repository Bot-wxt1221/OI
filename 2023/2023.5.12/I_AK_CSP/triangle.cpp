#include <iostream>
#include <cstdio>
inline int read();
int x;
long long C(long long a,long long b){
    long double res=1;
    for(long long i=a,j=1;j<=b;i--,j++){
        res=(res*((long double)i))/j;
        if(res>x)
            return res;
    }
	return (long long)res;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	#endif
    int t=read();
    while(t--){
        x=read();
        if(x==1){
            printf("1\n");
            continue;
        }
        bool ans=1;
        for(int i=20;i>=1&&ans;i--){
            long long l=0,r=1e9,mid;
            while(l<=r){
                mid=(l+r)/2;
                long long temp=C(mid,i);
                if(temp==x){
                    printf("%lld\n",mid+1);
                    ans=0;
                    break;
                }else if(temp<x){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
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


