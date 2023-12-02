#include<bits/stdc++.h>
#define l long long
#define F(n) for (l i=1;i<=n;i++)
using namespace std;

const l N=1e6+5,p=1e9+7;
l n,d[N],D[N],t,T,u,v,M,c[N],A,m=-1;
vector<l> e[N];
struct b{
    l m,M;
    bool operator<(const b a){
        return M!=a.M?M<a.M:m>a.m;
    }
}B[N];

void s(l u,l f)
{
    for (l v:e[u])
        if (v!=f)
            d[v]=d[u]+1,s(v,u);
}

void S(l u,l f)
{
    for (l v:e[u])
        if (v!=f)
            D[v]=D[u]+1,S(v,u);
}

main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
    cin>>n;
    c[1]=2;
    F(n-1){
        c[i+1]=c[i]*2%p;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    s(1,1);
    F(n) if (d[i]>M) M=d[i],t=i;
    d[t]=M=0;
    s(t,t);
    F(n) if (d[i]>M) M=d[i],T=i;
    S(T,T);
    F(n){
        if (d[i]==d[T]&&D[i]==D[t]) return cout<<c[n]*d[T]%p,0;
        B[i]={min(d[i],D[i]),max(d[i],D[i])};
        m=max(m,B[i].m);
    }
    sort(B+1,B+1+n);
    A=m*2%p+c[n-2]*d[T]*2%p;
    F(n-2) A=(A+c[i]*max(m,B[i].M)%p)%p;
    cout<<A;
}
