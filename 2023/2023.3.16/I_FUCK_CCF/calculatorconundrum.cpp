#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int n=1;
int Times(int a,int b){
    int temp=a*b;
    while(temp>=n){
        temp/=10;
    }
    return temp;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("calculatorconundrum.in","r",stdin);
	freopen("calculatorconundrum.out","w",stdout);
	#endif
    int t=read();
    while(t--){
            int n=read();
            ::n=1;
            for(int i=1;i<=n;i++){
                ::n=::n*10;
            }
            int k=read();
            int _max=k;
            int k2=k;
            while(true){
                k=Times(k,k);
                k2=Times(k2,k2);
                _max=std::max(_max,k2);
                k2=Times(k2,k2);
                _max=std::max(_max,k);
                _max=std::max(_max,k2);
                if(k==k2){
                    break;
                }
            }
            printf("%lld\n",_max);
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


