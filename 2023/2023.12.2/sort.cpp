#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();
int a[1000005];
int tree[1000005];
int n;
class node{
    public:
        int a,b,c;
        node(int xx=0,int yy=0){
            a=xx;
            b=yy;
            return ;
        }
}tt[1000005];
bool operator < (node a,node b){
    return a.a>b.a;
}
bool cmp2(node a,node b){
    return a.c<b.c;
}
int lowbit(int now){
    return (now)&(-now);
}
void add(int x,int y){
    while(x<=n){
        tree[x]+=y;
        x+=lowbit(x);
    }
    return ;
}
int query(int x){
    int ans=0;
    while(x>0){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	#endif
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        tt[i].a=a[i];
        tt[i].b=i;
        tree[i]=lowbit(i);
    }
    std::sort(tt+1,tt+n+1);
    int ans=0;
    int last=0;
    for(int i=1;i<=n;i++){
        int bi=i;
        if(tt[i].b>last){
            tt[i].c=tt[i].b-last;
        }else{
            tt[i].c=tt[i].b+(n-last+1);
        }
        while(i<=n&&tt[i+1].a==tt[i].a){
            i++;
            if(tt[i].b>last){
                tt[i].c=tt[i].b-last;
            }else{
                tt[i].c=tt[i].b+(n-last+1);
            }
        }
        std::sort(tt+bi,tt+i+1,cmp2);
        for(int j=bi;j<=i;j++){
            add(tt[j].b,-1);
            if(tt[j].b>last){
                ans+=query(tt[j].b-1)-query(last);
            }else{//tt[last].b>tt[j].b
                ans+=query(tt[j].b-1)+query(n)-query(last);
            }
            last=tt[j].b;
        }
    }
    printf("%lld",ans);
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

