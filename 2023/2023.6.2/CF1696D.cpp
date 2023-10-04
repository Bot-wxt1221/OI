#include <iostream>
#include <cstdio>
inline int read();
int a[500005],n;
int pos[500005];
int l_max[500005],l_min[500005],r_max[500005],r_min[500005];
int dfs(int l,int r){
    if(l==r){
        return 0;
    }
    if(l!=1&&r!=n){
        return 1;
    }
    int lp,rp;
    if(l==1){
        lp=std::min(l_min[r],l_max[r]);
        rp=std::max(l_min[r],l_max[r]);
    }else if(r==n){
        lp=std::min(r_max[l],r_min[l]);
        rp=std::max(r_max[l],r_min[l]);
    }
    if(lp==l&&rp==r){
        return 1;
    }
    return dfs(l,lp)+dfs(lp,rp)+dfs(rp,r);
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int T=read();
    while(T--){
        n=read();
        l_max[0]=0;
        l_min[0]=0x3f3f3f3f;
        r_max[n+1]=0;
        r_min[n+1]=0x3f3f3f3f;
        for(int i=1;i<=n;i++){
            a[i]=read();
            l_max[i]=std::max(l_max[i-1],a[i]);
            l_min[i]=std::min(l_min[i-1],a[i]);
            pos[a[i]]=i;
        }
        for(int i=n;i>=1;i--){
            r_max[i]=std::max(r_max[i+1],a[i]);
            r_min[i]=std::min(r_min[i+1],a[i]);
        }
        for(int i=1;i<=n;i++){
            l_min[i]=pos[l_min[i]];
            l_max[i]=pos[l_max[i]];
            r_min[i]=pos[r_min[i]];
            r_max[i]=pos[r_max[i]];
        }
        printf("%d\n",dfs(1,n));
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


