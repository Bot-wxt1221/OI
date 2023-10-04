#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#define int long long
inline int read();
int qa[8000005];
int qb[8000005];
int qc[8000005];
int la,lb,lc;
int ha=1,hb=1,hc=1;
std::priority_queue<int>qu;
int seq[8000005];
int cmp(int a,int b){
    return a>b;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("earthworm.in","r",stdin);
	freopen("earthworm.out","w",stdout);
	#endif
    int n=read(),m,q,u,v,t;
    m=read();
    q=read();
    u=read();
    v=read();
    t=read();
    for(int i=1;i<=n;i++){
        seq[i]=read();
    }
    std::sort(seq+1,seq+n+1,cmp);
    for(int i=1;i<=n;i++){
        qa[++la]=seq[i];
    }
    for(int i=1;i<=m;i++){
        int t1=-0x3f3f3f3f3f3f3f3f,t2=-0x3f3f3f3f3f3f3f3f,t3=-0x3f3f3f3f3f3f3f3f;
        if(la!=ha-1){
            t1=qa[ha];
        }
        if(lb!=hb-1){
            t2=qb[hb];
        }
        if(lc!=hc-1){
            t3=qc[hc];
        }
        int final=0;
        if(t1>=t2&&t1>=t3){
            final=t1+(i-1)*q;
            ha++;
        }else if(t2>=t1&&t2>=t3){
            final=t2+(i-1)*q;
            hb++;
        }else{
            final=t3+(i-1)*q;
            hc++;
        }
        int temp=final*u/v;
        // b.push(temp-i*q);
        qb[++lb]=temp-i*q;
        // c.push(final-temp-i*q);
        qc[++lc]=final-temp-i*q;
        if(i%t==0){
            printf("%lld ",final);
        }
    }
    printf("\n");
    while(ha-1!=la){
        qu.push(qa[ha]);
        ha++;
    }
    while(hb-1!=lb){
        qu.push(qb[hb]);
        hb++;
    }
    while(hc-1!=lc){
        qu.push(qc[hc]);
        hc++;
    }
    int i=0;
    while(qu.size()>0){
        i++;
        if(i%t==0){
            printf("%lld ",qu.top()+m*q);
        }
        qu.pop();
    }
    printf("\n");
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


