#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
int dfs(int l,int r){
    if(l==r){
        return l;
    }
    int mid=(l+r)/2;
    int aa=dfs(l,mid);
    int bb=dfs(mid+1,r);
    int uu=0,vv=0;
    if(aa!=bb){
        printf("? %d %d\n",aa,bb);
        fflush(stdout);
        uu=read();
    }
    if(aa!=bb-1){
        printf("? %d %d\n",aa,bb-1);
        fflush(stdout);
        vv=read();
    }
    if(uu==vv){
        return bb;
    }else{
        return aa;
    }
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int T=read();
    while(T--){
        int n=read();
        int l=0;
        printf("! %d\n",dfs(1,n));
        fflush(stdout);
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


