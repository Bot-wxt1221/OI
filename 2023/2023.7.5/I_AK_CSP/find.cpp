#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
class node{
    public:
        int num,da;
        node(){
            num=da=0;
        }
}a[100005];
int to[100005];
int nxt[100005];
int pre[100005];
int ans1[100005];
int ans2[100005];
bool cmp(node a,node b){
    return a.da<b.da;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	#endif
    int n=read();
    for(int i=1;i<=n;i++){
        a[i].da=read();
        a[i].num=i;
    }
    std::sort(a+1,a+n+1,cmp);
    a[0].da=0x7f7f7f7f;
    a[n+1].da=0x7f7f7f7f;
    pre[0]=-1;
    nxt[0]=1;
    pre[n+1]=n;
    nxt[n+1]=-1;
    for(int i=1;i<=n;i++){
        to[a[i].num]=i;
    }
    for(int i=1;i<=n;i++){
        nxt[i]=i+1;
        pre[i]=i-1;
    }

    for(int i=n;i>=1;i--){
        int now=to[i];
        int t1=std::abs(a[pre[to[i]]].da-a[to[i]].da);
        int t2=std::abs(a[nxt[to[i]]].da-a[to[i]].da);
        if(t2<t1){
            ans1[i]=t2;
            ans2[i]=a[nxt[to[i]]].num;
            // printf("%d %d\n",t2,a[nxt[to[i]]].num);
        }else{
            ans1[i]=t1;
            ans2[i]=a[pre[to[i]]].num;
            // printf("%d %d\n",t1,a[pre[to[i]]].num);
        }
        nxt[pre[now]]=nxt[now];
        pre[nxt[now]]=pre[now];
    }
    for(int i=2;i<=n;i++){
        printf("%d %d\n",ans1[i],ans2[i]);
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


