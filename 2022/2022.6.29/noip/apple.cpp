#include <iostream>
#include <cstdio>
#include <vector>
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
vector<pair<int,int> >map[105];
int dp[105][105];//n½Úµãq¸öÊ÷Ö¦ 
int n,q;
int dfs(int now,int qn,int fa);
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	n=read();
	q=read();
	for(int i=1;i<=n-1;i++){
		int a=read(),b;
		b=read();
		int c=read();
		map[a].push_back(make_pair(b,c));
		map[b].push_back(make_pair(a,c));
	}
	printf("%d",dfs(1,q,0));
	return 0;
}
int dfs(int now,int qn,int fa){
	if(qn==0){
		return 0;
	}
	if(dp[now][qn]){
		return dp[now][qn];
	}
	int son1=0,son2=0;
	int si1,si2;
	for(int i=0;i<map[now].size();i++){
		if(map[now][i].first!=fa){
			if(son1==0){
				son1=map[now][i].first;
				si1=i;
			}else{
				son2=map[now][i].first;
				si2=i;
			}
		}
	}
	if(map[now].size()==1){
		return 0;
	}
	dp[now][qn]=max(dp[now][qn],dfs(son1,qn-1,now)+map[now][si1].second);
	dp[now][qn]=max(dp[now][qn],dfs(son2,qn-1,now)+map[now][si2].second);
	for(int i=1;i<qn;i++){
		dp[now][qn]=max(dp[now][qn],dfs(son1,i-1,now)+map[now][si1].second+dfs(son2,qn-i-1,now)+map[now][si2].second);
	}
	return dp[now][qn];
	
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



