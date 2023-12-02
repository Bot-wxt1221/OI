#include <iostream>
#include <cstdio>
#include <cstring>
inline long long read();
bool book[4000005];
long long prime[4000005];
long long isPrime[4000005];
signed main(){
	// #ifdef ONLINE_JUDGE
	// #else
	// freopen("primedistance.in","r",stdin);
	// freopen("primedistance.out","w",stdout);
	// #endif
    long long l,r;
    long long m=0;
    for(long long i=2;i<=56430;i++){
        if(!book[i]){
            prime[++m]=i;
            for(long long j=i*2;j<=56430;j+=i){
                book[j]=1;
            }
        }
    }
    while(scanf("%lld%lld",&l,&r)!=EOF){
        if(l==1){
            l=2;
        }
        if(l>r){
            printf("There are no adjacent primes.\n");
            continue;
        }
        memset(isPrime,0,sizeof(isPrime));
        for(long long i=1;i<=m;i++){
            for(long long j=l/prime[i];j<=r/prime[i];j++){
                if(prime[i]*j>=l&&j>1&&prime[i]*j<=r){
                    isPrime[prime[i]*j-l]=1;
                }
            }
        }
        long long _min=0x3f3f3f3f3f3f3f3fll,_max=0;
        long long il,ir,al,ar;
        long long summ=0;
        long long bef=-1;
        for(long long i=l;i<=r;i++){
            if(isPrime[i-l]){
                continue;
            }
            summ++;
            if(bef!=-1){
                if(_min>i-bef){
                    _min=i-bef;
                    il=bef;
                    ir=i;
                }
                if(_max<i-bef){
                    _max=i-bef;
                    al=bef;
                    ar=i;
                }
            }
            bef=i;
        }
        if(summ<2){
            printf("There are no adjacent primes.\n");
        }else{
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",il,ir,al,ar);
        }
    }
	return 0;
}
inline long long read(){
	long long x=0,f=1;char c=getchar();
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


