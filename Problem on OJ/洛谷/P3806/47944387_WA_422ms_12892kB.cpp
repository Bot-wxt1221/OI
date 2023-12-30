#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
int fir[100005];
int nxt[200005];
int v[200005];
int w[200005];
int now,n,m;
int ques[1005];
bool vised[100005];
void add(int a,int b,int c){
    now++;
    v[now]=b;
    w[now]=c;
    nxt[now]=fir[a];
    fir[a]=now;
    return ;
}
int cnt,sum;
int dis[100005];
int dd[100005];
bool df[10000005];
int siz[100005];
int we[100005];
int he=0;
std::queue<int>a;
void calcsiz(int now,int fa){
    siz[now]=1;
    we[now]=0;
    for(int i=fir[now];i!=-1;i=nxt[i]){
        if(vised[i]||fa==v[i]){
            continue;
        }
        calcsiz(v[i],now);
        we[now]=std::max(we[now],siz[v[i]]);
        siz[now]+=siz[v[i]];
    }
    we[now]=std::max(we[now],sum-we[now]);
    if(we[now]<=n/2){
        he=now;
    }
    return ;
}
void calcdis(int now,int fa){
    dd[++cnt]=dis[now];
    for(int i=fir[now];i!=-1;i=nxt[i]){
        if(vised[v[i]]||fa==v[i]){
            continue;
        }
        dis[v[i]]=dis[now]+w[i];
        calcdis(v[i],now);
    }
    return ;
}
bool res[1005];
void dfs(int now,int fa){
    vised[now]=1;
    df[0]=1; 
    a.push(0);
    for(int i=fir[now];i!=-1;i=nxt[i]){
        if(vised[v[i]]||fa==v[i]){
            continue;
        }
        cnt=0;
        dis[v[i]]=w[i];
        calcdis(v[i],now);
        for(int j=1;j<=cnt;j++){
            for(int kk=1;kk<=m;kk++){
                if(ques[kk]>=dd[j]){
                    res[kk]|=df[ques[kk]-dd[j]];
                }
            }
        }
        for(int j=1;j<=cnt;j++){
            if(dd[j]<=10000001){
                df[dd[j]]=1;
                a.push(dd[j]);
            }
        }
    }
    while(a.size()>0){
        df[a.front()]=0;
        a.pop();
    }
    for(int i=fir[now];i!=-1;i=nxt[i]){
        if(vised[v[i]]||fa==v[i]){
            continue;
        }
        sum=siz[v[i]];
        calcsiz(v[i],now);
        int hee=he;
        calcsiz(hee,now);
        dfs(hee,now);
    }
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("P3806_1.in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        fir[i]=-1;
    }
    for(int i=1;i<n;i++){
        int u=read();
        int v=read();
        int w=read();
        add(u,v,w);
        add(v,u,w);
    }
    for(int i=1;i<=m;i++){
        ques[i]=read();
    }
    dfs(1,1);
    for(int i=1;i<=m;i++){
        if(res[i]){
            printf("AYE\n");
        }else{
            printf("NAY\n");
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


