#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
inline int read();
int a[50005];
int ans=0;
int anss[50005];
int ina[50005];
class node{
    public:
        int l,r;
        int i;
}que[50005];
int cnt[50005];
bool operator < (node a,node b){
    if(ina[a.l]!=ina[b.l]){
        return ina[a.l]<ina[b.l];
    }else{
        if(a.r%2){
            return a.r<b.r;
        }else{
            return a.r>b.r;
        }
    }
}
void add(int l){
    ans+=cnt[a[l]]*2+1;
    cnt[a[l]]++;
    return ;
}
void del(int l){
    ans-=cnt[a[l]]*2-1;
    cnt[a[l]]--;
    return ;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	#endif
    int n=read(),m,k;
    m=read();
    k=read();
    int blocksize=sqrt(n);
    int now=1;
    int be=1;
    ina[1]=1;
    for(int i=1;i<=n;i++){
        if(i-now+1>blocksize){
            now++;
            be=i;
        }
        ina[i]=now;
        a[i]=read();
    }
    for(int i=1;i<=m;i++){
        que[i].l=read();
        que[i].r=read();
        que[i].i=i;
    }
    std::sort(que+1,que+m+1);
    int l=1,r=0;
    for(int i=1;i<=m;i++){
        int &ll=que[i].l;
        int &rr=que[i].r;
        while(l<ll){
            del(l++);
        }
        while(l>ll){
            add(--l);
        }
        while(r<rr){
            add(++r);
        }
        while(r>rr){
            del(r--);
        }
        anss[que[i].i]=ans;
    }
    for(int i=1;i<=m;i++){
        printf("%d\n",anss[i]);
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

