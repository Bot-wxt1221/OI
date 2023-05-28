#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
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
queue<int>aa;
stack<int>in;
int dfsn=0;
int ans;
int now=0;
int w[200005];
int fir[200005];
int nxt[200005];
int v[200006];
int have=0;
void add(int a,int b,int c){
	now++;
	v[now]=b;
    w[now]=c;
	nxt[now]=fir[a];
	fir[a]=now;
	return ;
}
int dfn[200005],low[200005],in_stack[200005];
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
namespace ng{
	int now;
	int in[200005];
	int fir[200005];
	int nxt[200005];
	int v[200005];
    int w[200005];
	void add(int a,int b,int c){
		in[b]++;
		now++;
		v[now]=b;
        w[now]=c;
		nxt[now]=fir[a];
		fir[a]=now;
		return ;
	}	
}
int numberfornode[200005];
void dfs(int,int);
int main(){
    #ifdef ONLINE_JUDGE
	#else
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	#endif
	int n=read(),m=read();
	int k=read();
	for(int i=1;i<=n;i++){
		dp[i]=0x3f3f3f3f;
		ng::fir[i]=-1;
		fir[i]=-1;
	}
	for(int i=1;i<=m;i++){
		int a,b,c;
		a=read();
		b=read();
        c=read();
		add(a,b,c);
	}
	for(int i=1;i<=n;i++){
		if(dfn[i]){
			continue;
		} 
		dfs(i,-1);
	}
	for(int i=1;i<=n;i++){
		for(int j=fir[i];j!=-1;j=nxt[j]){
			if(numberfornode[i]!=numberfornode[v[j]]){
				ng::add(numberfornode[i],numberfornode[v[j]],w[j]);
			}
		}
	}
	a.push(node(numberfornode[1],0));
    dp[numberfornode[1]]=0;
    while(a.size()>0){
        node temp=a.top();
        a.pop();
        while(a.size()>0&&used[temp.i]){
            temp=a.top();
            a.pop();
        }
        used[temp.i]=1;
        for(int i=ng::fir[temp.i];i!=-1;i=ng::nxt[i]){
            // dp[v[i]]=std::min(dp[v[i]],dp[temp.i]+w[i]);
            if(dp[ng::v[i]]>dp[temp.i]+ng::w[i]){
                dp[ng::v[i]]=dp[temp.i]+ng::w[i];
                a.push(node(ng::v[i],dp[ng::v[i]]));
            }
        }
    }
	printf("%d",dp[numberfornode[k]]);
	return 0;
}
void dfs(int now,int fa){
	low[now]=dfn[now]=++dfsn;
	in.push(now);
	in_stack[now]=1;
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(dfn[v[i]]==0){
			dfs(v[i],now);
			low[now]=min(low[now],low[v[i]]);
		}else if(in_stack[v[i]]){
			low[now]=min(low[now],dfn[v[i]]);
		}
	}
	if(dfn[now]==low[now]){
		int tot=0;
		while(in.size()>0&&in.top()!=now){
			in_stack[in.top()]=0;
			numberfornode[in.top()]=ans+1;
			in.pop();
			have++;
		}
		in_stack[in.top()]=0;
		in.pop();
		numberfornode[now]=ans+1;	
		ans++;
	}
	return ;
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
