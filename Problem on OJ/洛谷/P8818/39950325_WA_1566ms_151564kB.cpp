#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstring>
#define int long long
using namespace std;
unsigned long long read(){
    char temp=getchar();
    unsigned long long f=1,x=0;
    while('0'>temp||temp>'9'){
        (temp=='-')?(f=-1):(1);
        temp=getchar();
    }
    while('0'<=temp&&temp<='9'){
        x=(x<<3)+(x<<1)+(temp^'0');
        temp=getchar();
    }
    return f*x;
}
class node{
    public:
        node(){
            return ;
        }
        ~node(){
            return ;
        }
        int st[200005][30];
        int _min_(int l,int r){
            int k=log2(r-l+1);
            return min(st[l][k],st[(r-(1<<k)+1)][k]);
        }
        int _max_(int l,int r){
            int k=log2(r-l+1);
            return max(st[l][k],st[(r-(1<<k)+1)][k]);
        }
}minb,maxb,mina,maxa,dmin,xmax;
int a0[200005];
int b0[200006];
signed main(){
    #ifdef ONLINE_JUDGE=LUOGU
    #else
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    #endif
    int n=read(),m,q;
    m=read();
    q=read();
    for(int i=1;i<=n;i++){
        mina.st[i][0]=read();
        maxa.st[i][0]=mina.st[i][0];
        if(mina.st[i][0]==0){
            a0[i]=a0[i-1]+1;
        }else{
            a0[i]=a0[i-1];
        }
        if(mina.st[i][0]<0){
            xmax.st[i][0]=mina.st[i][0];
            dmin.st[i][0]=0x3f3f3f3f3f3f3f3f;
        }
        if(mina.st[i][0]>0){
            dmin.st[i][0]=mina.st[i][0];
            xmax.st[i][0]=-0x3f3f3f3f3f3f3f3f;
        }
    }
    for(int i=1;i<=m;i++){
        minb.st[i][0]=read();
        maxb.st[i][0]=minb.st[i][0];
        if(minb.st[i][0]==0){
            b0[i]=b0[i-1]+1;
        }else{
            b0[i]=b0[i-1];
        }
    }
    for(int k=1;k<=log2(n);k++){
        for(int i=1;i<=n;i++){
            dmin.st[i][k]=min(dmin.st[i][k-1],dmin.st[i+(1<<(k-1))][k-1]);
            xmax.st[i][k]=max(xmax.st[i][k-1],xmax.st[i+(1<<(k-1))][k-1]);
            maxa.st[i][k]=max(maxa.st[i][k-1],maxa.st[i+(1<<(k-1))][k-1]);
            mina.st[i][k]=min(mina.st[i][k-1],mina.st[i+(1<<(k-1))][k-1]);
        }
    }
    for(int k=1;k<=log2(m);k++){
        for(int i=1;i<=m;i++){
            maxb.st[i][k]=max(maxb.st[i][k-1],maxb.st[i+(1<<(k-1))][k-1]);
            minb.st[i][k]=min(minb.st[i][k-1],minb.st[i+(1<<(k-1))][k-1]);
        }
    }
    for(int i=1;i<=q;i++){
        int l1=read();
        int r1=read();
        int l2=read();
        int r2=read();
        if(minb._min_(l2,r2)>0){
            printf("%lld\n",maxa._max_(l1,r1)*minb._min_(l2,r2));
        }else if(maxb._max_(l2,r2)<0){
            printf("%lld\n",mina._min_(l1,r1)*maxb._max_(l2,r2));
        }else{
            if(a0[r1]!=a0[l1-1]){
                printf("0\n");
            }else{
                // cerr<<xmax._max_(l1,r1);
                printf("%lld\n",max(xmax._max_(l1,r1)*maxb._max_(l2,r2),dmin._min_(l1,r1)*minb._min_(l2,r2)));
            }
        }
    }
    return 0;
}
