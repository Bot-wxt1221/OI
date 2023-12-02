#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
inline int read();

signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("gcdandlcm.in","r",stdin);
	freopen("gcdandlcm.out","w",stdout);
	#endif
    int T=read();
    while(T--){
        int G=read();
        int L=read();
        if(L%G!=0){
            printf("0\n");
            break;
        }
        int sq=sqrt(G);
        int ans=1;
        for(int i=2;i<=sq;i++){
            if(G%i==0){
                int cnt1=0;
                while(G%i==0){
                    G=G/i;
                    cnt1++;
                }
                int cnt2=0;
                while(L%i==0){
                    L=L/i;
                    cnt2++;
                }
                if(cnt2!=cnt1){
                    ans*=((cnt2-cnt1-1)*6+6);
                }else{
                    ans*=1;
                }
            }
        }
        if(G!=1){
            int i=G;
            int cnt1=0;
            while(G%i==0){
                G=G/i;
                cnt1++;
            }
            int cnt2=0;
            while(L%i==0){
                L=L/i;
                cnt2++;
            }
            if(cnt2!=cnt1){
                ans*=((cnt2-cnt1-1)*6+6);
            }else{
                ans*=1;
            }
        }
        sq=sqrt(L);
        for(int i=2;i<=sq;i++){
            if(L%i==0){
                int cnt2=0;
                while(L%i==0){
                    L=L/i;
                    cnt2++;
                }
                int cnt1=0;
                if(cnt2!=cnt1){
                    ans*=((cnt2-cnt1-1)*6+6);
                }else{
                    ans*=1;
                }
            }
        }
        if(L!=1){
            int i=L;
            int cnt2=0;
            while(L%i==0){
                L=L/i;
                cnt2++;
            }
            int cnt1=0;
            if(cnt2!=cnt1){
                ans*=((cnt2-cnt1-1)*6+6);
            }else{
                ans*=1;
            }
        }
        printf("%lld\n",ans);
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


