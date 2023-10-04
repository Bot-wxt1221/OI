#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
inline int read();
int fir[80005];
int nxt[80005];
int v[80005];
int w[80005];
int now;
int n;
class node{
    public:
        int i,w;
        node(int ii,int ww){
            i=ii;
            w=ww;
        }
};
bool operator < (node a,node b){
    return a.w>b.w;
}
int dp[80005];
bool used[80005];
std::priority_queue<node>a;
void add(int uu,int vv,int ww){
    now++;
    v[now]=vv;
    if(ww>=0){
        w[now]=ww;
    }else if(abs(ww)<=n*10){
        w[now]=0;
    }else{
        w[now]=0x3f3f3f3f;
    }
    nxt[now]=fir[uu];
    fir[uu]=now;
    return ;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
//	freopen("geili.in","r",stdin);
//	freopen("geili.out","w",stdout);
	#endif
    int p=read();
    n=read();
    int m=read();
    for(int i=1;i<=n;i++){
        fir[i]=-1;
        dp[i]=0x3f3f3f3f;
    }
    for(int i=1;i<=m;i++){
        int x=read();
        int y=read();
        int z=read();
        add(x,y,z);
    }
    a.push(node(1,0));
    dp[1]=0;
    while(a.size()>0){
        node temp=a.top();
        a.pop();
        while(a.size()>0&&used[temp.i]){
            temp=a.top();
            a.pop();
        }
        used[temp.i]=1;
        for(int i=fir[temp.i];i!=-1;i=nxt[i]){
            // dp[v[i]]=std::min(dp[v[i]],dp[temp.i]+w[i]);
            if(dp[v[i]]>dp[temp.i]+w[i]){
                dp[v[i]]=dp[temp.i]+w[i];
                a.push(node(v[i],dp[v[i]]));
            }
        }
    }
    if(dp[n]<=p&&dp[n]!=0x3f3f3f3f){
        printf("%d",p-dp[n]);
    }else{
        printf("bu gei li a.");
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


