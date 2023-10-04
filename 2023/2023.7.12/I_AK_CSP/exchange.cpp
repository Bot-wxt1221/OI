#include <iostream>
#include <cstdio>
inline int read();
int fir[50005];
int nxt[100005];
int v[100005];
bool vised[50005];
int now;
void add(int a,int b){
    v[++now]=b;
    nxt[now]=fir[a];
    fir[a]=now;
    return ;
}
int tot;
void dfs(int now){
    vised[now]=1;
    tot++;
    for(int i=fir[now];i!=-1;i=nxt[i]){
        if(vised[v[i]]){
            continue;
        }
        dfs(v[i]);
    }
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("exchange.in","r",stdin);
	freopen("exchange.out","w",stdout);
	#endif
    int n=read(),k;
    k=read();
    for(int i=1;i<=n;i++){
        fir[i]=-1;
    }
    for(int i=1;i<=n;i++){
        int a=read();
        add(i,a);
        add(a,i);
    }
    int ans1=0,ans2=0;
    for(int i=1;i<=n;i++){
        if(vised[i]){
            continue;
        }
        tot=0;
        dfs(i);
        ans1+=tot-1;
        if(tot!=1){
            ans2+=(tot)*(tot-1)/2;
        }
    }
    if(k==2){
        printf("%d\n%d",ans1,ans2);
    }else{
        printf("%d",ans1);
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


