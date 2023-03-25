#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
using namespace std;
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
int dp[2005];
int nxt[6005];
int fir[2005];
int v[6005];
int w[6005];
int now;
int in[2005];
bool vised[2005];
queue<int>a;
void add(int x,int y,int z){
    now++;
    v[now]=y;
    w[now]=z;
    nxt[now]=fir[x];
    fir[x]=now;
    return ;
}
signed main(){
    #ifdef ONLINE_JUDGE=luogu
    #else
	 freopen(".in","r",stdin);
	 freopen(".out","w",stdout);
    #endif
    int T=read();
    while(T--){
        int n=read();
        int m=read();
        now=0;
        for(int i=0;i<=n;i++){
            vised[i]=0;
            dp[i]=0x3f3f3f3f3f3f3f3fll;
            in[i]=0;
            fir[i]=-1;
        }
        for(int i=1;i<=m;i++){
            nxt[i]=-1;
        }
        for(int i=1;i<=m;i++){
            int x=read();
            int y=read();
            int w=read();
            if(w>=0){
                add(x,y,w);
                add(y,x,w);
            }else{
                add(x,y,w);
            }
        }
        dp[1]=0;
        vised[1]=1;
        in[1]=1;
        a.push(1);
        int ans=0;
        while(a.size()>0){
            int temp=a.front();
            a.pop();
            vised[temp]=0;
            bool br=1;
            for(int i=fir[temp];i!=-1&&br;i=nxt[i]){
                if(dp[v[i]]>dp[temp]+w[i]){
                    dp[v[i]]=dp[temp]+w[i];
                    if(vised[v[i]]){

                    }else{
                        vised[v[i]]=1;
                        a.push(v[i]);
                        in[v[i]]++;
                        if(in[v[i]]>=n){
                            a=queue<int>();
                            ans=1;
                            br=0;
                            break;
                        }
                    }
                }
            }
        }
        if(!ans){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }
	return 0;
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