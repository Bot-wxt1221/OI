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
int dp[205000];
stack<int>in;
int dfsn=0;
int ans;
int now=0;
int fir[205000];
int nxt[2000005];
int v[2000050];
int have=0;
int a[2000050];
void add(int a,int b){
	now++;
	v[now]=b;
	nxt[now]=fir[a];
	fir[a]=now;
	return ;
}
int dfn[155000],low[150000],in_stack[150000];
namespace ng{
	int now;
	int in[500050];
	int fir[155000];
	int nxt[2000050];
	int v[2000050];
	int a[2000050];
	int siz[155000];
	void add(int a,int b){
		if(a==b){
			return ;
		}
		in[b]++;
		now++;
		v[now]=b;
		nxt[now]=fir[a];
		fir[a]=now;
		return ;
	}	
}
int numberfornode[500050];
void dfs(int,int);
int main(){
	freopen("semi0.in","r",stdin);
	freopen("semi.out","w",stdout);
	int n=read(),m=read();
	int x=read();
	for(int i=1;i<=n;i++){
		a[i]=1;
		ng::fir[i]=-1;
		fir[i]=-1;
	}
	for(int i=1;i<=m;i++){
		int a,b;
		a=read();
		b=read();
		add(a,b);
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
				ng::add(numberfornode[i],numberfornode[v[j]]);
			}
		}
	}
	for(int i=1;i<=ans;i++){
		if(ng::in[i]==0){
			aa.push(i);
		}
	}
	int anas=0;
	while(aa.size()>0){
		int temp=aa.front();
		aa.pop();
		for(int i=ng::fir[temp];i!=-1;i=ng::nxt[i]){
			dp[ng::v[i]]=max(dp[ng::v[i]],dp[temp]+ng::siz[ng::v[i]]);
			ng::in[ng::v[i]]--;
			if(ng::in[ng::v[i]]==0){
				aa.push(ng::v[i]);
			}
		}
	}
	int tmp=0;
	for(int i=1;i<=ans;i++) {
		if(dp[i]>anas) {
			anas=dp[i];
			tmp=dp[i];
		}else if(dp[i]==anas) {
			tmp+=dp[i];
			tmp%=x;
		}
	}
	printf("%d\n%d\n",anas,tmp);
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
			tot+=a[in.top()];
			numberfornode[in.top()]=ans+1;
			in.pop();
			have++;
		}
		ng::siz[ans+1]=have+1;
		in_stack[in.top()]=0;
		in.pop();
		numberfornode[now]=ans+1;	
		tot+=a[now];
		ans++;
		ng::a[ans]=tot;
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


