#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int fa[1000005];
int count[1000005];
int sum[1000005];
int getfa(int a){
    return fa[a]==a?a:fa[a]=getfa(fa[a]);
}
void bing(int a,int b){
    int fa=getfa(a);
    int fb=getfa(b);
    if(fa==fb){
        return ;
    }
    if(count[fa]<count[fb]){
        std::swap(fa,fb);
    }
    ::fa[fb]=::fa[fa];
    count[fa]+=count[fb];
    sum[fa]+=sum[fb];
    return ;
}
void add(int a,int b){
    int fb=getfa(b);
    int faa=getfa(a);
    fa[a]=fb;
    count[fb]++;
    sum[fb]+=a;
    count[faa]--;
    sum[faa]-=a;
}
void Sum(int a){
    int fb=getfa(a);
    printf("%lld %lld\n",count[fb],sum[fb]);
    return ;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
//	freopen("UVA11987.in","r",stdin);
//	freopen("UVA11987.out","w",stdout);
	#endif
    int n,m;
    while(scanf("%lld%lld",&n,&m)!=EOF){
    for(int i=1;i<=n;i++){
        fa[i]=i+n;
        fa[i+n]=i+n;
        count[i+n]=1;
        sum[i+n]=i;
    }
    for(int i=1;i<=m;i++){
        int k=read();
        int p=read();
        switch(k){
            case 1:{
                bing(p,read());
                break;
            }
            case 2:{
                add(p,read());
                break;
            }
            case 3:{
                Sum(p);
                break;
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

