#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
#include <cstring>
#define int long long
inline int read();
int fir[10005];
int nxt[25000005];
int v[25000005];
int in[10005];
int now;
void add(int a,int b){
    now++;
    v[now]=b;
    nxt[now]=fir[a];
    fir[a]=now;
    if(in[b]!=-1)
        in[b]++;
    return ;
}
int dp[10005];
bool have[10005];
std::queue<std::pair<int,int> >a;
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
        have[temp]=1;
        a.push(std::make_pair(0,temp));
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
        std::pair<int,int> now=a.front();
        a.pop();
        for(int i=fir[now.second];i!=-1;i=nxt[i]){
            in[v[i]]--;
            dp[v[i]]=std::max(dp[v[i]],dp[now.second]+1);
            if(in[v[i]]==0){
                a.push(std::make_pair(-dp[v[i]],v[i]));
                if(v[i]==k){
                    printf("%lld",dp[k]);
                    return 0;
                }
            }
        }
    }
    // if(dp[k]==0||in[k]>0){
    printf("-1");
    // }else{
    //     printf("%lld",dp[k]);
    // }
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