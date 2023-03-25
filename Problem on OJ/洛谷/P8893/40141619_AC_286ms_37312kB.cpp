#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
inline int read();
int fir[5005];
int nxt[15000005];
int v[15000005];
int in[5005];
int now;
void add(int a,int b){
    now++;
    v[now]=b;
    nxt[now]=fir[a];
    fir[a]=now;
    in[b]++;
    return ;
}
int dp[5005];
std::queue<int>a;
signed main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	// freopen("rec4.in","r",stdin);
	// freopen(".out","w",stdout);
	#endif
    int n=read(),k=read(),p=read();
    for(int i=1;i<=n;i++){
        fir[i]=-1;
    }
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=p;i++){
        int temp=read();
        if(k==temp){
            printf("0");
            return 0;
        }
        dp[temp]=0;
        a.push(temp);
    }
    int r=read();
    for(int i=1;i<=r;i++){
        int v=read();
        int s=read();
        for(int j=1;j<=s;j++){
            add(read(),v);
        }
    }
    while(a.size()>0){
        int now=a.front();
        a.pop();
        for(int i=fir[now];i!=-1;i=nxt[i]){
            in[v[i]]--;
            dp[v[i]]=std::max(dp[v[i]],dp[now]+1);
            if(in[v[i]]==0){
                a.push(v[i]);
            }
        }
    }
    if(dp[k]==0){
        printf("-1");
    }else{
        printf("%d",dp[k]);
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
