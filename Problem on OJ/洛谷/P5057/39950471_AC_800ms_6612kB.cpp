#include <iostream>
#include <cstdio>
#include <queue>
#include <bitset>
using namespace std;
inline int read();
bool tag[6000005];
char hurt[2000005];
int m[6000005];
int k;
int x,y;
int siz[6000005];
void build(int l,int r,int now){
    if(l==r){
        siz[now]=r-l+1;
        m[now]=hurt[l];
        return ;
    }else if(l>r){
        return ;
    }
    siz[now]=r-l+1;
    int mid=(l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    m[now]=m[now*2]+m[now*2+1];
    return ;
}
void push_down(int now){
    if(tag[now]==0){
        return ;
    }
    m[now*2]=siz[now*2]-m[now*2];
    m[now*2+1]=siz[now*2+1]-m[now*2+1];
    tag[now*2]^=tag[now];
    tag[now*2+1]^=tag[now];
    tag[now]=0;
    return ;
}
void change(int l,int r,int now){
    if(l>r){
        return ;
    }
    push_down(now);
    if(x<=l&&r<=y){
        m[now]=siz[now]-m[now];
        tag[now]^=1;
        return ;
    }else if(x>r||y<l){
        return ;
    }
    int mid=(l+r)/2;
    change(l,mid,now*2);
    change(mid+1,r,now*2+1);
    m[now]=m[now*2]+m[now*2+1];
    return ;
}
void ques(int l,int r,int now){
    if(l>r){
        return ;
    }
    push_down(now);
    if(x<=l&&r<=y){
        k+=m[now];
        return ;
    }else if(x>r||y<l){
        return ;
    }
    int mid=(l+r)/2;
    ques(l,mid,now*2);
    ques(mid+1,r,now*2+1);
    return ;
}
int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen("P2574_1.in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read(),m=read();
    // scanf("%s",hurt+1);
    build(1,n,1);
    for(int i=1;i<=m;i++){
        int op=read();
        x=read();
        k=0;
        if(op==1){
            y=read();
            change(1,n,1);
        }else{
            y=x;
            ques(1,n,1);
            printf("%d\n",k);
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

