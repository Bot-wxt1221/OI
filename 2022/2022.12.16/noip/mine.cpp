#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
inline int read();
int fir[205];
int nxt[400005];
int v[400005];
int w[205];
int dp[205];
std::stack<int>out;
std::queue<int>a;
int now;
int in[205];
int from[205];
void add(int x,int y){
    now++;
    v[now]=y;
    nxt[now]=fir[x];
    fir[x]=now;
    in[y]++;
    return ;
}
int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen("mine.in","r",stdin);
	freopen("mine.out","w",stdout);
	#endif
    int n=read();
    for(int i=1;i<=n;i++){
        fir[i]=-1;
        w[i]=read();
    }
    int x1,y1;
    while(scanf("%d %d",&x1,&y1)!=EOF&&(x1!=0||y1!=0)){
        add(x1,y1);
    }
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            a.push(i);
            dp[i]=w[i];
        }
    }
    while(a.size()>0){
        int now=a.front();
        a.pop();
        for(int i=fir[now];i!=-1;i=nxt[i]){
            if(dp[v[i]]<dp[now]+w[v[i]]){
                dp[v[i]]=dp[now]+w[v[i]];
                from[v[i]]=now;
            }
            in[v[i]]--;
            if(in[v[i]]==0){
                a.push(v[i]);
            }
        }
    }
    int ans=0,ansi=0;
    for(int i=1;i<=n;i++){
        if(dp[i]>ans){
            ans=dp[i];
            ansi=i;
        }
    }
    while(ansi!=0){
        out.push(ansi);
        ansi=from[ansi];
    }
    while(out.size()>1){
        printf("%d-",out.top());
        out.pop();
    }
    printf("%d\n",out.top());
    printf("%d",ans);
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

