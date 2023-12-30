#include <iostream>
#include <cstdio>
inline int read();
int fir[100005];
int nxt[100005];
int v[100005];
int now,n;
char a[105];
void add(int x,int y){
    now++;
    v[now]=y;
    nxt[now]=fir[x];
    fir[x]=now;
    return ;
}
int dep[100005];
int fa[100005];
int siz[100005];
int bson[100005];
void dfs1(int now,int fa){
    siz[now]=1;
    dep[now]=dep[fa]+1;
    ::fa[now]=fa;
    bson[now]=0;
    for(int i=fir[now];i!=-1;i=nxt[i]){
        if(v[i]==fa){
            continue;
        }
        dfs1(v[i],now);
        siz[now]+=siz[v[i]];
        if(siz[v[i]]>siz[bson[now]]){
            bson[now]=v[i];
        }
    }
    return ;
}
int id[100005];
int cnt=0;
int top[100005];
void dfs2(int now,int topf){
    id[now]=++cnt;
    top[now]=topf;
    if(bson[now]==0){
        return ;
    }
    dfs2(bson[now],topf);
    for(int i=fir[now];i!=-1;i=nxt[i]){
        if(v[i]==fa[now]||v[i]==bson[now]){
            continue;
        }
        dfs2(v[i],v[i]);
    }
    return ;
}
int x,y,k;
int b[800005];
int siz1[800005];
int lazy[800005];
void build(int l,int r,int now){
    if(l==r){
        b[now]=0;
        siz1[now]=1;
        return ;
    }else if(l>r){
        return ;
    }
    siz1[now]=(r-l+1);
    int mid=(l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    b[now]=b[now*2]+b[now*2+1];
    return ;
}
inline void push_down(int now){
    if(lazy[now]==0){
        return ;
    }
    lazy[now*2]=lazy[now];
    lazy[now*2+1]=lazy[now];
    lazy[now]--;
    b[now]=siz1[now]*lazy[now];
    lazy[now]=0;
    return ;
}
void add(int l,int r,int now){
    
    if(l>r){
        return ;
    }
    push_down(now);
    if(r<x||y<l){
        return ;
    }
    if(x<=l&&r<=y){
        b[now]=siz1[now]*k;
        lazy[now]=k+1;
        return ;
    }else{
        int mid=(l+r)/2;
        add(l,mid,now*2);
        add(mid+1,r,now*2+1);
        b[now]=b[now*2]+b[now*2+1];
    }
    return ;
}
void ques(int l,int r,int now){
    if(l>r){
        return ;
    }
    push_down(now);
    if(r<x||y<l){
        return ;
    }
    if(x<=l&&r<=y){
        k+=b[now];
        return ;
    }else{
        int mid=(l+r)/2;
        ques(l,mid,now*2);
        ques(mid+1,r,now*2+1);
        b[now]=b[now*2]+b[now*2+1];
    }
    return ;
}
int query1(int x,int y){
    int ans=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]){
            std::swap(x,y);
        }
        ::k=0;
        ::x=id[top[x]];
        ::y=id[x];
        ques(1,n,1);
        ans+=k;
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]){
        std::swap(x,y);
    }
    ::k=0;
    ::x=id[x];
    ::y=id[y];
    ques(1,n,1);
    ans+=k;
    return ans;
}
void add11(int x,int y,int z){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]){
            std::swap(x,y);
        }
        ::x=id[top[x]];
        ::y=id[x];
        ::k=z;
        add(1,n,1);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]){
        std::swap(x,y);
    }
    ::x=id[x];
    ::y=id[y];
    ::k=z;
    add(1,n,1);
    return ;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    n=read();
    for(int i=1;i<=n;i++){
        fir[i]=-1;
    }
    for(int i=2;i<=n;i++){
        add(read()+1,i);
    }
    build(1,n,1);
    dfs1(1,1);
    dfs2(1,1);
    int q=read();
    while(q--){
        scanf("%s",a);
        int x=read()+1;
        int fron;
        if(a[0]=='i'){
            fron=query1(1,x);
            add11(1,x,1);
            //install
            printf("%d\n",query1(1,x)-fron);
        }else {
            ::x=id[x];
            ::y=id[x]+siz[x]-1;
            ::k=0;
            ques(1,n,1);
            fron=::k;
            ::k=0;
            add(1,n,1);
            ::k=0;
            ques(1,n,1);
            printf("%d\n",fron-::k);
            //uninstall
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


