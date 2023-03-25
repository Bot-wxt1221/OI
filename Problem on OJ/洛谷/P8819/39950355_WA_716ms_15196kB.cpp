#include <iostream>
#include <cstdio>
#include <random>
inline int read();
unsigned long long hash[500005];
unsigned long long v1[500005];
unsigned long long v2[500005];
unsigned long long bv1[500005];
unsigned long long bv2[500005];
int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    std::mt19937 mt_rand(19260817);
    unsigned long long sum=0,ans=0;
    int n=read(),m=read();
    for(int i=1;i<=n;i++){
        hash[i]=mt_rand();
        sum+=hash[i];
    }
    for(int i=1;i<=m;i++){
        int u=read();
        int v=read();
        v1[v]+=hash[u];
        ans+=hash[v];
        // ans2^=hash[v];
        // v2[v]^=hash[u];
        bv1[v]+=hash[u];
        // bv2[v]^=hash[u];
    }
    int q=read();
    for(int i=1;i<=q;i++){
        int t=read();
        if(t==1){
            int u=read();
            int v=read();
            v1[v]-=hash[u];
            ans-=hash[u];
            // ans2^=hash[u];
            if(ans==sum){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }else if(t==2){
            int u=read();
            ans-=v1[u];
            // ans2^=v1[u];
            v1[u]=0;
            if(ans==sum){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }else if(t==3){
            int u=read();
            int v=read();
            v1[v]+=hash[u];
            ans+=hash[u];
            // ans2^=hash[u];
            if(ans==sum){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }else if(t==4){
            int u=read();
            // ans2^=v1[u];
            // ans2^=bv1[u];
            ans-=v1[u];
            ans+=bv1[u];
            v1[u]=bv1[u];
            if(ans==sum){
                printf("YES\n");
            }else{
                printf("NO\n");
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


